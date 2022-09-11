#pragma once
#include <iostream>
#include <Windows.h>

#include "Motor.h"
#include "Button.h"

#define BCOUNT 3
#define START 3000
#define LOADING 5000
#define ICECOUNT 3


class Machine
{
private:

	Button* m_Buttons[BCOUNT] =
	{
		new Button("차가운물"),
		new Button("조각얼음"),
		new Button("얼음조각")
	};
	Motor* m_Motor = new Motor(START, LOADING);
	int m_IceCount = 0;

public:
	void InitMachine() { m_Motor->StartBooting(); }
	void SelectButton();
	void PushButton(Button* p_PushButton, Type p_Type);
};

