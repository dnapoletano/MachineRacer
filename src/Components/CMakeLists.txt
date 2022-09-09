set(Components_SOURCES
  TransformComponent.cpp
  SpriteComponent.cpp
  # InputComponent.cpp
  # CollisionComponent.cpp
)

include_directories(${SDL_Include})
link_directories(${SDL_Library_Path})
link_libraries(SDL2)
add_library(Components ${Components_SOURCES})

set_target_properties(Components PROPERTIES PREFIX "libTwoDEngine")
target_link_libraries(Components PUBLIC Utils)
