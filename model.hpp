#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <string>


class Model {
public:
  Model();
  void addQuestions(std::string question);
  std::vector<std::string> getAllQuestions() const;
  std::vector<std::string> getRandomQuestions() const;
  int getInputKeyCount() const;
  int getQuestionsCharCount() const;
  void incrementInputKeyCount();
  void incrementQuestionsCharCount();
  void init();
private:
  std::vector<std::string> questions;
  int inputKeyCount;
  int questionsCharCount;
};


inline int Model::getInputKeyCount() const {
  return inputKeyCount;
}


inline int Model::getQuestionsCharCount() const {
  return questionsCharCount;
}


#endif

