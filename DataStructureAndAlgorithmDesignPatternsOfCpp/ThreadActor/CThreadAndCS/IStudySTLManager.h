#pragma once

class IStudySTLManager
{
public:
	virtual int StartProcessThread() = 0;
	virtual void ShutDown() = 0;
	virtual ~IStudySTLManager() {}
};
