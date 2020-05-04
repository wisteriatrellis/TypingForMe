#include "game.hpp"
#include "model.hpp"
#include <fstream>
#include <string>
#include <stdlib.h>
#include <ncurses.h>
#include <iostream>
#include <memory>


Game::Game(std::shared_ptr<Model> pModel) {
  this->pModel = pModel; 
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
    pModel->addQuestions(str);
  }
  file.close();
}


void Game::run() {
  initscr();
  noecho();
  auto questions = pModel->getRandomQuestions();
  pModel->setStartTime();

  for (auto question : questions) {
    move(0, 0);
    clrtoeol();
    printw("%s", question.c_str());
    move(1, 0);
    clrtoeol();
    this->inputUserKeys(question);
  }
  
  pModel->setEndTime();
  endwin();
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
      pModel->incrementQuestionsCharCount();
    } else {
      flash();
      beep();
    }
    pModel->incrementInputKeyCount();
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

