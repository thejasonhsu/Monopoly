
#ifndef CENTRALWIDGET_H
#define CENTRALWIDGET_H

#include <QtGui>
#include <QWidget>
#include <QPushButton>
#include <QPixmap>
#include <QLabel>

class CentralWidget: public QWidget {
  Q_OBJECT

  private:
    QPushButton* cardDeckButton;
    QLabel* boardLabel;
    QPixmap* cardFaceDown;
    QPixmap* cardFaceUp;
    bool isFaceDown;

  private slots:
    void drawCard();

 public:
    CentralWidget();

};

#endif
