//player.h
#ifndef PLAYER_H
#define PLAYER_H

#include <QString>

class Player {
 private:
  QString playerName;

 public:
  Player(QString n);
  void setName( QString n );
  QString getName();

};

#endif
