#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_CTQLiveWindow.h"
#include "CCustomMainWindow.h"

#define PADDING 2



class CTQLiveWindow : public QMainWindow
{
	Q_OBJECT

	enum Direction { UP = 0, DOWN = 1, LEFT, RIGHT, LEFTTOP, LEFTBOTTOM, RIGHTBOTTOM, RIGHTTOP, NONE };

public:
	CTQLiveWindow(QWidget *parent = Q_NULLPTR);
	~CTQLiveWindow();
	void region(const QPoint &cursorGlobalPoint);

protected:
	void mouseReleaseEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mousePressEvent(QMouseEvent *event);

protected:
	//virtual bool nativeEvent(const QByteArray &eventType, void *message, long *result);

public:
	Ui::CTQLiveWindowClass ui;
	bool isLeftPressDown;  // �ж�����Ƿ���
	QPoint dragPosition;   // �����ƶ��϶�ʱ��Ҫ��ס�ĵ� 
	Direction dir;        // ���ڴ�С�ı�ʱ����¼�ı䷽��
};
