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
	std::string strNodeName;                               //当前节点名字
	std::unordered_map<std::string, std::string>  xmlattr; //当前节点的属性
	std::list<std::string>  listSubName;                   //子节点名字
	std::string strParentName;                             //父节点 记录了从根节点到上一个节点的名字，用"."隔开 
	std::string strValue;                                  //当前节点的值
};


void XMLParse(const boost::property_tree::ptree& pxml, std::list<XmlNode_s>& listNode, std::string strNode = "")
{
	for (const auto& node : pxml)
	{
		std::string  NodeKey = node.first.data(); //属性或者子节点
		if (NodeKey == "<xmlattr>") //判断是否是属性
		{
			continue; //属性已经在父节点中做了保存
		}
		XmlNode_s xmlnode;
		xmlnode.strNodeName = std::string(node.first.data()); //节点名
		xmlnode.strValue = node.second.data(); //值
		xmlnode.strParentName = strNode; //父节点是外面传入进来的
	//获取该节点的属性
		for (const auto& attr : node.second)
		{
			std::string strAttr = attr.first.data();
			if (std::string(strAttr) == "<xmlattr>") //是属性
			{
				//获取属性的值
				for (auto& att : attr.second)
				{
					std::cout << att.first.data() << std::endl; //属性名字
					std::cout << att.second.data() << std::endl; //属性值
					xmlnode.xmlattr[att.first.data()] = att.second.data();
				}
			}
			else //节点自身
			{
				xmlnode.listSubName.emplace_back(strAttr); //当前节点的子节点名字
			}
		}
		listNode.emplace_back(xmlnode); //保存当前节点
		if (!NodeKey.empty()) //当前节点
		{
			xmlnode.xmlattr.clear();
			//获取子节点信息 递归
			std::string strParentName;
			if (!xmlnode.strParentName.empty())
			{
				strParentName += xmlnode.strParentName + "." + xmlnode.strNodeName;
			}
			else
			{
				strParentName = xmlnode.strNodeName;
			}
			//生成父节点 写入XML的时候需要知道父节点
			XMLParse(node.second, listNode, strParentName); //递归遍历
		}
	}
}


void MakeXmlNode(boost::property_tree::ptree& pt, XmlNode_s& node)
{
	pt.put_value(node.strValue); //添加值
	for (auto& itA : node.xmlattr)
	{
		std::string strA = "<xmlattr>.";
		pt.add(strA + itA.first, itA.second); //设置属性
	}
}


void AddXmlNode(boost::property_tree::ptree& pt, XmlNode_s& node, std::string& strPreNode)
{
	auto itPos = strPreNode.find("."); //如果没有"."表示根节点
	if (itPos == std::string::npos)
	{
		boost::property_tree::ptree tmp;
		MakeXmlNode(tmp, node);
		if (pt.size() == 0) //节点第一次出现，直接添加
		{
			pt.add_child(node.strNodeName, tmp);
		}
		else
		{//有多个相同节点，取最后一个，否则数据将只会放在第一个  因为遍历的时候是先把当前节点遍历完了再回来遍历的。类似于二叉树的先序遍历
			pt.back().second.add_child(node.strNodeName, tmp); //取最后一个节点  
		}
	}
	else
	{
		std::string strSub = strPreNode.substr(itPos + 1);
		auto& ptTmp = pt.back().second; //要引用，否则写入的信息将不会在父节点上
		AddXmlNode(ptTmp, node, strSub); //递归写入  
	}
}


void WriteXML(std::string& strFile, std::list<XmlNode_s>& listNode)
{
	boost::property_tree::ptree ptRoot; //根节点
	for (auto it = listNode.begin(); it != listNode.end(); ++it)
	{
		AddXmlNode(ptRoot, *it, it->strParentName); //添加节点
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
	read_xml("conf.xml", pt);     //读入一个xml文件   
		//child表示在dss.devicelist的节点，也就是它会计算dss.devicelist节点下一层的所有的值
	boost::property_tree::ptree child = pt.get_child("dss.devicelist");    //取一个子节点   

	//每一个child下面有很多元素
	for (boost::property_tree::ptree::iterator pos = child.begin(); pos != child.end(); ++pos)  //   
	{
		boost::property_tree::ptree pTreedevice = pos->second.get_child("");//表示本身device节点
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