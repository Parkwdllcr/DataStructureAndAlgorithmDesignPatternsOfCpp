#include <iostream>
#include <memory>
#include <string>
#include <map>
#include<sstream>
#include<boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/typeof/typeof.hpp>
#include <unordered_map>
#include <list>



struct strSubDevice
{
	std::string m_strName;
	std::string m_strFile;
	std::string m_strMode;
	std::string m_strEDSVersion;
	std::string m_strEDSUpgradeFileData;
	std::string m_strEDSUpgradeFileLen;
	std::string m_strEDSUpgradeResult;
};

struct  XmlNode_s
{
	std::string strNodeName;                               //��ǰ�ڵ�����
	std::unordered_map<std::string, std::string>  xmlattr; //��ǰ�ڵ������
	std::list<std::string>  listSubName;                   //�ӽڵ�����
	std::string strParentName;                             //���ڵ� ��¼�˴Ӹ��ڵ㵽��һ���ڵ�����֣���"."���� 
	std::string strValue;                                  //��ǰ�ڵ��ֵ
};


class CReadAndWrite
{
public:
	
	~CReadAndWrite();
	CReadAndWrite(const CReadAndWrite&) = delete;
	CReadAndWrite& operator=(const CReadAndWrite&) = delete;
	static CReadAndWrite* GetInstance();
	void ReadXml(boost::property_tree::ptree pt);
	void WriteXML(std::string& strFile, std::list<XmlNode_s>& listNode);
	void MakeXmlNode(boost::property_tree::ptree& pt, XmlNode_s& node);
	void AddXmlNode(boost::property_tree::ptree& pt, XmlNode_s& node, std::string& strPreNode);
	void XMLParse(const boost::property_tree::ptree& pxml, std::list<XmlNode_s>& listNode, std::string strNode = "");
private:
	CReadAndWrite();

private:
	std::map<std::string, std::map<std::string, strSubDevice>> m_mLoadware;

};





