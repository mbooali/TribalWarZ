// Ajor.cpp: implementation of the Ajor class.
//
//////////////////////////////////////////////////////////////////////

#include "Ajor.h"
#include <iostream>
#include "define.h"
using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Ajor::Ajor(Resource *r)
{
	level = 1;
	resource = r;
	remain = 0;
	lasttime = time(0);
	mojoodi = 0;
}

Ajor::~Ajor()
{
	
}

void Ajor::show()
{
	cout << endl << "Available Clay : " << resource->ajor_() << endl << "Clay production : " << resource->getPajor() << endl << "Timber on LEVEL (" << level << ")"; 
}

void Ajor::run(time_t t)				//payan zaman upgrade ra check mikonad
{
	if( remain > 0 )
	{
		if( remain > (t-lasttime)*(100/resource->cons_()) )
		{
			remain -= (t-lasttime)*(100/resource->cons_());
		}
		else if(remain <= (t-lasttime)*(100/resource->cons_()))
		{
			level++;
			remain = 0;
		}
	}
	
	switch(level)					//in switch mojodi ajor ra ba gozasht zaman mohasebe mikonad
	{
	case 1:
		mojoodi += (float) ( 30 * ( t - lasttime ) / 60 );
		resource->setPajor(30);
		break;
	case 2:
		mojoodi += (float) ( 35 * ( t - lasttime ) / 60 );
		resource->setPajor(35);
		break;
	case 3:
		mojoodi += (float) ( 41 * ( t - lasttime ) / 60 );
		resource->setPajor(41);
		break;
	case 4:
		mojoodi += (float) ( 47 * ( t - lasttime ) / 60 );
		resource->setPajor(47);
		break;
	case 5:
		mojoodi += (float) ( 55 * ( t - lasttime ) / 60 );
		resource->setPajor(55);
		break;
	case 6:
		mojoodi += (float) ( 64 * ( t - lasttime ) / 60 );
		resource->setPajor(64);
		break;
	case 7:
		mojoodi += (float) ( 74 * ( t - lasttime ) / 60 );
		resource->setPajor(74);
		break;
	case 8:
		mojoodi += (float) ( 86 * ( t - lasttime ) / 60 );
		resource->setPajor(86);
		break;
	case 9:
		mojoodi += (float) ( 100 * ( t - lasttime ) / 60 );
		resource->setPajor(100);
		break;
	case 10:
		mojoodi += (float) ( 117 * ( t - lasttime ) / 60 );
		resource->setPajor(117);
		break;
	case 11:
		mojoodi += (float) ( 136 * ( t - lasttime ) / 60 );
		resource->setPajor(136);
		break;
	case 12:
		mojoodi += (float) ( 158 * ( t - lasttime ) / 60 );
		resource->setPajor(158);
		break;
	case 13:
		mojoodi += (float) ( 184 * ( t - lasttime ) / 60 );
		resource->setPajor(184);
		break;
	case 14:
		mojoodi += (float) ( 214 * ( t - lasttime ) / 60 );
		resource->setPajor(214);
		break;
	case 15:
		mojoodi += (float) ( 249 * ( t - lasttime ) / 60 );
		resource->setPajor(249);
		break;
	case 16:
		mojoodi += (float) ( 189 * ( t - lasttime ) / 60 );
		resource->setPajor(189);
		break;
	case 17:
		mojoodi += (float) ( 337 * ( t - lasttime ) / 60 );
		resource->setPajor(337);
		break;
	case 18:
		mojoodi += (float) ( 391 * ( t - lasttime ) / 60 );
		resource->setPajor(391);
		break;
	case 19:
		mojoodi += (float) ( 455 * ( t - lasttime ) / 60 );
		resource->setPajor(455);
		break;
	case 20:
		mojoodi += (float) ( 530 * ( t - lasttime ) / 60 );
		resource->setPajor(530);
		break;
	case 21:
		mojoodi += (float) ( 616 * ( t - lasttime ) / 60 );
		resource->setPajor(616);
		break;
	case 22:
		mojoodi += (float) ( 717 * ( t - lasttime ) / 60 );
		resource->setPajor(717);
		break;
	case 23:
		mojoodi += (float) ( 833 * ( t - lasttime ) / 60 );
		resource->setPajor(833);
		break;
	case 24:
		mojoodi += (float) ( 969 * ( t - lasttime ) / 60 );
		resource->setPajor(969);
		break;
	case 25:
		mojoodi += (float) ( 1127 * ( t - lasttime ) / 60 );
		resource->setPajor(1127);
		break;
	case 26:
		mojoodi += (float) ( 1311 * ( t - lasttime ) / 60 );
		resource->setPajor(1311);
		break;
	case 27:
		mojoodi += (float) ( 1525 * ( t - lasttime ) / 60 );
		resource->setPajor(1525);
		break;
	case 28:
		mojoodi += (float) ( 1774 * ( t - lasttime ) / 60 );
		resource->setPajor(1774);
		break;
	case 29:
		mojoodi += (float) ( 2063 * ( t - lasttime ) / 60 );
		resource->setPajor(2063);
		break;
	case 30:
		mojoodi += (float) ( 2400 * ( t - lasttime ) / 60 );
		resource->setPajor(2400);
		break;
	}
		
	resource->add_ajor( (int)mojoodi );
	mojoodi -= (int) mojoodi;
	lasttime = t;
}

