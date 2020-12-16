#include <gui/screen1_screen/Screen1View.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>

Screen1Presenter::Screen1Presenter(Screen1View& v)
    : view(v)
{

}

void Screen1Presenter::activate()
{

}

void Screen1Presenter::deactivate()
{

}

void Screen1Presenter::AnalogUpdate( uint32_t value )
{
	view.AnalogUpdate( value);
}

void Screen1Presenter::ProgressBarUpdate( uint32_t value )
{
	view.ProgressBarUpdate( value);
}