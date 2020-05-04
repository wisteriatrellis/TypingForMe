#include "model.hpp"
#include "game.hpp"
#include "result.hpp"
#include <string.h>
#include <memory>


int main(int argc, char* argv[]) {
  std::string mainPart = "sqlite3 data.db \"select ex_sentence from teppeki";
  std::string outputPart = " > data.txt";
  std::string modifierPart = "";
  for (int i = 1; i < argc; i++) {
    modifierPart += " ";
    modifierPart += std::string(argv[i]);
  }
  modifierPart += "\"";
       

  std::shared_ptr<Model> pModel(new Model());
  Game game = Game(pModel);
  game.inputQuestions(mainPart + modifierPart + outputPart);
  game.run();
  Result result = Result(pModel);
  result.run();

  return 0;
}

