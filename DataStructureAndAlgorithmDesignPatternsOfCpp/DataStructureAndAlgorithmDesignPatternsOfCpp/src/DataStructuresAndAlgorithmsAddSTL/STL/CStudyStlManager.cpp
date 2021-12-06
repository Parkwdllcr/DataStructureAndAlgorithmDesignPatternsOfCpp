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

CStudyStlManager::CStudyStlManager(const CStudyStlManager& copyObject)
{
}

CStudyStlManager& CStudyStlManager::operator=(const CStudyStlManager& studySTLmanger)
{
    // TODO: 在此处插入 return 语句
    return *this;
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
    
    return 1;
}
