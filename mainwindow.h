#ifndef _MAINWINDOW_H
#define _MAINWINDOW_H

#include <QtGui>
#include "centralwidget.h"
#include <QMainWindow>
#include "player.h"
#include "guiplayer.h"
#include "Board.h"

class MainWindow : public QMainWindow
{
  Q_OBJECT

  private:
  QLabel *boardLabel;

  QPushButton *cardDeckButton;
  QPushButton *rollButton, *buyrentButton;
  QPushButton *endButton, *resignButton;

  CentralWidget* centralWidget;
  Player** players;
  GUIPlayer* guiPlayers[4];
  Board *b = NULL;

  private slots:
    void startGame();
    void rollDie();
    void endTurn();
    void resign();
    void buyOrRent();

  public:
    MainWindow();
    void drawLocation();

};

#endif
