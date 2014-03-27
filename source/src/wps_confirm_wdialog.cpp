
#include "wps_confirm_wdialog.h"

#include "wps_wtitlebar.h"

#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>

WPS_Confirm_WDialog::WPS_Confirm_WDialog(QWidget *parent) : QDialog(parent)
{
	setupUi();
}

WPS_Confirm_WDialog::~WPS_Confirm_WDialog()
{
}

void WPS_Confirm_WDialog::setupUi() 	//to setup ui
{
	QVBoxLayout *mainLayout = new QVBoxLayout(this);
	QHBoxLayout	*buttonLayout = new QHBoxLayout;

	
	m_titleBar = new WPS_WTitleBar;
	m_titleBar->setObjectName("m_titleBar");

	m_title = new QLabel;
	m_confirmBtn = new QPushButton;
	m_cancelBtn = new QPushButton;
	QLabel *leftLabel = new QLabel;
	QLabel *centerLabel = new QLabel;
	QLabel *rightLabel = new QLabel;

	m_confirmBtn->setObjectName("m_confirmBtn");
	m_cancelBtn->setObjectName("m_cancelBtn");

	buttonLayout->addWidget(leftLabel);
	buttonLayout->addWidget(m_confirmBtn);
	buttonLayout->addWidget(centerLabel);
	buttonLayout->addWidget(m_cancelBtn);
	buttonLayout->addWidget(rightLabel);

	mainLayout->addWidget(m_titleBar);
	mainLayout->addWidget(m_title);
	mainLayout->addLayout(buttonLayout);

	buttonLayout->setSpacing(0);
	buttonLayout->setContentsMargins(0, 0, 0, 0);
	mainLayout->setSpacing(0);
	mainLayout->setContentsMargins(0, 0, 0, 0);

	setWindowFlags(Qt::FramelessWindowHint);

	retranslateUi();
	setConnect();
	
}

void WPS_Confirm_WDialog::retranslateUi()	//used for update to translate ui from one language to another
{
	if (!(NULL == m_confirmBtn)) {
		m_confirmBtn->setText("ok");
	}

	if (!(NULL == m_cancelBtn)) {
		m_cancelBtn->setText("cancel");
	}
}

void WPS_Confirm_WDialog::setConnect()
{
	if (!(NULL == m_confirmBtn)) {
		connect(m_confirmBtn, SIGNAL(clicked()), this, SLOT(accept()));
	}

	if (!(NULL == m_cancelBtn)) {
		connect(m_cancelBtn, SIGNAL(clicked()), this, SLOT(reject()));
	}

	if (!(NULL == m_titleBar)) {
		connect(m_titleBar, SIGNAL(sigClose()), this, SLOT(reject()));
		connect(m_titleBar, SIGNAL(sigMin()), this, SLOT(showMinimized()));
	}
}

void WPS_Confirm_WDialog::setTitle(const QString &title)
{
	m_title->setText("       " + title);
}




