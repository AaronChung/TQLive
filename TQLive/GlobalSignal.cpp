/***********************************************************************************
*								GlobalSignal.cpp
*
* Copyright(C):	����̽������Ƽ����޹�˾
*
* Author:  �����
*
* Date: 2019-09
*
* Description: ȫ���ź���
***********************************************************************************/
#include "GlobalSignal.h"

GlobalSignal* GlobalSignal::m_pInstance = Q_NULLPTR;

GlobalSignal* GlobalSignal::instance()
{
	if (m_pInstance == Q_NULLPTR)
	{
		m_pInstance = new GlobalSignal;
	}
	return m_pInstance;
}

GlobalSignal::GlobalSignal(QObject *parent)
	: QObject(parent)
{

}

GlobalSignal::~GlobalSignal()
{

}
