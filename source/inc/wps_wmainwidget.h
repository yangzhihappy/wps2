
#ifndef __HAVE_ARCH_WPS_WMAINWIDGET
#define __HAVE_ARCH_WPS_WMAINWIDGET

#include <QWidget>

class WPS_WMainWidget : public QWidget
{
Q_OBJECT
public:
	WPS_WMainWidget(QWidget * parent = 0);
	virtual ~WPS_WMainWidget();
protected:
	virtual void setupUi();		//to setup ui
	virtual void retranslateUi();	//used for update to translate ui from one language to another
private:
	void setConnect();			//set ui signal and slot
private:	
};


#endif

