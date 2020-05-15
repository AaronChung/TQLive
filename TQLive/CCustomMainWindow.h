#pragma once

#include <QMainWindow>

#include "qsystemdetection.h"
#include <QObject>
#include <QMainWindow>

//A nice frameless window for both Windows and OS X
//Author: Bringer-of-Light
//Github: https://github.com/Bringer-of-Light/Qt-Nice-Frameless-Window
// Usage: use "CCustomMainWindow" as base class instead of "QMainWindow", and enjoy
#include <QWidget>
#include <QList>
#include <QMargins>
#include <QRect>

class CCustomMainWindow : public QMainWindow
{
	Q_OBJECT
public:
	explicit CCustomMainWindow(QWidget *parent = 0);
public:

	//�����Ƿ����ͨ�����������ڴ�С
	//if resizeable is set to false, then the window can not be resized by mouse
	//but still can be resized programtically
	void setResizeable(bool resizeable = true);
	bool isResizeable() { return m_bResizeable; }

	//���ÿɵ�����С����Ŀ�ȣ��ڴ������ڣ�����ʹ�����������ڴ�С
	//set border width, inside this aera, window can be resized by mouse
	void setResizeableAreaWidth(int width = 5);
protected:
	//����һ��������widget����widget�ᱻ�����������Դ�
	//set a widget which will be treat as SYSTEM titlebar
	void setTitleBar(QWidget* titlebar);

	//�ڱ������ؼ��ڣ�Ҳ�������ӿؼ����ǩ�ؼ���label1������label1�ڸ��˱����������²���ͨ��label1�϶�����
	//Ҫ��������⣬ʹ��addIgnoreWidget(label1)
	//generally, we can add widget say "label1" on titlebar, and it will cover the titlebar under it
	//as a result, we can not drag and move the MainWindow with this "label1" again
	//we can fix this by add "label1" to a ignorelist, just call addIgnoreWidget(label1)
	void addIgnoreWidget(QWidget* widget);

	bool nativeEvent(const QByteArray &eventType, void *message, long *result);
	//void showEvent(QShowEvent *event);

private slots:
	void onTitleBarDestroyed();

public:
	void setContentsMargins(const QMargins &margins);
	void setContentsMargins(int left, int top, int right, int bottom);
	QMargins contentsMargins() const;
	QRect contentsRect() const;
	void getContentsMargins(int *left, int *top, int *right, int *bottom) const;

public slots:
	void showFullScreen();



private:
	QWidget* m_titlebar;
	QList<QWidget*> m_whiteList;
	int m_borderWidth;

	QMargins m_margins;
	QMargins m_frames;
	bool m_bJustMaximized;

	bool m_bResizeable;
};