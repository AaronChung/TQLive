/***********************************************************************************
*								EnumData.h
*
* Copyright(C):	����̽������Ƽ����޹�˾
*
* Author:  �����
*
* Date: 2019-09
*
* Description: ͨ��ö��
***********************************************************************************/
#pragma once

//��Ļ����
enum BarrageType
{
	USER_SUSPEND_WARNING = 3500,         //�û�ͣ������
	USER_TIPS_WARNING    = 3600,         //�û�Υ����ʾ����
	USER_LOGOUT_LIVE     = 3801,         //�û��˳�ֱ����
	USER_LOGIN_LIVE      = 3802,         //�û���¼ֱ����
	USER_SEND_GIFT       = 7000,         //�û�ˢ����
	USER_SEND_MSG        = 8000,         //�û���Ϣ
};

//ֱ�����û���ɫ����
enum LiveRoomUserRoleType
{
	USERROLE_HOMIE      = 1,           //����
	USERROLE_ROOMADMIN  = 2,           //����
	USERROLE_SUPERADMIN = 3,           //����
};

//IM�Ự����
enum TIMConvType
{
	kTIMConv_Invalid = 0,            //��Ч�Ự
	kTIMConv_C2C     = 1,            //���˻Ự
	kTIMConv_Group   = 2,            //Ⱥ��Ự
	kTIMConv_System  = 3,            //ϵͳ�Ự
};

//IMԪ������
enum TIMElemType
{
	kTIMElem_Text          = 0,           //�ı�Ԫ��
	kTIMElem_Image         = 1,           //ͼƬԪ��
	kTIMElem_Sound         = 2,           //����Ԫ��
	kTIMElem_Custom        = 3,           //�Զ���Ԫ��
	kTIMElem_File          = 4,           //�ļ�Ԫ��
	kTIMElem_GroupTips     = 5,           //Ⱥ��ϵͳ��ϢԪ��
	kTIMElem_Face          = 6,           //����Ԫ��
	kTIMElem_Location      = 7,           //λ��Ԫ��
	kTIMElem_GroupReport   = 8,           //Ⱥ��ϵͳ֪ͨԪ��
	kTIMElem_Video         = 9,           //��ƵԪ��
	kTIMElem_FriendChange  = 10,          //��ϵ��������ϢԪ��
	kTIMElem_ProfileChange = 11,          //���ϱ����ϢԪ��
};

//�Ի����������
enum OperatorType
{
	DIALOG_CANCEL_FORBIDDEN_OPERATOR    = 100,        //������Բ���
	DIALOG_DELETE_ROOMMANAGER_OPERATOR  = 101,        //ɾ�����ܲ���
	DIALOG_PAY_CONFIRM_SIMPLE_OPERATOR  = 102,        //֧��ȷ�ϼ��ײ���
	DIALOG_PAY_CONFIRM_COMPLEX_OPERATOR = 103,        //֧��ȷ�ϸ��Ӳ���
	DIALOG_LOGOUT_ACCOUNT_OPERATOR      = 104,        //ע���û�����
	DIALOG_IDENTITY_TIPS_OPERATOR       = 105,        //���������ʾ
	DIALOG_INSTANCE_EXIST_OPERATOR      = 106,        //ʵ����������
	DIALOG_CUSTOM_OPERATOR              = 200,        //�Զ�������
};

//Ӧ���˳���ʾ����
enum ExitTipsType
{
	EXIT_APP     = -1000,               //�˳�Ӧ��
	EXIT_TO_TRAY = -1001,               //�˳���ϵͳ����
};

//ֱ����������
enum LiveBroadcastTerminatedType
{
	NORMAL_TERMINATED    = 1000,        //�����ж�
	EXCEPTION_TERMINATED = 1001,        //�쳣�ж�
	LIVE_CONTENT_RESET = 1002,			//ֱ����������
};

//ֱ����������
enum LivePicQualityType
{
	PICQUALITY_BD_4M     = 0,
	PICQUALITY_BD        = 1,
	PICQUALITY_FHD       = 2,
	PICQUALITY_HD        = 3,
	PICQUALITY_SD        = 4,
	PICQUALITY_CUSTOMIZE = 5
};

//ֱ����������
enum LiveBitrateType
{
	BITRATE_800 = 0,
	BITRATE_1000,
	BITRATE_1200,
	BITRATE_1500,
	BITRATE_2000,
	BITRATE_3000,
	BITRATE_4000
};

//ֱ��֡������
enum LiveFrameIntervalType
{
	FRAME_INTERVAL_20 = 0,
	FRAME_INTERVAL_25,
	FRAME_INTERVAL_30,
	FRAME_INTERVAL_40,
	FRAME_INTERVAL_50,
	FRAME_INTERVAL_60
};

//ֱ���ֱ�������
enum LiveResolutionType
{
	RESOLUTION_720P = 0,
	RESOLUTION_450P,
	RESOLUTION_360P,
	RESOLUTION_1080P
};

//����������
enum LiveEncoderType
{
	ENCODER_CPU = 0,
	ENCODER_GPU
};

//�����������
enum LiveOutputBitrateType
{
	OUTPUT_BITRATE_VBR = 0,
	OUTPUT_BITRATE_CBR
};

//��¼����������
enum LoginCodeType
{
	LOGIN_ACCOUNT_NULL = -100,
	LOGIN_PASSWD_NULL = -101,
	LOGIN_PASSWD_FORMAT_ERR = -102,
	LOGIN_PHONENUMBER_FORMAT_ERR = -103,
	LOGIN_INITIALIZE = 0,
	LOGIN_CONNECTION_TIMEOUT1 = 417,
	LOGIN_CONNECTION_TIMEOUT2 = 500,
	LOGIN_ACCOUNT_INFO_ERR = 4003,
	LOGIN_FORBIDDEN = 4004,
	LOGIN_REFUSED_BY_POWER = 5005,
	LOGIN_FORBIDDEN_LIMIT = 5006,
	LOGIN_FORBIDDEN_FOREVER = 5009,
	LOGIN_UNABLE_TO_CONNECT_SERVER = 401,
	LOGIN_NETWORK_CONNECTION_ERROR = 5,
	LOGIN_UNKNOWN_ERROR = 99,
};

//�ز�����
enum MateriralType
{
	MATERIAL_CAMERA = 1,
	MATERIAL_VIDEO,
	MATERIAL_IMAGE,
	MATERIAL_TEXT,
	MATERIAL_SOURCE,
	MATERIAL_CAPTURE,
	MATERIAL_FULLSCREEN,
	MATERIAL_WINDOW,
};

//Դ�ť����
enum SourceItemButtonType
{
	SOURCEITEM_SETTINGS = 1,
	SOURCEITEM_UP,
	SOURCEITEM_DOWN,
	SOURCEITEM_DEL
};

//�����б�ѭ������
enum LoopType
{
	LOOP_RANDOM = 0,
	LOOP_SINGLE = 1,
	LOOP_CYCLE  = 2
};
