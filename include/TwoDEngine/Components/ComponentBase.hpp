#ifndef TWO2DENGINE_COMPONENTS_COMPONENTBASE_H
#define TWO2DENGINE_COMPONENTS_COMPONENTBASE_H

class ComponentBase {
public:
  virtual ~ComponentBase() {}
  virtual bool Init()   = 0;
  virtual bool Update() = 0;
  virtual bool Draw()   = 0;
};

#endif // TWO2DENGINE_COMPONENTS_COMPONENTBASE_H