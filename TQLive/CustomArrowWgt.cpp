/***********************************************************************************
*								CustomArrowWgt.cpp
*
* Copyright(C):	����̽������Ƽ����޹�˾
*
* Author:  �����
*
* Date: 2019-11
*
* Description: �Զ�������ǵ����ݴ���
***********************************************************************************/
#include "CustomArrowWgt.h"
#include <QPaintEvent>
#include <QPainter>
#include <QHBoxLayout>
#include <QGraphicsDropShadowEffect>
#include <QSound>

#define SHADOW_WIDTH 15                 // ������Ӱ���;
#define TRIANGLE_WIDTH 12               // С���ǵĿ��;
#define TRIANGLE_HEIGHT 6              // С���ǵĸ߶�;
#define BORDER_RADIUS 4                 // ���ڱ߽ǵĻ���;

CustomArrowWgt::CustomArrowWgt(QWidget *parent)
	: QDialog(parent)
	, m_nStartPosX((124 - TRIANGLE_WIDTH) / 2)
	, m_nTriangleW(TRIANGLE_WIDTH)
	, m_nTriangleH(TRIANGLE_HEIGHT)
{
	setWindowFlags(windowFlags() | Qt::FramelessWindowHint);
	this->setAttribute(Qt::WA_TranslucentBackground, true);

	// ������Ӱ�߿�;
	auto shadowEffect = new QGraphicsDropShadowEffect(this);
	shadowEffect->setOffset(0, 0);
	shadowEffect->setColor(Qt::gray);
	shadowEffect->setBlurRadius(SHADOW_WIDTH);
	this->setGraphicsEffect(shadowEffect);
	
	setFixedSize(124, 126);
}

CustomArrowWgt::~CustomArrowWgt()
{

}

void CustomArrowWgt::setStartPos(int startPosX)
{
	m_nStartPosX = startPosX;
}

void CustomArrowWgt::setTriangleInfo(int width, int height)
{
	m_nTriangleW = width;
	m_nTriangleH = height;
}

void CustomArrowWgt::setCenterWidget(QWidget * widget)
{
	QHBoxLayout *hMainLayout = new QHBoxLayout(this);
	hMainLayout->addWidget(widget);
	hMainLayout->setSpacing(0);
	hMainLayout->setContentsMargins(SHADOW_WIDTH, SHADOW_WIDTH + m_nTriangleH, SHADOW_WIDTH, SHADOW_WIDTH + m_nTriangleH);
}

void CustomArrowWgt::paintEvent(QPaintEvent *event)
{
	Q_UNUSED(event);

	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing, true);
	painter.setPen(Qt::NoPen);
	painter.setBrush(QColor("#333333"));

	QPolygon trianglePolygon;
	trianglePolygon << QPoint(m_nStartPosX, height() - SHADOW_WIDTH - m_nTriangleH);
	trianglePolygon << QPoint(m_nStartPosX + m_nTriangleW / 2, height() - SHADOW_WIDTH);
	trianglePolygon << QPoint(m_nStartPosX + m_nTriangleW, height() - SHADOW_WIDTH - m_nTriangleH);

	QPainterPath drawPath;
	drawPath.addRoundedRect(QRect(SHADOW_WIDTH, SHADOW_WIDTH, \
		width() - SHADOW_WIDTH * 2, height() - SHADOW_WIDTH * 2 - m_nTriangleH), \
		BORDER_RADIUS, BORDER_RADIUS);

	drawPath.addPolygon(trianglePolygon);
	painter.drawPath(drawPath);
}

void CustomArrowWgt::keyPressEvent(QKeyEvent *event)
{
	Q_UNUSED(event)

	if (event->key() == Qt::Key_1 && (event->modifiers() & Qt::ControlModifier)) {
		QSound::play(QStringLiteral("./Resource/����.wav"));
	}
	else if (event->key() == Qt::Key_2 && (event->modifiers() & Qt::ControlModifier)) {
		QSound::play(QStringLiteral("./Resource/����.wav"));
	}
	else if (event->key() == Qt::Key_3 && (event->modifiers() & Qt::ControlModifier)) {
		QSound::play(QStringLiteral("./Resource/����.wav"));
	}

	return QDialog::keyPressEvent(event);
}
