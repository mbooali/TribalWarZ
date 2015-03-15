// Ajor.h: interface for the Ajor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AJOR_H__58D16112_763F_4D45_B1E1_1EC939268D77__INCLUDED_)
#define AFX_AJOR_H__58D16112_763F_4D45_B1E1_1EC939268D77__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Resource.h"
#include <time.h>

class Ajor  
{
	int area, choobmoredeniaz, ajormoredniaz, ahanmoredeniaz;
	int tolid;
	int level;
	time_t lasttime;
	float remain;
	float mojoodi;
	Resource *resource;
public:
	void show();
	void run(time_t t);
	void updateLevel();
	Ajor(Resource *r);
	virtual ~Ajor();

};

#endif // !defined(AFX_AJOR_H__58D16112_763F_4D45_B1E1_1EC939268D77__INCLUDED_)

