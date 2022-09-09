#ifndef TWO2DENGINE_ENGINE_ENGINE_HPP
#define TWO2DENGINE_ENGINE_ENGINE_HPP

#include "TwoDEngine/Components/SpriteComponent.hpp"

#include <fstream>
#include <map>
#include <memory>
#include <vector>

union SDL_Event;
class SDL_Window;
class SDL_Renderer;

class Map {
private:
  TextureWrapper _Texture;
  /// A map is just a vector of sprites
  std::vector<SpriteComponent> _Sprites;
public:
  Map(SDL_Renderer* Renderer, const std::string& path):
    _Texture{Renderer, path}
  { }
  Map(Map& map) = delete;
  Map(const Map& map) = delete;

  Map(Map&& map) :
    _Texture{std::move(map._Texture)}, _Sprites{std::move(map._Sprites)}
  { }

  void LoadMap(SDL_Window* Window)
  {
    std::ifstream map {"/Users/Nappo/games/machineracing/Maps/map.map", std::ios::in};
    int WindowHeight = 0, WindowWidth = 0;
    SDL_GetWindowSize(Window, &WindowHeight, &WindowWidth);
    const int RescaleFactorY = WindowHeight/256;
    const int RescaleFactorX = WindowWidth/256;
    const int TileSetSize = 32;
    const int ImgSize = 8;

    _Sprites.reserve(TileSetSize * TileSetSize);

    for (int j{0}; j < TileSetSize; ++j) {
      for (int i{0}; i < TileSetSize; ++i) {
        std::pair<int,int> SrcPos;
        char c;
        map.get(c);
        if (c == '1') { // Grass, 0-offset
          SrcPos.first = SrcPos.second = 0;
        }
        else if (c == '2') { // Curb, 2-offset
          SrcPos.first = ImgSize * 2;
          SrcPos.second = 0;
        }
        else if (c == '3') { // Tarmac
          SrcPos.first  = ImgSize;
          SrcPos.second = 0;
        }
        _Sprites.push_back(
          SpriteComponent{SrcPos,ImgSize,RescaleFactorX,RescaleFactorY,
                          &_Texture,Vector2D{static_cast<float>(i),static_cast<float>(j)}}
        );

        map.ignore();
      }
    }
    map.close();
  }

  void DrawMap()
  {
    for(auto& s: _Sprites){
      s.Draw();
    }
  }
};

class Engine {
public:
  Engine(const std::string& title, const int width, const int height, const bool fullscreen);
  ~Engine();

  bool isRunning(SDL_Event& event);

  inline SDL_Renderer* GetRenderer() const {return _Renderer;}
  inline SDL_Window* GetWindow() const {return _Window;}

private:
  SDL_Window*   _Window;
  SDL_Renderer* _Renderer;
  Map _map;
};







#endif