// Timber.cpp: implementation of the Timber class.
//
//////////////////////////////////////////////////////////////////////

#include "Timber.h"
#include "define.h"
#include <iostream>
using namespace std;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Timber::Timber(Resource *r)
{
	level = 1;
	resource = r;
	remain = 0;
	lasttime = time(0);
	mojoodi = 0;
	
}

Timber::~Timber()
{
	
}

void Timber::show()
{
	cout << endl << "Available wood : " << resource->choob_() << endl << "Wood production : " << resource->getPchoob() << endl << "Timber on LEVEL (" << level << ")"; 
}


void Timber::run(time_t t)
{
	if( remain > 0 )			//zaman payan upgare ra mohasebe mikonad
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
	
	switch(level)				//mojodi choob ra ba tavajoh be gozasht zaman mohasebe mikonad
	{
	case 1:
		mojoodi += (float) ( 30 * ( t - lasttime ) / 60 );
		resource->setPchoob(30);
		break;
	case 2:
		mojoodi += (float) ( 35 * ( t - lasttime ) / 60 );
		resource->setPchoob(35);
		break;
	case 3:
		mojoodi += (float) ( 41 * ( t - lasttime ) / 60 );
		resource->setPchoob(41);
		break;
	case 4:
		mojoodi += (float) ( 47 * ( t - lasttime ) / 60 );
		resource->setPchoob(47);
		break;
	case 5:
		mojoodi += (float) ( 55 * ( t - lasttime ) / 60 );
		resource->setPchoob(55);
		break;
	case 6:
		mojoodi += (float) ( 64 * ( t - lasttime ) / 60 );
		resource->setPchoob(64);
		break;
	case 7:
		mojoodi += (float) ( 74 * ( t - lasttime ) / 60 );
		resource->setPchoob(74);
		break;
	case 8:
		mojoodi += (float) ( 86 * ( t - lasttime ) / 60 );
		resource->setPchoob(86);
		break;
	case 9:
		mojoodi += (float) ( 100 * ( t - lasttime ) / 60 );
		resource->setPchoob(100);
		break;
	case 10:
		mojoodi += (float) ( 117 * ( t - lasttime ) / 60 );
		resource->setPchoob(117);
		break;
	case 11:
		mojoodi += (float) ( 136 * ( t - lasttime ) / 60 );
		resource->setPchoob(136);
		break;
	case 12:
		mojoodi += (float) ( 158 * ( t - lasttime ) / 60 );
		resource->setPchoob(158);
		break;
	case 13:
		mojoodi += (float) ( 184 * ( t - lasttime ) / 60 );
		resource->setPchoob(184);
		break;
	case 14:
		mojoodi += (float) ( 214 * ( t - lasttime ) / 60 );
		resource->setPchoob(214);
		break;
	case 15:
		mojoodi += (float) ( 249 * ( t - lasttime ) / 60 );
		resource->setPchoob(249);
		break;
	case 16:
		mojoodi += (float) ( 189 * ( t - lasttime ) / 60 );
		resource->setPchoob(189);
		break;
	case 17:
		mojoodi += (float) ( 337 * ( t - lasttime ) / 60 );
		resource->setPchoob(337);
		break;
	case 18:
		mojoodi += (float) ( 391 * ( t - lasttime ) / 60 );
		resource->setPchoob(391);
		break;
	case 19:
		mojoodi += (float) ( 455 * ( t - lasttime ) / 60 );
		resource->setPchoob(455);
		break;
	case 20:
		mojoodi += (float) ( 530 * ( t - lasttime ) / 60 );
		resource->setPchoob(530);
		break;
	case 21:
		mojoodi += (float) ( 616 * ( t - lasttime ) / 60 );
		resource->setPchoob(616);
		break;
	case 22:
		mojoodi += (float) ( 717 * ( t - lasttime ) / 60 );
		resource->setPchoob(717);
		break;
	case 23:
		mojoodi += (float) ( 833 * ( t - lasttime ) / 60 );
		resource->setPchoob(833);
		break;
	case 24:
		mojoodi += (float) ( 969 * ( t - lasttime ) / 60 );
		resource->setPchoob(969);
		break;
	case 25:
		mojoodi += (float) ( 1127 * ( t - lasttime ) / 60 );
		resource->setPchoob(1127);
		break;
	case 26:
		mojoodi += (float) ( 1311 * ( t - lasttime ) / 60 );
		resource->setPchoob(1311);
		break;
	case 27:
		mojoodi += (float) ( 1525 * ( t - lasttime ) / 60 );
		resource->setPchoob(1525);
		break;
	case 28:
		mojoodi += (float) ( 1774 * ( t - lasttime ) / 60 );
		resource->setPchoob(1774);
		break;
	case 29:
		mojoodi += (float) ( 2063 * ( t - lasttime ) / 60 );
		resource->setPchoob(2063);
		break;
	case 30:
		mojoodi += (float) ( 2400 * ( t - lasttime ) / 60 );
		resource->setPchoob(2400);
		break;
	}
	resource->add_choob( (int)mojoodi );
	mojoodi -= (int) mojoodi;
	lasttime = t;
}



