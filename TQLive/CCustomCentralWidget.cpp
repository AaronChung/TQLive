#include "CCustomCentralWidget.h"
#include <QPainter>
#include <QStyleOption>
#include <QMouseEvent>
#include <windows.h>
#include <windowsx.h>

#define REDRAW_RT_NUM 2

CCustomCentralWidget::CCustomCentralWidget(QWidget *parent)
	: QWidget(parent)
{
	//m_bouderWidth = 5;
	setAttribute(Qt::WA_OpaquePaintEvent);
}

CCustomCentralWidget::~CCustomCentralWidget()
{
}

void CCustomCentralWidget::paintEvent(QPaintEvent *event)
{
	//QMainWindow::paintEvent(event);
	QStyleOption option;
	option.init(this);

	QRect rc = event->rect();

	int x = rc.x();

	QPainter painter(this);
	style()->drawPrimitive(QStyle::PE_Widget, &option, &painter, this);

	//m_shadowFrame.Draw(this);

	//QPainter painter(this);
	//painter.setRenderHint(QPainter::Antialiasing);  // �����;

	QRect rect = this->rect();

	////QPen pen(QColor(47, 47, 47));
	//QPen pen(QColor(255, 0, 0));
	//pen.setWidth(5);
	//pen.setStyle(Qt::SolidLine);
	//painter.setPen(pen);

	//

	//painter.drawLine(0, 2, rect.width(), 2);
	////painter.drawLine(0, 0, 0, 50);
	//painter.drawLine(rect.width() - 3, 0, rect.width() - 3, 50);

	QBrush brush(QColor(38, 38, 38));
	painter.setBrush(brush);
	painter.setPen(Qt::NoPen);

	QRect szRect[REDRAW_RT_NUM] = {
		QRect(250, 50, 5, rect.height()),
		QRect(rect.width() - 5, 50, 5, rect.height()),
	};

	painter.drawRects(szRect, sizeof(szRect) / sizeof(QRect));
}

//bool CCustomCentralWidget::nativeEvent(const QByteArray &eventType, void *message, long *result)
//{
//#ifdef Q_OS_WIN
//	MSG* msg = (MSG*)message;
//	switch (msg->message)
//	{
//	case WM_NCHITTEST:
//		int xPos = GET_X_LPARAM(msg->lParam) - this->frameGeometry().x();
//		int yPos = GET_Y_LPARAM(msg->lParam) - this->frameGeometry().y();
//		int nUseFulWidth = width() - m_bouderWidth;
//		int nUseFulHeight = height() - m_bouderWidth;
//		if (xPos < m_bouderWidth && yPos < m_bouderWidth)	//���Ͻ�
//			*result = HTTOPLEFT;
//		else if (xPos >= nUseFulWidth && yPos < m_bouderWidth)	//���Ͻ�
//			*result = HTTOPRIGHT;
//		else if (xPos < m_bouderWidth && yPos >= nUseFulHeight)	//���½�
//			*result = HTBOTTOMLEFT;
//		else if (xPos >= nUseFulWidth && yPos >= nUseFulHeight)	//���½�
//			*result = HTBOTTOMRIGHT;
//		else if (xPos < m_bouderWidth)	//���
//			*result = HTLEFT;
//		else if (xPos >= nUseFulWidth)	//�ұ�
//			*result = HTRIGHT;
//		else if (yPos < m_bouderWidth)	//�ϱ�
//			*result = HTTOP;
//		else if (yPos >= nUseFulHeight)	//�±�
//			*result = HTBOTTOM;
//		else
//			return false;
//
//		return true;
//	}
//#endif
//	return QWidget::nativeEvent(eventType, message, result);	//�˴�����false�����������¼�����������
//
//}
//
//void CCustomCentralWidget::mousePressEvent(QMouseEvent *e)
//{
//#ifdef Q_OS_WIN
//	if (e->button() == Qt::LeftButton)
//		m_curPos = e->pos();
//#endif
//	return QWidget::mousePressEvent(e);
//}
//void CCustomCentralWidget::mouseMoveEvent(QMouseEvent *e)
//{
//#ifdef Q_OS_WIN
//	if (e->buttons() & Qt::LeftButton)
//		((QWidget *)this->parent())->move(e->pos() + pos() - m_curPos);
//#endif
//	return QWidget::mouseMoveEvent(e);
//}