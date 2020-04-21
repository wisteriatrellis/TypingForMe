#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <string>


class Model {
public:
  void addQuestions(std::string question);
  std::vector<std::string> getAllQuestions() const;
  std::vector<std::string> getRandomQuestions() const;
private:
  std::vector<std::string> questions;
};


#endif

