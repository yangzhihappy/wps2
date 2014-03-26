
#ifndef __HAVE_ARCH_WPS_WTITLEBAR
#define __HAVE_ARCH_WPS_WTITLEBAR

#include <QWidget>

class WPS_WTitleBar : public QWidget
{
Q_OBJECT
public:
	WPS_WTitleBar(QWidget *parent = 0);
	virtual ~WPS_WTitleBar();
protected:
	virtual void setupUi();		//to setup ui
	virtual void retranslateUi();	//used for update to translate ui from one language to another
private:
	void setConnect();			//set ui signal and slot
private:
};

#endif

