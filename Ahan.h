// Ahan.h: interface for the Ahan class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AHAN_H__F2420DD5_EC39_4310_A85E_3C68386EC09D__INCLUDED_)
#define AFX_AHAN_H__F2420DD5_EC39_4310_A85E_3C68386EC09D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Resource.h"
#include <time.h>
class Ahan  
{
	int level;
	time_t lasttime;
	float remain;
	float mojoodi;
	Resource *resource;

public:
	void show();
	void updateLevel();
	void run(time_t t);
	Ahan(Resource *r);
	virtual ~Ahan();

};

#endif // !defined(AFX_AHAN_H__F2420DD5_EC39_4310_A85E_3C68386EC09D__INCLUDED_)

