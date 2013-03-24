#include <Windows.h>

#include "sys/FsTimer.h"

NS_FS_BEGIN 
Timer::Timer()
{
	m_begin=GetTickCount();
}
void Timer::reset()
{
	m_begin=GetTickCount();
}

long Timer::now() const 
{
	return  GetTickCount()-m_begin;
}

NS_FS_END 
