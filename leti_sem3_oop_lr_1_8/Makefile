# TARGET = main
# CC = g++

#здесь будут храниться имена всех файлов с окончанием на .cpp // src - хранит все исходники на .cpp 
# SRC = $(wildcard *.cpp) 

#хранит все объектные файлы // берт файлы .срр и добавляе к себе но с расширением .о и берет их из SRC
# OBJ = $(patsubst %.cpp, %.o, $(SRC))

#конструкция для маленьких целей в общем случае
# $< - справа от ":"
# $> - слева от ":"

#шаблон сразу для каждого файла из SRC
#%.o : %.cpp
#	$(CC) -c $< -o $@



#$(TARGET) : $(OBJ)
#	S(CC) $(OBJ) -o $(TARGET)

#$(TARGET) : main.o Cell.o Controller.o GameField.o Player.o Intro.o
#	$(CC) main.o Cell.o Controller.o GameField.o Player.o Intro.o -o $(TARGET)

#main.o : main.cpp
#	$(CC) -c main.cpp -o main.o

#Cell.o : Cell.cpp
#	$(CC) -c Cell.cpp -o Cell.o

#Controller.o : Controller.cpp
#	$(CC) -c Controller.cpp -o Controller.o

#GameField.o : GameField.cpp
#	$(CC) -c GameField.cpp -o GameField.o

#Player.o : Player.cpp
#	$(CC) -c Player.cpp -o Player.o

#Intro.o : Intro.cpp
#	$(CC) -c Intro.cpp -o Intro.o

#clean :
#	rm $(TARGET) *.o 




TARGET = main
CC = g++
SRC = $(wildcard *.cpp) 
OBJ = $(patsubst %.cpp, %.o, $(SRC))

$(TARGET) : $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)
%.o : %.cpp
	$(CC) -c $< -o $@
clean :
	rm $(TARGET) *.o 

