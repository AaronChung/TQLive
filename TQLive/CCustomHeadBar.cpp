#include "stdafx.h"
#include "CCustomHeadBar.h"
#include "CScaleSize.h"

CCustomHeadBar::CCustomHeadBar(QWidget *parent)
	: QWidget(parent)
	, m_bMoveSwitch(true)
	, m_qsBkImageFilePath("")
	, m_bMousePressMark(false)
{
	this->setMouseTracking(m_bMoveSwitch);
	m_bkColor = QColor(47, 47, 47, 255);						// ͸��ͨ��������ɫ��һ��
	m_pHostWidget = parent;
	//this->setAttribute(Qt::WA_StaticContents);
}

void CCustomHeadBar::SetBkImageFilePath(const QString &qsFilePath)
{
	m_qsBkImageFilePath = qsFilePath;
}

void CCustomHeadBar::mousePressEvent(QMouseEvent *event)
{  
	if (m_bMoveSwitch)										// �Ƿ����������϶�����
	{
		if (event->button() == Qt::LeftButton)
		{
			m_ptCursorStartPos = event->globalPos();		// �������ڴ����λ�ã�����ʹ��event->globalPos() - this->pos()��// ���λ��
			m_bMousePressMark = true;
		}
	}
	
	// ����QWidget���ִ��벻��ִ�У����ܳ���Ī������Ĵ���
	QWidget::mousePressEvent(event);
}

// QWidget��ʽ���õ���QPalette����ʧЧ
void CCustomHeadBar::SetBkColor(const QColor &bkColor)
{
	m_bkColor = bkColor;
	
	//QPalette palette(this->palette());
	//palette.setColor(QPalette::Background, m_bkColor);
	//this->setAutoFillBackground(true);
	//this->setPalette(palette);
}

void CCustomHeadBar::SetHostWindow(QWidget *pWidget)
{
	m_pHostWidget = pWidget;

}

