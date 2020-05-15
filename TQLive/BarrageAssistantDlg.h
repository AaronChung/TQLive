#pragma once

#include <QDialog>
#include <QMutex>
#include "ui_BarrageAssistantDlg.h"
#include "StructData.h"
#include "BarrageStatisticsAgent.h"

class BarrageAssistantDlg : public QDialog
{
	Q_OBJECT

public:
	BarrageAssistantDlg(QWidget *parent);
	~BarrageAssistantDlg();

signals:
	void onSigUpdateThread(const BarrageStatisticsInfo & barrageStatisticsInfo);
	void onSigClearStatisticsData();
	void onSigInitStatisticsData();
	void onSigMicHotKeyTrigger();
	void onSigLiveHotKeyTrigger();

protected:
	void keyPressEvent(QKeyEvent *event);

private slots:
    /*����ֱ����ĵ�Ļ��Ϣ*/
    void onRecvChatRoomMsg(const BarrageDetialInfo &barrageDetialInfo);

	void onClearStatisticsThread();
	void onInitStatisticsThread();

private:
	/*��ʼ��UI*/
	void InitUI();
	/*��ʼ��������*/
	void InitConnect();
	/*�����С�仯������б�*/
	void UpdateList();
	/*��ͼƬ�����Ӧ���û�����*/
	void ImageAddText(QString imagePath, int userLevel);
	void roleImageAddText(QString imagePath, int userRole);
	/*��ʼ����Ļ��*/
	void InitBarragePool(int barrageMsgType);
	/*��ʼ�������*/
	void InitGiftPool();
	/*�����û������ȡ��Ӧ��ͼƬ��Դ·��*/
	QString getImagePathByUserLevel(int userLevel);
	/*�����û���ɫ��ȡ��Ӧ��ͼƬ��Դ·��*/
	QString getImagePathByUserRole(int userRole);
	/*�����û���ɫ��ȡ��Ӧ���ı�����*/
	QString getTextByUserRole(int userRole);
	/*��Ӧ��ݼ�����*/
	void RespondHotKey(QString hotKey);

private:
	Ui::BarrageAssistantDlg ui;
	BarrageDetialInfo m_pBarrageDetialInfo;          //ʵʱ�洢ÿ����Ļ��Ϣ
	QList<BarrageDetialInfo> m_pBarragePoolRecord;   //��Ļ��ʷ��Ϣ����
	int m_curr_fontSize;                             //��ǰ��Ļ�����С
	BarrageStatisticsAgent *m_pStatisticsThread;
	bool m_pIsLiving = false;
};
