/***********************************************************************************
*								HotKeyInputLineEdit.cpp
*
* Copyright(C):	����̽������Ƽ����޹�˾
*
* Author:  �����
*
* Date: 2019-11
*
* Description: ��ݼ�������༭��
***********************************************************************************/
#include "HotKeyInputLineEdit.h"
#include <QKeyEvent>
#include <QDebug>

HotKeyInputLineEdit::HotKeyInputLineEdit(QWidget *parent)
	: QLineEdit(parent)
{
	setReadOnly(true);
}

HotKeyInputLineEdit::~HotKeyInputLineEdit()
{

}

void HotKeyInputLineEdit::keyPressEvent(QKeyEvent *event)
{
	int keyInt = event->key();
	Qt::Key key = static_cast<Qt::Key>(keyInt);
	if (key == Qt::Key_unknown)
	{
		qDebug() << "Unknown key from a macro probably";
		return;
	}

	if (key == Qt::Key_Control)
	{
		keyInt = Qt::CTRL;
	}
	else if (key == Qt::Key_Shift)
	{
		keyInt = Qt::SHIFT;
	}
	else if (key == Qt::Key_Alt)
	{
		keyInt = Qt::ALT;
	}
	else if (key == Qt::Key_Meta)
	{
		keyInt = Qt::META;
	}
	else
	{
		Qt::KeyboardModifiers modifiers = event->modifiers();
		if (modifiers & Qt::ShiftModifier)
			keyInt += Qt::SHIFT;
		if (modifiers & Qt::ControlModifier)
			keyInt += Qt::CTRL;
		if (modifiers & Qt::AltModifier)
			keyInt += Qt::ALT;
		if (modifiers & Qt::MetaModifier)
			keyInt += Qt::META;

		SetInputContent(QKeySequence(keyInt).toString(QKeySequence::NativeText));
		return;
	}

	SetInputContent(QKeySequence(keyInt).toString(QKeySequence::NativeText).remove("+"));
}

void HotKeyInputLineEdit::SetInputContent(QString content)
{
	setText(content);
}
