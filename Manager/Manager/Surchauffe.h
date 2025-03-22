#pragma once

#include "tools.h"

namespace Surchauffe
{
	void IncrementationTimer(float _timer);
	void DecrementationTimer(float _timer);
	void init();
	void update();
	void draw();
	void destroy();

	//getters
	bool getSurchauffe();
	float getTimerSurchauffe();
	float getTimerSurchauffeMaxValue();
	float getTimerSurchauffeDecrease();
	
	//setters
	void setSurchauffe(bool _surchauffe);
	void setTimerSurchauffe(float _timerSurchauffe);
	void setTimerSurchauffeMaxValue(float _timerSurchauffeMaxValue);
	void setTimerSurchauffeDecrease(float _timerSurchauffeDecrease);
}