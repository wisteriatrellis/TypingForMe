#include "game.hpp"
#include "model.hpp"
#include <fstream>
#include <string>
#include <stdlib.h>
#include <ncurses.h>
#include <iostream>
#include <chrono>


Game::Game() {
  model = Model();
}


void Game::inputQuestions(std::string command) {
  system(command.c_str());
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


void Game::loop() {
  initscr();
  noecho();
  auto questions = model.getRandomQuestions();
  auto start = std::chrono::high_resolution_clock::now();

  for (auto question : questions) {
    move(0, 0);
    clrtoeol();
    printw("%s", question.c_str());
    move(1, 0);
    clrtoeol();
    this->inputUserKeys(question);
  }
  
  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start).count();
  endwin();
  
  // ここらへんはresult画面(Result)クラスに移す予定
  int questionsCharCount = model.getQuestionsCharCount();
  int inputKeyCount = model.getInputKeyCount();
  float precision = questionsCharCount * 100 / static_cast<float>(inputKeyCount);
  float wpm = questionsCharCount * 60 / static_cast<float>(duration);

  std::cout << "precision: " << precision << "%" << std::endl;
  std::cout << "WPM: " << wpm << std::endl;
  std::cout << "Time: " << duration << "s" << std::endl;
}


void Game::inputUserKeys(std::string question) {
  int questionLength = question.length();
  int charPos = 0;
  while (charPos != questionLength) {
    int ch = getch(); 
    if (ch == question[charPos]) {
      ++charPos;
      insch(ch);
      moveCursor(0, 1);
      model.incrementQuestionsCharCount();
    } else {
      flash();
      beep();
    }
    model.incrementInputKeyCount();
    refresh();
  }
}


void Game::moveCursor(int argY, int argX) const {
  int nowY, nowX;

  getyx(stdscr, nowY, nowX);
  int maxX = getmaxx(stdscr);
  int newY = nowY + argY;
  int newX = nowX + argX;

  if (maxX <= newX) {
    newX %= maxX;
    newY += 1;
  }

  move(newY, newX);
}

