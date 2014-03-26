
#include "wps_wmainwidget.h"

#include "wps_wtitlebar.h"

#include <QMouseEvent>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>


WPS_WMainWidget::WPS_WMainWidget(QWidget * parent): QWidget(parent)
{
	setupUi();
}

WPS_WMainWidget::~WPS_WMainWidget()
{
}

void WPS_WMainWidget::setupUi()
{
	QVBoxLayout *mainLayout = new QVBoxLayout(this);

	//set title bar
	m_titleBar = new WPS_WTitleBar;
	m_titleBar->setObjectName("m_titleBar");
	mainLayout->addWidget(m_titleBar);

	//add spaceing to set left and right contro in center
	QWidget *topSpaceWidget = new QWidget;
	topSpaceWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	mainLayout->addWidget(topSpaceWidget);


	//set select file layout
	QHBoxLayout *selectFileLayout = new QHBoxLayout;
	selectFileLayout->setSpacing(0);
	selectFileLayout->setContentsMargins(0, 0, 0, 0);
	
	m_leftEdit = new QLineEdit;
	m_leftEdit->setObjectName("m_leftEdit");

	m_rightEdit = new QLineEdit;
	m_rightEdit->setObjectName("m_rightEdit");

	m_leftBtn = new QPushButton;
	m_leftBtn->setObjectName("m_leftBtn");
	m_leftBtn->setFocusPolicy(Qt::NoFocus);

	m_rightBtn= new QPushButton;
	m_rightBtn->setObjectName("m_leftBtn");
	m_rightBtn->setFocusPolicy(Qt::NoFocus);

	selectFileLayout->addWidget(m_leftEdit);
	selectFileLayout->addSpacing(1);
	selectFileLayout->addWidget(m_leftBtn);
	selectFileLayout->addSpacing(5);
	selectFileLayout->addWidget(m_rightEdit);
	selectFileLayout->addSpacing(1);
	selectFileLayout->addWidget(m_rightBtn);
	selectFileLayout->addSpacing(5);

	m_selectWidget = new QWidget;
	m_selectWidget->setObjectName("m_selectWidget");
	m_selectWidget->setLayout(selectFileLayout);

	mainLayout->addWidget(m_selectWidget);


	//set file name layout;
	QHBoxLayout *fileNameLayout = new QHBoxLayout;
	fileNameLayout->setSpacing(0);
	fileNameLayout->setContentsMargins(0, 0, 0, 0);

	m_leftLabel = new QLabel;
	m_leftLabel->setObjectName("m_leftLabel");

	m_rightLabel = new QLabel;
	m_rightLabel->setObjectName("m_leftLabel");

	fileNameLayout->addWidget(m_leftLabel);
	fileNameLayout->addWidget(m_rightLabel);

	m_nameWidget = new QWidget;
	m_nameWidget->setObjectName("m_selectWidget");
	m_nameWidget->setLayout(fileNameLayout);

	mainLayout->addWidget(m_nameWidget);


	//set file content layout;
	QHBoxLayout	*textLayout = new QHBoxLayout;
	textLayout->setSpacing(0);
	textLayout->setContentsMargins(0, 0, 0, 0);

	m_leftText = new QTextEdit;
	m_leftText->setObjectName("m_leftText");

	m_rightText= new QTextEdit;
	m_rightText->setObjectName("m_rightText");

	textLayout->addWidget(m_leftText);
	textLayout->addWidget(m_rightText);

	m_textWidget = new QWidget;
	m_textWidget->setObjectName("m_textWidget");
	m_textWidget->setLayout(textLayout);

	mainLayout->addWidget(m_textWidget);


	m_changeText = new QTextEdit;
	m_changeText->setObjectName("m_changeText");
	
	mainLayout->addWidget(m_changeText);
	

	QWidget *bottomSpaceWidget = new QWidget;
	bottomSpaceWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	mainLayout->addWidget(bottomSpaceWidget);

	
	mainLayout->setSpacing(0);
	mainLayout->setContentsMargins(10, 0, 10, 0);

	
	
	setWindowFlags(Qt::FramelessWindowHint);
	setAttribute(Qt::WA_DeleteOnClose);
	
	retranslateUi();
	setConnect();
}

void WPS_WMainWidget::retranslateUi()
{
	if (!(NULL == m_titleBar)) {
		m_titleBar->setTitle("WPS CMP File");
	}
	
	if (!(NULL == m_leftBtn)) {
		m_leftBtn->setText("Select");
	}

	if (!(NULL == m_rightBtn)) {
		m_rightBtn->setText("Select");
	}
}

void WPS_WMainWidget::setConnect()
{
	if (!(NULL == m_titleBar)) {
		connect(m_titleBar, SIGNAL(sigClose()), this, SLOT(close()));
		connect(m_titleBar, SIGNAL(sigMin()), this, SLOT(showMinimized()));
	}
}

void WPS_WMainWidget::mousePressEvent(QMouseEvent * event)
{
	if (Qt::LeftButton == event->button()) {
		m_localPos = this->pos();
		m_globalPos = event->globalPos();
	}

	QWidget::mousePressEvent(event);
}

void WPS_WMainWidget::mouseMoveEvent(QMouseEvent * event)
{
	if (Qt::LeftButton == event->buttons()) {
		QPoint pos = event->globalPos();		
		int x = pos.x()- m_globalPos.x();
		int y = pos.y()- m_globalPos.y();

		m_globalPos = pos;
		m_localPos.setX(m_localPos.x()+ x);
		m_localPos.setY(m_localPos.y() + y);
		move(m_localPos);
	}
	
	QWidget::mouseMoveEvent(event);
}

void WPS_WMainWidget::changeEvent(QEvent * event)
{
	QWidget::changeEvent(event);
	
    switch (event->type()) {
    	case QEvent::LanguageChange:
        	retranslateUi();
        	break;
    	default:
        	break;
    }
}





