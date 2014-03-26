
#include "wps_wtitlebar.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

WPS_WTitleBar::WPS_WTitleBar(QWidget *parent) : QWidget(parent)
{
	setupUi();
}

WPS_WTitleBar::~WPS_WTitleBar()
{
}

void WPS_WTitleBar::setupUi()		//to setup ui
{
	QHBoxLayout *mainLayout = new QHBoxLayout(this);
	QHBoxLayout *rightTopLayout = new QHBoxLayout;
	QVBoxLayout *rightLayout = new QVBoxLayout;
	
	m_titleLabel = new QLabel;
	m_closeBtn = new QPushButton;
	m_minBtn = new QPushButton;
	QLabel *spaceLabel = new QLabel;

	QWidget *spaceWidget = new QWidget;
	spaceWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

	m_titleLabel->setObjectName("m_titleLabel");
	m_closeBtn->setObjectName("m_closeBtn");
	m_minBtn->setObjectName("m_minBtn");

	m_closeBtn->setFocusPolicy(Qt::NoFocus);
	m_minBtn->setFocusPolicy(Qt::NoFocus);

	rightTopLayout->setSpacing(0);
	rightTopLayout->setContentsMargins(0, 0, 0, 0);
	rightLayout->setSpacing(0);
	rightLayout->setContentsMargins(0, 0, 0, 0);
	mainLayout->setSpacing(0);
	mainLayout->setContentsMargins(0, 0, 0, 0);
	
	
	rightTopLayout->addWidget(spaceWidget);
	rightTopLayout->addWidget(m_minBtn);
	rightTopLayout->addSpacing(5);
	rightTopLayout->addWidget(m_closeBtn);

	rightLayout->addLayout(rightTopLayout);
	rightLayout->addWidget(spaceLabel);

	mainLayout->addWidget(m_titleLabel);
	mainLayout->addLayout(rightLayout);
	
	retranslateUi();
	setConnect();
}

void WPS_WTitleBar::retranslateUi()	//used for update to translate ui from one language to another
{
}

void WPS_WTitleBar::setConnect()			//set ui signal and slot
{
	connect(m_minBtn, SIGNAL(clicked()), this, SLOT(slotClicked()));
	connect(m_closeBtn, SIGNAL(clicked()), this, SLOT(slotClicked()));
}

void WPS_WTitleBar::slotClicked()
{
	QObject * sendObj = sender();

	if (sendObj == m_minBtn) {
		emit sigMin();
	} else if (sendObj == m_closeBtn) {
		emit sigClose();
	}
}

void WPS_WTitleBar::setTitle(const QString & title)
{
	if (!(NULL == m_titleLabel)) {
		m_titleLabel->setText(title);
	}
}



