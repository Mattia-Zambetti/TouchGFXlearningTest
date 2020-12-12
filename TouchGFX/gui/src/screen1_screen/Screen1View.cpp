#include <gui/screen1_screen/Screen1View.hpp>
#include <Utils.hpp>
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
