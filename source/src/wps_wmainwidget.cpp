
#include "wps_wmainwidget.h"

#include "wps_wtitlebar.h"
#include "wps_common_manner.h"

#include <QMouseEvent>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QFileDialog>
#include <QFile>

const int LAYOUT_SPACING = 0;				//set the spacing of layout;

const int MARGIN_TOP = 0;
const int MARGIN_BOTTOM = 0;
const int MARGIN_LEFT = 10;
const int MARGING_RIGHT = 10;

WPS_WMainWidget::WPS_WMainWidget(QWidget * parent): QWidget(parent)
{
	m_leftFileName = "";
	m_rightFileName = "";
	m_changedFileName = "";

	setupUi();
}

WPS_WMainWidget::~WPS_WMainWidget()
{
}

void WPS_WMainWidget::setupTitleBarUi()
{
	//set title bar
	m_titleBar = new WPS_WTitleBar;
	m_titleBar->setObjectName("m_titleBar");

	QLayout *layout = m_titleBar->layout();
	setLayoutUi(layout);
}

void WPS_WMainWidget::setupSelectUi()
{
	//set select file layout
	QHBoxLayout *selectFileLayout = new QHBoxLayout;
	setLayoutUi(selectFileLayout);
	
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

	m_leftClearBtn= new QPushButton;
	m_leftClearBtn->setObjectName("m_leftClearBtn");
	m_leftClearBtn->setFocusPolicy(Qt::NoFocus);
	m_leftClearBtn->setVisible(false);

	m_rightClearBtn= new QPushButton;
	m_rightClearBtn->setObjectName("m_rightClearBtn");
	m_rightClearBtn->setFocusPolicy(Qt::NoFocus);
	m_rightClearBtn->setVisible(false);
	

	selectFileLayout->addWidget(m_leftEdit);
	selectFileLayout->addSpacing(1);
	selectFileLayout->addWidget(m_leftBtn);
	selectFileLayout->addWidget(m_leftClearBtn);
	selectFileLayout->addSpacing(5);
	selectFileLayout->addWidget(m_rightEdit);
	selectFileLayout->addSpacing(1);
	selectFileLayout->addWidget(m_rightBtn);
	selectFileLayout->addWidget(m_rightClearBtn);
	selectFileLayout->addSpacing(5);

	m_selectWidget = new QWidget;
	m_selectWidget->setObjectName("m_selectWidget");
	m_selectWidget->setLayout(selectFileLayout);
}

void WPS_WMainWidget::setupNameUi()
{
	//set file name layout;
	QHBoxLayout *fileNameLayout = new QHBoxLayout;
	setLayoutUi(fileNameLayout);

	m_leftLabel = new QLabel;
	m_leftLabel->setObjectName("m_leftLabel");

	m_rightLabel = new QLabel;
	m_rightLabel->setObjectName("m_leftLabel");

	fileNameLayout->addWidget(m_leftLabel);
	fileNameLayout->addWidget(m_rightLabel);

	m_nameWidget = new QWidget;
	m_nameWidget->setObjectName("m_selectWidget");
	m_nameWidget->setLayout(fileNameLayout);
}

void WPS_WMainWidget::setupTextUi()
{
	//set file content layout;
	QHBoxLayout	*textLayout = new QHBoxLayout;
	setLayoutUi(textLayout);

	m_leftText = new QTextEdit;
	m_leftText->setObjectName("m_leftText");

	m_rightText= new QTextEdit;
	m_rightText->setObjectName("m_rightText");

	textLayout->addWidget(m_leftText);
	textLayout->addWidget(m_rightText);

	m_textWidget = new QWidget;
	m_textWidget->setObjectName("m_textWidget");
	m_textWidget->setLayout(textLayout);
}

void WPS_WMainWidget::setupChangedUi()
{
	//set file content layout;
	QHBoxLayout	*changedLayout = new QHBoxLayout;
	setLayoutUi(changedLayout);

	m_changeText = new QTextEdit;
	m_changeText->setObjectName("m_changeText");

	changedLayout->addWidget(m_changeText);

	m_changeWidget = new QWidget;
	m_changeWidget->setObjectName("m_changeWidget");
	m_changeWidget->setLayout(changedLayout);
}

void WPS_WMainWidget::setLayoutUi(QLayout *layout)
{
	layout->setSpacing(LAYOUT_SPACING);
	layout->setContentsMargins(MARGIN_LEFT, MARGIN_TOP, MARGING_RIGHT, MARGIN_BOTTOM);
}


void WPS_WMainWidget::setupUi()
{
	QVBoxLayout *mainLayout = new QVBoxLayout(this);

	setupTitleBarUi();
	setupSelectUi();
	setupNameUi();
	setupTextUi();
	setupChangedUi();

	if (!(NULL == m_titleBar)) {
		mainLayout->addWidget(m_titleBar);
	}

	if (!(NULL == m_selectWidget)) {
		mainLayout->addWidget(m_selectWidget);
	}

	if (!(NULL == m_nameWidget)) {
		mainLayout->addWidget(m_nameWidget);
	}

	if (!(NULL == m_textWidget)) {
		mainLayout->addWidget(m_textWidget);
	}

	if (!(NULL == m_changeWidget)) {
		mainLayout->addWidget(m_changeText);
	}
	
	mainLayout->setSpacing(0);
	mainLayout->setContentsMargins(0, 0, 0, 0);
	
	setWindowFlags(Qt::FramelessWindowHint);
	setAttribute(Qt::WA_DeleteOnClose);

	setFocus();
	setFocusProxy(m_leftEdit);
	
	retranslateUi();
	setConnect();
}

