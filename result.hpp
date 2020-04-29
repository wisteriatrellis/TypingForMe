#ifndef RESULT_H
#define RESULT_H


#include "model.hpp"
#include <memory>


class Result {
public:
  Result();
  void run();
private:
  std::shared_ptr<Model> pModel;
};


#endif

