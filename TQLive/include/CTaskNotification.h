#pragma once

#include <QObject>
#include "CDataCentre.h"

class CTaskNotification : public QObject
{
	Q_OBJECT

public:
	CTaskNotification(QObject *parent);
	~CTaskNotification();
	static CTaskNotification *CTaskNotification::GetInstance();

private:
	static CTaskNotification *m_pInstance;

signals:
	void signalLoginTaskNotification(int, QString);
	void signalFinishLiveTaskNotification(int, QString);
	void signalLogoutTaskNotification(int, QString);
	void signalHeartbeatValidationTaskNotification(int, QString);
	void signalLiveRoomSetupTaskNotification(int, QString);
	void signalIMLogin();
	void signalRecvChatRoomMsg(const QString &);
	void signalAcquireLivePushAddress(int, const QString &);
	void signalAcquireCompetitionList(int, const QString &, QList<ST_COMPETITION_INFO> obLCompetitionList, const void *userData);
	void signalAcquireMatchList(int, const QString &, QList<ST_MATCH_INFO> obLMatchList, const void *userData);
	void signalAcquireLiveScheduleList(int, const QString &, QList<ST_MATCH_INFO>);

	void signalAcquireFriendList(int nStatuCode, const QString &qsInfo, const void *userData = NULL);
	void signalDownloadFileFinish(int nCode, const QString &qsInfo, const void *receiver = NULL, const void *userData = NULL);
	void signalDownloadFileNotification(int nCode, const QString &qsInfo, const void *userData);
	//void signalReceiveIMImageMsg(int nCode, const QString &qsInfo, const void *userData);
	//void signalIMRecvImageMsg(QString qsUserID, QString qsLocalPath);
	//void signalIMRecvTextMsg(const QString &qsUserID, const QString &qsTextPath);

	void signalIMRecvImageMsg(const ST_MSG_INFO &stMsgInfo);
	void signalIMRecvTextMsg(const ST_MSG_INFO &stMsgInfo);

	void signalIMAcquireConv();
	void signalIMAcquireConvList();
	void signalAcquireConvMsgList(const QList<ST_MSG_INFO> &obLMsgInfo, const void *);
	void signalIMSendMsg();
	void signalIMRecvMsg(EN_MSG_TYPE eMsgType, void *userData);

	void signalIMLogout();
	void signalJSExecuted(const QVariant &v);

	void signalUserPortraitDownloadFinish();

	// ���Լ�¼�б�
	void signalAcquireProhibitToSpeakList(int nStatuCode, const QString &qsInfo, QList<ST_PROHIBIT_TO_SPEAK_RECORD> obList);

	// �������Ա�б�
	void signalAcquireRoomAdministratorList(int, const QString &, QList<ST_ROOM_ADMINISTRATOR_RECORD>);

	// �ƹ�Ⱥ�б�
	void signalAcquireGroupGeneralizeList(int, const QString &, QList<ST_GROUP_INFO>);

	// ȡ���û�����
	void signalRepealSilent(int, const QString &);

	// ȡ���������Ա
	void signalRepealRoomAdministrator(int, const QString &);

	// ��ȡ��������Ϣ
	void signalIMAcquireGroupInfo(int nStatuCode, const QString &qsMsg, const ST_GROUP_INFO &stGroupInfo);

	// ������������֪ͨ
	void signalSendStartToBroadcastReminder(int nStatusCode, const QString &qsMsg);

	// ����ֱ��ͳ����Ϣ����֪ͨ
	void signalAcquireLiveEndStatistics(int nStatusCode, const QString &qsMsg, const ST_LIVE_STATISTICS &stLiveStatistics, const void *userData);

	// ��ȡϵͳ����
	void signalAcquireSystemAnnouncementList(int, const QString &, const QList<ST_SYSTEM_ANNOUNCEMENT> &obList, const void *userData);

	// ��ȡֱ������������ʣ�෢�ʹ���
	void signalAcquireReminderContent(int nStatusCode, const QString &qsMsg, int nRemainedTime, const void *userData);

	// ��ȡֱ�������б�
	void signalAcquireLiveCategory(int nStatusCode, const QString &qsMsg, const QList<ST_LIVE_CATEGORY_INFO> &obList, const void *userData);

	// ��ȡ�����������°汾
	void signalAcquireAppUpToDate(int nStatusCode, const QString &qsMsg, const ST_VER_INFO &stVerInfo, const void *userData);

	// ����ֱ������֪ͨ
	void signalUpdateLiveContentTaskNotification(int, QString, const void *userData);

	// ��ȡĬ�ϵ�ֱ������
	void signalAcquireDefaultLiveContent(int nStatusCode, const QString &qsMsg, const ST_LIVE_CONTENT &stLiveContent, const void *userData);

	// ��ȡOSS�����Ϣ
	void signalAcquireOSSInformation(int nStatusCode, const QString &qsMsg, const ST_OSS_INFORMATION &stOSSInformation, const void *userData);

	// �ϴ��ļ�
	void signalUploadFile(int nStatusCode, const QString &qsMsg, const QString &qsFileID, const void *userData);
};
