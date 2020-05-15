#pragma once

#include <QObject>
#include "StructData.h"
#include "CDataCentre.h"

class HttpAgent : public QObject
{
	Q_OBJECT

public:
	static HttpAgent* instance();

	/*�����ȡ�����û��б�*/
	void RequestOnGetForbiddenUserList();
	/*�����ȡ�����б�*/
	void RequestOnGetRoomManagerList();
	/*�����ȡQQȺ�б�*/
	void RequestOnGetGroupChatList();
	/*����ȡ����userId�Ľ����û�*/
	void RequestOnCancelForbiddenUser(int userId);
	/*����ɾ����userId�ķ���*/
	void RequestOnDeleteRoomManager(int userId);
	/*���󿪲�����*/
	void RequestOnBroadcastReminder();
	/*����ز�ͳ����Ϣ*/
	void RequestOnOffcastStatistics(int nLiveRecordID);
	/*�����¼�û���Ϣ*/
	void RequestOnRecordUserInformation(const QString &qsAccountNumber, const QString &qsPassword, bool isRememberPwd, int nLoginMethod, int nAutoLoginMark);
	/*�����ȡ�����������ݺ�ʣ�෢�ʹ���*/
	void RequestOnGetReminderContent();
	/*�����ȡƽ̨ϵͳ����*/
	void RequestOnGetSystemNotification();
	/*�����޸�ֱ�������*/
	void RequestOnModifyLiveRoomParams(int nSettingsType, const QString &qsPropertyValue);
	/*�����ȡ���°汾��*/
	void RequestOnGetAppUpToDateVer();
	/*�����ȡ����������*/
	void RequestOnGetChatGroupInfo(const QString &groupNumber);
	/*��ȡOSS�����Ϣ*/
	void RequestOnGetOSSInfo();
	/*�ϴ������ļ���OSS*/
	void RequestOnUploadFileToOSS(const ST_OSS_INFORMATION &ossInfo, const QString &filePath);
	/*�ϱ�ˮӡ�����Ƿ���*/
	void RequestOnWaterMarkFlags(const QString &value);

private slots:
    /*���յ�Ļ��������Ϣ�ۺ���*/
	void onRecvChatRoomMsg(const QString &recvMsg);

signals:
	/*���յ�Ļ��������Ϣ�źź���*/
	void onSigRecvChatRoomMsg(const BarrageDetialInfo &barrageDetialInfo);
	/*��ȡ�����û��б��źź���*/
	void onSigGetForbiddenUserList(int nStatuCode, const QString &qsInfo, QList<ST_PROHIBIT_TO_SPEAK_RECORD> obList);
	/*��ȡ�����б��źź���*/
	void onSigGetRoomManagerList(int nStatuCode, const QString &qsInfo, QList<ST_ROOM_ADMINISTRATOR_RECORD> recordList);
	/*��ȡ�ƹ�Ⱥ�б��źź���*/
	void onSigGetGroupChatList(int nStatuCode, const QString &qsInfo, QList<ST_GROUP_INFO> groupList);
	/*ȡ�������û��źź���*/
	void onSigCancelForbiddenUser(int nStatuCode, const QString &qsInfo);
	/*ȡ�������źź���*/
	void onSigDeleteRoomManager(int nStatuCode, const QString &qsInfo);
	/*���������źź���*/
	void onSigBroadcastReminder(int nStatusCode, const QString &qsMsg);
	/*�ز�ͳ���źź���*/
	void onSigOffcastStatistics(int nStatusCode, const QString &qsMsg, const ST_LIVE_STATISTICS &stLiveStatistics, const void *userData);
	/*��ȡֱ������������ʣ�෢�ʹ����źź���*/
	void onSigGetReminderContent(int nStatusCode, const QString &qsMsg, int nRemainedTime, const void *userData);
	/*��ȡϵͳ�����źź���*/
	void onSigGetSystemNotification(int nStatusCode, const QString &qsMsg, const QList<ST_SYSTEM_ANNOUNCEMENT> &obList, const void *userData);
	/*��ȡ���°汾���źź���*/
	void onSigGetAppUpToDateVer(int nStatusCode, const QString &qsMsg, const ST_VER_INFO &stVerInfo, const void *userData);
	/*��ȡȺ�������źź���*/
	void onSigGetChatGroupInfo(int nStatusCode, const QString &qsMsg, const ST_GROUP_INFO &stGroupInfo);
	/*IM��¼��Ӧ�źź���*/
	void onSigIMLoginRespond();
	/*��̨����֪ͨ*/
	void onSigWarningTips(int nStatusCode, QString sMsg, int nLimitTime);
	/*��ȡOSS�����Ϣ�źź���*/
	void onSigGetOSSInfo(int nStatusCode, const QString &sMsg, const ST_OSS_INFORMATION &ossInfo, const void *userData);
	/*�ϴ��ļ���OSS���źź���*/
	void onSigUploadFileToOSS(int nStatusCode, const QString &sMsg, const QString &fileID, const void *userData);

private:
	explicit HttpAgent(QObject *parent = 0);
	~HttpAgent();

private:
	/*��ʼ��������*/
	void initConnect();
	/*������������Ϣ��*/
	void ParsingMsg(const QString &elem_data, const QString &elem_ext, const QString &elem_desc);

private:
	static HttpAgent* m_pInstance;
};
