CC=g++
CCFLAG = -std=c++11
BOOSTFLAG = -lboost_filesystem -lboost_system -lboost_serialization

RM = rm -rf
OUTPUT = ../test

MAIN_CPP = main.cpp BinaryTree.cpp

all :
	$(CC) $(MAIN_CPP) -o $(OUTPUT)  -static -static-libgcc -static-libstdc++ $(CCFLAG) $(BOOSTFLAG)

clean : 
	$(RM) *.o $(OUTPUT)
