/***********************************************************************************
*								DataPathManager.cpp
*
* Copyright(C):	����̽������Ƽ����޹�˾
*
* Author:  �����
*
* Date: 2019-09
*
* Description: ����Ŀ¼������ʵ��
***********************************************************************************/
#include "DataPathManager.h"
#include <Windows.h>
#include <ShlObj.h>
#include <QFileInfo>

string DataPathManager::getUserDir()
{
	//��ȡӦ�ó��������ļ����Ŀ¼
	char personalPath[MAX_PATH] = { 0 };
	setlocale(LC_ALL, "chs");
	bool bRet = SHGetSpecialFolderPathA(NULL, personalPath, CSIDL_PERSONAL, FALSE);

	string dir = string(personalPath);
	string userDir = dir + "\\TQLive";
	::CreateDirectoryA(userDir.c_str(), NULL);

	return userDir;
}
