#pragma once

#include <QObject>

class AppInitializer : public QObject
{
	Q_OBJECT

public:
	AppInitializer(QObject *parent = 0);
	~AppInitializer();

	/*Ӧ�ó����ʼ��*/
	void init();

private:
	/*������ʼ��*/
	void initSingleObjects();

	/*�����ļ���ʼ��*/
	void initConfig();
};
