/***********************************************************************************
*								SystemSettingsDlg.cpp
*
* Copyright(C):	����̽������Ƽ����޹�˾
*
* Author:  �����
*
* Date: 2019-09
*
* Description: ���õ����˵�
***********************************************************************************/
#include "SystemSettingsDlg.h"

SystemSettingsDlg::SystemSettingsDlg(QWidget *parent)
	: QDialog(parent)
	, m_pTQLiveAboutDlg(NULL)
{
	ui.setupUi(this);
	setWindowFlags(windowFlags() | Qt::FramelessWindowHint);
	this->setAttribute(Qt::WA_TranslucentBackground, true);
	this->setFixedHeight(122);

	InitConnect();

	/*���ز��ֹ��ܣ����ڿ���*/
	ui.btn_help->hide();
	ui.btn_customer->hide();
	ui.btn_feedback->hide();
	ui.btn_specification->hide();
}

SystemSettingsDlg::~SystemSettingsDlg()
{

}

void SystemSettingsDlg::InitConnect()
{
	connect(ui.btn_about, &QToolButton::clicked, this, [&]() {
		emit onSigShowAboutDlg();
	});

	connect(ui.btn_settings, &QPushButton::clicked, this, [&]() {
		emit onSigShowSettingsIniDlg();
	});

	connect(ui.btn_logout, &QPushButton::clicked, this, [&]() {
		emit onSigShowLogoutDlg();
	});

	connect(ui.btn_feedback, &QPushButton::clicked, this, [&]() {
		emit onSigShowFeedbackDlg();
	});
}
