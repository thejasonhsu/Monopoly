
#include "mainwindow.h"

MainWindow::MainWindow() {
  setGeometry( 0, 0, 750, 750 );

  //Display the board in the central widget
  centralWidget = new CentralWidget();
  setCentralWidget( centralWidget );

  //Create the 4 players
  players[0] = new Player( "Joe" );
  players[1] = new Player( "Mary" );
  players[2] = new Player( "Fred" );
  players[3] = new Player( "Linda" );

  //Player 1 is at the bottom. 2 at the left. 3 on top. 4 on the right
  //Create the GUIPlayers
  guiPlayers[0] = new GUIPlayerHorizontal( players[0] );
  guiPlayers[1] = new GUIPlayerVertical( players[1] );
  guiPlayers[2] = new GUIPlayerHorizontal( players[2] );
  guiPlayers[3] = new GUIPlayerVertical( players[3] );

  addDockWidget( Qt::BottomDockWidgetArea, guiPlayers[0] );
  addDockWidget( Qt::LeftDockWidgetArea, guiPlayers[1] );
  addDockWidget( Qt::TopDockWidgetArea, guiPlayers[2] );
  addDockWidget( Qt::RightDockWidgetArea, guiPlayers[3] );
}
