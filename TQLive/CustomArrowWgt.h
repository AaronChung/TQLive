#pragma once

#include <QDialog>

class CustomArrowWgt : public QDialog
{
	Q_OBJECT

public:
	CustomArrowWgt(QWidget *parent = Q_NULLPTR);
	~CustomArrowWgt();

	//����С���ǵ���ʼλ��
	void setStartPos(int startPosX);    

	//����С���ǵĿ�͸�
	void setTriangleInfo(int width, int height);

	//�����м������widget
	void setCenterWidget(QWidget *widget);

protected:
	void paintEvent(QPaintEvent *event);
	void keyPressEvent(QKeyEvent *event);

private:
	int m_nStartPosX;
	int m_nTriangleW;
	int m_nTriangleH;
};
