#include "gamestate.h"

GameState::GameState() {
  
}

GameState::~GameState() {}

void GameState::setGameState(int state) {
  currentstate = state;
}

int GameState::getGameState() {
  return currentstate;
}
