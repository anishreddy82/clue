CXX=g++
SRCS=board.cpp Card.cpp Game.cpp Helper.cpp main.cpp Menu.cpp Notebook.cpp Player.cpp room.cpp

a.out: ${SRCS}
	${CXX} ${SRCS}
