CC = g++
TARGET = BattleShip
SOURCES = BattleShip.cpp \
	Aircraft.cpp \
	main.cpp \
	Cruiser.cpp \
	Destroyer.cpp \
	GameManager.cpp \
	Player.cpp \
	Ship.cpp \
	Pane.cpp \
	BattleShipMap.cpp \
	StatPane.cpp \
	InputPane.cpp \
	BattleShipApp.cpp
LDFLAGS = -lncurses -std=c++11

all:
	$(CC) -o $(TARGET) $(SOURCES) $(LDFLAGS)

clean:
	rm -rf *.o $(TARGET)
