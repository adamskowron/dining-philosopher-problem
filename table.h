#pragma once
#include "philosoph.h"
#include "fork.h"
#include "wiz.h"
#include <vector>
#include <thread>

class Table{
private:

	int number;
	std::vector<Fork> forks;
	std::vector<Philosoph> philosophs;
    	std::vector<std::thread> threads;
public:

Table(int n);

};
