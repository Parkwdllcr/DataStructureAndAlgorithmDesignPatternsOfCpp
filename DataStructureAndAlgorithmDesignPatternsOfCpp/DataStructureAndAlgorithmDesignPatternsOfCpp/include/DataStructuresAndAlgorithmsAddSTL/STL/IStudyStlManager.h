#pragma once
#include<list>
#include<string>
#include "IStlContain.h"
//#include"os_type.h"

typedef std::list<IStlContain*> StlContainList;

class IStudyStlManager
{
public:
   //please notice this ,the destructor must have
   virtual ~IStudyStlManager(){}
   virtual int Initialize() = 0;
   virtual const std::string& MyNameIs() const = 0;
   virtual StlContainList QueryStlContain() = 0;
   virtual StlContainList GetContainList() = 0;
 
};

// typedef IStudyStlManager* (*FUNC_DLL_EXPORT_STL_MANAGER_INSTALL)();

// extern "C"
// {
//    EXPORT IStudyStlManager* GetStlContainManagerInstance();

// }






