#include "mainwindow.h"
#include "guiplayervertical.h"
#include "guiplayerhorizontal.h"
#include "player.h"
#include <QApplication>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <iostream>
#include <string>

using namespace std;

MainWindow::MainWindow() : QMainWindow()
{
  setGeometry( 50, 50, 758, 615 );

  //Display the board in the central widget
  centralWidget = new CentralWidget();
  setCentralWidget( centralWidget );

  QMenuBar *menubar = menuBar();
  QMenu *file = new QMenu("File", this);
  menubar->addMenu(file);

  QAction *newgameAction = new QAction("New Game", this);
  file->addAction(newgameAction);
  connect(newgameAction, SIGNAL(triggered()), this, SLOT(startGame()));

  QAction *exitAction = new QAction("Exit", this);
  file->addAction(exitAction);
  connect(exitAction, SIGNAL(triggered()), QApplication::instance(), SLOT(quit()));

  //Create the roll button for the board.
  rollButton = new QPushButton( centralWidget );
  rollButton->setText("ROLL");
  rollButton->setGeometry(98, 405, 90, 40);
  connect(rollButton, SIGNAL(pressed()), this, SLOT(rollDie()));

  buyrentButton = new QPushButton( centralWidget );
  buyrentButton->setText("BUY / UPGRADE");
  buyrentButton->setGeometry(198, 405, 90, 40);
  connect(buyrentButton, SIGNAL(pressed()), this, SLOT(buyOrRent()));

  endButton = new QPushButton( centralWidget );
  endButton->setText("END TURN");
  endButton->setGeometry(298, 405, 90, 40);
  connect(endButton, SIGNAL(pressed()), this, SLOT(endTurn()));

  resignButton = new QPushButton( centralWidget );
  resignButton->setText("RESIGN");
  resignButton->setGeometry(398, 405, 90, 40);
  connect(resignButton, SIGNAL(pressed()), this, SLOT(resign()));

  this->show();

  for(int i = 0; i < 4; i++)
      guiPlayers[i] = NULL;

  rollButton->setEnabled(false);
  buyrentButton->setEnabled(false);
  endButton->setEnabled(false);
  resignButton->setEnabled(false);
}

void MainWindow::startGame()
{
    if (b != NULL)
        delete b;
    b = new Board();

    //Create the 4 players
    int numPlayers = b->getNumPlayers();

    for(int i = 0; i < 4; i++)
        if(guiPlayers[i] != NULL)
        {
            removeDockWidget(guiPlayers[i]);
            guiPlayers[i] = NULL;
        }

    //Player 1 is at the bottom. 2 at the left. 3 on top. 4 on the right
    //Create the GUIPlayers
    for(int i = 0; i < numPlayers; i++)
    {
        Player *p = b->getPlayer(i);
        if(i % 2 == 0)
            guiPlayers[i] = new GUIPlayerHorizontal(p);
        else
            guiPlayers[i] = new GUIPlayerVertical(p);
    }
    addDockWidget( Qt::BottomDockWidgetArea, guiPlayers[0] );
    addDockWidget( Qt::LeftDockWidgetArea, guiPlayers[1] );
    if(numPlayers > 2)
        addDockWidget( Qt::TopDockWidgetArea, guiPlayers[2] );
    if(numPlayers > 3)
        addDockWidget( Qt::RightDockWidgetArea, guiPlayers[3] );

    rollButton->setEnabled(true);
    buyrentButton->setEnabled(false);
    endButton->setEnabled(false);
    resignButton->setEnabled(true);

    drawLocation();
}

void MainWindow::drawLocation()
{
    centralWidget->drawPieces(b->getAllPlayers(), b->getNumPlayers());

    for(int i = 0; i < b->getNumPlayers(); i++)
        guiPlayers[i]->setMoney(b->getPlayer(i)->getMoney());
}

void MainWindow::rollDie()
{
    b->roll();
    drawLocation();
    b->doAutomaticActions();
    drawLocation();
    rollButton->setEnabled(false);
    if(b->hasAction())
        buyrentButton->setEnabled(true);
    else
        buyrentButton->setEnabled(false);
    endButton->setEnabled(true);
    resignButton->setEnabled(true);
}

void MainWindow::endTurn()
{
    bool isNotFinished = b->nextPerson();
    if(isNotFinished)
    {
        rollButton->setEnabled(true);
        resignButton->setEnabled(true);
    }
    else
    {
        rollButton->setEnabled(false);
        resignButton->setEnabled(false);
    }
    buyrentButton->setEnabled(false);
    endButton->setEnabled(false);
    drawLocation();
}

void MainWindow::resign()
{
    b->shouldResign();
    rollButton->setEnabled(false);
    buyrentButton->setEnabled(false);
    endButton->setEnabled(true);
    resignButton->setEnabled(false);
    drawLocation();
}

void MainWindow::buyOrRent()
{
    b->selectBuyOrUpgrade();
    rollButton->setEnabled(false);
    buyrentButton->setEnabled(false);
    endButton->setEnabled(true);
    resignButton->setEnabled(true);
    drawLocation();
}
