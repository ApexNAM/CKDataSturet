#pragma once
#include <iostream>
#include <string>

enum Type
{
	DRINK, ICE
};

class Button
{
private:
	std::string name;
	
public:
	Button(std::string p_Name)
	{
		name = p_Name;
	}

	void PushedButton(Type p_Type);
	std::string PrintButton();
};

