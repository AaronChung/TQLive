/***********************************************************************************
*								CustomMaterialButton.cpp
*
* Copyright(C):	����̽������Ƽ����޹�˾
*
* Author:  �����
*
* Date: 2019-10
*
* Description: �Զ����زİ�ť
***********************************************************************************/
#include "CustomMaterialButton.h"

CustomMaterialButton::CustomMaterialButton(MaterialTypeData materialTypeData, QWidget *parent)
	: QToolButton(parent)
	, m_pMaterialTypeData(materialTypeData)
{
	this->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

	InitStyle();
	InitUI();
	InitConnect();
}

CustomMaterialButton::~CustomMaterialButton()
{

}

void CustomMaterialButton::enterEvent(QEvent * event)
{
	Q_UNUSED(event)

	this->setIcon(QIcon(m_pMaterialTypeData.sHoverIcon));
}

void CustomMaterialButton::leaveEvent(QEvent * event)
{
	Q_UNUSED(event)

	this->setIcon(QIcon(m_pMaterialTypeData.sIcon));
}

void CustomMaterialButton::InitUI()
{
	this->setText(m_pMaterialTypeData.sName);
	this->setIcon(QIcon(m_pMaterialTypeData.sIcon));
	this->setIconSize(QSize(20, 18));
}

void CustomMaterialButton::InitConnect()
{
	connect(this, &QToolButton::clicked, this, [&]() {
		emit onCustomMaterialButtonActive(m_pMaterialTypeData.nType);
	});
}

void CustomMaterialButton::InitStyle()
{
	QString style = QString("QToolButton { \
                             background:transparent; \
                             border-radius:4px; \
                             font-family:%1; \
                             font-size:12px; \
                             color:#DCDCDC; \
                           } \
                           QToolButton:hover { \
                             background:#262626; \
                             color:#4AB134; \
                           }").arg(QStringLiteral("΢���ź�"));

	this->setStyleSheet(style);
}