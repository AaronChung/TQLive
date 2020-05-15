/***********************************************************************************
*								AppInitializer.cpp
*
* Copyright(C):	����̽������Ƽ����޹�˾
*
* Author:  �����
*
* Date: 2019-09
*
* Description: ���ڽ�������ʱ��һЩ��ʼ������
***********************************************************************************/
#include "AppInitializer.h"
#include "UserConfig.h"
#include "HttpAgent.h"
#include "CTaskNotification.h"
#include "CController.h"
#include "SourceIniXML.h"
#include "SourceIniJson.h"
#include "CameraCacheJson.h"

AppInitializer::AppInitializer(QObject *parent)
	: QObject(parent)
{

}

AppInitializer::~AppInitializer()
{

}

void AppInitializer::init()
{
	//��ʼ��
	initSingleObjects();
	initConfig();
}

void AppInitializer::initSingleObjects()
{
	//ʵ��������
	UserConfig::instance();
	HttpAgent::instance();

	CTaskNotification::GetInstance();
	CController::GetInstance();

	SourceIniXML::instance()->ReadXml();
	SourceIniJson::instance()->Read();
	CameraCacheJson::instance()->Read();
}

void AppInitializer::initConfig()
{
	//����������Ϣ
	UserConfig::instance()->load();
}