#pragma once

	//study call back 
//(1)����һ��callback��typedefһ��
//(2)ע��һ��callback�����ܺ�����ָ��ע�뵽�����������callback
//(3)��ô������ʲôʱ��ȥ����������ܣ��Ϳ���������ˡ�
//Ҳ���ǹ��ܺ����͵������Ƿֿ��ģ�

// 1������һ����������ͨ�������ɣ���
//�����������CCallBackReceiver�е�OnCalBack
// 2�����˺����ĵ�ַע��������ߣ�
// 3���ض����¼�����������ʱ��������ʹ�ú���ָ����ûص�������

typedef void (*MyCallBack)(int a,int b);

class CCallBack
{

public:
	void StartWork();
	void RegCallBack(MyCallBack fun, int iFrist, int iSecond);
	void NowCall();//work 
private:
	int  m_iTestCall;
	int  m_iTestCallSecond;
	MyCallBack m_func;
};
