#include "Motor.h"

// ���Ǳ� ���� �Լ�
void Motor::StartBooting()
{
	std::cout << "û�����Ǳ� �غ���..." << std::endl;
	Sleep(m_StartupTime);
	std::cout << "û�����Ǳ� �غ�Ϸ�! �������� ��ħ��..." << std::endl;
	Sleep(m_LoadingTime);
	std::cout << "ȯ���մϴ�!" << std::endl;
	isRunning = true;
}

// ���Ǳ� ���� �Լ�
void Motor::EndBooting()
{
	std::cout << "���Ǳ⸦ �����մϴ�." << std::endl;
	Sleep(m_LoadingTime);
	isRunning = false;
}

// ���� �������� �Լ�
bool Motor::GetRunning() { return isRunning; }
int Motor::GetLoadingTime() { return m_LoadingTime; }
