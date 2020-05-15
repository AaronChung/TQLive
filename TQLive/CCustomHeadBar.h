#ifndef CCustomHeadBar_H
#define CCustomHeadBar_H

class CCustomHeadBar : public QWidget
{
	Q_OBJECT

public:
	CCustomHeadBar(QWidget *parent);
	~CCustomHeadBar();
	void SetBkImageFilePath(const QString &qsFilePath);
	void SetBkColor(const QColor &bkColor);
	void SetHostWindow(QWidget *pWidget);
	
protected: 
	virtual void mousePressEvent(QMouseEvent *event);  
	virtual void mouseMoveEvent(QMouseEvent *event);
	virtual void mouseReleaseEvent(QMouseEvent *event);  
	virtual void paintEvent(QPaintEvent *);

private:
	QString m_qsBkImageFilePath;
	bool m_bMoveSwitch;
	bool m_bMousePressMark;					// ��갴�±�� ��ʶ�������ڱ������ӿؼ��ϰ��£��ƶ������������ӿؼ���������
	QPoint  m_ptCursorStartPos; 
	QWidget *m_pHostWidget;
	QColor m_bkColor;
};

#endif
