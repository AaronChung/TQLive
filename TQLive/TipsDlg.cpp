/***********************************************************************************
*								TipsDlg.cpp
*
* Copyright(C):	����̽������Ƽ����޹�˾
*
* Author:  �����
*
* Date: 2019-10
*
* Description: ͨ�õ�����ʾ�Ի���
***********************************************************************************/

#include "TipsDlg.h"
#include "EnumData.h"
#include "FramelessHelper.h"

TipsDlg::TipsDlg(int operatorType, QWidget *parent)
	: QDialog(parent)
	, m_pOperatorType(operatorType)
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

TipsDlg::~TipsDlg()
{

}

void TipsDlg::setText(const QString & text)
{
	ui.lbl_content->setText(text);
}

void TipsDlg::setTitle(const QString &title)
{
	ui.lbl_tip->setText(title);
}

void TipsDlg::showEvent(QShowEvent *event)
{
	Q_UNUSED(event)
}

void TipsDlg::InitConnect()
{
	connect(ui.btn_close, &QPushButton::clicked, this, &TipsDlg::close);
	connect(ui.btn_cancel, &QPushButton::clicked, this, &TipsDlg::reject);
	connect(ui.btn_confirm, &QPushButton::clicked, this, &TipsDlg::accept);
}

void TipsDlg::InitUI()
{
	QString sText;
	switch (m_pOperatorType)
	{
	case DIALOG_CANCEL_FORBIDDEN_OPERATOR:
		sText = QStringLiteral("ȷ�Ͻ��������");
		break;
	case DIALOG_DELETE_ROOMMANAGER_OPERATOR:
		sText = QStringLiteral("ȷ��ɾ��������");
		break;
	case DIALOG_LOGOUT_ACCOUNT_OPERATOR:
		sText = QStringLiteral("�Ƿ�ȷ���˳���¼��");
		break;
	case DIALOG_IDENTITY_TIPS_OPERATOR:
		sText = QStringLiteral("����û�������ʸ�!");
		ui.btn_confirm->setStyleSheet("#btn_confirm{background-image:url(:/TQLive/images/apply.png);background-repeat:no-repeat;border:none;} \
                       #btn_confirm:pressed{margin:1px;padding:1px;}");
		ui.lbl_tip->setText(QStringLiteral("���������ʾ"));
		break;
	case DIALOG_INSTANCE_EXIST_OPERATOR:
		sText = QStringLiteral("̽��ֱ�������������С�");
		ui.lbl_tip->setText(QStringLiteral("̽��ֱ������"));
		ui.btn_cancel->setHidden(true);
		break;
	default:
		break;
	}

	ui.lbl_content->setText(sText);
}