void Timber::updateLevel(){						//check mikonad resource lazem baraye upgrade kardan mojod bashad va resource estefade shode ra kam mikonad
	int ajor, ahan, choob, farm;
	
	ajor = resource->ajor_();
	ahan = resource->ahan_();
	choob = resource->choob_();
	farm = resource->farm_();
	if( remain == 0)
	{
		if( level == 1 && choob >= 63 && ajor >= 77 && ahan >= 50 && farm >= 1 )
		{
			
			resource->kam_ahan(63);
			resource->kam_ajor(77);
			resource->kam_choob(50);
			resource->kam_farm(1);
			remain = wait_time;
		}
		else if( level == 2 && choob >= 78 && ajor >= 98 && ahan >= 62 && farm >= 1 )
		{
			
			resource->kam_ahan(78);
			resource->kam_ajor(98);
			resource->kam_choob(62);
			resource->kam_farm(1);
			remain = wait_time;
		}
		else if( level == 3 && choob >= 98 && ajor >= 124 && ahan >= 77 && farm >= 1 )
		{
			
			resource->kam_ahan(98);
			resource->kam_ajor(124);
			resource->kam_choob(77);
			resource->kam_farm(1);
			remain = wait_time;
		}
		else if( level == 4 && choob >= 122 && ajor >= 159 && ahan >= 96 && farm >= 1 )
		{
			
			resource->kam_ahan(122);
			resource->kam_ajor(159);
			resource->kam_choob(96);
			resource->kam_farm(1);
			remain = wait_time;
		}
		else if( level == 5 && choob >= 153 && ajor >= 202 && ahan >= 120 && farm >= 1 )
		{
			
			resource->kam_ahan(153);
			resource->kam_ajor(202);
			resource->kam_choob(120);
			resource->kam_farm(1);
			remain = wait_time;
		}
		else if( level == 6 && choob >= 191 && ajor >= 258 && ahan >= 149 && farm >= 2 )
		{
			
			resource->kam_ahan(191);
			resource->kam_ajor(258);
			resource->kam_choob(149);
			resource->kam_farm(2);
			remain = wait_time;
		}
		else if( level == 7 && choob >= 238 && ajor >= 329 && ahan >= 185 && farm >= 2 )
		{
			
			resource->kam_ahan(238);
			resource->kam_ajor(329);
			resource->kam_choob(185);
			resource->kam_farm(2);
			remain = wait_time;
		}
		else if( level == 8 && choob >= 298 && ajor >= 419 && ahan >= 231 && farm >= 2 )
		{
			
			resource->kam_ahan(298);
			resource->kam_ajor(419);
			resource->kam_choob(231);
			resource->kam_farm(2);
			remain = wait_time;
		}
		else if( level == 9 && choob >= 373 && ajor >= 534 && ahan >= 287 && farm >= 2 )
		{
			
			resource->kam_ahan(373);
			resource->kam_ajor(534);
			resource->kam_choob(287);
			resource->kam_farm(2);
			remain = wait_time;
		}
		else if( level == 10 && choob >= 466 && ajor >= 681 && ahan >= 358 && farm >= 3 )
		{
			
			resource->kam_ahan(466);
			resource->kam_ajor(681);
			resource->kam_choob(358);
			resource->kam_farm(3);
			remain = wait_time;
		}
		else if( level == 11 && choob >= 582 && ajor >= 868 && ahan >= 446 && farm >= 3 )
		{
			
			resource->kam_ahan(582);
			resource->kam_ajor(868);
			resource->kam_choob(446);
			resource->kam_farm(3);
			remain = wait_time;
		}
		else if( level == 12 && choob >= 728 && ajor >= 1107 && ahan >= 555 && farm >= 4 )
		{
			
			resource->kam_ahan(728);
			resource->kam_ajor(1107);
			resource->kam_choob(555);
			resource->kam_farm(4);
			remain = wait_time;
		}
		else if( level == 13 && choob >= 909 && ajor >= 1412 && ahan >= 691 && farm >= 5 )
		{
			
			resource->kam_ahan(909);
			resource->kam_ajor(1412);
			resource->kam_choob(691);
			resource->kam_farm(5);
			remain = wait_time;
		}
		else if( level == 14 && choob >= 1137 && ajor >= 1800 && ahan >= 860 && farm >= 5 )
		{
			
			resource->kam_ahan(1137);
			resource->kam_ajor(1800);
			resource->kam_choob(860);
			resource->kam_farm(5);
			remain = wait_time;
		}
		else if( level == 15 && choob >= 1421 && ajor >= 2295 && ahan >= 1071 && farm >= 5 )
		{
			
			resource->kam_ahan(1421);
			resource->kam_ajor(2295);
			resource->kam_choob(1071);
			resource->kam_farm(5);
			remain = wait_time;
		}
		else if( level == 16 && choob >= 1776 && ajor >= 2926 && ahan >= 1333 && farm >= 7 )
		{
			
			resource->kam_ahan(1776);
			resource->kam_ajor(2926);
			resource->kam_choob(1333);
			resource->kam_farm(7);
			remain = wait_time;
		}
		else if( level == 17 && choob >= 2220 && ajor >= 3731 && ahan >= 1659 && farm >= 8 )
		{
			
			resource->kam_ahan(2220);
			resource->kam_ajor(3731);
			resource->kam_choob(1659);
			resource->kam_farm(8);
			remain = wait_time;
		}
		else if( level == 18 && choob >= 2776 && ajor >= 4757 && ahan >= 2066 && farm >= 9 )
		{
			
			resource->kam_ahan(2776);
			resource->kam_ajor(4757);
			resource->kam_choob(2066);
			resource->kam_farm(9);
			remain = wait_time;
		}
		else if( level == 19 && choob >= 4369 && ajor >= 6065 && ahan >= 2572 && farm >= 10 )
		{
			
			resource->kam_ahan(4369);
			resource->kam_ajor(6065);
			resource->kam_choob(2572);
			resource->kam_farm(10);
			remain = wait_time;
		}
		else if( level == 20 && choob >= 4337 && ajor >= 7733 && ahan >= 3202 && farm >= 12 )
		{
			
			resource->kam_ahan(4337);
			resource->kam_ajor(7733);
			resource->kam_choob(3202);
			resource->kam_farm(12);
			remain = wait_time;
		}
		else if( level == 21 && choob >= 5421 && ajor >= 9860 && ahan >= 3987 && farm >= 14 )
		{
			
			resource->kam_ahan(5421);
			resource->kam_ajor(9860);
			resource->kam_choob(3987);
			resource->kam_farm(14);
			remain = wait_time;
		}
		else if( level == 22 && choob >= 6776 && ajor >=12571  && ahan >= 4963 && farm >= 16 )
		{
			
			resource->kam_ahan(6776);
			resource->kam_ajor(12571);
			resource->kam_choob(4963);
			resource->kam_farm(16);
			remain = wait_time;
		}
		else if( level == 23 && choob >= 8470 && ajor >= 16028 && ahan >= 6180 && farm >= 19 )
		{
			
			resource->kam_ahan(8470);
			resource->kam_ajor(16028);
			resource->kam_choob(6180);
			resource->kam_farm(19);
			remain = wait_time;
		}
		else if( level == 24 && choob >= 10588 && ajor >= 20436 && ahan >= 7694 && farm >= 21 )
		{
			
			resource->kam_ahan(10588);
			resource->kam_ajor(20436);
			resource->kam_choob(7694);
			resource->kam_farm(21);
			remain = wait_time;
		}
		else if( level == 25 && choob >= 13235 && ajor >= 26056 && ahan >= 9578 && farm >= 24 )
		{
			
			resource->kam_ahan(13235);
			resource->kam_ajor(26056);
			resource->kam_choob(9578);
			resource->kam_farm(24);
			remain = wait_time;
		}
		else if( level == 26 && choob >= 16544 && ajor >= 33221 && ahan >= 11025 && farm >= 29 )
		{
			
			resource->kam_ahan(16544);
			resource->kam_ajor(33221);
			resource->kam_choob(11025);
			resource->kam_farm(29);
			remain = wait_time;
		}
		else if( level == 27 && choob >= 20680 && ajor >= 42327 && ahan >= 14847 && farm >= 33 )
		{
			
			resource->kam_ahan(20680);
			resource->kam_ajor(42327);
			resource->kam_choob(14847);
			resource->kam_farm(33);
			remain = wait_time;
		}
		else if( level == 28 && choob >= 25849 && ajor >= 54005 && ahan >= 18484 && farm >= 38 )
		{
			
			resource->kam_ahan(25849);
			resource->kam_ajor(54005);
			resource->kam_choob(18484);
			resource->kam_farm(38);
			remain = wait_time;
		}
		else if( level == 29 && choob >= 32312 && ajor >= 68857 && ahan >= 23013 && farm >= 43 )
		{
			
			resource->kam_ahan(32312);
			resource->kam_ajor(68857);
			resource->kam_choob(23013);
			resource->kam_farm(43);
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

