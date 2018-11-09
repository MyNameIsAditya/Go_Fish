# target: dependencies
# <tab> rule

# make (without arguments) executes first rule in file
# Ideally, one target for every object file and a target for final binary.

go_fish: go_fish.o card.o deck.o player.o
	g++ -ogo_fish  go_fish.o card.o deck.o player.o
go_fish.o: go_fish.cpp card.h deck.h player.h
	g++ -c go_fish.cpp
card.o: card.cpp card.h
	g++ -c card.cpp
deck.o: deck.cpp deck.h card.h
	g++ -c deck.cpp
player.o: player.cpp player.h card.h
	g++ -c player.cpp
