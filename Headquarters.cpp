// Headquarters.cpp: implementation of the Headquarters class.
//
//////////////////////////////////////////////////////////////////////

#include "Headquarters.h"
#include "define.h"
#include <iostream>
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Headquarters::Headquarters(Resource *r)
{
	resource = r;
	ahan = new Ahan(r);
	barracks = new Barracks(r);
	timber = new Timber(r);
	ajor = new Ajor(r);
	farm = new Farm(r);
	warehouse = new Warehouse(r);
	
	level = 1;
	remain = 0;
	lasttime = time(0);
}

Headquarters::~Headquarters()
{
	
}

void Headquarters::builder_()					//baraye sakhtan barracks
{
	if(barracks->getLevel() == 0 && barracks->getRemain() == 0 && level >= 3 && resource->ahan_() >= 90 && resource->choob_() >= 200 && resource->ajor_() >= 170 && resource->farm_() >= 7)
	{
		resource->kam_ahan(90);
		resource->kam_ajor(170);
		resource->kam_choob(200);
		resource->kam_farm(7);
		barracks->setRemain(wait_time);
		cout << "construction of Barracks has been started " << endl;
	}
	else if(barracks->getLevel() != 0 || barracks->getRemain() != 0)
	{
		cout << "\nyou Can build the Barraks 1 time only!!!\n";
	}
	else if(level < 3)
	{
		cout << "\nBarracks need headQuarter level 3 or higher\n";
	}
	else if(resource->ahan_() >= 90 && resource->choob_() >= 200 && resource->ajor_() >= 170 && resource->farm_() >= 7)
	{
		cout << "\nToo few resource...\n";
	}
	return;
}

void Headquarters::barracks_()				//UI in barracks			
{
	char command = 'X';
	int num;
	barracks->show();

	while(command != 'q')
	{
		cout << "\nLevelUp=l\tBuildForce=f\tSHowInfo=s\tQuit=q\ncommand line : ";
		cin >> command;
		if(command == 'l')
		{
			barracks->updateLevel();
		}
		else if(command == 'f')
		{
			cout << "\n how many soldiers :  ";
			cin >> num;
			for(int i = 0; i < num; i++)
				barracks->add_sol();
		}
		else if(command == 's')
		{
			barracks->show();
		}
	}
}

void Headquarters::timber_()			//UI in timber
{
	char command = 'X';
	timber->show();
	
	while(command != 'q')
	{
		cout << "\nLevelUp=l\tSHowInfo=s\tQuit=q\ncommand line : ";
		cin >> command;
		if(command == 'l')
		{
			timber->updateLevel();
		}
		else if(command == 's')
		{
			timber->show();
		}
	}
}

void Headquarters::clay_()				//UI in clay
{
	char command = 'X';
	ajor->show();
	
	while(command != 'q')
	{
		cout << "\nLevelUp=l\tSHowInfo=s\tQuit=q\ncommand line : ";
		cin >> command;
		if(command == 'l')
		{
			ajor->updateLevel();
		}
		else if(command == 's')
		{
			ajor->show();
		}
	}
}
void Headquarters::iron_()			//UI in iron
{
	char command = 'X';
	ahan->show();
	
	while(command != 'q')
	{
		cout << "\nLevelUp=l\tSHowInfo=s\tQuit=q\ncommand line : ";
		cin >> command;
		if(command == 'l')
		{
			ahan->updateLevel();
		}
		else if(command == 's')
		{
			ahan->show();
		}
	}
}
void Headquarters::farm_()			//UI in farm
{
	char command = 'X';
	farm->show();
	
	while(command != 'q')
	{
		cout << "\nLevelUp=l\tSHowInfo=s\tQuit=q\ncommand line : ";
		cin >> command;
		if(command == 'l')
		{
			farm->updateLevel();
		}
		else if(command == 's')
		{
			farm->show();
		}
	}
}
void Headquarters::warehouse_()					//UI in ware house
{
	char command = 'X';
	warehouse->show();
	
	while(command != 'q')
	{
		cout << "\nLevelUp=l\tSHowInfo=s\tQuit=q\ncommand line : ";
		cin >> command;
		if(command == 'l')
		{
			warehouse->updateLevel();
		}
		else if(command == 's')
		{
			warehouse->show();
		}
	}
}

