
#ifndef CENTRALWIDGET_H
#define CENTRALWIDGET_H

#include <QtGui>
#include <QWidget>
#include <QPushButton>
#include <QPixmap>
#include <QLabel>
#include "Player.h"

class CentralWidget: public QWidget {
  Q_OBJECT

  private:
    QLabel *boardLabel, **pieces;
    int xCoor[4], yCoor[4], size;
    QString pName[4];
    QString getImageFile(QString piece);

 public:
    CentralWidget();
    void drawPieces(Player *p, int s);
    void paintEvent(QPaintEvent *);

};

#endif
