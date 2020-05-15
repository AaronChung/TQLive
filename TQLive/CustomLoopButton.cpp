/***********************************************************************************
*								CustomLoopButton.cpp
*
* Copyright(C):	����̽������Ƽ����޹�˾
*
* Author:  �����
*
* Date: 2019-11
*
* Description: �Զ����б�ѭ����ť
***********************************************************************************/
#include "CustomLoopButton.h"

CustomLoopButton::CustomLoopButton(QWidget *parent)
	: QPushButton(parent)
	, m_nLoopType(LOOP_CYCLE)
{
	ui.setupUi(this);
}

CustomLoopButton::~CustomLoopButton()
{

}

void CustomLoopButton::setLoopType(int type)
{
	m_nLoopType = type;

	QString image;
	QString text;
	switch (m_nLoopType)
	{
	case LOOP_RANDOM:
		image = "video_icon_random_normal.png";
		text = QStringLiteral("���");
		break;
	case LOOP_SINGLE:
		image = "video_icon_a single_normal.png";
		text = QStringLiteral("����");
		break;
	case LOOP_CYCLE:
		image = "video_icon_cycle_normal.png";
		text = QStringLiteral("�б�");
		break;
	default:
		break;
	}

	ui.label->setText(text);
	ui.widget->setStyleSheet(QString("#label{ color:#EEEEEE; }  \
        #label_icon{ border-image:url(:/TQLive/images/%1); }").arg(image));
}

void CustomLoopButton::enterEvent(QEvent *event)
{
	Q_UNUSED(event)

	this->setCursor(Qt::PointingHandCursor);

	QString image;
	switch (m_nLoopType)
	{
	case LOOP_RANDOM:
		image = "video_icon_random_hover.png";
		break;
	case LOOP_SINGLE:
		image = "video_icon_a single_hover.png";
		break;
	case LOOP_CYCLE:
		image = "video_icon_cycle_hover.png";
		break;
	default:
		break;
	}
	ui.widget->setStyleSheet(QString("QLabel{ color:#4AB134; }  \
		#label_icon{ border-image: url(:/TQLive/images/%1); }").arg(image));
}

void CustomLoopButton::leaveEvent(QEvent * event)
{
	Q_UNUSED(event)

	this->setCursor(Qt::ArrowCursor);

	QString image;
	switch (m_nLoopType)
	{
	case LOOP_RANDOM:
		image = "video_icon_random_normal.png";
		break;
	case LOOP_SINGLE:
		image = "video_icon_a single_normal.png";
		break;
	case LOOP_CYCLE:
		image = "video_icon_cycle_normal.png";
		break;
	default:
		break;
	}
	ui.widget->setStyleSheet(QString("#label{ color:#EEEEEE; }  \
        #label_icon{ border-image:url(:/TQLive/images/%1); }").arg(image));
}
