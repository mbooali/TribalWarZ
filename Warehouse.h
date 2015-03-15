// Warehouse.h: interface for the Warehouse class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_WAREHOUSE_H__590E434B_26F1_4D8A_9422_567F9E295FCD__INCLUDED_)
#define AFX_WAREHOUSE_H__590E434B_26F1_4D8A_9422_567F9E295FCD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Resource.h"
#include <time.h>

class Warehouse  
{
	int area, choobmoredeniaz, ajormoredniaz, ahanmoredeniaz;
	int AvailableChoob, AvailableAjor, AvailableAhan;
	int max;
	int level ;
	time_t lasttime;
	float remain;
	Resource *resource;
public:
	void show();
	void updateLevel();
	void run(time_t t);		// check and distribute
	Warehouse(Resource *r);
	virtual ~Warehouse();

};

#endif // !defined(AFX_WAREHOUSE_H__590E434B_26F1_4D8A_9422_567F9E295FCD__INCLUDED_)

