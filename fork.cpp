#include "fork.h"

Fork::Fork()
{
	 mtx = new std::mutex();
}

Fork::Fork(int n)
{
    	mtx = new std::mutex();
		id = n;
}

