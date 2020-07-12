#include "table.h"

Table::Table(int n)
{

        for(int i = 0; i<n; i++)
        {
                Fork* f = new Fork(i);
                forks.push_back(*f);
	}

	for(int i= 0; i<n;i++)
	{
                Philosoph* p = new Philosoph(i,forks);
                philosophs.push_back(*p);
        }

	Wiz wiz(n);

        for(int i = 0; i<n; i++)
        {
		std::thread t(&Philosoph::live,&philosophs.at(i),std::ref(wiz));
		threads.push_back(std::move(t));
        }

	for(int i = 0; i<n; i++)
        {
               threads.at(i).join();

        }


}
