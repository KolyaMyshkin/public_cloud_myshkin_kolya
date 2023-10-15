main : main.o Cell.o Controller.o GameField.o Player.o
	g++ main.o Cell.o Controller.o GameField.o Player.o -o main

main.o : main.cpp
	g++ -c main.cpp -o main.o

Cell.o : Cell.cpp
	g++ -c Cell.cpp -o Cell.o

Controller.o : Controller.cpp
	g++ -c Controller.cpp -o Controller.o

GameField.o : GameField.cpp
	g++ -c GameField.cpp -o GameField.o

Player.o : Player.cpp
	g++ -c Player.cpp -o Player.o

clean :
	rm main *.o 

