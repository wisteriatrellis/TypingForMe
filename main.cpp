#include "game.hpp"
#include <string.h>


int main(int argc, char* argv[]) {
  std::string mainPart = "sqlite3 data.db \"select ex_sentence from teppeki";
  std::string outputPart = " > data.txt";
  std::string modifierPart = "";
  for (int i = 1; i < argc; i++) {
    modifierPart += " ";
    modifierPart += std::string(argv[i]);
  }
  modifierPart += "\"";
       
  Game game = Game();
  game.inputQuestions(mainPart + modifierPart + outputPart);
  game.loop();

  return 0;
}

