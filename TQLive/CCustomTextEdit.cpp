#include "CCustomTextEdit.h"
#include <QPainter>
#include <QApplication>
#include <QTimer>
#include <QMouseEvent>
#include <QTextBlock>
#include <QScrollBar>

CCustomTextEdit::CCustomTextEdit(QWidget *parent, bool isCursorVisible)
	: QTextEdit(parent)
	, m_cursorVisible(isCursorVisible)
{
	this->setMouseTracking(true);

	// ���ع��
	this->setCursorWidth(0);
}

CCustomTextEdit::~CCustomTextEdit()
{
}

void CCustomTextEdit::SetCursorVisible(bool isCursorVisible)
{
	m_cursorVisible = isCursorVisible;
	if (m_cursorVisible)
	{
		m_pCursorTimer = new QTimer(this);
		QApplication::setCursorFlashTime(0);

		// ÿ 500 ������˸һ��
		m_pCursorTimer->setInterval(500);

		connect(m_pCursorTimer, &QTimer::timeout, [=] {
			m_cursorVisible = !m_cursorVisible;

			viewport()->update();
		});

		// ���������˸
		m_pCursorTimer->start();
	}
}

void CCustomTextEdit::paintEvent(QPaintEvent *e)
{
	QTextEdit::paintEvent(e);

	if (m_cursorVisible) {

		QScrollBar *pScrollBar = this->verticalScrollBar();
		if (pScrollBar != NULL)
		{
			pScrollBar->setValue(pScrollBar->maximum());
		}

		QPainter painter(viewport());
		QRect r = cursorRect();
		r.setTop(r.bottom() - 10);
		r.setWidth(1);
		painter.fillRect(r, Qt::white);
	}
}

void CCustomTextEdit::mouseDoubleClickEvent(QMouseEvent *e)
{
	int x = e->pos().x();
	int y = e->pos().y();
	qDebug("x:%d y:%d", x, y);

	QTextCursor cursor = this->cursorForPosition(e->pos());
	QTextBlock block = cursor.block();

	if (block.isValid())
	{
		for (QTextBlock::iterator iterator = block.begin(); !(iterator.atEnd()); iterator++)							// ����Block��Fragment
		{
			QTextFragment currentFragment = iterator.fragment();
			QTextImageFormat newImageFormat = currentFragment.charFormat().toImageFormat();

			// ͼƬ��Ϣ
			if (newImageFormat.isValid())
			{
				int pos = cursor.positionInBlock();
				QString qsURL = newImageFormat.name();
			}
			// �ı���Ϣ
			else
			{
				QString qsText = currentFragment.text();
				
			}
		}
	}
}
