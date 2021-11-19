#pragma once

class IStlContain
{
public:
    virtual void AddElement(int iElement) = 0;
    virtual void DeleteAllElement() = 0;
    virtual void PrintAllElement() = 0;
     //please notice this ,the destructor must have
    virtual ~IStlContain(){}
};
