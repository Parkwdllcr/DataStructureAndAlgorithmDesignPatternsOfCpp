#pragma once
//this class is order to illustrate class,struct,enum,char,
//char*,stding,const char *,array ,new/delete and pointer 
//this is very import


class CFourthComplexDataType
{
public:
	//four base function 
public:
	void  TestFourthComplexDataType();
public:
	//《高质量程序设计--c++/c语言》
	//<HighQualityProgramming--C++ /C Language> at page 289-page291
	//will get a paper
	void  GetMemory(char* pChar, int iNum);
	void  GetMemory(char** pChar, int iNum);
    char* GetMemory(int inum);

	char* GetString(void);
	//char* GetStringSecond(void);

	//I have a problem,,add const,& and * is diffent ?，this is very import 


};