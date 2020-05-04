#include "result.hpp"
#include "model.hpp"
#include <chrono>
#include <iostream>


Result::Result(std::shared_ptr<Model> pModel) {
  this->pModel = pModel;
}


void Result::run() {
  int questionsCharCount = pModel->getQuestionsCharCount();
  int inputKeyCount = pModel->getInputKeyCount();
  auto start = pModel->getStartTime();
  auto end = pModel->getEndTime();
  auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start).count();
  float wpm = questionsCharCount * 60 / static_cast<float>(duration);
  float precision = questionsCharCount * 100 / static_cast<float>(inputKeyCount);

  std::cout << "Time: " << duration << "s" << std::endl;  
  std::cout << "WPM: " << wpm << std::endl;
  std::cout << "precision: " << precision << "%" << std::endl;
}

