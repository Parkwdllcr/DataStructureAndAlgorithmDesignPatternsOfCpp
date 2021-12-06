#include "DataStructuresAndAlgorithmsAddSTL/STL/CStudyString.h"
#include "CPrimerPlus/CPublicClass.h"



CStudyString::~CStudyString()
{

}

void CStudyString::Inital()
{
	std::cout << "<---------------->" << std::endl;
	std::cout << "<void CStudyString::Inital>" << std::endl;

	m_strInitFirst = "1234  5";
	m_pPubicClass->ShowAndSize<std::string>(m_strInitFirst);

	std::string strInitSecond("1234  5");
	m_pPubicClass->ShowAndSize<std::string>(strInitSecond);

	std::string strInitThird(7, '1');
	m_pPubicClass->ShowAndSize<std::string>(strInitThird);

	std::string strInitFour;
	m_pPubicClass->ShowAndSize<std::string>(strInitFour);

	std::string strInitFive("1234  5",6);
	m_pPubicClass->ShowAndSize<std::string>(strInitFive);

	std::string strInitSix(strInitThird.begin(),strInitThird.end()-3);
	m_pPubicClass->ShowAndSize<std::string>(strInitSix);

	std::string strInitSeven = m_strInitFirst + strInitThird;
	m_pPubicClass->ShowAndSize<std::string>(strInitSeven);

}
