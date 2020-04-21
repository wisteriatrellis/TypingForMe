#include "model.hpp"
#include <vector>
#include <string>
#include <random>


void Model::addQuestions(std::string question) {
  questions.push_back(question);
}


std::vector<std::string> Model::getAllQuestions() const {
  return questions;
}


std::vector<std::string> Model::getRandomQuestions() const {
  std::vector<std::string> randomQuestions = {};
  for (auto question : questions) {
    randomQuestions.push_back(question);
  }

  std::random_device seed_gen;
  std::mt19937 engine(seed_gen());

  for (int i = 0; i < questions.size(); i++) {
    std::uint32_t randomIndex = engine() % (questions.size() - i) + i;
    auto tmp = randomQuestions[randomIndex];
    randomQuestions[randomIndex] = randomQuestions[i];
    randomQuestions[i] = tmp;
  }
  return randomQuestions;
}