void WPS_WMainWidget::retranslateUi()
{
	if (!(NULL == m_titleBar)) {
		m_titleBar->setTitle("WPS CMP File");
	}
	
	if (!(NULL == m_leftBtn)) {
		m_leftBtn->setText(tr("选择"));
	}

	if (!(NULL == m_rightBtn)) {
		m_rightBtn->setText(tr("选择"));
	}

	if (!(NULL == m_leftClearBtn)) {
		m_leftClearBtn->setText(tr("清除"));
	}

	if (!(NULL == m_rightClearBtn)) {
		m_rightClearBtn->setText(tr("清除"));
	}

	if (!(NULL == m_leftEdit)) {
		m_leftEdit->setPlaceholderText(tr("请您输入或选择文件路径按回车"));
	}

	if (!(NULL == m_rightEdit)) {
		m_rightEdit->setPlaceholderText(tr(""));
		m_rightEdit->setPlaceholderText(tr("请您输入或选择文件路径按回车"));
	}
}

void WPS_WMainWidget::setConnect()
{
	if (!(NULL == m_titleBar)) {
		connect(m_titleBar, SIGNAL(sigClose()), this, SLOT(close()));
		connect(m_titleBar, SIGNAL(sigMin()), this, SLOT(showMinimized()));
	}

	if (!(NULL == m_leftEdit)) {
		connect(m_leftEdit, SIGNAL(returnPressed()), this, SLOT(slotReturnPressed()));
	}

	if (!(NULL == m_rightEdit)) {
		connect(m_rightEdit, SIGNAL(returnPressed()), this, SLOT(slotReturnPressed()));
	}

	if (!(NULL == m_leftBtn)) {
		connect(m_leftBtn, SIGNAL(clicked()), this, SLOT(slotClicked()));
	}

	if (!(NULL == m_rightBtn)) {
		connect(m_rightBtn, SIGNAL(clicked()), this, SLOT(slotClicked()));
	}

	if (!(NULL == m_leftClearBtn)) {
		connect(m_leftClearBtn, SIGNAL(clicked()), this, SLOT(slotClear()));
	}

	if (!(NULL == m_rightClearBtn)) {
		connect(m_rightClearBtn, SIGNAL(clicked()), this, SLOT(slotClear()));
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

void WPS_WMainWidget::slotReturnPressed()
{
	QObject *senderObj = sender();
	QLineEdit * edit = dynamic_cast<QLineEdit *>(senderObj);

	if (NULL == edit) {
		return;
	}

	QString fileName = edit->text();
	if (fileName.isEmpty()) {
		fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "~/project/wps/source");
	}

	if (fileName.isEmpty()) {
		return;
	}

	if (m_leftEdit == senderObj) {
		m_leftFileName = fileName;
		updateLeftUi();
	} else {
		m_rightFileName = fileName;
		updateRightUi();
	}

}

void WPS_WMainWidget::slotClicked()
{
	QObject *senderObj = sender();
	QString fileName = "";

	fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "~/project/wps/source");

	if (fileName.isEmpty()) {
		return;
	}

	if (m_leftBtn== senderObj) {
		m_leftFileName = fileName;
		updateLeftUi();
	} else {
		m_rightFileName = fileName;
		updateRightUi();
	}
}

void WPS_WMainWidget::slotClear()
{
	QObject *senderObj = sender();
	
	if (m_leftClearBtn == senderObj) {
		m_leftFileName = "";
		updateLeftUi();
	} else {
		m_rightFileName = "";
		updateRightUi();
	}
}

void WPS_WMainWidget::updateLeftUi()
{
	if (m_leftFileName.isEmpty()) {
		m_leftLabel->setText("");
		m_leftEdit->clear();
		m_leftText->clear();
		m_leftBtn->setVisible(true);
		m_leftClearBtn->setVisible(false);
		return;
	}

	m_leftBtn->setVisible(false);
	m_leftClearBtn->setVisible(true);

	m_leftEdit->setText(m_leftFileName);
	m_leftLabel->setText(m_leftFileName);

	QFile leftFile(m_leftFileName);
	if (!leftFile.exists()) {
		m_leftFileName = "";
		return updateLeftUi();		
	}
	leftFile.open(QFile::ReadOnly);
	m_leftText->setText(QString(leftFile.readAll()));
	leftFile.close();

	updateChangedUi();
}

void WPS_WMainWidget::updateRightUi()
{
	if (m_rightFileName.isEmpty()) {
		m_rightLabel->setText("");
		m_rightEdit->clear();
		m_rightText->clear();
		m_rightBtn->setVisible(true);
		m_rightClearBtn->setVisible(false);
		return;
	}

	m_rightBtn->setVisible(false);
	m_rightClearBtn->setVisible(true);
	m_rightEdit->setText(m_rightFileName);
	m_rightLabel->setText(m_rightFileName);

	QFile rightFile(m_rightFileName);
	if (!rightFile.exists()) {
		m_rightFileName = "";
		return updateRightUi();		
	}
	rightFile.open(QFile::ReadOnly);
	m_rightText->setText(QString(rightFile.readAll()));
	rightFile.close();

	updateChangedUi();
}

#include <QtDebug>
void WPS_WMainWidget::updateChangedUi()
{
	if (m_changedFileName.isEmpty()) {
		m_changedFileName = WPS_Common_Manner::random_fileName();
	} else {
		QFile::remove(m_changedFileName);
		m_changeText->clear();
	}
	WPS_Common_Manner::wps_cmp_file(m_leftFileName, m_rightFileName, m_changedFileName);

	qDebug() << "before set text....";
	QFile file(m_changedFileName);
	if (!file.exists()) {
		m_changeText->clear();
		return;
	}
	qDebug() << "file exists !";
	file.open(QFile::ReadOnly);
	m_changeText->setText(QString(file.readAll()));
	file.close();
}




