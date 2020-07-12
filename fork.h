#pragma once 
#include <mutex>

using namespace std; 
class Fork {

    public:
        std::mutex* mtx;
	int id;
        bool isUsed;

	Fork();
	Fork(int i);
};

