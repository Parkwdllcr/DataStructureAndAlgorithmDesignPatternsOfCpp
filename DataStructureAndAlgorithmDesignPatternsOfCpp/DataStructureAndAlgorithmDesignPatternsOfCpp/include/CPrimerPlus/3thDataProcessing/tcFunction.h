#pragma once

// ���� SDKDDKVer.h ��������õ���߰汾�� Windows ƽ̨��

// ���ҪΪ��ǰ�� Windows ƽ̨����Ӧ�ó�������� WinSDKVer.h������
// WIN32_WINNT ������ΪҪ֧�ֵ�ƽ̨��Ȼ���ٰ��� SDKDDKVer.h��

//I do not know this header ,I will debug it when I have some time

#include <SDKDDKVer.h>
#include <stdio.h>
#include <tchar.h>
#include <functional>
#include <iostream>

namespace tc_package
{
	class TemplateCaller
	{
	public:
		TemplateCaller() :m_func(NULL) {}
		template <typename T1, typename T2>
		void RegisterCallback(T1 memberFunc, T2* pThis)
		{
			m_func = std::bind(memberFunc, pThis, std::placeholders::_1, std::placeholders::_2);
		}

		template<typename T>
		void RegisterCallback(T globalFunc)
		{
			m_func = std::bind(globalFunc, std::placeholders::_1, std::placeholders::_2);
		}

		bool Run()
		{
			std::string str("Hello World");
			if (m_func != NULL)
			{
				return m_func(str, NULL);
			}
			return false;
		}
	private:
		typedef std::function<bool(std::string& str, void* pUserData)> MyCallBack;
		MyCallBack m_func;
	};
}


class NewReceiver
{
public:
	NewReceiver()
	{

		caller.RegisterCallback(&NewReceiver::CallBack, this);
		caller.Run();
	}
	bool CallBack(std::string& str, void* pUserData)
	{
		std::cout << "123" << std::endl;
		return true;
	}
private:
	tc_package::TemplateCaller caller;
};

void  TestTcFunction()
{
	NewReceiver ba;
}
