#ifndef GAME_H
#define GAME_H

#include "model.hpp"


class Game {
public:
  Game();
  void inputQuestions();
  void loop();
private:
  Model model;
  void inputUserKeys(std::string question);
  void moveCursor(int argY, int argX) const;
};


#endif

