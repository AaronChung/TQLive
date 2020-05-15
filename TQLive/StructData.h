/***********************************************************************************
*								StructData.h
*
* Copyright(C):	����̽������Ƽ����޹�˾
*
* Author:  �����
*
* Date: 2019-09
*
* Description: ͨ�����ݽṹ
***********************************************************************************/
#pragma once

#include <QVariant>
#include <QStringList>
#include <QColor>
#include "EnumData.h"

static inline QColor color_from_int(long long val)
{
	return QColor(val & 0xff,
		(val >> 8) & 0xff,
		(val >> 16) & 0xff,
		(val >> 24) & 0xff);
}

static inline long long color_to_int(QColor color)
{
	auto shift = [&](unsigned val, int shift)
	{
		return ((val & 0xff) << shift);
	};

	return  shift(color.red(), 0) |
		shift(color.green(), 8) |
		shift(color.blue(), 16) |
		shift(color.alpha(), 24);
}

//��Ļ������Ϣ
struct BarrageDetialInfo
{
	int nMsgType;              //��Ϣ����
	int nUserLevel;            //�û�����
	int nUserRole;             //�û���ɫ  1��������2�����ܣ�3�����ܣ�0��δ֪�� -1��������
	int nUserId;               //�û�ID
	int nUserVipLevel;         //�û�Vip�ȼ�  

	QString sUserName;         //�û�����
	QString sMsgInfo;          //�û���Ϣ

	int nGiftNum;              //��������
	QString sGiftName;         //��������

	qint64 nEnterTime;          //����ֱ����ʱ��
	qint64 nLeaveTime;          //�뿪ֱ����ʱ��

	BarrageDetialInfo() {
		nMsgType      = -1;
		nUserLevel    = -1;
		nUserRole     = -1;
		nUserId       = -1;
		nUserVipLevel = -1;

		nEnterTime    = 0;
		nLeaveTime    = 0;
	}

	BarrageDetialInfo& operator =(const BarrageDetialInfo& obj)
	{
		if (this != &obj)
		{
			this->nMsgType      = obj.nMsgType;
			this->nUserLevel    = obj.nUserLevel;
			this->nUserRole     = obj.nUserRole;
			this->nUserId       = obj.nUserId;
			this->nUserVipLevel = obj.nUserVipLevel;

			this->sUserName     = obj.sUserName;
			this->sMsgInfo      = obj.sMsgInfo;

			this->nGiftNum      = obj.nGiftNum;
			this->sGiftName     = obj.sGiftName;

			this->nEnterTime    = obj.nEnterTime;
			this->nLeaveTime    = obj.nLeaveTime;
		}
		return *this;
	}
};
Q_DECLARE_METATYPE(BarrageDetialInfo)


//��Ļͳ����Ϣ
struct BarrageStatisticsInfo
{
	int nMsgType;               //��Ϣ����
	int nUserId;                //�û�ID
	int nUserVipLevel;          //�û�Vip�ȼ�
	int nUserRole;              //�û���ɫ  1��������2�����ܣ�3�����ܣ�0��δ֪�� -1��������
	
	qint64 nEnterTime;          //����ֱ����ʱ��
	qint64 nLeaveTime;          //�뿪ֱ����ʱ��
	 
	int nUserMsgTotal;          //��Ļ��Ϣͳ������
	int nRealUserMsgTotal;      //��ʵ��Ļͳ�Ƹ���
	int nTerminalTotal;         //�ն˸���
	bool bInRoom;               //�Ƿ���ֱ����

	BarrageStatisticsInfo() {
		nMsgType       = -1;
		nUserId        = -1;
		nUserVipLevel  = -1;
		nUserRole      = 0;

		nEnterTime     = 0;
		nLeaveTime     = 0;

		nUserMsgTotal  = 0;
		nRealUserMsgTotal = 0;
		nTerminalTotal = 0;
		bInRoom = true;
	}

	BarrageStatisticsInfo& operator =(const BarrageStatisticsInfo& obj)
	{
		if (this != &obj)
		{
			this->nMsgType       = obj.nMsgType;
			this->nUserId        = obj.nUserId;
			this->nUserVipLevel  = obj.nUserVipLevel;
			this->nUserRole      = obj.nUserRole;

			this->nEnterTime     = obj.nEnterTime;
			this->nLeaveTime     = obj.nLeaveTime;

			this->nUserMsgTotal  = obj.nUserMsgTotal;
			this->nRealUserMsgTotal = obj.nRealUserMsgTotal;
			this->nTerminalTotal = obj.nTerminalTotal;
			this->bInRoom = obj.bInRoom;
		}
		return *this;
	}
};
Q_DECLARE_METATYPE(BarrageStatisticsInfo)

