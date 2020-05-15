/***********************************************************************************
*								CustomSoundEffectBtn.cpp
*
* Copyright(C):	����̽������Ƽ����޹�˾
*
* Author:  �����
*
* Date: 2019-11
*
* Description: �Զ�����Ч��ť
***********************************************************************************/
#include "CustomSoundEffectBtn.h"

CustomSoundEffectBtn::CustomSoundEffectBtn(QWidget *parent)
	: QPushButton(parent)
{
	setStyleSheet("QPushButton { color:#999999; border:none; font-size:12px; font-family:Microsoft YaHei; padding:0px; background:transparent; } \
                                   QPushButton:hover { color:#4AB134; background:transparent; }");

	connect(this, &QPushButton::clicked, this, [&]() {
		emit onSigPlayAudio(m_pSoundEffectTypeData.qAduioFile);
	});
}

CustomSoundEffectBtn::~CustomSoundEffectBtn()
{

}

void CustomSoundEffectBtn::setData(const SoundEffectTypeData & data)
{
	m_pSoundEffectTypeData = data;

	setShortcut(QKeySequence(m_pSoundEffectTypeData.qHotKey));
	setText(QString("%1(%2)").arg(m_pSoundEffectTypeData.qSoundEffectName).arg(m_pSoundEffectTypeData.qHotKey));
}

SoundEffectTypeData & CustomSoundEffectBtn::getData()
{
	return m_pSoundEffectTypeData;
}
