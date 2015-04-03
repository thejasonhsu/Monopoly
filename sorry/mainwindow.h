#ifndef _MAINWINDOW_H
#define _MAINWINDOW_H

#include <QtGui>

#include "guiplayerhorizontal.h"
#include "guiplayervertical.h"
#include "centralwidget.h"

#include <QMainWindow>


class MainWindow : public QMainWindow {
  Q_OBJECT

  private:
  QLabel *boardLabel;
  Player* players[4];
  GUIPlayer* guiPlayers[4];
  QPushButton* cardDeckButton;
  QWidget* centralWidget;

  public:
    MainWindow();

};

#endif
