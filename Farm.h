// Farm.h: interface for the Farm class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FARM_H__BBAD8E24_3571_4ED8_9569_2F06E885FA5B__INCLUDED_)
#define AFX_FARM_H__BBAD8E24_3571_4ED8_9569_2F06E885FA5B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Resource.h"
#include <time.h>

class Farm  
{
	int area, choobmoredeniaz, ajormoredniaz, ahanmoredeniaz;
	int AvailableFarm;
	int num_all_farm;
	int level ;
	time_t lasttime;
	float remain;
	int max;
	Resource *resource;
public:
	void show();
	void updateLevel();
	void run(time_t t);
	Farm(Resource *r);
	virtual ~Farm();
	int getMax();

};

#endif // !defined(AFX_FARM_H__BBAD8E24_3571_4ED8_9569_2F06E885FA5B__INCLUDED_)