Ajor* Headquarters::getAjor()
{
	return ajor;
}
Ahan* Headquarters::getAhan()
{
	return ahan;
}
Farm* Headquarters::getFarm()
{
	return farm;
}
Warehouse* Headquarters::getWarehouse()
{
	return warehouse;
}
Barracks* Headquarters::getBarracks()
{
	return barracks;
}
Timber* Headquarters::getTimber()
{
	return timber;
}


void Headquarters::run(time_t t)			//payane zamane upgrade ra mohasebe mikonad
{
	if( remain > 0 )
	{
		if( remain > (t-lasttime)*(100/resource->cons_()) )
		{
			remain -= (t-lasttime)*(100/resource->cons_());
		}
		else if(remain <= (t-lasttime)*(100/resource->cons_()))
		{
			remain = 0;
			switch(level)			//ba tavajoh be level HQ modat zamane upgrade baghie ra moshakhas mikonad
			{
			case 1:
				resource->set_cons(91);
				break;
			case 2:
				resource->set_cons(86);
				break;
			case 3:
				resource->set_cons(82);
				break;
			case 4:
				resource->set_cons(78);
				break;
			case 5:
				resource->set_cons(75);
				break;
			case 6:
				resource->set_cons(71);
				break;
			case 7:
				resource->set_cons(68);
				break;
			case 8:
				resource->set_cons(64);
				break;
			case 9:
				resource->set_cons(61);
				break;
			case 10:
				resource->set_cons(58);
				break;
			case 11:
				resource->set_cons(56);
				break;
			case 12:
				resource->set_cons(53);
				break;
			case 13:
				resource->set_cons(51);
				break;
			case 14:
				resource->set_cons(48);
				break;
			case 15:
				resource->set_cons(46);
				break;
			case 16:
				resource->set_cons(44);
				break;
			case 17:
				resource->set_cons(42);
				break;
			case 18:
				resource->set_cons(40);
				break;
			case 19:
				resource->set_cons(38);
				break;
			case 20:
				resource->set_cons(36);
				break;
			case 21:
				resource->set_cons(34);
				break;
			case 22:
				resource->set_cons(33);
				break;
			case 23:
				resource->set_cons(31);
				break;
			case 24:
				resource->set_cons(30);
				break;
			case 25:
				resource->set_cons(28);
				break;
			case 26:
				resource->set_cons(27);
				break;
			case 27:
				resource->set_cons(26);
				break;
			case 28:
				resource->set_cons(24);
				break;
			case 29:
				resource->set_cons(23);
				break;
			}
			level++;
		}
	}
	lasttime = t;
}


 void Headquarters::updateLevel(){			//check mikonad resource kafi baraye upgrade kardan vojod dashte bashad va resource estfade shode ra kam mikonad
	
	int ajor, ahan, choob, farm;
	
	ajor = resource->ajor_();
	ahan = resource->ahan_();
	choob = resource->choob_();
	farm = resource->farm_();
	
	if(remain==0)
	{
		
		if( level == 1 && choob >= 113 && ajor >= 102 && ahan >= 88 && farm >= 1 )
		{
			//91%
			
			resource->kam_ahan(113);
			resource->kam_ajor(102);
			resource->kam_choob(88);
			resource->kam_farm(1);
			remain = wait_time;
		}
		else if( level == 2 && choob >= 143 && ajor >= 130 && ahan >= 111 && farm >= 1 )
		{
			//86%
			
			resource->kam_ahan(143);
			resource->kam_ajor(130);
			resource->kam_choob(111);
			resource->kam_farm(1);
			remain = wait_time;
		}
		else if( level == 3 && choob >= 180 && ajor >= 166 && ahan >= 140 && farm >= 1 )
		{
			//82%
			
			resource->kam_ahan(180);
			resource->kam_ajor(166);
			resource->kam_choob(140);
			resource->kam_farm(1);
			remain = wait_time;
		}
		else if( level == 4 && choob >= 227 && ajor >= 211 && ahan >= 176 && farm >= 1 )
		{
			//78%
			
			resource->kam_ahan(227);
			resource->kam_ajor(211);
			resource->kam_choob(176);
			resource->kam_farm(1);
			remain = wait_time;
		}
		else if( level == 5 && choob >= 286 && ajor >= 270 && ahan >= 222 && farm >= 2 )
		{
			//75%
			
			resource->kam_ahan(286);
			resource->kam_ajor(270);
			resource->kam_choob(222);
			resource->kam_farm(2);
			remain = wait_time;
		}
		else if( level == 6 && choob >= 360 && ajor >= 344 && ahan >= 280 && farm >= 2 )
		{
			//71%
			
			resource->kam_ahan(360);
			resource->kam_ajor(344);
			resource->kam_choob(280);
			resource->kam_farm(2);
			remain = wait_time;
		}
		else if( level == 7 && choob >= 454 && ajor >= 438 && ahan >= 353 && farm >= 2 )
		{
			//68%
			
			resource->kam_ahan(454);
			resource->kam_ajor(438);
			resource->kam_choob(353);
			resource->kam_farm(2);
			remain = wait_time;
		}
		else if( level == 8 && choob >= 572 && ajor >= 559 && ahan >=445 && farm >= 3 )
		{
			//64%
			
			resource->kam_ahan(572);
			resource->kam_ajor(559);
			resource->kam_choob(445);
			resource->kam_farm(3);
			remain = wait_time;
		}
		else if( level == 9 && choob >= 720 && ajor >= 712 && ahan >= 560 && farm >= 3 )
		{
			//61%
			
			resource->kam_ahan(720);
			resource->kam_ajor(712);
			resource->kam_choob(560);
			resource->kam_farm(3);
			remain = wait_time;
		}
		else if( level == 10 && choob >= 908 && ajor >= 908 && ahan >= 706 && farm >= 3 )
		{
			//58%
			
			resource->kam_ahan(908);
			resource->kam_ajor(908);
			resource->kam_choob(706);
			resource->kam_farm(3);
			remain = wait_time;
		}
		else if( level == 11 && choob >= 1144 && ajor >= 1158 && ahan >= 890 && farm >= 4 )
		{
			//56%
			
			resource->kam_ahan(1144);
			resource->kam_ajor(1158);
			resource->kam_choob(890);
			resource->kam_farm(4);
			remain = wait_time;
		}
		else if( level == 12 && choob >= 1441 && ajor >= 1476 && ahan >= 1121 && farm >= 5 )
		{
			//53%
			
			resource->kam_ahan(1441);
			resource->kam_ajor(1476);
			resource->kam_choob(1121);
			resource->kam_farm(5);
			remain = wait_time;
		}
		else if( level == 13 && choob >= 1816 && ajor >= 1882 && ahan >= 1412 && farm >= 5 )
		{
			//51%
			
			resource->kam_ahan(1816);
			resource->kam_ajor(1882);
			resource->kam_choob(1412);
			resource->kam_farm(5);
			remain = wait_time;
		}
		else if( level == 14 && choob >= 2288 && ajor >= 2400 && ahan >= 1779 && farm >= 7 )
		{
			//48%
			
			resource->kam_ahan(2288);
			resource->kam_ajor(2400);
			resource->kam_choob(1779);
			resource->kam_farm(7);
			remain = wait_time;
		}
		else if( level == 15 && choob >= 2883 && ajor >= 3060 && ahan >= 2242 && farm >= 8 )
		{
			//46%
			
			resource->kam_ahan(2883);
			resource->kam_ajor(3060);
			resource->kam_choob(2242);
			resource->kam_farm(8);
			remain = wait_time;
		}
		else if( level == 16 && choob >= 3632 && ajor >= 3902 && ahan >= 2825 && farm >= 9 )
		{
			//44%
			
			resource->kam_ahan(3632);
			resource->kam_ajor(3902);
			resource->kam_choob(2825);
			resource->kam_farm(9);
			remain = wait_time;
		}
		else if( level == 17 && choob >= 4577 && ajor >= 4975 && ahan >= 3560 && farm >= 10 )
		{
			//42%
			
			resource->kam_ahan(4577);
			resource->kam_ajor(4975);
			resource->kam_choob(3560);
			resource->kam_farm(10);
			remain = wait_time;
			
		}
		else if( level == 18 && choob >= 5767 && ajor >= 6343 && ahan >= 4485 && farm >= 12 )
		{
			//40%
			
			resource->kam_ahan(5767);
			resource->kam_ajor(6343);
			resource->kam_choob(4485);
			resource->kam_farm(12);
			remain = wait_time;
			
		}
		else if( level == 19 && choob >= 7266 && ajor >= 8087 && ahan >= 5651 && farm >= 15 )
		{
			//38%
			
			resource->kam_ahan(7266);
			resource->kam_ajor(8087);
			resource->kam_choob(5651);
			resource->kam_farm(15);
			remain = wait_time;
			
		}
		else if( level == 20 && choob >= 9151 && ajor >= 10311 && ahan >= 7120 && farm >= 17 )
		{
			//36%
			
			resource->kam_ahan(9151);
			resource->kam_ajor(10311);
			resource->kam_choob(7120);
			resource->kam_farm(17);
			remain = wait_time;
			
		}
		else if( level == 21 && choob >= 11535 && ajor >= 13146 && ahan >= 8972 && farm >= 19 )
		{
			//34%
			
			resource->kam_ahan(11535);
			resource->kam_ajor(13146);
			resource->kam_choob(8972);
			resource->kam_farm(19);
			remain = wait_time;
			
		}
		else if( level == 22 && choob >= 14534 && ajor >= 16762 && ahan >= 11304 && farm >= 23 )
		{
			//33%
			
			resource->kam_ahan(14534);
			resource->kam_ajor(16762);
			resource->kam_choob(11304);
			resource->kam_farm(23);
			remain = wait_time;
			
		}
		else if( level == 23 && choob >= 18313 && ajor >= 21371 && ahan >= 14244 && farm >= 27 )
		{
			//31%
			
			resource->kam_ahan(18313);
			resource->kam_ajor(21371);
			resource->kam_choob(14244);
			resource->kam_farm(27);
			remain = wait_time;
			
		}
		else if( level == 24 && choob >= 23075 && ajor >= 27248 && ahan >= 17947 && farm >= 31 )
		{
			//30%
			
			resource->kam_ahan(23075);
			resource->kam_ajor(27248);
			resource->kam_choob(17947);
			resource->kam_farm(31);
			remain = wait_time;
			
		}
		else if( level == 25 && choob >= 29074 && ajor >= 34741 && ahan >= 22613 && farm >= 37 )
		{
			//28%
			
			resource->kam_ahan(29074);
			resource->kam_ajor(34741);
			resource->kam_choob(22613);
			resource->kam_farm(37);
			remain = wait_time;
			
		}
		else if( level == 26 && choob >= 36633 && ajor >= 44295 && ahan >= 28493 && farm >= 43 )
		{
			//27%
			
			resource->kam_ahan(36633);
			resource->kam_ajor(44295);
			resource->kam_choob(28493);
			resource->kam_farm(43);
			remain = wait_time;
			
		}
		else if( level == 27 && choob >= 46158 && ajor >= 56476 && ahan >= 35901 && farm >= 51 )
		{
			//26%
			
			resource->kam_ahan(46158);
			resource->kam_ajor(56476);
			resource->kam_choob(35901);
			resource->kam_farm(51);
			remain = wait_time;
			
		}
		else if( level == 28 && choob >= 58159 && ajor >= 72007 && ahan >= 45235 && farm >= 59 )
		{
			//24%
			
			resource->kam_ahan(58159);
			resource->kam_ajor(72007);
			resource->kam_choob(45235);
			resource->kam_farm(59);
			remain = wait_time;
			
		}
		else if( level == 29 && choob >= 73280 && ajor >= 91809 && ahan >= 56996 && farm >= 69)
		{
			//23%
			
			resource->kam_ahan(73280);
			resource->kam_ajor(91809);
			resource->kam_choob(56996);
			resource->kam_farm(69);
			remain = wait_time;
			
		}
		else
		{
			
			cout << "\ntoo few resource..." <<endl;
		}
	}
	else
	{
		cout << "\nworkers at work...\n";
	}
	
}



