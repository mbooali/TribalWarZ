// Farm.cpp: implementation of the Farm class.
//
//////////////////////////////////////////////////////////////////////

#include "Farm.h"
#include <iostream>
#include "define.h"
using namespace std;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Farm::Farm(Resource *r)
{
	level = 1;
	resource = r;
	remain = 0;
	lasttime = time(0);
	max = 240;
}

Farm::~Farm()
{
	
}

int Farm::getMax()
{
	return max;
}

void Farm::show()
{
	cout << endl << resource->getUsed() << "(used)/" << max << "(ToTaL)" << endl << "Available Farm : " << resource->farm_() << endl << "Farm on LEVEL (" << level << ")"; 
}

void Farm::run(time_t t)			//zaman payan upgrade har level ra mohasebe mikonad
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
			switch(level)			//ba tavajoh be level max farm ra set mikonad
			{
			case 2:
				max =281;
				break;
			case 3:
				max =329;
				break;
			case 4:
				max =386;
				break;
			case 5:
				max =452;
				break;
			case 6:
				max =530;
				break;
			case 7:
				max =622;
				break;
			case 8:
				max =729;
				break;
			case 9:
				max =854;
				break;
			case 10:
				max =1002;
				break;
			case 11:
				max =1174;
				break;
			case 12:
				max =1376;
				break;
			case 13:
				max =1613;
				break;
			case 14:
				max =1891;
				break;
			case 15:
				max =2216;
				break;
			case 16:
				max =2598;
				break;
			case 17:
				max =3045;
				break;
			case 18:
				max =3569;
				break;
			case 19:
				max =4183;
				break;
			case 20:
				max =4904;
				break;
			case 21:
				max =5748;
				break;
			case 22:
				max =6737;
				break;
			case 23:
				max =7896;
				break;
			case 24:
				max =9255;
				break;
			case 25:
				max =10848;
				break;
			case 26:
				max =12715;
				break;
			case 27:
				max =14904;
				break;
			case 28:
				max =17469;
				break;
			case 29:
				max =20476;
				break;
			case 30:
				max =24000;
				break;
			}
			resource->set_farm(max);
			
			lasttime = t;
		}
	}
}


