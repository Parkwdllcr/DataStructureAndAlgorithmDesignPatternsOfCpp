

class CCallBackReceiver
{
public:
    CCallBackReceiver(void);
    ~CCallBackReceiver(void);

    void WorkFunction(void);
    static void OnCalBack(int iA,int iB);
private:
    CProcessingData *m_pCaller;
};