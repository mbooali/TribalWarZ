// Timber.h: interface for the Timber class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TIMBER_H__3EC82B3B_5B5B_4DDE_8969_6B47794194E3__INCLUDED_)
#define AFX_TIMBER_H__3EC82B3B_5B5B_4DDE_8969_6B47794194E3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Resource.h"
#include <time.h>

class Timber  
{
	int area, choobmoredeniaz, ajormoredniaz, ahanmoredeniaz;
	int tolid;
	int level ;
	time_t lasttime;
	float remain;
	float mojoodi;
	Resource *resource;
public:
	void show();
	void updateLevel();
	void run(time_t t);
	Timber(Resource *r);
	virtual ~Timber();

};

#endif // !defined(AFX_TIMBER_H__3EC82B3B_5B5B_4DDE_8969_6B47794194E3__INCLUDED_)



