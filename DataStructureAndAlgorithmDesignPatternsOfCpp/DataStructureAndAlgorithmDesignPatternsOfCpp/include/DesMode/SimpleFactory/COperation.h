#pragma once

class COperation
{
public:
	COperation();
	COperation(double dbNumberA, double dbNumberb);
	~COperation();
	virtual bool GetResult(double& dbResult) const = 0;
public:
	bool SetNumberA(const double dbNumberA);
	bool GetNumberA(double& dbResultA) const;
	bool SetNumberB(const double dbNumberB);
	bool GetNumberB(double& dbResultB) const;
protected:
	double m_dbNumberA;
	double m_dbNumberB;


};
