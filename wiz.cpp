#include "wiz.h"
#include <cmath>

Wiz::Wiz(int n)
{
	mtx = new std::mutex();
	number = n;
	angle = (double)1/(double)number*(double)2*(double)M_PI;
	phiRadA = 18;
	phiRadB = 23;
	tabRadA = 10;
	tabRadB = 15;
	initscr();
	curs_set(FALSE);
	attron(A_BOLD);
	printw("WCISNIJ Q ABY ZAKONCZYC	[* = FILOZOF] [Y = WIDELEC]");

	for(int i = 0; i < n; i++)
	{
		int x = (10)*cos(angle*i + angle/(double)2)+LINES/2;
                int y = (15)*sin(angle*i + angle/(double)2)+COLS/2;
                move(x,y);
                printw("Y");

	}
}

void Wiz::setState(std::string s, double p, int id)
{

start_color();
init_pair(0,COLOR_WHITE, COLOR_BLACK);
init_pair(1, COLOR_YELLOW, COLOR_BLACK);
init_pair(2, COLOR_CYAN, COLOR_BLACK);
init_pair(3, COLOR_BLUE, COLOR_BLACK);
init_pair(4, COLOR_RED, COLOR_BLACK);
init_pair(5,COLOR_MAGENTA, COLOR_BLACK);
init_pair(6, COLOR_GREEN, COLOR_BLACK);

	double a = (double)(id)/(double)number*(double)2*(double)M_PI; //jeden rowny odcinek okregu odpowadajcy filozofowi
	double x = (phiRadA)*cos(a)+LINES/2;	//25
	double y = (phiRadB)*sin(a)+COLS/2;	//15

	move((int)x,(int)y-8); //-8

	int cid = id%6;
	if(cid == 0)
	{
		cid = 6;
	}

	attron(COLOR_PAIR((int)(cid)) | A_STANDOUT);
	std::string sout = "Filozof " + std::to_string(id) +" " + s;
	if(s == "je")
	{
		sout.append("   ");
	}
	printw(sout.c_str());
	move((int)x+1,(int)y-8); //y-8
	int segments = (int)(p/100*15);
	std::string bar;
	for(int i =0; i < segments; i++)
	{
		bar.append("|");
	}
	for(int i = segments; i < 15; i++)
        {
        	bar.append(" ");
        }
	bar.append("]");
	bar.insert(0,"[");
	printw(bar.c_str());

	x = (tabRadA)*cos(a)+LINES/2;
        y = (tabRadB)*sin(a)+COLS/2;
	move(x,y);
	printw("*");	//rysowanie filozofow

//jesli je to koloruje jego kolorem widelce obok
	if(s == "je")
	{
		//koloruj(rysuj) widelce obok
		x = (tabRadA)*cos(a + angle/(double)2)+LINES/2;
        	y = (tabRadB)*sin(a + angle/(double)2)+COLS/2;
		move(x,y);
		printw("Y");

		x = (tabRadA)*cos(a - angle/(double)2)+LINES/2;
                y = (tabRadB)*sin(a - angle/(double)2)+COLS/2;
                move(x,y);
                printw("Y");
	}

	refresh();
}

Wiz::~Wiz()
{
	delete mtx;
	endwin();
}
