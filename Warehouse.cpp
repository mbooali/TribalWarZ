// Warehouse.cpp: implementation of the Warehouse class.
//
//////////////////////////////////////////////////////////////////////

#include "Warehouse.h"
#include "define.h"
#include <iostream>
using namespace std;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Warehouse::Warehouse(Resource* r)
{
	resource = r;
	max = 1000;
	remain = 0;
	level = 1;
	lasttime = time(0);
}

Warehouse::~Warehouse()
{
	
}

void Warehouse::show()
{
	cout << endl << "Available Capacity : " << max << endl << "Timber on LEVEL (" << level << ")"; 
}

void Warehouse::run(time_t t)			//payan zaman upgrade kardan ra mohasebe mikonad
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
			switch(level)			//max hajm Warehouse ra ba tavajoh be level moshakhas mikonad
			{
			case 1:
				max = 1000;
				break;
			case 2:
				max = 1229;
				break;
			case 3:
				max = 1512;
				break;
			case 4:
				max = 1859;
				break;
			case 5:
				max = 2285;
				break;
			case 6:
				max = 2810;
				break;
			case 7:
				max = 3454;
				break;
			case 8:
				max = 4247;
				break;
			case 9:
				max = 5222;
				break;
			case 10:
				max = 6420;
				break;
			case 11:
				max = 7893;
				break;
			case 12:
				max = 9705;
				break;
			case 13:
				max = 11932;
				break;
			case 14:
				max = 14670;
				break;
			case 15:
				max = 18037;
				break;
			case 16:
				max = 22177;
				break;
			case 17:
				max = 27266;
				break;
			case 18:
				max = 33523;
				break;
			case 19:
				max = 41217;
				break;
			case 20:
				max = 50675;
				break;
			case 21:
				max = 62305;
				break;
			case 22:
				max = 76604;
				break;
			case 23:
				max = 94184;
				break;
			case 24:
				max = 115798;
				break;
			case 25:
				max = 142373;
				break;
			case 26:
				max = 175047;
				break;
			case 27:
				max = 215219;
				break;
			case 28:
				max = 264611;
				break;
			case 29:
				max = 325337;
				break;
			case 30:
				max = 400000;
				break;
			}
		}
	}
	
	if( resource->choob_() > max )			//check mikonad mojodi resource az hajm Warehouse bishtar nashavad
		resource->set_choob(max);
	
	if( resource->ahan_() > max )
		resource->set_ahan(max);
	
	if( resource->ajor_() > max )
		resource->set_ajor(max);
}

