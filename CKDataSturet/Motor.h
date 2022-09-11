#pragma once
#include <iostream>
#include <Windows.h>


class Motor
{
private:
	int m_StartupTime, m_LoadingTime;
	bool isRunning = false;
public:
	Motor(int p_Start, int p_Loading)
	{
		m_StartupTime = p_Start;
		m_LoadingTime = p_Loading;
	}

	void StartBooting();
	void EndBooting();
	
	bool GetRunning();
	int GetLoadingTime();
};
