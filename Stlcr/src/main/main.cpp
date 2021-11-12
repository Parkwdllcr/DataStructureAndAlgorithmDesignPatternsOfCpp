//////////////////////////////////////////////////////////////////////////
/// \defgroup Framework Demo
///  Copyright, (c) Shanghai United Imaging healthcare Inc., 2011
///  All rights reserved.
///
///  \author   LIN yilin yilin.lin@united-imaging.com
///
///  \file    main.cpp
///  \brief   framework demo main
///
///  \version 1.0
///  \date    July. 02 2021
//////////////////////////////////////////////////////////////////////////
#include <signal.h>
#include <errno.h>
#include <iostream>

#include "Logger/logger.h"
#include "Logger/rt_logger.h"
#include "Logger/logger_return_code.h"
#include "test_actor.h"

using namespace utilsbox;
using namespace std;

bool g_bExit = false;

static void MAIN_CatchTerminatingSignal(int i)
{
	g_bExit = true;
}

int main()
{
	// LOG使用 Step 1 初始化
	LOGGER_LOG_INITIAL("Demo", "");
	// Step 2 设置log level
	LOGGER_TRACE_INFO_SWITCH(1);

	LOGGER_INFO("Main thread start");
	LOGGER_REALTIME_INFO("Main thread start");

	TestActor *actor = new TestActor();
	actor->Start();

	TestActor *actor1 = new TestActor();
	actor1->Start();

	// 必须先配置才能编译通过
	/* Register signal process function to operating system */
	if (SIG_ERR == signal(SIGTERM, MAIN_CatchTerminatingSignal))
	{
		LOGGER_PRINTF("\r\n ERROR: signal() return failed(Errno==%d)!!Exit program...\r\n", errno);
		return 0;
	}
	CUtils::MSleep(5 * 1000);
	if (actor != nullptr)
	{
		delete actor;
		actor = nullptr;
	}

	if (actor1 != nullptr)
	{
		delete actor1;
		actor1 = nullptr;
	}

	return 0;
}