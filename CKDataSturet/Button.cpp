#include "Button.h"

// 음료수 또는 얼음 판정
void Button::PushedButton(Type p_Type)
{
	std::cout << name << "을 선택했습니다." << std::endl;

	if (p_Type == ICE)
	{
		std::cout << "얼음을 선택하셨습니다." << std::endl;
	}
	else if (p_Type == DRINK)
	{
		std::cout << "음료수를 선택하셨습니다." << std::endl;
	}
}

// 출력 완료 판정
std::string Button::PrintButton()
{
	return name + "이(가) 출력이 완료되었습니다.";
}
