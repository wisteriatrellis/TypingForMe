#ifndef RESULT_H
#define RESULT_H


#include "scene.hpp"
#include "model.hpp"
#include <memory>


class Result : public Scene {
public:
  Result(std::shared_ptr<Model> pModel);
  void run();
private:
  std::shared_ptr<Model> pModel;
};


#endif

