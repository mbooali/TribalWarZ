// Barracks.cpp: implementation of the Barracks class.
//
//////////////////////////////////////////////////////////////////////

#include "Barracks.h"
#include "Resource.h"
#include "define.h"
#include <iostream>
#define SOLTIME 18
using namespace std;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Barracks::Barracks(Resource *r)
{
	resource = r;
	level = 0;
	sol_num = 0;
	darsad = 0;
	remain = 0;
	num_all_soldier = 0;
	lasttime = time(0);
}

Barracks::~Barracks()
{
	
}

void Barracks::plus(int num)			
{
	num_all_soldier += num;
}

void Barracks::show()
{
	cout << endl <<"number of available soldiers : " << sol_num << endl << "Barraks on LEVEL (" << level << ")"; 
}

void Barracks::setRemain(int rem)
{
	remain = rem;
}

float Barracks::getRemain()
{
	return remain;
}

int Barracks::getLevel()
{
	return level;
}

bool Barracks::add_sol()
{
	int ajor, ahan, choob, farm;
	
	ajor = resource->ajor_();
	ahan = resource->ahan_();
	choob = resource->choob_();
	farm = resource->farm_();
	
	if(ajor >= 30 && ahan >= 10 && choob >= 50 && farm >= 1)		//check mikonad ke resource kafi baraye tolid soldier mojod bashad
	{
		timesol.push_back( SOLTIME );
		resource->kam_ahan(10);
		resource->kam_ajor(30);
		resource->kam_choob(50);
		resource->kam_farm(1);
		return true;
	}
	else
	{
		return false;
	}
	
}

