
#include "wps_wtitlebar.h"


WPS_WTitleBar::WPS_WTitleBar(QWidget *parent) : QWidget(parent)
{
	setupUi();
}

WPS_WTitleBar::~WPS_WTitleBar()
{
}

void WPS_WTitleBar::setupUi()		//to setup ui
{
	retranslateUi();
	setConnect();
}

void WPS_WTitleBar::retranslateUi()	//used for update to translate ui from one language to another
{
}

void WPS_WTitleBar::setConnect()			//set ui signal and slot
{
}


