#pragma once
#include"IStudyStlManager.h"

class CStudyStlManager:public IStudyStlManager
{
public:
    CStudyStlManager();
    CStudyStlManager(std::string strStlContainName);
    CStudyStlManager(const CStudyStlManager& copyObject);
    CStudyStlManager& operator = (const CStudyStlManager & studySTLmanger);
    virtual ~CStudyStlManager();

public:
//覆盖了接口类的方法
   //inital add ptr
    virtual int Inital();
    virtual const std::string& MyNameIs() ;
    virtual StlContainList QueryStlContain(std::string strStlName);
    virtual StlContainList GetContainList() ;
    void ReleaseStlList();
private:
    std::string  m_strStlContainName;
};



