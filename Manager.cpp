// Manager.cpp: implementation of the Manager class.
//
//////////////////////////////////////////////////////////////////////

#include "Manager.h"
#include <iostream>
#include "time.h"
#include "define.h"

using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Manager::Manager()		//in class haste barnameeh ra motasel mikonad be main
{
	resource = new Resource();
	headquarters = new Headquarters(resource);
}

Manager::~Manager()
{

}


void Manager::start()
{

	char command = 'X';
	time_t t;

	while(command != 'q')
	{
		cout << "\nHeadQuarter LeveL " << headquarters->getlevel() << endl;
		//system("cls");
		cout << "\nBuild = s\nBarracks = b\nTimber = t\nCLay_Pit = c\nIron = i\nFarm = f\nWareHouse = w\nReFreSH = r\n" << ""<< endl;

		cout << "\nWood per hour : " << resource->getPchoob() << "\t" << "Available : " << resource->choob_();
		cout << "\nIron per hour : " << resource->getPahan() << "\t" << "Available : " << resource->ahan_();
		cout << "\nClay per hour : " << resource->getPajor() << "\t" << "Available : " << resource->ajor_();
		cout << "\n Farm : " << resource->getUsed() << "/" << resource->farm_()+resource->getUsed() << endl;

		cout << "command Line : ";
		cin >> command;
		switch(command)
		{
		case 's':
		//	system("cls");
			headquarters->builder_();
			break;
		case 'b':
		//	system("cls");
			if(headquarters->getBarracks()->getLevel() != 0)
				headquarters->barracks_();
			else
				cout << "please build barracks before enter it...\n";
			break;
		case 't':
		//	system("cls");
			headquarters->timber_();
			break;
		case 'c':
		//	system("cls");
			headquarters->clay_();
			break;
		case 'i':
		//	system("cls");
			headquarters->iron_();
			break;
		case 'f':
		//	system("cls");
			headquarters->farm_();
			break;
		case 'w':
		//	system("cls");
			headquarters->warehouse_();
			break;
		case 'l':
			headquarters->updateLevel();
			break;
		}
		t = time(0);
		
		headquarters->getBarracks()->run(t);
		headquarters->getTimber()->run(t);
		headquarters->getAjor()->run(t);
		headquarters->getAhan()->run(t);
		headquarters->getFarm()->run(t);
		headquarters->getWarehouse()->run(t);
		headquarters->run(t);
	}
}


