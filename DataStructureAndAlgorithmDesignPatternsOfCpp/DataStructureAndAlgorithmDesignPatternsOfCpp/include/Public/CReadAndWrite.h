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



class CReadAndWrite
{
public:
	CReadAndWrite();
	~CReadAndWrite();

public:
	void ReadXml(boost::property_tree::ptree pt);


};


struct  XmlNode_s
{
	std::string strNodeName;                               //��ǰ�ڵ�����
	std::unordered_map<std::string, std::string>  xmlattr; //��ǰ�ڵ������
	std::list<std::string>  listSubName;                   //�ӽڵ�����
	std::string strParentName;                             //���ڵ� ��¼�˴Ӹ��ڵ㵽��һ���ڵ�����֣���"."���� 
	std::string strValue;                                  //��ǰ�ڵ��ֵ
};


void XMLParse(const boost::property_tree::ptree& pxml, std::list<XmlNode_s>& listNode, std::string strNode = "")
{
	for (const auto& node : pxml)
	{
		std::string  NodeKey = node.first.data(); //���Ի����ӽڵ�
		if (NodeKey == "<xmlattr>") //�ж��Ƿ�������
		{
			continue; //�����Ѿ��ڸ��ڵ������˱���
		}
		XmlNode_s xmlnode;
		xmlnode.strNodeName = std::string(node.first.data()); //�ڵ���
		xmlnode.strValue = node.second.data(); //ֵ
		xmlnode.strParentName = strNode; //���ڵ������洫�������
	//��ȡ�ýڵ������
		for (const auto& attr : node.second)
		{
			std::string strAttr = attr.first.data();
			if (std::string(strAttr) == "<xmlattr>") //������
			{
				//��ȡ���Ե�ֵ
				for (auto& att : attr.second)
				{
					std::cout << att.first.data() << std::endl; //��������
					std::cout << att.second.data() << std::endl; //����ֵ
					xmlnode.xmlattr[att.first.data()] = att.second.data();
				}
			}
			else //�ڵ�����
			{
				xmlnode.listSubName.emplace_back(strAttr); //��ǰ�ڵ���ӽڵ�����
			}
		}
		listNode.emplace_back(xmlnode); //���浱ǰ�ڵ�
		if (!NodeKey.empty()) //��ǰ�ڵ�
		{
			xmlnode.xmlattr.clear();
			//��ȡ�ӽڵ���Ϣ �ݹ�
			std::string strParentName;
			if (!xmlnode.strParentName.empty())
			{
				strParentName += xmlnode.strParentName + "." + xmlnode.strNodeName;
			}
			else
			{
				strParentName = xmlnode.strNodeName;
			}
			//���ɸ��ڵ� д��XML��ʱ����Ҫ֪�����ڵ�
			XMLParse(node.second, listNode, strParentName); //�ݹ����
		}
	}
}


void MakeXmlNode(boost::property_tree::ptree& pt, XmlNode_s& node)
{
	pt.put_value(node.strValue); //���ֵ
	for (auto& itA : node.xmlattr)
	{
		std::string strA = "<xmlattr>.";
		pt.add(strA + itA.first, itA.second); //��������
	}
}


void AddXmlNode(boost::property_tree::ptree& pt, XmlNode_s& node, std::string& strPreNode)
{
	auto itPos = strPreNode.find("."); //���û��"."��ʾ���ڵ�
	if (itPos == std::string::npos)
	{
		boost::property_tree::ptree tmp;
		MakeXmlNode(tmp, node);
		if (pt.size() == 0) //�ڵ��һ�γ��֣�ֱ�����
		{
			pt.add_child(node.strNodeName, tmp);
		}
		else
		{//�ж����ͬ�ڵ㣬ȡ���һ�����������ݽ�ֻ����ڵ�һ��  ��Ϊ������ʱ�����Ȱѵ�ǰ�ڵ���������ٻ��������ġ������ڶ��������������
			pt.back().second.add_child(node.strNodeName, tmp); //ȡ���һ���ڵ�  
		}
	}
	else
	{
		std::string strSub = strPreNode.substr(itPos + 1);
		auto& ptTmp = pt.back().second; //Ҫ���ã�����д�����Ϣ�������ڸ��ڵ���
		AddXmlNode(ptTmp, node, strSub); //�ݹ�д��  
	}
}


void WriteXML(std::string& strFile, std::list<XmlNode_s>& listNode)
{
	boost::property_tree::ptree ptRoot; //���ڵ�
	for (auto it = listNode.begin(); it != listNode.end(); ++it)
	{
		AddXmlNode(ptRoot, *it, it->strParentName); //��ӽڵ�
	}
	auto settings = boost::property_tree::xml_writer_make_settings<std::string>('\t', 1);
	write_xml(strFile, ptRoot, std::locale(), settings);
}


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
std::map<std::string, std::map<std::string, strSubDevice>> m_mLoadware;

void ReadXml(boost::property_tree::ptree pt)
{
	read_xml("conf.xml", pt);     //����һ��xml�ļ�   
		//child��ʾ��dss.devicelist�Ľڵ㣬Ҳ�����������dss.devicelist�ڵ���һ������е�ֵ
	boost::property_tree::ptree child = pt.get_child("dss.devicelist");    //ȡһ���ӽڵ�   

	//ÿһ��child�����кܶ�Ԫ��
	for (boost::property_tree::ptree::iterator pos = child.begin(); pos != child.end(); ++pos)  //   
	{
		boost::property_tree::ptree pTreedevice = pos->second.get_child("");//��ʾ����device�ڵ�
		boost::property_tree::ptree::iterator strSubDeviceiter = pTreedevice.begin();
		std::cout << pos->second.get_child("").get<std::string>("name") << std::endl;
		strSubDeviceiter++;
		std::cout << pos->second.get_child("").get<std::string>("description") << std::endl;
		strSubDeviceiter++;
		for (strSubDeviceiter; strSubDeviceiter != pTreedevice.end(); ++strSubDeviceiter)
		{
			boost::property_tree::ptree pTreedeviceSubDevice = strSubDeviceiter->second.get_child("");
			std::cout << pTreedeviceSubDevice.get<std::string>("name") << std::endl;
			std::cout << pTreedeviceSubDevice.get<std::string>("upgrademode") << std::endl;
			std::cout << pTreedeviceSubDevice.get<std::string>("EDSVersion") << std::endl;
			std::cout << pTreedeviceSubDevice.get<std::string>("EDSUpgradeFileData") << std::endl;
			std::cout << pTreedeviceSubDevice.get<std::string>("EDSUpgradeFileLen") << std::endl;
			std::cout << pTreedeviceSubDevice.get<std::string>("EDSUpgradeFileLen") << std::endl;
		}

	}
}
void WriteXml(boost::property_tree::ptree& pt)
{

}