// Resource.cpp: implementation of the Resource class.
//
//////////////////////////////////////////////////////////////////////

#include "Resource.h"
#include "define.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Resource::Resource()
{
	farm = 240;
	perchoob = 30;
	perajor = 30;
	perahan = 30;
	perfarm = 240;
	cons = 95;
	used = 0;
	ajor = 1000;
	ahan = 1000;
	choob = 1000;

}

Resource::~Resource()
{

}

int Resource::getUsed()
{
	return used;
}

int Resource::getPchoob()			//meghdar tolid choob dar 1 saat
{
	return perchoob;
}
int Resource::getPajor()			//meghdar tolid ajor dar 1 saat
{
	return perajor;
}
int Resource::getPahan()			//meghdar tolid ahan dar 1 saat
{
	return perahan;
}
int Resource::getPfarm()			//meghdar tolid farm dar 1 saat
{
	return perfarm;
}
void Resource::setPchoob(int choobx)
{
	perchoob = choobx;
}
void Resource::setPajor(int ajorx)
{
	perajor = ajorx;
}
void Resource::setPahan(int ahanx)
{
	perahan = ahanx;
}
void Resource::setPfarm(int farmx)
{
	perfarm = farmx;
}


int Resource::cons_()
{
	return cons;
}

int Resource::choob_()
{
	return choob;
}

int Resource::ahan_()
{
	return ahan;
}

int Resource::ajor_()
{
	return ajor;
}

int Resource::farm_()
{
	return farm - used;
}

void Resource::set_cons(int cons__)
{
	cons = cons__;
}

void Resource::set_choob(int choob__)
{
	choob = choob__;
}

void Resource::set_ajor(int ajor__)
{
	ajor = ajor__;
}

void Resource::set_ahan(int ahan__)
{
	ahan = ahan__;
}

void Resource::set_farm(int farm__)
{
	farm = farm__;
}

void Resource::add_ahan(int n)
{
	ahan += n;
}

void Resource::add_choob(int n)
{
	choob += n;
}

void Resource::add_ajor(int n)
{
	ajor += n;
}





////////////////////////////////////////////////////////////////////


void Resource::kam_ahan(int n)
{

	ahan = ahan - n;
}

void Resource::kam_choob(int n)
{

	choob = choob - n;
}

void Resource::kam_ajor(int n)
{

	ajor = ajor - n;
}

void Resource::kam_farm(int n)
{
	used += n;
}


