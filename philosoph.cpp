#include "philosoph.h"

static char Philosoph::check = 0;

Philosoph::Philosoph(int n,std::vector<Fork> forks)
{
	percent = 0;
	this->number = n;

	this->right = forks.at((n+1) % forks.size());
	this->left = forks.at(n);

}

void Philosoph::live(Wiz &wiz)
{
	

	while(Philosoph::check != 'q')
	{
	think(wiz);

	if(left.id < right.id)
	{
		left.mtx->lock();
		right.mtx->lock();
	}
	else
	{
		right.mtx->lock();
		left.mtx->lock();
	}

	eat(wiz); 

	if(left.id < right.id) 
	{
		right.mtx->unlock();
                left.mtx->unlock();
	}
	else
	{
		left.mtx->unlock();
                right.mtx->unlock();
	}

	}
}

void Philosoph::eat(Wiz &wiz)
{
//losowy czas z przedzialu 25, 35
	double t = minTime + (std::rand() % (maxTime - minTime + 1));
	t = t * 100000;

	for(double i = 0; i <= t && Philosoph::check != 'q'; i = i + 250000)
	{
	nodelay(stdscr,TRUE);
	wiz.mtx->lock();
	Philosoph::check = getch();
	wiz.mtx->unlock();
	this->state = "je";
    //procent aktualizacja
	percent = i/t*(double)100;
	wiz.mtx->lock();
	wiz.setState(this->state,percent,number);
	wiz.mtx->unlock();
        usleep(250000);
	}

        return;
}

void Philosoph::think(Wiz &wiz)
{

	double t = minTime + (std::rand() % (maxTime - minTime + 1));
        t = t * 100000;

        this->state = "mysli";
        for(double i = 0; i <= t && Philosoph::check != 'q'; i = i + 250000)
        {
	nodelay(stdscr,TRUE);
	wiz.mtx->lock();
	Philosoph::check = getch();
	wiz.mtx->unlock();
    //procent aktualizacja
        percent = (i/t*(double)100);
	wiz.mtx->lock();
        wiz.setState(this->state,percent,number);
	wiz.mtx->unlock();
        usleep(250000);
        }
	this->state = "czeka";
	wiz.mtx->lock();
	wiz.setState(this->state,100.0,number);
	wiz.mtx->unlock();
	return;
}

