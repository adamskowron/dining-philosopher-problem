#pragma once
#include "fork.h"
#include "wiz.h"
#include "ncurses.h"
#include <string>
#include <cstdlib>
#include <unistd.h>
#include <vector>


class Philosoph
{
	std::string state;
	const int minTime = 25;
        const int maxTime = 35;
        int number;
	double percent;
        Fork left,right;
        int leftFork(int i);
        int rightFork(int i);
	static char check;

        public:
                Philosoph(int n,std::vector<Fork> forks);

                void live(Wiz &wiz);
		void eat(Wiz &wiz);
		void think(Wiz &wiz);
};


