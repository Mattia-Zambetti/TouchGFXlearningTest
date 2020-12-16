#include <gui/screen1_screen/Screen1View.hpp>
#include <Utils.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include "BitmapDatabase.hpp"

uint32_t ProgressBarValue;

Screen1View::Screen1View()
{

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

void Screen1View::AnalogUpdate( uint16_t value )
{
	memset ( &ADCtextBuffer, value, ADCTEXT_SIZE); //ADCtextBuffer taken from Screen1ViewBase.cpp
	Unicode::snprintfFloat ( ADCtextBuffer, sizeof(ADCtextBuffer), "%.2f", value*0.0008056641);
	ADCtext.invalidate();
}

void Screen1View::ProgressBarUpdate( uint16_t value )
{
	ProgressBarValue=value*0.0244140625;
	/*if ( ProgressBarValue >= 50 )				//Text color change
	{
		ProgressBarText.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
	}
	else
	{
    ProgressBarText.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
	}*/
	memset ( &ProgressBarTextBuffer, value, PROGRESSBARTEXT_SIZE);
	Unicode::snprintfFloat ( ProgressBarTextBuffer, sizeof(ProgressBarTextBuffer), "%.0f %", ProgressBarValue);
	lineProgress1.setValue((int)ProgressBarValue);
	ProgressBarText.invalidate();
	lineProgress1.invalidate();
}

