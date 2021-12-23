#pragma once
#include "UtilsBox/utilsbox_mutex.h"
#include "ListAndMap/IStudyStl.h"
#include <map>
#include <string>

class CStudyMap:public IStudyStl
{
public:
   CStudyMap();
   ~CStudyMap();

   //just to read!
// private:
//    CStudyMap(std::map<std::string,int> TempMap);
//    CStudyMap(const CStudyMap & other);
//    CStudyMap& operator=(const CStudyMap& other);
public:
   virtual  void AddElement() ;
   virtual  void DeleteAllElement() ;
   virtual  void PrintAllElement() ;
	
private:
	std::map<std::string, int>    m_MapTest;
   utilsbox::CMutex              m_MutexMap;
};
