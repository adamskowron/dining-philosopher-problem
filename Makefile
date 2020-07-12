#Makefile
all:
	g++ -std=c++11 table.cpp fork.cpp philosoph.cpp wiz.cpp main.cpp -o test -pthread -fpermissive -lncurses -w -g
