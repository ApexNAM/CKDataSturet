#include "Machine.h"

void Machine::SelectButton()
{
	// �������϶� ������� ������ �����Ҽ� �ֽ��ϴ�. ���⼭ ������� �����ϸ� ���Ǳ�� ����˴ϴ�.
	// �ݸ� ������ �����ϸ� ������ ��µ�����, �뷮�� Ŀ���ϴ�.
	while (m_Motor->GetRunning())
	{
		int select;

		std::cout << "���� ���Ḧ �������ּ���." << std::endl;

		std::cout << "0. �����" << std::endl;
		std::cout << "1. ��������" << std::endl;
		std::cout << "2. ��������" << std::endl;

		std::cin >> select;

		switch (select)
		{
		case 0:
			PushButton(m_Buttons[0], DRINK);
			break;
		case 1:
			PushButton(m_Buttons[1], ICE);
			break;
		case 2:
			PushButton(m_Buttons[2], ICE);
			break;
		default: // �ٸ� ���� �Է½�, ��õ�
			std::cout << "�ٸ� ��ư�� �����̽��ϴ�. �ٽ� �õ��Ͻʽÿ�." << std::endl;
			break;
		}
	}
}

void Machine::PushButton(Button* p_PushButton, Type p_Type)
{
	std::cout << "����ϰ� �ֽ��ϴ�...." << std::endl;

	if (p_Type == ICE)
	{
		// ���� �뷮�� �������� ����� �����ϰ� ����ϴ�.
		if (m_IceCount >= ICECOUNT)
		{
			std::cout << "��� ����! ������ ����á���ϴ�!" << std::endl;
		}
		else
		{
			p_PushButton->PushedButton(p_Type);
			Sleep(m_Motor->GetLoadingTime());
			std::cout << p_PushButton->PrintButton() << std::endl;
			m_IceCount++;
		}

	}
	else if (p_Type == DRINK) // ������� �����ϸ� ���Ǳ�� �ڵ����� ����˴ϴ�.
	{
		p_PushButton->PushedButton(p_Type);
		Sleep(m_Motor->GetLoadingTime());
		std::cout << p_PushButton->PrintButton() << std::endl;
		m_Motor->EndBooting();
	}
}
