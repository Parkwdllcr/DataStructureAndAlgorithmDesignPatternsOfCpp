#pragma once

class IStudyStlManagder
{
public:
     virtual int Initialize() = 0;
     virtual void AddElemt() = 0;
     virtual void DeletAllElement() = 0;
     virtual void ShowElement() = 0;
     virtual void Shutdown() = 0;
     virtual ~IStudyStlManagder(){}
};