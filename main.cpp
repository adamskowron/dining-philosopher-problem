#include "table.h"
#include "philosoph.h"
#include <vector>
#include <cstdlib>
#include <iostream>

int main(int argc, char *argv[])
{

	if(argc != 2)
	std::cout << "zla liczba argumentow\n";
	else
	{

		int n = atoi(argv[1]);

	if(n < 5)
	{
		std::cout<<"podaj ilosc filozofow - minimalnie 5\n";
		return 0;
	}

	Table t(n);
	}
	return 0;
}