void CCustomHeadBar::mouseMoveEvent(QMouseEvent *event)
{
	// �ƶ����ش򿪲������������µ�λ���Ƿ��ӿؼ����� �ƶ�������
	// �����������λ��Ϊ�ӿؼ����� �϶�λ��Ϊ��������������
	//if (m_bMoveSwitch && m_bMousePressMark)
	//{
	//	//QWidget *parent = (QWidget *)this->parent();

	//	if (m_pHostWidget)
	//	{
	//		QPoint ptCursorMovePos = event->globalPos();							
	//		QPoint ptDstPos = m_pHostWidget->pos() + (ptCursorMovePos - m_ptCursorStartPos);

	//		QDesktopWidget *pDesk = QApplication::desktop();
	//		int nWorkAreaWidth = pDesk->availableGeometry().width();
	//		int nWorkAreaHeight = pDesk->availableGeometry().height();

	//		//if (ptDstPos.x() > -(m_pMoveWidget->rect().width() - 20) && ptDstPos.x() < nWorkAreaWidth - 20 && ptDstPos.y() > 20 && ptDstPos.y() < nWorkAreaHeight - 20)
	//		//{
	//		//	m_pMoveWidget->move(ptDstPos);
	//		//	m_ptCursorStartPos = ptCursorMovePos;
	//		//}

	//		// �Ƿ���Ҫ���ҡ��¸�Ԥ��������һ�����򵯳�ģ̬�Ի���ʱ
	//		//QRect rcOriginScope(QPoint(-(parent->rect().width() - 20), 20), QPoint(nWorkAreaWidth - 20,  nWorkAreaHeight - 20));
	//		/*if (rcOriginScope.contains(ptDstPos))
	//		{
	//			parent->move(ptDstPos);
	//			m_ptCursorStartPos = ptCursorMovePos;
	//		}*/
	//		//else
	//		//{
	//		//	m_pMoveWidget->move((nWorkAreaWidth - m_pMoveWidget->width()) / 2, (nWorkAreaHeight - m_pMoveWidget->height()) / 2);
	//		//	m_ptCursorStartPos.setX((nWorkAreaWidth - m_pMoveWidget->width()) / 2);
	//		//	m_ptCursorStartPos.setY((nWorkAreaHeight - m_pMoveWidget->height()) / 2);
	//		//}

	//		//if (ptDstPos.x() < 0)
	//		//{
	//		//	qDebug("test. parent->pos():%d Delta:%d", parent->pos().x(), ptCursorMovePos.x() - m_ptCursorStartPos.x());
	//		//}

	//		m_pHostWidget->move(ptDstPos);
	//		m_ptCursorStartPos = ptCursorMovePos;
	//	}
	//}

	//// ע��:��ֹ�¼����ݵ������
	//QWidget::mouseMoveEvent(event);						// �����OBSBasic�д���mouseMoveEvent�¼�

	//if (m_bMousePressMark)
	//{
	//	//QRect rcWndArea = this->rect();
	//	//rcWndArea.adjust(5, 5, -5, 0);
	//	//if (rcWndArea.contains(event->pos(), false))
	//	//{
	//	//	// ���Ŵ���
	//	//	QWidget::mouseMoveEvent(event);
	//	//}
	//	//else
	//	//{

	//	//}


	//}

	QPoint ptCursorPos = event->globalPos();

	//qDebug("x:%d y:%d", ptCursorPos.x(), ptCursorPos.y());

	EN_ZONE_TYPE eZoneType = CScaleSize::CalcCursorLocation(this, event->pos());

	int nMinimumWidth = m_pHostWidget->minimumWidth();
	int nMinimumHeight = m_pHostWidget->minimumHeight();

	switch (eZoneType)
	{
	case CENTRE:
	case LEFTBOTTOM:
	case BOTTOM:
	case RIGHTBOTTOM:
	{
		this->setCursor(QCursor(Qt::ArrowCursor));

		if (m_bMoveSwitch && m_bMousePressMark)
		{
			QPoint ptDstPos = m_pHostWidget->pos() + (ptCursorPos - m_ptCursorStartPos);
			m_pHostWidget->move(ptDstPos);
			m_ptCursorStartPos = ptCursorPos;
		}
		
		break;
	}
	// ��������
	case LEFTTOP:
	{
		this->setCursor(QCursor(Qt::SizeFDiagCursor));

		if (m_bMousePressMark)
		{
			CScaleSize::ScaleByCursorZoneType(m_pHostWidget, eZoneType, ptCursorPos, nMinimumWidth, nMinimumHeight);
		}
		
		break;
	}
	case RIGHTTOP:
	{
		this->setCursor(QCursor(Qt::SizeBDiagCursor));

		if (m_bMousePressMark)
		{
			CScaleSize::ScaleByCursorZoneType(m_pHostWidget, eZoneType, ptCursorPos, nMinimumWidth, nMinimumHeight);
		}

		break;
	}
	case LEFT:
	case RIGHT:
	{
		this->setCursor(QCursor(Qt::SizeHorCursor));

		if (m_bMousePressMark)
		{
			CScaleSize::ScaleByCursorZoneType(m_pHostWidget, eZoneType, ptCursorPos, nMinimumWidth, nMinimumHeight);
		}

		break;
	}
	case TOP:
	{
		this->setCursor(QCursor(Qt::SizeVerCursor));

		if (m_bMousePressMark)
		{
			CScaleSize::ScaleByCursorZoneType(m_pHostWidget, eZoneType, ptCursorPos, nMinimumWidth, nMinimumHeight);

			qDebug("x:%d y:%d", ptCursorPos.x(), ptCursorPos.y());
		}

		break;
	}
	default:
		break;
	}
}

void CCustomHeadBar::mouseReleaseEvent(QMouseEvent *event)
{  
	m_bMousePressMark = false;
	QWidget::mouseReleaseEvent(event);
	
}

void CCustomHeadBar::paintEvent(QPaintEvent *event)
{
	QRect rc = event->rect();

	QPainter painter(this);
	
	//painter.setClipRect(rc);

	if (m_qsBkImageFilePath == "")
	{
		//QStyleOption option;
		//option.init(this);
		//style()->drawPrimitive(QStyle::PE_Widget, &option, &painter, this);

		//QWidget::paintEvent(event);

		QBrush brush(this->m_bkColor);
		
		painter.setPen(Qt::NoPen);
		painter.setBrush(brush);
		painter.drawRect(this->rect());
	}
	else
	{
		QPixmap pixmap(m_qsBkImageFilePath);
		painter.drawPixmap(this->rect(), pixmap);
	}
}

CCustomHeadBar::~CCustomHeadBar()
{
}
