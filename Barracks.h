// Barracks.h: interface for the Barracks class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BARRACKS_H__4EC62BF9_C1F4_49D1_9FDD_21C4FB1FB847__INCLUDED_)
#define AFX_BARRACKS_H__4EC62BF9_C1F4_49D1_9FDD_21C4FB1FB847__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Resource.h"
#include <vector>
#include <time.h>
using namespace std;

class Barracks  
{
	int area, choobmoredeniaz, ajormoredniaz, ahanmoredeniaz;
	int level ;
	int darsad;
	float remain;
	int sol_num;
	int num_all_soldier;
	time_t lasttime;
	Resource *resource;
	vector<time_t> timesol;
public:
	void plus(int num);
	void show();
	float getRemain();
	int getLevel();
	bool add_sol();
	void run(time_t t);
	void updateLevel();
	void add_soldier();
	void setRemain(int rem);
	Barracks(Resource* r);
	virtual ~Barracks();

};

#endif // !defined(AFX_BARRACKS_H__4EC62BF9_C1F4_49D1_9FDD_21C4FB1FB847__INCLUDED_)

