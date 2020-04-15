#include "game.hpp"
#include "model.hpp"
#include <fstream>
#include <string>
#include <stdlib.h>
#include <iostream>


Game::Game() {
  model = Model();
}


void Game::inputQuestions() {
  std::ifstream file;
  std::string str;

  file.open("data.txt", std::ios::in);
  if (file.fail()) {
    exit(EXIT_FAILURE);
  }
  while (getline(file, str)) {
    model.addQuestions(str);
  }
  file.close();
}


void Game::print() {
  auto questions = model.getQuestions();
  for (auto question : questions) {
    std::cout << question << std::endl;
  }
}
  
