CXX=g++
SRCS=board.cpp Card.cpp Game.cpp Helper.cpp main.cpp Menu.cpp Notebook.cpp Player.cpp room.cpp StateMachine.cpp AssetManager.cpp InputManager.cpp SplashState.cpp MainMenuState.cpp GameState.cpp PauseState.cpp
SFFLAGS=-lsfml-graphics
SFFLAGS+=-lsfml-window
SFFLAGS+=-lsfml-system

a.out: ${SRCS}
	${CXX} ${SRCS} ${SFFLAGS}