void Farm::updateLevel(){
	int ajor, ahan, choob;
	
	ajor = resource->ajor_();
	ahan = resource->ahan_();
	choob = resource->choob_();
	
	if( remain == 0)			
	{
		if( level == 1 && choob >= 59 && ajor >= 53 && ahan >= 39 )		//check mikonad resource baraye upgrade kafi bashad va resource estefadeh shode ra kam mikonad	
		{
			resource->kam_ahan(39);
			resource->kam_ajor(53);
			resource->kam_choob(59);
			remain = 2;    // 20 * 60
		}
		else if( level == 2 && choob >= 76 && ajor >= 70 && ahan >= 50 )
		{
			resource->kam_ahan(50);
			resource->kam_ajor(70);
			resource->kam_choob(76);
			remain = wait_time;
		}
		else if( level == 3 && choob >= 99 && ajor >= 92 && ahan >= 64 )
		{
			resource->kam_ahan(64);
			resource->kam_ajor(92);
			resource->kam_choob(99);
			remain = wait_time;
		}
		else if( level == 4 && choob >= 129 && ajor >= 121 && ahan >= 83 )
		{
			resource->kam_ahan(83);
			resource->kam_ajor(121);
			resource->kam_choob(129);
			remain = wait_time;
		}
		else if( level == 5 && choob >= 167 && ajor >= 160 && ahan >= 107 )
		{
			resource->kam_ahan(107);
			resource->kam_ajor(160);
			resource->kam_choob(167);
			remain = wait_time;
		}
		else if( level == 6 && choob >= 217 && ajor >= 212 && ahan >= 138 )
		{
			resource->kam_ahan(138);
			resource->kam_ajor(212);
			resource->kam_choob(217);
			remain = wait_time;
		}
		else if( level == 7 && choob >= 282 && ajor >= 279 && ahan >= 178 )
		{
			resource->kam_ahan(178);
			resource->kam_ajor(279);
			resource->kam_choob(282);
			remain = wait_time;
		}
		else if( level == 8 && choob >= 367 && ajor >= 369 && ahan >= 230 )
		{
			resource->kam_ahan(230);
			resource->kam_ajor(369);
			resource->kam_choob(367);
			remain = wait_time;
		}
		else if( level == 9 && choob >= 477 && ajor >= 487 && ahan >= 297 )
		{
			resource->kam_ahan(297);
			resource->kam_ajor(487);
			resource->kam_choob(477);
			remain = wait_time;
		}
		else if( level == 10 && choob >= 620 && ajor >= 642 && ahan >= 383 )
		{
			resource->kam_ahan(383);
			resource->kam_ajor(642);
			resource->kam_choob(620);
			remain = wait_time;
		}
		else if( level == 11 && choob >=806  && ajor >=848  && ahan >=494 )
		{
			resource->kam_ahan(494);
			resource->kam_ajor(848);
			resource->kam_choob(806);
			remain = wait_time;
		}
		else if( level == 12 && choob >=1043  && ajor >=119  && ahan >= 637 )
		{
			resource->kam_ahan(637);
			resource->kam_ajor(119);
			resource->kam_choob(1043);
			remain = wait_time;
		}
		else if( level == 13 && choob >=1363  && ajor >=1477  && ahan >=822 )
		{
			resource->kam_ahan(822);
			resource->kam_ajor(1477);
			resource->kam_choob(1363);
			remain = wait_time;
		}
		else if( level == 14 && choob >=1772  && ajor >=1950  && ahan >=1060 )
		{
			resource->kam_ahan(1060);
			resource->kam_ajor(1950);
			resource->kam_choob(1772);
			remain = wait_time;
		}
		else if( level == 15 && choob >=2303  && ajor >=2574  && ahan >=1368 )
		{
			resource->kam_ahan(1368);
			resource->kam_ajor(2574);
			resource->kam_choob(2303);
			remain = wait_time;
		}
		else if( level == 16 && choob >=2994  && ajor >=3398  && ahan >=1764  )
		{
			resource->kam_ahan(1764);
			resource->kam_ajor(3398);
			resource->kam_choob(2994);
			remain = wait_time;
		}
		else if( level == 17 && choob >=3893  && ajor >=4486  && ahan >=2276  )
		{
			resource->kam_ahan(2276);
			resource->kam_ajor(4486);
			resource->kam_choob(3893);
			remain = wait_time;
		}
		else if( level == 18 && choob >=5060  && ajor >=5921  && ahan >=2936 )
		{
			resource->kam_ahan(2936);
			resource->kam_ajor(5921);
			resource->kam_choob(5060);
			remain = wait_time;
		}
		else if( level == 19 && choob >=6579  && ajor >=7816  && ahan >=3787 )
		{
			resource->kam_ahan(3787);
			resource->kam_ajor(7816);
			resource->kam_choob(6579);
			remain = wait_time;
		}
		else if( level == 20 && choob >=8552  && ajor >=10317  && ahan >=4886  )
		{
			resource->kam_ahan(4886);
			resource->kam_ajor(10317);
			resource->kam_choob(8552);
			remain = wait_time;
		}
		else if( level == 21 && choob >=11118  && ajor >=13618  && ahan >=6302 )
		{
			resource->kam_ahan(6302);
			resource->kam_ajor(13618);
			resource->kam_choob(11118);
			remain = wait_time;
		}
		else if( level == 22 && choob >=14453  && ajor >=17976  && ahan >=8130 )
		{
			resource->kam_ahan(8130);
			resource->kam_ajor(17976);
			resource->kam_choob(14453);
			remain = wait_time;
		}
		else if( level == 23 && choob >=18789  && ajor >=23728  && ahan >=10488 )
		{
			resource->kam_ahan(10488);
			resource->kam_ajor(23728);
			resource->kam_choob(18789);
			remain = wait_time;
		}
		else if( level == 24 && choob >=24426  && ajor >=31321  && ahan >=13529 )
		{
			resource->kam_ahan(13529);
			resource->kam_ajor(31321);
			resource->kam_choob(24426);
			remain = wait_time;
		}
		else if( level == 25 && choob >=31754  && ajor >=41344  && ahan >= 17453)
		{
			resource->kam_ahan(31754);
			resource->kam_ajor(41344);
			resource->kam_choob(17453);
			remain = wait_time;
		}
		else if( level == 26 && choob >= 41280 && ajor >= 54574 && ahan >= 22514 )
		{
			resource->kam_ahan(41280);
			resource->kam_ajor(54574);
			resource->kam_choob(22514);
			remain = wait_time;
		}
		else if( level == 27 && choob >= 53664 && ajor >= 72037 && ahan >= 29043 )
		{
			resource->kam_ahan(53664);
			resource->kam_ajor(72037);
			resource->kam_choob(29043);
			remain = wait_time;
		}
		else if( level == 28 && choob >= 69763 && ajor >= 95089 && ahan >= 37466 )
		{
			resource->kam_ahan(69763);
			resource->kam_ajor(95089);
			resource->kam_choob(37466);
			remain = wait_time;
		}
		else if( level == 29 && choob >= 90692 && ajor >= 125517 && ahan >= 48331 )
		{
			resource->kam_ahan(90692);
			resource->kam_ajor(125517);
			resource->kam_choob(48331);
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

