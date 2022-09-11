#include "Motor.h"

// 자판기 부팅 함수
void Motor::StartBooting()
{
	std::cout << "청강자판기 준비중..." << std::endl;
	Sleep(m_StartupTime);
	std::cout << "청강자판기 준비완료! 최종설정 마침중..." << std::endl;
	Sleep(m_LoadingTime);
	std::cout << "환영합니다!" << std::endl;
	isRunning = true;
}

// 자판기 종료 함수
void Motor::EndBooting()
{
	std::cout << "자판기를 종료합니다." << std::endl;
	Sleep(m_LoadingTime);
	isRunning = false;
}

// 변수 가져오기 함수
bool Motor::GetRunning() { return isRunning; }
int Motor::GetLoadingTime() { return m_LoadingTime; }
