
#ifndef __HAVE_ARCH_WPS_CONFIRM_WDIALOG
#define __HAVE_ARCH_WPS_CONFIRM_WDIALOG

#include <QDialog>

class WPS_WTitleBar;

class QLabel;
class QPushButton;

class WPS_Confirm_WDialog : public QDialog
{
	Q_OBJECT
public:
	WPS_Confirm_WDialog(QWidget *parent = 0);
	virtual ~WPS_Confirm_WDialog();
	void setTitle(const QString &);
protected:	
	virtual void setupUi(); 	//to setup ui
	virtual void retranslateUi();	//used for update to translate ui from one language to another
private:
	void setConnect();
private:
	WPS_WTitleBar	*m_titleBar;
	QLabel			*m_title;
	QPushButton		*m_confirmBtn;
	QPushButton		*m_cancelBtn;
};


#endif

