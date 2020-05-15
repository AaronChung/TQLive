#pragma once

#include <QWidget>
#include "ui_CTQMainWidget.h"
#include <QMouseEvent>
#include <QMainWindow>

#define PADDING 2
enum Direction { UP = 0, DOWN = 1, LEFT, RIGHT, LEFTTOP, LEFTBOTTOM, RIGHTBOTTOM, RIGHTTOP, NONE };

class CTQMainWidget : public QMainWindow
{
	Q_OBJECT

public:
	CTQMainWidget(QWidget *parent = Q_NULLPTR);
	~CTQMainWidget();
	void region(const QPoint &cursorGlobalPoint);

protected:
	void mouseReleaseEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mousePressEvent(QMouseEvent *event);

public:
	Ui::CTQMainWidget ui;
	bool isLeftPressDown;  // �ж�����Ƿ���
	QPoint dragPosition;   // �����ƶ��϶�ʱ��Ҫ��ס�ĵ� 
	Direction dir;        // ���ڴ�С�ı�ʱ����¼�ı䷽��
};
