#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <string>
#include <chrono>


class Model {
public:
  Model();
  void addQuestions(std::string question);
  std::vector<std::string> getAllQuestions() const;
  std::vector<std::string> getRandomQuestions() const;
  int getInputKeyCount() const;
  int getQuestionsCharCount() const;
  std::chrono::high_resolution_clock::time_point getStartTime() const;
  std::chrono::high_resolution_clock::time_point getEndTime() const;
  void setStartTime();
  void setEndTime();
  void incrementInputKeyCount();
  void incrementQuestionsCharCount();
  void init();
private:
  std::vector<std::string> questions;
  int inputKeyCount;
  int questionsCharCount;
  std::chrono::high_resolution_clock::time_point start;
  std::chrono::high_resolution_clock::time_point end;
};


inline int Model::getInputKeyCount() const {
  return inputKeyCount;
}


inline int Model::getQuestionsCharCount() const {
  return questionsCharCount;
}


inline std::chrono::high_resolution_clock::time_point Model::getStartTime() const {
  return start;
}


inline std::chrono::high_resolution_clock::time_point Model::getEndTime() const {
  return end;
}


#endif

