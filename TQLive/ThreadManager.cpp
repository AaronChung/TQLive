/***********************************************************************************
*								ThreadManager.cpp
*
* Copyright(C):	����̽������Ƽ����޹�˾
*
* Author:  �����
*
* Date: 2019-10
*
* Description: ͨ���߳�����ʵ��
***********************************************************************************/

#include "ThreadManager.h"

QThread* ThreadManager::m_pAgentThread = NULL;

QThread* ThreadManager::getAgentThread()
{
	if (m_pAgentThread == NULL)
	{
		m_pAgentThread = new QThread;
	}
	return m_pAgentThread;
}
