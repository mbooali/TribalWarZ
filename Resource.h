// Resource.h: interface for the Resource class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RESOURCE_H__3F7C5CF5_F311_45EA_8770_549630F692A7__INCLUDED_)
#define AFX_RESOURCE_H__3F7C5CF5_F311_45EA_8770_549630F692A7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Resource  
{
	int choob,ajor,ahan,farm,cons,used;
	int perchoob,perajor,perahan,perfarm;
public:
	Resource();
	~Resource();
	void add_ahan(int n);
	void add_choob(int n);
	void add_ajor(int n);

	void kam_ahan(int n);
	void kam_choob(int n);
	void kam_ajor(int n);
	void kam_farm(int n);

	void set_choob(int choob__);
	void set_ajor(int ajor__);
	void set_ahan(int ahan__);
	void set_farm(int farm__);
	void set_cons(int cons__);
	void setPchoob(int choobx);
	void setPajor(int ajorx);
	void setPahan(int ahanx);
	void setPfarm(int farmx);
	
	int choob_();
	int ahan_();
	int ajor_();
	int farm_();
	int cons_();
	int getPchoob();
	int getPajor();
	int getPahan();
	int getPfarm();
	int getUsed();

};

#endif // !defined(AFX_RESOURCE_H__3F7C5CF5_F311_45EA_8770_549630F692A7__INCLUDED_)

