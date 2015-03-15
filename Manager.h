// Manager.h: interface for the Manager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MANAGER_H__C3BFD326_B7D9_4814_B11A_0C4B63B74F00__INCLUDED_)
#define AFX_MANAGER_H__C3BFD326_B7D9_4814_B11A_0C4B63B74F00__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Headquarters.h"
#include "Resource.h"

class Manager  
{
	Headquarters *headquarters;
	Resource *resource;
	
public:
	Manager();
	virtual ~Manager();
	void start();
};

#endif // !defined(AFX_MANAGER_H__C3BFD326_B7D9_4814_B11A_0C4B63B74F00__INCLUDED_)
