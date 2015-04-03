#include "centralwidget.h"
#include <iostream>

using namespace std;

CentralWidget::CentralWidget(): QWidget()
{
  //setGeometry( 0, 0, 577, 577 );
  boardLabel = new QLabel( this );
  boardLabel->setPixmap( QPixmap("C:\\images\\board.png") );
  pieces = new QLabel*[4];
  size = 0;
}

void CentralWidget::drawPieces(Player *p, int s)
{
    for(int i = 0; i < s; i++)
    {
        if(p[i].isAlive())
        {
            xCoor[i] = p[i].getX();
            yCoor[i] = p[i].getY();
        }
        else
        {
            xCoor[i] = -100;
            yCoor[i] = -100;
        }
        size = s;
        pName[i] = p[i].getToken();
    }
    update();
}

void CentralWidget::paintEvent(QPaintEvent *)
{
    boardLabel->setPixmap( QPixmap("C:\\images\\board.png") );
    QImage map(boardLabel->pixmap()->toImage());
    QPainter painter(&map);
    for(int i = 0; i < size; i++)
    {
        QImage img( getImageFile(pName[i]) );
        painter.drawImage(xCoor[i] + 25 * (i % 2) + 8, yCoor[i] + 20 * (i / 2) + 8, img);
    }
    painter.end();
    boardLabel->setPixmap(QPixmap::fromImage(map));
}

QString CentralWidget::getImageFile(QString piece)  //display tokens corresponding to player choices
{
    if(piece == "dog")
        return "C:\\images\\dog.png";
    else if(piece == "shoe")
        return "C:\\images\\shoe.png";
    else if(piece == "thimble")
        return "C:\\images\\thimble.png";
    else
        return "C:\\images\\battleship.png";
}
