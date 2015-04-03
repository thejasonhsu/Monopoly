//player.cpp
#include "player.h"

Player::Player( QString n ) {
  playerName = n;
}

void Player::setName( QString n ) {
  playerName = n;
}

QString Player::getName() {
  return playerName;
}
