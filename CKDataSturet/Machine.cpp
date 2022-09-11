#include "Machine.h"

void Machine::SelectButton()
{
	// 실행중일때 음료수나 얼음을 선택할수 있습니다. 여기서 음료수를 선택하면 자판기는 종료됩니다.
	// 반면 얼음을 선택하면 얼음이 출력되지만, 용량이 커집니다.
	while (m_Motor->GetRunning())
	{
		int select;

		std::cout << "마실 음료를 선택해주세요." << std::endl;

		std::cout << "0. 차가운물" << std::endl;
		std::cout << "1. 조각얼음" << std::endl;
		std::cout << "2. 얼음조각" << std::endl;

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
		default: // 다른 숫자 입력시, 재시도
			std::cout << "다른 버튼을 누르셨습니다. 다시 시도하십시오." << std::endl;
			break;
		}
	}
}

void Machine::PushButton(Button* p_PushButton, Type p_Type)
{
	std::cout << "출력하고 있습니다...." << std::endl;

	if (p_Type == ICE)
	{
		// 얼음 용량이 가득차면 출력을 실패하게 만듭니다.
		if (m_IceCount >= ICECOUNT)
		{
			std::cout << "출력 실패! 얼음이 가득찼습니다!" << std::endl;
		}
		else
		{
			p_PushButton->PushedButton(p_Type);
			Sleep(m_Motor->GetLoadingTime());
			std::cout << p_PushButton->PrintButton() << std::endl;
			m_IceCount++;
		}

	}
	else if (p_Type == DRINK) // 음료수를 선택하면 자판기는 자동으로 종료됩니다.
	{
		p_PushButton->PushedButton(p_Type);
		Sleep(m_Motor->GetLoadingTime());
		std::cout << p_PushButton->PrintButton() << std::endl;
		m_Motor->EndBooting();
	}
}
