
#ifndef __HAVE_ARCH_WPS_WMAINWIDGET
#define __HAVE_ARCH_WPS_WMAINWIDGET

#include <QWidget>

class WPS_WTitleBar;

class QLabel;
class QLineEdit;
class QTextEdit;
class QPushButton;
class QLayout;

class WPS_WMainWidget : public QWidget
{
Q_OBJECT
public:
	WPS_WMainWidget(QWidget * parent = 0);
	virtual ~WPS_WMainWidget();
private slots:
	void slotReturnPressed();
	void slotClicked();
protected:
	virtual void setupUi();		//to setup ui
	virtual void retranslateUi();	//used for update to translate ui from one language to another

	void mousePressEvent(QMouseEvent * event);
	void mouseMoveEvent(QMouseEvent * event);
	void changeEvent(QEvent * event);
private:
	void setConnect();			//set ui signal and slot

	void setupTitleBarUi();
	void setupSelectUi();
	void setupNameUi();
	void setupTextUi();
	void setupChangedUi();

	void setLayoutUi(QLayout *);
private:
	QPoint				m_globalPos;		//mark start pos when move to calculate pos;
	QPoint				m_localPos;			//mark start pos used to move;

	WPS_WTitleBar		*m_titleBar;

	QLineEdit	*m_leftEdit;		//used to input file name
	QLineEdit	*m_rightEdit;
	QPushButton	*m_leftBtn;			//used to select file by dialog
	QPushButton	*m_rightBtn;
	QWidget		*m_selectWidget;	//used to add select control

	QLabel		*m_leftLabel;		//used to show file name;
	QLabel		*m_rightLabel;
	QWidget		*m_nameWidget;		//used to add name control

	QTextEdit	*m_leftText;		//used to show file content;
	QTextEdit	*m_rightText;
	QWidget		*m_textWidget;
	
	QTextEdit	*m_changeText;		//used to merge the defference between left file and right file
	QWidget		*m_changeWidget;
};


#endif

