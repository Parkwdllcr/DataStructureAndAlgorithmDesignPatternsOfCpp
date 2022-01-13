
#include <iostream>
#include <time.h>
#include "ListAndMap/CStudyStlManager.h"
#include "MulThread/thread_mutex.h"
#include "MulThread/Actor.h"
#include "MulThread/thread_semaphore.h"

#include <iostream>
int main()
{
	double dbStartTime, dbEndTime,dbTialTime;
	bool bShutDown = true;
	dbStartTime = (clock() / CLOCKS_PER_SEC);
	CStudyStlManager* pStlManager = new CStudyStlManager();
	pStlManager->Initialize();

	while (bShutDown)
	{
		dbEndTime = (clock()/CLOCKS_PER_SEC);
		dbTialTime = (dbEndTime - dbStartTime);
		if (dbTialTime > 6)
		{
			bShutDown = false;
		}
	}
	pStlManager->Shutdown();
	while (pStlManager->getListSize() > 0);
	if (nullptr != pStlManager&& pStlManager->getListSize()==0)
	{
		delete pStlManager;
		pStlManager = nullptr;
	}
	
	return 1;
}

