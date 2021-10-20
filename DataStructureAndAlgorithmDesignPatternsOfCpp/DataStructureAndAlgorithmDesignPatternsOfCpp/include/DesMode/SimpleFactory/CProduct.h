#pragma once

//Simple factory mode

typedef enum {
	PRODUCT_ADD,
	PRODUCT_MUL
}emProduct;

class CProduct
{
public:
	CProduct(){}
	virtual ~CProduct(){}
public:
	virtual int operation(int a,int b) = 0;
};

