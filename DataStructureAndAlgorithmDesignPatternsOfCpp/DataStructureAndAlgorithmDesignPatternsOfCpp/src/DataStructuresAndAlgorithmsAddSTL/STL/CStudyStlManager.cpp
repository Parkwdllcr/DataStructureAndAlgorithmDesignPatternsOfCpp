#include "DataStructuresAndAlgorithmsAddSTL/STL/CStudyStlManager.h"
#include<iostream>

CStudyStlManager::CStudyStlManager()
                           :m_strStlContainName("")
{

}

CStudyStlManager::CStudyStlManager(std::string strStlContainName)
                :m_strStlContainName(strStlContainName)
{

}

CStudyStlManager::~CStudyStlManager()
{
    try
    {
         ReleaseStlList();
    }
    catch(...)
    {
        std::cout << "Unknown Err" << std::endl;
    }

}

int CStudyStlManager::Inital()
{
    

}