void Warehouse::updateLevel(){		//check mikonad resource lazem baraye upgrade kardan mojod bashad va resource estefade shode ra kam mikonad
	int ajor, ahan, choob;
	
	ajor = resource->ajor_();
	ahan = resource->ahan_();
	choob = resource->choob_();
	
	if( remain == 0)
	{
		if( level == 1 && choob >= 76 && ajor >= 64 && ahan >= 50 )
		{
			
			resource->kam_ahan(76);
			resource->kam_ajor(64);
			resource->kam_choob(50);
			remain = wait_time;
		}
		else if( level == 2 && choob >= 96 && ajor >= 81 && ahan >= 62 )
		{
			
			resource->kam_ahan(96);
			resource->kam_ajor(81);
			resource->kam_choob(62);
			remain = wait_time;
			
		}
		else if( level == 3 && choob >= 121 && ajor >= 102 && ahan >= 77 )
		{
			
			resource->kam_ahan(121);
			resource->kam_ajor(102);
			resource->kam_choob(77);
			remain = wait_time;
			
		}
		else if( level == 4 && choob >= 154 && ajor >= 130 && ahan >= 96 )
		{
			
			resource->kam_ahan(154);
			resource->kam_ajor(130);
			resource->kam_choob(96);
			remain = wait_time;
			
		}
		else if( level == 5 && choob >= 194 && ajor >= 165 && ahan >= 120 )
		{
			
			resource->kam_ahan(194);
			resource->kam_ajor(165);
			resource->kam_choob(120);
			remain = wait_time;
			
		}
		else if( level == 6 && choob >= 246 && ajor >= 210 && ahan >= 149 )
		{
			
			resource->kam_ahan(246);
			resource->kam_ajor(210);
			resource->kam_choob(149);
			remain = wait_time;
			
		}
		else if( level == 7 && choob >= 311 && ajor >= 266 && ahan >= 185 )
		{
			
			resource->kam_ahan(311);
			resource->kam_ajor(266);
			resource->kam_choob(185);
			remain = wait_time;
			
		}
		else if( level == 8 && choob >= 393 && ajor >= 338 && ahan >= 231 )
		{
			
			resource->kam_ahan(393);
			resource->kam_ajor(338);
			resource->kam_choob(231);
			remain = wait_time;
			
		}
		else if( level == 9 && choob >= 498 && ajor >= 430 && ahan >= 287 )
		{
			
			resource->kam_ahan(498);
			resource->kam_ajor(430);
			resource->kam_choob(287);
			remain = wait_time;
			
		}
		else if( level == 10 && choob >= 630 && ajor >= 546 && ahan >= 358 )
		{
			
			resource->kam_ahan(630);
			resource->kam_ajor(546);
			resource->kam_choob(358);
			remain = wait_time;
			
		}
		else if( level == 11 && choob >= 796 && ajor >= 693 && ahan >= 446 )
		{
			
			resource->kam_ahan(796);
			resource->kam_ajor(693);
			resource->kam_choob(446);
			remain = wait_time;
			
		}
		else if( level == 12 && choob >= 1007 && ajor >= 880 && ahan >= 555 )
		{
			
			resource->kam_ahan(1007);
			resource->kam_ajor(880);
			resource->kam_choob(555);
			remain = wait_time;
			
		}
		else if( level == 13 && choob >= 1274 && ajor >= 1118 && ahan >= 691 )
		{
			
			resource->kam_ahan(1274);
			resource->kam_ajor(1118);
			resource->kam_choob(691);
			remain = wait_time;
			
		}
		else if( level == 14 && choob >= 1612 && ajor >= 1420 && ahan >= 860 )
		{
			
			resource->kam_ahan(1612);
			resource->kam_ajor(1420);
			resource->kam_choob(860);
			remain = wait_time;
			
		}
		else if( level == 15 && choob >= 2039 && ajor >= 1803 && ahan >= 1071 )
		{
			
			resource->kam_ahan(2039);
			resource->kam_ajor(1803);
			resource->kam_choob(1071);
			remain = wait_time;
			
		}
		else if( level == 16 && choob >= 2580 && ajor >= 2290 && ahan >= 1333 )
		{
			
			resource->kam_ahan(2580);
			resource->kam_ajor(2290);
			resource->kam_choob(1333);
			remain = wait_time;
			
		}
		else if( level == 17 && choob >= 3264 && ajor >= 2908 && ahan >= 1659 )
		{
			
			resource->kam_ahan(3264);
			resource->kam_ajor(2908);
			resource->kam_choob(1659);
			remain = wait_time;
			
		}
		else if( level == 18 && choob >= 4128 && ajor >= 3693 && ahan >= 2066 )
		{
			
			resource->kam_ahan(4128);
			resource->kam_ajor(3693);
			resource->kam_choob(2066);
			remain = wait_time;
			
		}
		else if( level == 19 && choob >= 5222 && ajor >= 4691 && ahan >= 2572)
		{
			
			resource->kam_ahan(5222);
			resource->kam_ajor(4691);
			resource->kam_choob(2572);
			remain = wait_time;
			
		}
		else if( level == 20 && choob >= 6606 && ajor >= 5957 && ahan >= 3202 )
		{
			
			resource->kam_ahan(6606);
			resource->kam_ajor(5957);
			resource->kam_choob(3202);
			remain = wait_time;
			
		}
		else if( level == 21 && choob >= 8357 && ajor >= 7566 && ahan >= 3987 )
		{
			
			resource->kam_ahan(8357);
			resource->kam_ajor(7566);
			resource->kam_choob(3987);
			remain = wait_time;
			
		}
		else if( level == 22 && choob >= 10572 && ajor >= 9608 && ahan >= 4963 )
		{
			
			resource->kam_ahan(10572);
			resource->kam_ajor(9608);
			resource->kam_choob(4963);
			remain = wait_time;
			
		}
		else if( level == 23 && choob >= 13373 && ajor >= 12203 && ahan >= 6180)
		{
			
			resource->kam_ahan(13373);
			resource->kam_ajor(12203);
			resource->kam_choob(6180);
			remain = wait_time;
			
		}
		else if( level == 24 && choob >= 16917 && ajor >= 15497 && ahan >= 7694 )
		{
			
			resource->kam_ahan(16917);
			resource->kam_ajor(15497);
			resource->kam_choob(7694);
			remain = wait_time;
			
		}
		else if( level == 25 && choob >= 21400 && ajor >= 19489 && ahan >= 9588 )
		{
			
			resource->kam_ahan(21400);
			resource->kam_ajor(19489);
			resource->kam_choob(9588);
			remain = wait_time;
			
		}
		else if( level == 26 && choob >= 27071 && ajor >= 24996 && ahan >= 11925 )
		{
			
			resource->kam_ahan(27071);
			resource->kam_ajor(24996);
			resource->kam_choob(11925);
			remain = wait_time;
			
		}
		else if( level == 27 && choob >= 34245 && ajor >= 31745 && ahan >= 14847 )
		{
			
			resource->kam_ahan(34245);
			resource->kam_ajor(31745);
			resource->kam_choob(14847);
			remain = wait_time;
			
		}
		else if( level == 28 && choob >= 43320 && ajor >= 40316 && ahan >= 18484 )
		{
			
			resource->kam_ahan(43320);
			resource->kam_ajor(40316);
			resource->kam_choob(18484);
			remain = wait_time;
			
		}
		else if( level == 29 && choob >= 54799 && ajor >= 51201 && ahan >= 23013 )
		{
			
			resource->kam_ahan(54799);
			resource->kam_ajor(51201);
			resource->kam_choob(23013);
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

