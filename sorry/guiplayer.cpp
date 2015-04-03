#include "guiplayer.h"

GUIPlayer::GUIPlayer( Player* p ) {
  player = p;
  nameLabel = new QLabel( this );
  nameLabel->setTextFormat(Qt::RichText);
  nameLabel->setText("<b><font color=\"blue\">" + player->getName() + "</font></b>");
}
