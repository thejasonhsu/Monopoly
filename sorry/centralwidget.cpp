#include "centralwidget.h"

CentralWidget::CentralWidget(): QWidget() {
  //setGeometry( 0, 0, 577, 577 );
  boardLabel = new QLabel( this );
  boardLabel->setPixmap( QPixmap(":/images/sorry.jpg") );

  //Create the two card images
  cardFaceDown = new QPixmap( ":/images/cardfacedown.png" );
  cardFaceUp = new QPixmap( ":/images/card5.png" );

  //Create the button for the card deck
  cardDeckButton = new QPushButton( this );
  cardDeckButton->setIcon( *cardFaceDown );
  cardDeckButton->setIconSize( QSize(97, 152) );
  cardDeckButton->setGeometry( 240, 205, 97, 152 );

  //Connect the button to drawCard
  connect( cardDeckButton, SIGNAL(clicked()), this, SLOT(drawCard()) );
  isFaceDown = true;
}

void CentralWidget::drawCard() {
  //Show the face up card
  if ( isFaceDown ) {
    cardDeckButton->setIcon( *cardFaceUp );
    isFaceDown = false;
  } else {
    cardDeckButton->setIcon( *cardFaceDown );
    isFaceDown = true;
  }
}
