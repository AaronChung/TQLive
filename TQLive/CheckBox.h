/***********************************************************************************
*								CheckBox.cpp
*
* Copyright(C):	����̽������Ƽ����޹�˾
*
* Author:  �����
*
* Date: 2019-09
*
* Description: ͨ�����CheckBox
***********************************************************************************/

#pragma once

#include <QCheckBox>
#include "StructData.h"
#include "CDataCentre.h"

#define CHECKBOX_MAX_LENGTH 15

class CheckBox : public QCheckBox
{
	Q_OBJECT

public:
	explicit CheckBox(QWidget *parent = 0);
	~CheckBox();

	void setData(const ST_GROUP_INFO &groupChatInfo);

signals:
	void sigOnStateChanged(ST_GROUP_INFO &groupChatInfo);

private:
	void InitUI();
	void InitConnect();

private:
	ST_GROUP_INFO m_pGroupChatInfo;
};