void Barracks::run(time_t t)
{
	int temp;
	vector<time_t>::iterator it;
	
	it = timesol.begin();
	
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
	if( timesol.begin() != timesol.end() )
	{
		switch(level)					//in switch zaman payan tolid yek soldier ra ba tavajoh be level mohasebe mikonad
		{
			
		case 1:
			if(  *it > (t-lasttime) * (100/63) )
			{
				*it -= (t-lasttime) * (100/63);
			}
			else if(  *it == (t-lasttime) * (100/63) )
			{
				timesol.erase(timesol.begin());
				sol_num++;
			}
			else if(  *it < (t-lasttime) * (100/63) )
			{
				temp = (t-lasttime) * (100/63);
				temp -= *it;
				timesol.erase(timesol.begin());
				sol_num++;
				*it -= temp;
			}
			
			break;
			
		case 2:
			
			if(  *it > (t-lasttime) * (100/59) )
			{
				*it -= (t-lasttime) * (100/59);
			}
			else if(  *it == (t-lasttime) * (100/59) )
			{
				timesol.erase(timesol.begin());
				sol_num++;
			}
			else if(  *it < (t-lasttime) * (100/59) )
			{
				temp = (t-lasttime) * (100/59);
				temp -= *it;
				timesol.erase(timesol.begin());
				sol_num++;
				*it -= temp;
			}
			break;
			
		case 3:
			
			if(  *it > (t-lasttime) * (100/56) )
			{
				*it -= (t-lasttime) * (100/56);
			}
			else if(  *it == (t-lasttime) * (100/56) )
			{
				timesol.erase(timesol.begin());
				sol_num++;
			}
			else if(  *it < (t-lasttime) * (100/56) )
			{
				temp = (t-lasttime) * (100/56);
				temp -= *it;
				timesol.erase(timesol.begin());
				sol_num++;
				*it -= temp;
			}
			
			break;
			
		case 4:
			
			if(  *it > (t-lasttime) * (100/53) )
			{
				*it -= (t-lasttime) * (100/53);
			}
			else if(  *it == (t-lasttime) * (100/53) )
			{
				timesol.erase(timesol.begin());
				sol_num++;
			}
			else if(  *it < (t-lasttime) * (100/53) )
			{
				temp = (t-lasttime) * (100/53);
				temp -= *it;
				timesol.erase(timesol.begin());
				sol_num++;
				*it -= temp;
			}
			
			break;
			
		case 5:
			
			if(  *it > (t-lasttime) * (100/50) )
			{
				*it -= (t-lasttime) * (100/50);
			}
			else if(  *it == (t-lasttime) * (100/50) )
			{
				timesol.erase(timesol.begin());
				sol_num++;
			}
			else if(  *it < (t-lasttime) * (100/50) )
			{
				temp = (t-lasttime) * (100/50);
				temp -= *it;
				timesol.erase(timesol.begin());
				sol_num++;
				*it -= temp;
			}
			
			break;
			
		case 6:
			
			if(  *it > (t-lasttime) * (100/47) )
			{
				*it -= (t-lasttime) * (100/47);
			}
			else if(  *it == (t-lasttime) * (100/47) )
			{
				timesol.erase(timesol.begin());
				sol_num++;
			}
			else if(  *it < (t-lasttime) * (100/47) )
			{
				temp = (t-lasttime) * (100/47);
				temp -= *it;
				timesol.erase(timesol.begin());
				sol_num++;
				*it -= temp;
			}
			
			break;
			
		case 7:
			
			if(  *it > (t-lasttime) * (100/44) )
			{
				*it -= (t-lasttime) * (100/44);
			}
			else if(  *it == (t-lasttime) * (100/44) )
			{
				timesol.erase(timesol.begin());
				sol_num++;
			}
			else if(  *it < (t-lasttime) * (100/44) )
			{
				temp = (t-lasttime) * (100/44);
				temp -= *it;
				timesol.erase(timesol.begin());
				sol_num++;
				*it -= temp;
			}
			
			break;
			
		case 8:
			
			if(  *it > (t-lasttime) * (100/42) )
			{
				*it -= (t-lasttime) * (100/42);
			}
			else if(  *it == (t-lasttime) * (100/42) )
			{
				timesol.erase(timesol.begin());
				sol_num++;
			}
			else if(  *it < (t-lasttime) * (100/42) )
			{
				temp = (t-lasttime) * (100/42);
				temp -= *it;
				timesol.erase(timesol.begin());
				sol_num++;
				*it -= temp;
			}
			
			break;
			
		case 9:
			
			if(  *it > (t-lasttime) * (100/39) )
			{
				*it -= (t-lasttime) * (100/39);
			}
			else if(  *it == (t-lasttime) * (100/39) )
			{
				timesol.erase(timesol.begin());
				sol_num++;
			}
			else if(  *it < (t-lasttime) * (100/39) )
			{
				temp = (t-lasttime) * (100/39);
				temp -= *it;
				timesol.erase(timesol.begin());
				sol_num++;
				*it -= temp;
			}
			
			break;
			
		case 10:
			
			if(  *it > (t-lasttime) * (100/37) )
			{
				*it -= (t-lasttime) * (100/37);
			}
			else if(  *it == (t-lasttime) * (100/37) )
			{
				timesol.erase(timesol.begin());
				sol_num++;
			}
			else if(  *it < (t-lasttime) * (100/37) )
			{
				temp = (t-lasttime) * (100/37);
				temp -= *it;
				timesol.erase(timesol.begin());
				sol_num++;
				*it -= temp;
			}
			
			break;
			
		case 11:
			
			if(  *it > (t-lasttime) * (100/35) )
			{
				*it -= (t-lasttime) * (100/35);
			}
			else if(  *it == (t-lasttime) * (100/35) )
			{
				timesol.erase(timesol.begin());
				sol_num++;
			}
			else if(  *it < (t-lasttime) * (100/35) )
			{
				temp = (t-lasttime) * (100/35);
				temp -= *it;
				timesol.erase(timesol.begin());
				sol_num++;
				*it -= temp;
			}
			
			break;
			
		case 12:
			
			if(  *it > (t-lasttime) * (100/33) )
			{
				*it -= (t-lasttime) * (100/33);
			}
			else if(  *it == (t-lasttime) * (100/33) )
			{
				timesol.erase(timesol.begin());
				sol_num++;
			}
			else if(  *it < (t-lasttime) * (100/33) )
			{
				temp = (t-lasttime) * (100/33);
				temp -= *it;
				timesol.erase(timesol.begin());
				sol_num++;
				*it -= temp;
			}
			
			break;
			
		case 13:
			
			if(  *it > (t-lasttime) * (100/31) )
			{
				*it -= (t-lasttime) * (100/31);
			}
			else if(  *it == (t-lasttime) * (100/31) )
			{
				timesol.erase(timesol.begin());
				sol_num++;
			}
			else if(  *it < (t-lasttime) * (100/31) )
			{
				temp = (t-lasttime) * (100/31);
				temp -= *it;
				timesol.erase(timesol.begin());
				sol_num++;
				*it -= temp;
			}
			
			break;
			
		case 14:
			
			if(  *it > (t-lasttime) * (100/29) )
			{
				*it -= (t-lasttime) * (100/29);
			}
			else if(  *it == (t-lasttime) * (100/29) )
			{
				timesol.erase(timesol.begin());
				sol_num++;
			}
			else if(  *it < (t-lasttime) * (100/29) )
			{
				temp = (t-lasttime) * (100/29);
				temp -= *it;
				timesol.erase(timesol.begin());
				sol_num++;
				*it -= temp;
			}
			
			break;
			
		case 15:
			
			if(  *it > (t-lasttime) * (100/28) )
			{
				*it -= (t-lasttime) * (100/28);
			}
			else if(  *it == (t-lasttime) * (100/28) )
			{
				timesol.erase(timesol.begin());
				sol_num++;
			}
			else if(  *it < (t-lasttime) * (100/28) )
			{
				temp = (t-lasttime) * (100/28);
				temp -= *it;
				timesol.erase(timesol.begin());
				sol_num++;
				*it -= temp;
			}
			
			break;
			
		case 16:
			
			if(  *it > (t-lasttime) * (100/26) )
			{
				*it -= (t-lasttime) * (100/26);
			}
			else if(  *it == (t-lasttime) * (100/26) )
			{
				timesol.erase(timesol.begin());
				sol_num++;
			}
			else if(  *it < (t-lasttime) * (100/26) )
			{
				temp = (t-lasttime) * (100/26);
				temp -= *it;
				timesol.erase(timesol.begin());
				sol_num++;
				*it -= temp;
			}
			
			break;
			
		case 17:
			
			if(  *it > (t-lasttime) * (100/25 ) )
			{
				*it -= (t-lasttime) * (100/25);
			}
			else if(  *it == (t-lasttime) * (100/25) )
			{
				timesol.erase(timesol.begin());
				sol_num++;
			}
			else if(  *it < (t-lasttime) * (100/25) )
			{
				temp = (t-lasttime) * (100/25);
				temp -= *it;
				timesol.erase(timesol.begin());
				sol_num++;
				*it -= temp;
			}
			
			break;
			
		case 18:
			
			if(  *it > (t-lasttime) * (100/23) )
			{
				*it -= (t-lasttime) * (100/23);
			}
			else if(  *it == (t-lasttime) * (100/23) )
			{
				timesol.erase(timesol.begin());
				sol_num++;
			}
			else if(  *it < (t-lasttime) * (100/23) )
			{
				temp = (t-lasttime) * (100/23);
				temp -= *it;
				timesol.erase(timesol.begin());
				sol_num++;
				*it -= temp;
			}
			
			break;
			
		case 19:
			
			if(  *it > (t-lasttime) * (100/22) )
			{
				*it -= (t-lasttime) * (100/22);
			}
			else if(  *it == (t-lasttime) * (100/22) )
			{
				timesol.erase(timesol.begin());
				sol_num++;
			}
			else if(  *it < (t-lasttime) * (100/22) )
			{
				temp = (t-lasttime) * (100/22);
				temp -= *it;
				timesol.erase(timesol.begin());
				sol_num++;
				*it -= temp;
			}
			
			break;
			
		case 20:
			
			if(  *it > (t-lasttime) * (100/21) )
			{
				*it -= (t-lasttime) * (100/21);
			}
			else if(  *it == (t-lasttime) * (100/21) )
			{
				timesol.erase(timesol.begin());
				sol_num++;
			}
			else if(  *it < (t-lasttime) * (100/21) )
			{
				temp = (t-lasttime) * (100/21);
				temp -= *it;
				timesol.erase(timesol.begin());
				sol_num++;
				*it -= temp;
			}
			
			break;
			
		case 21:
			
			if(  *it > (t-lasttime) * (100/20) )
			{
				*it -= (t-lasttime) * (100/20);
			}
			else if(  *it == (t-lasttime) * (100/20) )
			{
				timesol.erase(timesol.begin());
				sol_num++;
			}
			else if(  *it < (t-lasttime) * (100/20) )
			{
				temp = (t-lasttime) * (100/20);
				temp -= *it;
				timesol.erase(timesol.begin());
				sol_num++;
				*it -= temp;
			}
			
			break;
			
		case 22:
			
			if(  *it > (t-lasttime) * (100/19) )
			{
				*it -= (t-lasttime) * (100/19);
			}
			else if(  *it == (t-lasttime) * (100/19) )
			{
				timesol.erase(timesol.begin());
				sol_num++;
			}
			else if(  *it < (t-lasttime) * (100/19) )
			{
				temp = (t-lasttime) * (100/19);
				temp -= *it;
				timesol.erase(timesol.begin());
				sol_num++;
				*it -= temp;
			}
			
			break;
			
		case 23:
			
			if(  *it > (t-lasttime) * (100/17) )
			{
				*it -= (t-lasttime) * (100/17);
			}
			else if(  *it == (t-lasttime) * (100/17) )
			{
				timesol.erase(timesol.begin());
				sol_num++;
			}
			else if(  *it < (t-lasttime) * (100/17) )
			{
				temp = (t-lasttime) * (100/17);
				temp -= *it;
				timesol.erase(timesol.begin());
				sol_num++;
				*it -= temp;
			}
			
			break;
			
		case 24:
			
			if(  *it > (t-lasttime) * (100/16) )
			{
				*it -= (t-lasttime) * (100/16);
			}
			else if(  *it == (t-lasttime) * (100/16) )
			{
				timesol.erase(timesol.begin());
				sol_num++;
			}
			else if(  *it < (t-lasttime) * (100/16) )
			{
				temp = (t-lasttime) * (100/16);
				temp -= *it;
				timesol.erase(timesol.begin());
				sol_num++;
				*it -= temp;
			}
			
			break;
			
		case 25:
			
			if(  *it > (t-lasttime) * (100/16) )
			{
				*it -= (t-lasttime) * (100/16);
			}
			else if(  *it == (t-lasttime) * (100/16) )
			{
				timesol.erase(timesol.begin());
				sol_num++;
			}
			else if(  *it < (t-lasttime) * (100/16) )
			{
				temp = (t-lasttime) * (100/16);
				temp -= *it;
				timesol.erase(timesol.begin());
				sol_num++;
				*it -= temp;
			}
			
			break;
	}
	}
	
	lasttime = t;
	//	resource->add_farm( (int)mojoodi );
	//	mojoodi -= (int) mojoodi;
}