void Ajor::updateLevel(){
	int ajor, ahan, choob, farm;
	
	ajor = resource->ajor_();
	ahan = resource->ahan_();
	choob = resource->choob_();
	farm = resource->farm_();
	
	if( remain == 0)						//check mikonad zaman upgrade level ghabl tamam shode bashad
	{
		if( level == 1 && choob >= 83 && ajor >= 63 && ahan >= 50 && farm >= 1 )		//check mikonad ke baraye har upgrade resource kafi mojod bashad va resource estefade shode ra kam mikonad
		{
			
			resource->kam_ahan(83);
			resource->kam_ajor(63);
			resource->kam_choob(50);
			resource->kam_farm(1);
			remain = wait_time;
		}
		else if( level == 2 && choob >= 105 && ajor >= 80 && ahan >= 62 && farm >= 2 )
		{
			
			resource->kam_ahan(105);
			resource->kam_ajor(80);
			resource->kam_choob(62);
			resource->kam_farm(2);
			remain = wait_time;
		}
		else if( level == 3 && choob >= 133 && ajor >= 101 && ahan >= 76 && farm >= 2 )
		{
			
			resource->kam_ahan(133);
			resource->kam_ajor(101);
			resource->kam_choob(76);
			resource->kam_farm(2);
			remain = wait_time;
		}
		else if( level == 4 && choob >= 169 && ajor >= 215 && ahan >= 117 && farm >= 2 )
		{
			
			resource->kam_ahan(169);
			resource->kam_ajor(215);
			resource->kam_choob(117);
			resource->kam_farm(2);
			remain = wait_time;
		}
		else if( level == 5 && choob >= 215 && ajor >= 162 && ahan >= 117 && farm >= 2 )
		{
			
			resource->kam_ahan(215);
			resource->kam_ajor(162);
			resource->kam_choob(117);
			resource->kam_farm(2);
			remain = wait_time;
		}
		else if( level == 6 && choob >= 273 && ajor >= 205 && ahan >= 145 && farm >= 3 )
		{
			
			resource->kam_ahan(273);
			resource->kam_ajor(205);
			resource->kam_choob(145);
			resource->kam_farm(3);
			remain = wait_time;
		}
		else if( level == 7 && choob >= 346 && ajor >= 259 && ahan >= 180 && farm >= 3 )
		{
			
			resource->kam_ahan(346);
			resource->kam_ajor(259);
			resource->kam_choob(180);
			resource->kam_farm(3);
			remain = wait_time;
		}
		else if( level == 8 && choob >= 440 && ajor >= 328 && ahan >= 224 && farm >= 4 )
		{
			
			resource->kam_ahan(440);
			resource->kam_ajor(328);
			resource->kam_choob(224);
			resource->kam_farm(4);
			remain = wait_time;
		}
		else if( level == 9 && choob >= 559 && ajor >= 415 && ahan >= 277 && farm >= 4 )
		{
			
			resource->kam_ahan(559);
			resource->kam_ajor(415);
			resource->kam_choob(277);
			resource->kam_farm(4);
			remain = wait_time;
		}
		else if( level == 10 && choob >= 709 && ajor >= 525 && ahan >= 344 && farm >= 4 )
		{
			
			resource->kam_ahan(709);
			resource->kam_ajor(5525);
			resource->kam_choob(344);
			resource->kam_farm(4);
			remain = wait_time;
		}
		else if( level == 11 && choob >=901  && ajor >=664  && ahan >=426  && farm >= 5 )
		{
			
			resource->kam_ahan(901);
			resource->kam_ajor(664);
			resource->kam_choob(426);
			resource->kam_farm(5);
			remain = wait_time;
		}
		else if( level == 12 && choob >=1144  && ajor >=840  && ahan >= 529 && farm >= 6 )
		{
			
			resource->kam_ahan(1144);
			resource->kam_ajor(840);
			resource->kam_choob(529);
			resource->kam_farm(6);
			remain = wait_time;
		}
		else if( level == 13 && choob >=1453  && ajor >=1062  && ahan >=655  && farm >= 7 )
		{
			
			resource->kam_ahan(1453);
			resource->kam_ajor(1062);
			resource->kam_choob(655);
			resource->kam_farm(7);
			remain = wait_time;
		}
		else if( level == 14 && choob >=1846  && ajor >=1343  && ahan >=813  && farm >= 8 )
		{
			
			resource->kam_ahan(1846);
			resource->kam_ajor(1343);
			resource->kam_choob(813);
			resource->kam_farm(8);
			remain = wait_time;
		}
		else if( level == 15 && choob >=2344  && ajor >=1700  && ahan >=1008  && farm >= 8 )
		{
			
			resource->kam_ahan(2344);
			resource->kam_ajor(1700);
			resource->kam_choob(1008);
			resource->kam_farm(8);
			remain = wait_time;
		}
		else if( level == 16 && choob >=2977  && ajor >=2150  && ahan >=1250  && farm >=10  )
		{
			
			resource->kam_ahan(2977);
			resource->kam_ajor(2150);
			resource->kam_choob(1250);
			resource->kam_farm(10);
			remain = wait_time;
		}
		else if( level == 17 && choob >=3781  && ajor >=2720  && ahan >=1550  && farm >=12  )
		{
			
			resource->kam_ahan(3781);
			resource->kam_ajor(2720);
			resource->kam_choob(1550);
			resource->kam_farm(12);
			remain = wait_time;
		}
		else if( level == 18 && choob >=4802  && ajor >=3440  && ahan >=1922  && farm >=13  )
		{
			
			resource->kam_ahan(4802);
			resource->kam_ajor(3440);
			resource->kam_choob(1922);
			resource->kam_farm(13);
			remain = wait_time;
		}
		else if( level == 19 && choob >=6098  && ajor >=4352  && ahan >=2383  && farm >= 15 )
		{
			
			resource->kam_ahan(6098);
			resource->kam_ajor(4352);
			resource->kam_choob(2383);
			resource->kam_farm(15);
			remain = wait_time;
		}
		else if( level == 20 && choob >=7744  && ajor >=5505  && ahan >=2955  && farm >=16  )
		{
			
			resource->kam_ahan(7744);
			resource->kam_ajor(5505);
			resource->kam_choob(2955);
			resource->kam_farm(16);
			remain = wait_time;
		}
		else if( level == 21 && choob >=9835  && ajor >=6964  && ahan >=3664  && farm >=20  )
		{
			
			resource->kam_ahan(9835);
			resource->kam_ajor(6964);
			resource->kam_choob(3664);
			resource->kam_farm(20);
			remain = wait_time;
		}
		else if( level == 22 && choob >=12491  && ajor >=8810  && ahan >=4543  && farm >=22  )
		{
			
			resource->kam_ahan(12491);
			resource->kam_ajor(8810);
			resource->kam_choob(4543);
			resource->kam_farm(22);
			remain = wait_time;
		}
		else if( level == 23 && choob >=15863  && ajor >=11144  && ahan >=5633  && farm >=25  )
		{
			
			resource->kam_ahan(15863);
			resource->kam_ajor(11144);
			resource->kam_choob(5633);
			resource->kam_farm(25);
			remain = wait_time;
		}
		else if( level == 24 && choob >=20147  && ajor >=14098  && ahan >=6985  && farm >=28  )
		{
			
			resource->kam_ahan(20147);
			resource->kam_ajor(14098);
			resource->kam_choob(6985);
			resource->kam_farm(28);
			remain = wait_time;
		}
		else if( level == 25 && choob >=25586  && ajor >=17833  && ahan >=8662  && farm >=33  )
		{
			
			resource->kam_ahan(25586);
			resource->kam_ajor(17833);
			resource->kam_choob(8662);
			resource->kam_farm(33);
			remain = wait_time;
		}
		else if( level == 26 && choob >=32495  && ajor >=22559  && ahan >=10740  && farm >=37  )
		{
			
			resource->kam_ahan(32495);
			resource->kam_ajor(22559);
			resource->kam_choob(10740);
			resource->kam_farm(37);
			remain = wait_time;
		}
		else if( level == 27 && choob >=41268  && ajor >=28537  && ahan >=13318  && farm >=42  )
		{
			
			resource->kam_ahan(41268);
			resource->kam_ajor(28537);
			resource->kam_choob(13318);
			resource->kam_farm(42);
			remain = wait_time;
		}
		else if( level == 28 && choob >=52410  && ajor >=36100  && ahan >=16515  && farm >=48  )
		{
			
			resource->kam_ahan(52410);
			resource->kam_ajor(36100);
			resource->kam_choob(16515);
			resource->kam_farm(48);
			remain = wait_time;
		}
		else if( level == 29 && choob >=66561  && ajor >=45666  && ahan >=20478  && farm >=55  )
		{
			
			resource->kam_ahan(66561);
			resource->kam_ajor(45666);
			resource->kam_choob(20478);
			resource->kam_farm(55);
			remain = wait_time;
		}
		else
		{
			cout << "\ntoo few resources...\n";
		}
	}
	else
	{
		cout << "\nworkers at work...\n";
	}
}


