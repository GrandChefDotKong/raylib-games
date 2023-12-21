#include "./includes/GameState.hpp"

GameState::GameState(): m_score(0), m_gameOver(false) {

  this->LoadingAssets();

}

void GameState::LoadingAssets() {
  AssetsManager* assetManager = AssetsManager::getInstance();

}

States GameState::Update() {
  if(m_gameOver) {
    return States::GAMEOVER;
  }
// Update here


// Fixed update
  if(m_speed->eventTriggered()) {
    this->FixedUpdate();
  }

  return States::CONTINUE;
}

void GameState::FixedUpdate() {}

void GameState::Draw() {}

GameState::~GameState() {}


