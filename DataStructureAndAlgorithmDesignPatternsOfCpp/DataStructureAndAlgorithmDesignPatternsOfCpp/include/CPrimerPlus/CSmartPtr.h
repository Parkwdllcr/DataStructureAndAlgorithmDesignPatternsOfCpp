//非侵入式引用计数管理对象接口

template<typename _Ty>
class INonintrusiveRefcountManager
{
public:
    virtual size_t     AddRef() = 0;
    virtual size_t     Release() = 0;
    virtual _Ty*       RealObject() = 0;
    virtual const _Ty* RealObject() const = 0;
};

template<typename _Ty>
class CDefaultNonintrusiveRefcountMgr:public INonintrusiveRefcountManager<_Ty>
{
public:
   typedef _Ty DataObjectType;
   explicit CDefaultNonintrusiveRefcountMgr(DataObjectType* pRep = nullptr):m_pData(pRep),m_RefCount(1){}
   virtual ~CDefaultNonintrusiveRefcountMgr(){}
   virtual size_t  AddRef()
   {
       ::InterlockedIncrement((long*)&m_RefCount);
       return m_RefCount;
   }
   virtual size_t Release()
   {
       ::InterlockedDecrement((long*)&m_RefCount);
       if (m_RefCount == 0)
       {
           this->_Destroy();
           delete this;
           //add or not add?
           //this = nullptr; 
           return 0;
       }
       return m_RefCount;
   }

   virtual DataObjectType* RealObject(){return m_pData;}
   virtual const DataObjectType* RealObject() const {return m_pData;}

protected:
   void _Destroy()
   {
       delete m_pData;
       m_pData = nullptr;
   }
DataObjectType*  m_pData;
size_t           m_RefCount;

private:
CDefaultNonintrusiveRefcountMgr(const CDefaultNonintrusiveRefcountMgr<_Ty>& CopyObject);
void operator=(const CDefaultNonintrusiveRefcountMgr<_Ty>& OtherObject)；

};