/***********************************************************************************
*								RoomManageDelegate.cpp
*
* Copyright(C):	����̽������Ƽ����޹�˾
*
* Author:  �����
*
* Date: 2019-09
*
* Description: �����б�������
***********************************************************************************/
#include "RoomManageDelegate.h"
#include <QStyleOption>
#include <QPainter>
#include <QApplication>
#include <QMouseEvent>

RoomManageDelegate::RoomManageDelegate(QObject *parent)
	: QItemDelegate(parent)
{

}

RoomManageDelegate::~RoomManageDelegate()
{

}

void RoomManageDelegate::paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const
{
	QStyleOptionButton* button = m_pButtons.value(index);
	if (!button) {
		button = new QStyleOptionButton();
		button->state |= QStyle::State_Enabled;
		button->iconSize = QSize(42, 18);
		button->icon = QIcon(QString(":/TQLive/images/delete.png"));

		(const_cast<RoomManageDelegate *>(this))->m_pButtons.insert(index, button);
	}
	button->rect = QRect(option.rect.left() + (100 - 42) / 2, option.rect.top() + (34 - 18) / 2, 42, 18); //
	painter->save();

	if (option.state & QStyle::State_Selected) {
		painter->fillRect(option.rect, option.palette.highlight());

	}
	painter->restore();
	QApplication::style()->drawControl(QStyle::CE_PushButton, button, painter);
}

bool RoomManageDelegate::editorEvent(QEvent * event, QAbstractItemModel * model, const QStyleOptionViewItem & option, const QModelIndex & index)
{
	if (event->type() == QEvent::MouseButtonPress)
	{
		if (m_pButtons.contains(index))
		{
			emit onDeleteClicked(index);
		}
	}
	return false;
}
