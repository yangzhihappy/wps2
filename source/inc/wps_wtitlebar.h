
#ifndef __HAVE_ARCH_WPS_WTITLEBAR
#define __HAVE_ARCH_WPS_WTITLEBAR

#include <QWidget>

class QPushButton;
class QLabel;

class WPS_WTitleBar : public QWidget
{
Q_OBJECT
public:
	WPS_WTitleBar(QWidget *parent = 0);
	virtual ~WPS_WTitleBar();
	void setTitle(const QString & title);
signals:
	void sigClose();
	void sigMin();
private slots:
	void slotClicked();
protected:
	virtual void setupUi();		//to setup ui
	virtual void retranslateUi();	//used for update to translate ui from one language to another
private:
	void setConnect();			//set ui signal and slot
private:
	QLabel			*m_titleLabel;
	QPushButton		*m_closeBtn;
	QPushButton		*m_minBtn;
};

#endif

