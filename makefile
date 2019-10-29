# Program name: Final - makefile
# Author: Nicholas Tensing
# Date: 6/3/19
# Description: makefile for Final


Final: main.cpp game.cpp game.hpp valid.cpp valid.hpp battle.cpp battle.hpp arena.cpp arena.hpp studio.cpp studio.hpp practiceRoom.cpp practiceRoom.hpp space.cpp space.hpp guitarist.cpp guitarist.hpp metalType.cpp metalType.hpp gear.cpp gear.hpp
	g++ -g -std=c++0x main.cpp valid.cpp game.cpp battle.cpp arena.cpp studio.cpp studio.hpp practiceRoom.cpp space.cpp guitarist.cpp metalType.cpp rockType.cpp bluesType.cpp legendType.cpp gear.cpp -o Final

clean:
	rm Final