void Barracks::updateLevel(){
	int ajor, ahan, choob, farm;
	
	ajor = resource->ajor_();
	ahan = resource->ahan_();
	choob = resource->choob_();
	farm = resource->farm_();
	if(remain == 0)							//neshan dahande payan upgrade level ghabl			
	{
		if( level == 1 && choob >= 252 && ajor >= 218 && ahan >= 113 && farm >= 1 )		//hesab mikonad ke aya mojodi baraye upgrade kardan kafist va resource estefade shode ra kam mikonad
		{
			//59%
			
			resource->kam_ahan(252);
			resource->kam_ajor(218);
			resource->kam_choob(113);
			resource->kam_farm(1);
			
			remain = wait_time;
		}
		else if( level == 2 && choob >= 318 && ajor >= 279 && ahan >= 143 && farm >= 2 )
		{
			
			//56%
			
			resource->kam_ahan(318);
			resource->kam_ajor(279);
			resource->kam_choob(143);
			resource->kam_farm(2);
			
			remain = wait_time;
		}
		else if( level == 3 && choob >= 400 && ajor >=357  && ahan >= 180 && farm >= 1 )
		{
			//53%
			
			resource->kam_ahan(400);
			resource->kam_ajor(357);
			resource->kam_choob(180);
			resource->kam_farm(1);
			
			remain = wait_time;
		}
		else if( level == 4 && choob >= 504 && ajor >= 456 && ahan >= 227 && farm >= 2 )
		{
			//50%
			
			resource->kam_ahan(504);
			resource->kam_ajor(456);
			resource->kam_choob(227);
			resource->kam_farm(2);
			
			remain = wait_time;
		}
		else if( level == 5 && choob >= 635 && ajor >= 584 && ahan >= 286 && farm >= 2 )
		{
			//47%
			
			resource->kam_ahan(635);
			resource->kam_ajor(584);
			resource->kam_choob(286);
			resource->kam_farm(2);
			
			remain = wait_time;
		}
		else if( level == 6 && choob >=800  && ajor >= 748 && ahan >= 360 && farm >= 3 )
		{
			//44%
			
			resource->kam_ahan(800);
			resource->kam_ajor(748);
			resource->kam_choob(360);
			resource->kam_farm(3);
			
			remain = wait_time;
		}
		else if( level == 7 && choob >= 1008 && ajor >= 957 && ahan >= 454 && farm >= 3 )
		{
			//42%
			
			resource->kam_ahan(1008);
			resource->kam_ajor(957);
			resource->kam_choob(454);
			resource->kam_farm(3);
			
			remain = wait_time;
		}
		else if( level == 8 && choob >= 1271 && ajor >= 1225 && ahan >= 572&& farm >= 4 )
		{
			//39%
			
			resource->kam_ahan(1271);
			resource->kam_ajor(1225);
			resource->kam_choob(572);
			resource->kam_farm(4);
			
			remain = wait_time;
		}
		else if( level == 9 && choob >= 1601 && ajor >= 1568 && ahan >= 720 && farm >= 4 )
		{
			//37%
			
			resource->kam_ahan(1601);
			resource->kam_ajor(1568);
			resource->kam_choob(720);
			resource->kam_farm(4);
			
			remain = wait_time;
		}
		else if( level == 10 && choob >= 2017 && ajor >= 2007 && ahan >= 908 && farm >= 5 )
		{
			//35%
			
			resource->kam_ahan(2017);
			resource->kam_ajor(2007);
			resource->kam_choob(908);
			resource->kam_farm(5);
			
			remain = wait_time;
		}
		else if( level == 11 && choob >= 2542 && ajor >= 2569 && ahan >= 1144 && farm >= 5 )
		{
			//33%
			
			resource->kam_ahan(2542);
			resource->kam_ajor(2569);
			resource->kam_choob(1144);
			resource->kam_farm(5);
			
			remain = wait_time;
		}
		else if( level == 12 && choob >= 3202 && ajor >= 3288 && ahan >= 1441 && farm >= 7 )
		{
			//31
			
			resource->kam_ahan(3202);
			resource->kam_ajor(3288);
			resource->kam_choob(1441);
			resource->kam_farm(7);
			
			remain = wait_time;
		}
		else if( level == 13 && choob >= 4035 && ajor >= 4209 && ahan >= 1816 && farm >= 8 )
		{
			//29%
			
			resource->kam_ahan(4035);
			resource->kam_ajor(4209);
			resource->kam_choob(1816);
			resource->kam_farm(8);
			
			remain = wait_time;
		}
		else if( level == 14 && choob >= 5084 && ajor >= 5388 && ahan >= 2288 && farm >= 9 )
		{
			//28%
			
			resource->kam_ahan(5084);
			resource->kam_ajor(5388);
			resource->kam_choob(2288);
			resource->kam_farm(9);
			
			remain = wait_time;
		}
		else if( level == 15 && choob >= 6406 && ajor >= 6896 && ahan >= 2883 && farm >= 11 )
		{
			//26%
			
			resource->kam_ahan(6406);
			resource->kam_ajor(6896);
			resource->kam_choob(2883);
			resource->kam_farm(11);
			
			remain = wait_time;
		}
		else if( level == 16 && choob >= 8072 && ajor >= 8827 && ahan >= 3632 && farm >= 12 )
		{
			//25%
			
			resource->kam_ahan(8072);
			resource->kam_ajor(8827);
			resource->kam_choob(3632);
			resource->kam_farm(12);
			
			remain = wait_time;
		}
		else if( level == 17 && choob >= 10170 && ajor >= 11298 && ahan >= 4577 && farm >= 15 )
		{
			//23%
			
			resource->kam_ahan(10170);
			resource->kam_ajor(11298);
			resource->kam_choob(4577);
			resource->kam_farm(15);
			
			remain = wait_time;
		}
		else if( level == 18 && choob >= 12814 && ajor >= 14462 && ahan >= 5767 && farm >= 17 )
		{
			//22%
			
			resource->kam_ahan(12814);
			resource->kam_ajor(14462);
			resource->kam_choob(5767);
			resource->kam_farm(17);
			
			remain = wait_time;
		}
		else if( level == 19 && choob >= 16146 && ajor >= 18511 && ahan >= 7266 && farm >= 20 )
		{
			//21%
			
			resource->kam_ahan(16146);
			resource->kam_ajor(18511);
			resource->kam_choob(7266);
			resource->kam_farm(20);
			
			remain = wait_time;
		}
		else if( level == 20 && choob >= 20344 && ajor >= 23695 && ahan >= 9155 && farm >= 24 )
		{
			//20%
			
			resource->kam_ahan(20344);
			resource->kam_ajor(23695);
			resource->kam_choob(9155);
			resource->kam_farm(24);
			
			remain = wait_time;
		}
		else if( level == 21 && choob >= 25634 && ajor >= 30329 && ahan >= 11535 && farm >= 27 )
		{
			//19%
			
			resource->kam_ahan(25634);
			resource->kam_ajor(30329);
			resource->kam_choob(11535);
			resource->kam_farm(27);
			
			remain = wait_time;
		}
		else if( level == 22 && choob >= 32298 && ajor >= 38821 && ahan >= 14534 && farm >= 32 )
		{
			//17%
			
			resource->kam_ahan(32298);
			resource->kam_ajor(38821);
			resource->kam_choob(14534);
			resource->kam_farm(32);
			
			remain = wait_time;
		}
		else if( level == 23 && choob >= 40696 && ajor >= 49691 && ahan >= 18313 && farm >= 38 )
		{
			//16%
			
			resource->kam_ahan(40696);
			resource->kam_ajor(49691);
			resource->kam_choob(18313);
			resource->kam_farm(38);
			
			remain = wait_time;
		}
		else if( level == 24 && choob >= 51277 && ajor >= 63605 && ahan >= 23075 && farm >= 44 )
		{
			//16%
			
			resource->kam_ahan(51277);
			resource->kam_ajor(63605);
			resource->kam_choob(23075);
			resource->kam_farm(23075);
			
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


