#include "DesMode/SimpleFactory/CFactory.h"

CProduct* CFactory::Creat(int iProductType)
{
	switch (iProductType)
	{
	case PRODUCT_ADD:
	{
		m_pCproduct = new CProduct_Add();
		break;
	}

	case PRODUCT_MUL:
	{
		m_pCproduct = new CProduct_Mul();
		break;
	}
	default:
		m_pCproduct = nullptr;
		break;
	}
	if (m_pCproduct != nullptr)
	{
		return m_pCproduct;
	}
	else
	{
		std::cout << "new CFactory is fall" << std::endl;
		return nullptr;
	}
	
}

void CFactory::Destory()
{
	if (m_pCproduct != nullptr)
	{
		delete m_pCproduct;
		m_pCproduct = nullptr;
	}
}
