#include <QtGui>

#ifndef GUIPLAYER_H
#define GUIPLAYER_H

#include "player.h"
#include <QDockWidget>
#include <QLabel>

class GUIPlayer : public QDockWidget
{
  Q_OBJECT

  protected:
    Player* player;
    QLabel *nameLabel = NULL;

  public:
    GUIPlayer( Player* p );
    void setMoney(int money);
    void updateStats();
    QString convert(int num);

};

#endif
