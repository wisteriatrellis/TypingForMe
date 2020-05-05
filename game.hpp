#ifndef GAME_H
#define GAME_H


#include "scene.hpp"
#include "model.hpp"
#include <memory>


class Game : public Scene {
public:
  Game(std::shared_ptr<Model> pModel);
  void inputQuestions(std::string command);
  void run();
private:
  std::shared_ptr<Model> pModel;
  void inputUserKeys(std::string question);
  void moveCursor(int argY, int argX) const;
};


#endif