//�ز���������
struct MaterialTypeData
{
	int     nType;
	QString sName;
	QString sIcon;
	QString sHoverIcon;

	MaterialTypeData() {
		nType = -1;
	}
};
Q_DECLARE_METATYPE(MaterialTypeData)

//�б�ѭ����������
struct LoopTypeData
{
	int     nType;
	QString sName;
	QString sIcon;
	QString sHoverIcon;

	LoopTypeData() {
		nType = -1;
	}

	LoopTypeData& operator =(const LoopTypeData& obj)
	{
		if (this != &obj)
		{
			this->nType = obj.nType;
			this->sName = obj.sName;
			this->sIcon = obj.sIcon;
			this->sHoverIcon = obj.sHoverIcon;
		}
		return *this;
	}
};
Q_DECLARE_METATYPE(LoopTypeData)

//��Ч����
struct SoundEffectTypeData
{
	QString qSoundEffectName;
	QString qHotKey;
	QString qAduioFile;

	SoundEffectTypeData& operator =(const SoundEffectTypeData& obj)
	{
		if (this != &obj)
		{
			this->qSoundEffectName = obj.qSoundEffectName;
			this->qHotKey          = obj.qHotKey;
			this->qAduioFile       = obj.qAduioFile;
		}
		return *this;
	}
};
Q_DECLARE_METATYPE(SoundEffectTypeData)

//ý����Ƶ����
struct MediaSourceData
{
	int nId;
	QString sMediaName;
	QString sMediaPath;

	int    nTotalTimeDuration;
	bool   bActive;

	MediaSourceData() {
		nId = 0;
		nTotalTimeDuration = 0;
		bActive = false;
	}

	MediaSourceData& operator =(const MediaSourceData& obj)
	{
		if (this != &obj)
		{
			this->nId = obj.nId;
			this->sMediaName = obj.sMediaName;
			this->sMediaPath = obj.sMediaPath;
			this->nTotalTimeDuration = obj.nTotalTimeDuration;
			this->bActive = obj.bActive;
		}
		return *this;
	}
};
Q_DECLARE_METATYPE(MediaSourceData)

struct SourceIniData
{
	QString sourceName;

	int cycleType;
	int voiceVal;
	int listLength;

	QList<MediaSourceData> mediaSourceList;

	SourceIniData() {
		cycleType  = 2;
		voiceVal   = 100;
		listLength = 0;
	}

	SourceIniData& operator =(const SourceIniData& obj)
	{
		if (this != &obj)
		{
			this->sourceName = obj.sourceName;
			this->cycleType = obj.cycleType;
			this->voiceVal = obj.voiceVal;
			this->listLength = obj.listLength;
			this->mediaSourceList = obj.mediaSourceList;
		}
		return *this;
	}
};
Q_DECLARE_METATYPE(SourceIniData)

struct TextSourceIniData
{
	QString sourceName;
	QString text;
	QString path;

	TextSourceIniData& operator =(const TextSourceIniData& obj)
	{
		if (this != &obj)
		{
			this->sourceName = obj.sourceName;
			this->text = obj.text;
			this->path = obj.path;
		}
		return *this;
	}
};
Q_DECLARE_METATYPE(TextSourceIniData)

struct CameraCacheData
{
	QString sourceName;
	int cameraItemIdx;
	int resoultionItemIdx;
	bool filterOfBgSelected;
	int filterOfBgColor;
	int similarityVal;
	int smoothnessVal;
	int spillVal;
	int flipTypeVal;

	CameraCacheData() {
		cameraItemIdx = 0;
		resoultionItemIdx = 0;
		filterOfBgSelected = false;
		filterOfBgColor = color_to_int(Qt::green);
		similarityVal = 1;
		smoothnessVal = 1;
		spillVal = 1;
		flipTypeVal = 0;
	}

	CameraCacheData& operator =(const CameraCacheData& obj)
	{
		if (this != &obj)
		{
			this->sourceName = obj.sourceName;
			this->cameraItemIdx = obj.cameraItemIdx;
			this->resoultionItemIdx = obj.resoultionItemIdx;
			this->filterOfBgSelected = obj.filterOfBgSelected;
			this->filterOfBgColor = obj.filterOfBgColor;
			this->similarityVal = obj.similarityVal;
			this->smoothnessVal = obj.smoothnessVal;
			this->spillVal = obj.spillVal;
			this->flipTypeVal = obj.flipTypeVal;
		}
		return *this;
	}
};
Q_DECLARE_METATYPE(CameraCacheData)