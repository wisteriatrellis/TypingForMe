#include "model.hpp"
#include <vector>
#include <string>


void Model::addQuestions(std::string question) {
  questions.push_back(question);
}


std::vector<std::string> Model::getQuestions() {
  return questions;
}


