// Headquarters.h: interface for the Headquarters class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_HEADQUARTERS_H__5020EF76_B124_4B9C_B569_ABD48643A77D__INCLUDED_)
#define AFX_HEADQUARTERS_H__5020EF76_B124_4B9C_B569_ABD48643A77D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Barracks.h"
#include "Timber.h"
#include "Ajor.h"
#include "Ahan.h"
#include "Farm.h"
#include "Warehouse.h"
#include "Resource.h"
#include <time.h>


class Headquarters  
{
	int level,totalfarm;		//totalfarm hameye farmhaye haroom shode vaseye 1 sakhtemune
	time_t lasttime;
	float remain;
	Resource *resource;
	Barracks *barracks;
	Timber *timber;
	Ajor *ajor;
	Ahan *ahan;
	Farm *farm;
	Warehouse *warehouse;

public:
	void builder_();
	void barracks_();
	void timber_();
	void clay_();
	void iron_();
	void farm_();
	void warehouse_();
	void run(time_t t);
	void updateLevel();
	int getlevel(){return level;}
	Ajor* getAjor();
	Ahan* getAhan();
	Farm* getFarm();
	Warehouse* getWarehouse();
	Barracks* getBarracks();
	Timber* getTimber();


	Headquarters(Resource *r);
	virtual ~Headquarters();
};

#endif // !defined(AFX_HEADQUARTERS_H__5020EF76_B124_4B9C_B569_ABD48643A77D__INCLUDED_)


