#include "Button.h"

// ����� �Ǵ� ���� ����
void Button::PushedButton(Type p_Type)
{
	std::cout << name << "�� �����߽��ϴ�." << std::endl;

	if (p_Type == ICE)
	{
		std::cout << "������ �����ϼ̽��ϴ�." << std::endl;
	}
	else if (p_Type == DRINK)
	{
		std::cout << "������� �����ϼ̽��ϴ�." << std::endl;
	}
}

// ��� �Ϸ� ����
std::string Button::PrintButton()
{
	return name + "��(��) ����� �Ϸ�Ǿ����ϴ�.";
}
