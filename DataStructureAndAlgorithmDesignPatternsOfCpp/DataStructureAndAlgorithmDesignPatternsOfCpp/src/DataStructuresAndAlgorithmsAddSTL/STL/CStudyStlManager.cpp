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
    // TODO: �ڴ˴����� return ���
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
