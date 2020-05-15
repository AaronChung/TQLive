/***********************************************************************************
*								RedEnvelopeDlg.cpp
*
* Copyright(C):	����̽������Ƽ����޹�˾
*
* Author:  �����
*
* Date: 2019-09
*
* Description: ������ܶԻ���
***********************************************************************************/

#include "RedEnvelopeDlg.h"
#include "FramelessHelper.h"
#include "EnumData.h"

#include <QIntValidator>
#include <QMessageBox>

RedEnvelopeDlg::RedEnvelopeDlg(QWidget *parent)
	: QDialog(parent)
	, m_curr_balance(0)
	, m_pTQPayConfirmDlg(NULL)
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

RedEnvelopeDlg::~RedEnvelopeDlg()
{

}

void RedEnvelopeDlg::onRechargeClicked()
{

}

void RedEnvelopeDlg::onConfirmClicked()
{
	if (ui.lineEdit_amount->text().isEmpty())
	{
		ui.lineEdit_amount->setFocus();
		QMessageBox::warning(this, QStringLiteral("����"), QStringLiteral("����ܽ���Ϊ�գ�"));
		return;
	}
	else if (ui.lineEdit_amount->text().toInt() == 0)
	{
		ui.lineEdit_amount->setFocus();
		ui.lineEdit_amount->clear();
		QMessageBox::warning(this, QStringLiteral("����"), QStringLiteral("����ܽ���Ϊ0��"));
		return;
	}
	else if (ui.lineEdit_amount->text().toInt() > m_curr_balance)
	{
		ui.lineEdit_amount->setFocus();
		ui.lineEdit_amount->clear();
		QMessageBox::warning(this, QStringLiteral("����"), QStringLiteral("��ǰ���㣡"));
		return;
	}
	else if (ui.lineEdit_number->text().isEmpty())
	{
		ui.lineEdit_number->setFocus();
		QMessageBox::warning(this, QStringLiteral("����"), QStringLiteral("�����������Ϊ�գ�"));
		return;
	}
	else if (ui.lineEdit_number->text().toInt() == 0)
	{
		ui.lineEdit_number->setFocus();
		ui.lineEdit_number->clear();
		QMessageBox::warning(this, QStringLiteral("����"), QStringLiteral("�����������Ϊ0��"));
		return;
	}
	else if (ui.lineEdit_number->text().toInt() > ui.lineEdit_amount->text().toInt())
	{
		ui.lineEdit_number->setFocus();
		ui.lineEdit_number->clear();
		QMessageBox::warning(this, QStringLiteral("����"), QStringLiteral("����������ܳ�������ܽ�"));
		return;
	}
	else if (ui.lineEdit_title->text().isEmpty())
	{
		ui.lineEdit_title->setFocus();
		QMessageBox::warning(this, QStringLiteral("����"), QStringLiteral("���ⲻ��Ϊ�գ�"));
		return;
	}

	if (m_pTQPayConfirmDlg == NULL)
	{
		m_pTQPayConfirmDlg = new TQPayConfirmDlg(DIALOG_PAY_CONFIRM_SIMPLE_OPERATOR, this);
	}
	m_pTQPayConfirmDlg->exec();

	this->accept();
}

void RedEnvelopeDlg::InitUI()
{
	QIntValidator *intValidator = new QIntValidator;
	intValidator->setRange(1, 2000);
	ui.lineEdit_amount->setValidator(intValidator);
	ui.lineEdit_amount->setMaxLength(4);

	ui.lineEdit_number->setValidator(intValidator);
	ui.lineEdit_number->setMaxLength(4);

	ui.lineEdit_title->setMaxLength(10);

	ui.lbl_current_goldVal->setText(QStringLiteral("��ǰ��%1̽���").arg(m_curr_balance));
}

void RedEnvelopeDlg::InitConnect()
{
	connect(ui.btn_close, &QPushButton::clicked, this, &QDialog::close);
	connect(ui.btn_cancel, &QPushButton::clicked, this, &QDialog::reject);
	connect(ui.btn_confirm, SIGNAL(clicked()), this, SLOT(onConfirmClicked()));
	connect(ui.btn_recharge, SIGNAL(clicked()), this, SLOT(onRechargeClicked()));
}
