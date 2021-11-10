

class CCallBack;

class CCallBackReceiver
{
public:
    CCallBackReceiver(void);
    ~CCallBackReceiver(void);

    void WorkFunction(void);
    static void OnCalBack(int iA,int iB);
private:
	CCallBack*     m_pCaller;
};