#ifndef SCENE_H
#define SCENE_H


class Scene {
public:
  virtual ~Scene();
  virtual void run() = 0;
};


#endif

