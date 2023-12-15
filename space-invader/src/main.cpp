#include "./includes/StateMachine.hpp"

int main () {

  StateMachine invaderGame = StateMachine();
  invaderGame.Run();

  AssetsManager::getInstance()->~AssetsManager();

  return 0;
}