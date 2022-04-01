#pragma once
#include "IStudySTLManager.h"
#include "IStudySTL.h"
#include "ITestTread.h"
#include <list>
#include <memory>

class CStudySTLManager :
    public IStudySTLManager
{
public:
public:
    CStudySTLManager();
    virtual ~CStudySTLManager();

public:
    int   StartProcessThread();
    void  ShutDown();

    void AddTestThread(std::shared_ptr<IThestThread> pTestThread);
public:
    int   GetThreadListSize() {
        return m_pListTestThread.size();
    }
private:
    std::list<std::shared_ptr<IThestThread>> m_pListTestThread;
};

