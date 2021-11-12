/*** 
 * @Copyright, (c) Shanghai United Imaging healthcare Inc., 2011 All rights reserved.
 * @Author: Lin Yilin    yilin.lin@cri-united-imaging.com
 * @Date: 2021-08-24 14:55:23
 * @LastEditTime: 2021-08-24 15:12:38
 * @LastEditors: Lin Yilin
 * @Description: 
 * @FilePath: /demo/src/main/test_actor.cpp
 */

#include <iostream>
#include "Logger/logger.h"
#include "Logger/rt_logger.h"
#include "test_actor.h"
#include "UtilsBox/utilsbox_utils.h"

using namespace std;

void TestActor::svc(void)
{
    while (true)
    {
        LOGGER_REALTIME_INFO("thread running info");
        LOGGER_INFO("thread running info");

        LOGGER_REALTIME_WARN("thread running warn");
        LOGGER_WARN("thread running info");

        LOGGER_REALTIME_ERROR("thread running error");
        LOGGER_ERROR("thread running info");
        utilsbox::CUtils::MSleep(100);
    }
};