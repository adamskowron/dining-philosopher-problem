#pragma once
#include <vector>
#include <string>
#include <ncurses.h>
#include <mutex>

class Wiz{
public:
	std::mutex *mtx;
	int number;
	double angle;
	int tabRadA,tabRadB,phiRadA,phiRadB;

	Wiz(int n);
	void setState(std::string state, double percent, int id);
	~Wiz();
};
