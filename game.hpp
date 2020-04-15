#ifndef GAME_H
#define GAME_H

#include "model.hpp"


class Game {
public:
  Game();
  void inputQuestions();
  void print();
private:
  Model model;
};


#endif

