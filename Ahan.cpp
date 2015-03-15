// Ahan.cpp: implementation of the Ahan class.
//
//////////////////////////////////////////////////////////////////////

#include "Ahan.h"
#include "define.h"
#include <iostream>
using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Ahan::Ahan(Resource *r)
{
	level = 1;
	resource = r;
	mojoodi = 0;
	remain = 0;
	lasttime = time(0);
}

Ahan::~Ahan()
{

}

void Ahan::show()
{
	cout << endl << "Available Iron : " << resource->ahan_() << endl << "Iron production : " << resource->getPahan() << endl << "Iron on LEVEL (" << level << ")"; 
}

void Ahan::run(time_t t)			//payan upgrade ra check mikonad
{

	if( remain > 0 )
	{
		if( remain > (float) (t-lasttime)*(100/resource->cons_()) )
		{
			remain -= (float) (t-lasttime)*(100/resource->cons_());
		}
		else if(remain <= (float) (t-lasttime)*(100/resource->cons_()))
		{
			level++;
			remain = 0;
		}

	}

	switch(level)				//in switch mojodi ahan ra ba gozasht zaman mohasebe mikonad.
	{
	case 1:
		mojoodi += (float) ( 30 * ( t - lasttime ) / 60 );
		resource->setPahan(30);
		break;
	case 2:
		mojoodi += (float) ( 35 * ( t - lasttime ) / 60 );
		resource->setPahan(35);
		break;
	case 3:
		mojoodi += (float) ( 41 * ( t - lasttime ) / 60 );
		resource->setPahan(41);
		break;
	case 4:
		mojoodi += (float) ( 47 * ( t - lasttime ) / 60 );
		resource->setPahan(47);
		break;
	case 5:
		mojoodi += (float) ( 55 * ( t - lasttime ) / 60 );
		resource->setPahan(55);
		break;
	case 6:
		mojoodi += (float) ( 64 * ( t - lasttime ) / 60 );
		resource->setPahan(64);
		break;
	case 7:
		mojoodi += (float) ( 74 * ( t - lasttime ) / 60 );
		resource->setPahan(74);
		break;
	case 8:
		mojoodi += (float) ( 86 * ( t - lasttime ) / 60 );
		resource->setPahan(86);
		break;
	case 9:
		mojoodi += (float) ( 100 * ( t - lasttime ) / 60 );
		resource->setPahan(100);
		break;
	case 10:
		mojoodi += (float) ( 117 * ( t - lasttime ) / 60 );
		resource->setPahan(117);
		break;
	case 11:
		mojoodi += (float) ( 136 * ( t - lasttime ) / 60 );
		resource->setPahan(136);
		break;
	case 12:
		mojoodi += (float) ( 158 * ( t - lasttime ) / 60 );
		resource->setPahan(158);
		break;
	case 13:
		mojoodi += (float) ( 184 * ( t - lasttime ) / 60 );
		resource->setPahan(184);
		break;
	case 14:
		mojoodi += (float) ( 214 * ( t - lasttime ) / 60 );
		resource->setPahan(214);
		break;
	case 15:
		mojoodi += (float) ( 249 * ( t - lasttime ) / 60 );
		resource->setPahan(249);
		break;
	case 16:
		mojoodi += (float) ( 189 * ( t - lasttime ) / 60 );
		resource->setPahan(189);
		break;
	case 17:
		mojoodi += (float) ( 337 * ( t - lasttime ) / 60 );
		resource->setPahan(337);
		break;
	case 18:
		mojoodi += (float) ( 391 * ( t - lasttime ) / 60 );
		resource->setPahan(391);
		break;
	case 19:
		mojoodi += (float) ( 455 * ( t - lasttime ) / 60 );
		resource->setPahan(455);
		break;
	case 20:
		mojoodi += (float) ( 530 * ( t - lasttime ) / 60 );
		resource->setPahan(530);
		break;
	case 21:
		mojoodi += (float) ( 616 * ( t - lasttime ) / 60 );
		resource->setPahan(616);
		break;
	case 22:
		mojoodi += (float) ( 717 * ( t - lasttime ) / 60 );
		resource->setPahan(717);
		break;
	case 23:
		mojoodi += (float) ( 833 * ( t - lasttime ) / 60 );
		resource->setPahan(833);
		break;
	case 24:
		mojoodi += (float) ( 969 * ( t - lasttime ) / 60 );
		resource->setPahan(969);
		break;
	case 25:
		mojoodi += (float) ( 1127 * ( t - lasttime ) / 60 );
		resource->setPahan(1127);
		break;
	case 26:
		mojoodi += (float) ( 1311 * ( t - lasttime ) / 60 );
		resource->setPahan(1311);
		break;
	case 27:
		mojoodi += (float) ( 1525 * ( t - lasttime ) / 60 );
		resource->setPahan(1525);
		break;
	case 28:
		mojoodi += (float) ( 1774 * ( t - lasttime ) / 60 );
		resource->setPahan(1774);
		break;
	case 29:
		mojoodi += (float) ( 2063 * ( t - lasttime ) / 60 );
		resource->setPahan(2063);
		break;
	case 30:
		mojoodi += (float) ( 2400 * ( t - lasttime ) / 60 );
		resource->setPahan(2400);
		break;
	}
	resource->add_ahan( (int)mojoodi);
	mojoodi -= (int) mojoodi;
	lasttime = t;
}


