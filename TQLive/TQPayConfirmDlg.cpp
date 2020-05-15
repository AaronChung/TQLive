/***********************************************************************************
*								TQPayConfirmDlg.cpp
*
* Copyright(C):	����̽������Ƽ����޹�˾
*
* Author:  �����
*
* Date: 2019-09
*
* Description: ֧��ȷ�϶Ի���
***********************************************************************************/
#include "TQPayConfirmDlg.h"
#include "EnumData.h"
#include "FramelessHelper.h"

#include <QMessageBox>

TQPayConfirmDlg::TQPayConfirmDlg(int operatorType, QWidget *parent)
	: QDialog(parent)
	, m_nOperatorType(operatorType)
{
	ui.setupUi(this);
	setWindowFlags(windowFlags() | Qt::FramelessWindowHint);
	this->setAttribute(Qt::WA_TranslucentBackground, true);

	FramelessHelper *helper = new FramelessHelper;
	helper->activateOn(this);
	helper->setDbClickOn(false);
	helper->setWidgetResizable(false);

	InitUI();
	InitConnect();
}

TQPayConfirmDlg::~TQPayConfirmDlg()
{

}

void TQPayConfirmDlg::onPayConfirmClicked()
{
	if (ui.lineEdit_pay_passwd->text().isEmpty())
	{
		ui.lineEdit_pay_passwd->setFocus();
		QMessageBox::warning(this, QStringLiteral("����"), QStringLiteral("�����뽻�����룡"));
	}

	QMessageBox *messageBox = new QMessageBox(this);
	messageBox->setIcon(QMessageBox::Information);
	messageBox->setWindowTitle(QStringLiteral("�����ɹ�"));
	messageBox->setText(QStringLiteral("������ͳɹ���"));
	messageBox->addButton(QStringLiteral("ȷ��"), QMessageBox::AcceptRole);
	messageBox->exec();

	this->accept();
}

void TQPayConfirmDlg::onRechargeClicked()
{

}

void TQPayConfirmDlg::InitUI()
{
	if (m_nOperatorType == DIALOG_PAY_CONFIRM_SIMPLE_OPERATOR)
	{
		ui.wgt_header->setHidden(true);
	}
	else if (m_nOperatorType == DIALOG_PAY_CONFIRM_COMPLEX_OPERATOR)
	{
		ui.wgt_header->setHidden(false);
	}
}
void TQPayConfirmDlg::InitConnect()
{
	connect(ui.btn_close, &QPushButton::clicked, this, &QDialog::close);
	connect(ui.btn_cancel, &QPushButton::clicked, this, &QDialog::reject);
	connect(ui.btn_confirm, SIGNAL(clicked()), this, SLOT(onPayConfirmClicked()));
	connect(ui.btn_recharge, SIGNAL(clicked()), this, SLOT(onRechargeClicked()));
}

