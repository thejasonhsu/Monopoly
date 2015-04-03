#include "guiplayer.h"
#include "player.h"
#include <iostream>
#include <string>

GUIPlayer::GUIPlayer( Player* p )
{
  player = p;
  if(nameLabel == NULL)
      nameLabel = new QLabel( this );
  nameLabel->setTextFormat(Qt::RichText);
  updateStats();
}

QString GUIPlayer::convert(int num)
{
    QString str = "";
    while(num != 0)
    {
        str = static_cast<char>(num % 10 + '0') + str;
        num /= 10;
    }
    return str;
}

void GUIPlayer::updateStats()
{
    QString str = player->getToken();
    QString money = convert(player->getMoney());
    nameLabel->setText("<b><font color=\"blue\">" + str + "</font></b>: $" + money);
}

void GUIPlayer::setMoney(int money)
{
    int total = money - player->getMoney();
    player->addMoney(total);
    updateStats();
}