void Ahan::updateLevel(){					
	int ajor, ahan, choob, farm;
		ajor = resource->ajor_();
	ahan = resource->ahan_();
	choob = resource->choob_();
	farm = resource->farm_();
	if( remain == 0)				//check mikonad ke resource kafi baraye upgrade kardan vojod darad va resource estefade shode ra kam mikonad
	{
		if( level == 1 && choob >= 94 && ajor >= 83 && ahan >= 87 && farm >= 2 )   
		{
			resource->kam_ahan(94);
			resource->kam_ajor(83);
			resource->kam_choob(87);
			resource->kam_farm(2);
			remain = wait_time;
		}
		else if( level == 2 && choob >= 118 && ajor >= 106 && ahan >= 108 && farm >= 2 )
		{
			resource->kam_ahan(118);
			resource->kam_ajor(106);
			resource->kam_choob(108);
			resource->kam_farm(2);
			remain = wait_time;
		}
		else if( level == 3 && choob >=147  && ajor >=135  && ahan >=133  && farm >= 2 )
		{
			resource->kam_ahan(147);
			resource->kam_ajor(135);
			resource->kam_choob(133);
			resource->kam_farm(2);
			remain = wait_time;
		}
		else if( level == 4 && choob >=184  && ajor >= 172 && ahan >=165  && farm >= 3 )
		{
			resource->kam_ahan(184);
			resource->kam_ajor(172);
			resource->kam_choob(165);
			resource->kam_farm(3);
			remain = wait_time;
		}
		else if( level == 5 && choob >=231  && ajor >= 219 && ahan >= 205 && farm >= 3 )
		{
			resource->kam_ahan(231);
			resource->kam_ajor(219);
			resource->kam_choob(205);
			resource->kam_farm(3);
			remain = wait_time;
		}
		else if( level == 6 && choob >=289  && ajor >=279  && ahan >=254  && farm >=4  )
		{
			resource->kam_ahan(289);
			resource->kam_ajor(279);
			resource->kam_choob(254);
			resource->kam_farm(4);
			remain = wait_time;
		}
		else if( level == 7 && choob >=362  && ajor >=356  && ahan >=316  && farm >=4  )
		{
			resource->kam_ahan(362);
			resource->kam_ajor(356);
			resource->kam_choob(316);
			resource->kam_farm(4);
			remain = wait_time;
		}
		else if( level == 8 && choob >=453  && ajor >=454  && ahan >=391  && farm >=5  )
		{
			resource->kam_ahan(453);
			resource->kam_ajor(454);
			resource->kam_choob(391);
			resource->kam_farm(5);
			remain = wait_time;
		}
		else if( level == 9 && choob >=567  && ajor >=579  && ahan >=485  && farm >=6  )
		{
			resource->kam_ahan(567);
			resource->kam_ajor(579);
			resource->kam_choob(485);
			resource->kam_farm(6);
			remain = wait_time;
		}
		else if( level == 10 && choob >=710  && ajor >=738  && ahan >=602  && farm >=7 )
		{
			resource->kam_ahan(710);
			resource->kam_ajor(738);
			resource->kam_choob(602);
			resource->kam_farm(7);
			remain = wait_time;
		}
		else if( level == 11 && choob >=889  && ajor >=941  && ahan >=746  && farm >=8  )
		{
			resource->kam_ahan(889);
			resource->kam_ajor(941);
			resource->kam_choob(746);
			resource->kam_farm(8);
			remain = wait_time;
		}
		else if( level == 12 && choob >=1113  && ajor >=1200  && ahan >=925  && farm >=10  )
		{
			resource->kam_ahan(1113);
			resource->kam_ajor(1200);
			resource->kam_choob(925);
			resource->kam_farm(10);
			remain = wait_time;
		}
		else if( level == 13 && choob >=1393  && ajor >=1529  && ahan >=1147  && farm >=11  )
		{
			resource->kam_ahan(1393);
			resource->kam_ajor(1529);
			resource->kam_choob(1147);
			resource->kam_farm(11);
			remain = wait_time;
		}
		else if( level == 14 && choob >=1744  && ajor >=1950  && ahan >=1422  && farm >=13  )
		{
			resource->kam_ahan(1744);
			resource->kam_ajor(1950);
			resource->kam_choob(1422);
			resource->kam_farm(13);
			remain = wait_time;
		}
		else if( level == 15 && choob >=2183  && ajor >=2486  && ahan >=1764  && farm >=15  )
		{
			resource->kam_ahan(2183);
			resource->kam_ajor(2486);
			resource->kam_choob(1764);
			resource->kam_farm(15);
			remain = wait_time;
		}
		else if( level == 16 && choob >=2734  && ajor >=3170  && ahan >=2187  && farm >=18  )
		{
			resource->kam_ahan(2734);
			resource->kam_ajor(3170);
			resource->kam_choob(2187);
			resource->kam_farm(18);
			remain = wait_time;
		}
		else if( level == 17 && choob >=3422  && ajor >=4042  && ahan >=2712  && farm >=21  )
		{
			resource->kam_ahan(3422);
			resource->kam_ajor(4042);
			resource->kam_choob(2712);
			resource->kam_farm(21);
			remain = wait_time;
		}
		else if( level == 18 && choob >=4285  && ajor >=5153  && ahan >=3363  && farm >=25  )
		{
			resource->kam_ahan(4285);
			resource->kam_ajor(5153);
			resource->kam_choob(3363);
			resource->kam_farm(25);
			remain = wait_time;
		}
		else if( level == 19 && choob >=5365  && ajor >=6571  && ahan >=4170  && farm >=28  )
		{
			resource->kam_ahan(5365);
			resource->kam_ajor(6571);
			resource->kam_choob(4170);
			resource->kam_farm(28);
			remain = wait_time;
		}
		else if( level == 20 && choob >=6717  && ajor >=8378  && ahan >=5170  && farm >=34  )
		{
			resource->kam_ahan(6717);
			resource->kam_ajor(8378);
			resource->kam_choob(5170);
			resource->kam_farm(34);
			remain = wait_time;
		}
		else if( level == 21 && choob >=8409  && ajor >=10681  && ahan >=6411  && farm >=39  )
		{
			resource->kam_ahan(8409);
			resource->kam_ajor(10681);
			resource->kam_choob(6411);
			resource->kam_farm(39);
			remain = wait_time;
		}
		else if( level == 22 && choob >=10528  && ajor >=13619  && ahan >=7950  && farm >=46  )
		{
			resource->kam_ahan(10528);
			resource->kam_ajor(13619);
			resource->kam_choob(7950);
			resource->kam_farm(46);
			remain = wait_time;
		}
		else if( level == 23 && choob >=13181  && ajor >=17364  && ahan >=9858  && farm >=54  )
		{
			resource->kam_ahan(13181);
			resource->kam_ajor(17364);
			resource->kam_choob(9858);
			resource->kam_farm(54);
			remain = wait_time;
		}
		else if( level == 24 && choob >=16503  && ajor >=22139  && ahan >=12224  && farm >=63  )
		{
			resource->kam_ahan(16503);
			resource->kam_ajor(22139);
			resource->kam_choob(12224);
			resource->kam_farm(63);
			remain = wait_time;
		}
		else if( level == 25 && choob >=20662  && ajor >=28227  && ahan >=15158  && farm >=74  )
		{	
			resource->kam_ahan(20662);
			resource->kam_ajor(28227);
			resource->kam_choob(15158);
			resource->kam_farm(74);
			remain = wait_time;
		}
		else if( level == 26 && choob >=25869  && ajor >=35990  && ahan >=18796  && farm >=86  )
		{
			resource->kam_ahan(25869);
			resource->kam_ajor(35990);
			resource->kam_choob(18796);
			resource->kam_farm(86);
			remain = wait_time;
		}
		else if( level == 27 && choob >=32388  && ajor >=45887  && ahan >=23307  && farm >=100  )
		{
			resource->kam_ahan(32388);
			resource->kam_ajor(45887);
			resource->kam_choob(23307);
			resource->kam_farm(100);
			remain = wait_time;
		}
		else if( level == 28 && choob >=40549  && ajor >=58506  && ahan >=28900  && farm >=118  )
		{
			resource->kam_ahan(40549);
			resource->kam_ajor(58506);
			resource->kam_choob(28900);
			resource->kam_farm(118);
			remain = wait_time;
		}
		else if( level == 29 && choob >= 50768 && ajor >= 74595 && ahan >= 35837 && farm >= 138 )
		{
			resource->kam_ahan(50768);
			resource->kam_ajor(74595);
			resource->kam_choob(35837);
			resource->kam_farm(138);
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
