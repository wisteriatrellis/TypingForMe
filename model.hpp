#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <string>


class Model {
public:
  void addQuestions(std::string question);
  std::vector<std::string> getQuestions();

private:
  std::vector<std::string> questions;
};


#endif

