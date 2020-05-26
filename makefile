CXX=g++
CXXFLAGS=-std=c++11

SRCS=Piece.cpp board.cpp Card.cpp Game.cpp Helper.cpp main.cpp Menu.cpp Notebook.cpp Player.cpp room.cpp StateMachine.cpp AssetManager.cpp InputManager.cpp SplashState.cpp MainMenuState.cpp GameState.cpp PauseState.cpp SetupState.cpp HandOfCardsState.cpp AccuseState.cpp TurnTransitionState.cpp NotebookState.cpp SuggestState.cpp GameOverState.cpp
SFFLAGS=-lsfml-graphics
SFFLAGS+=-lsfml-window
SFFLAGS+=-lsfml-system

a.out: ${SRCS}
	${CXX} ${CXXFLAGS} ${SRCS} ${SFFLAGS}
