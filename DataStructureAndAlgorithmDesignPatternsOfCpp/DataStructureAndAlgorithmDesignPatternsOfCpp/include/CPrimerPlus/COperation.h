#pragma once

class COperation
{
public:
	virtual bool GetResult(double& dbResult) const = 0;
	COperation();
	COperation(double dbNumberA, double dbNumberb);
	~COperation();
protected:
	double m_dbNumberA;
	double m_dbNumberB;
	bool SetNumberA(const double dbNumberA) ;
	bool GetNumberA(double& dbResultA) const;
	bool SetNumberB(const double dbNumberB) ;
	bool GetNumberB(double& dbResultB) const;

};
