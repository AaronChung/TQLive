#include "CTestDlg.h"
#include "CViewTemplate.h"
#include "CDataCentre.h"

CTestDlg::CTestDlg(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	ST_COMPETITION_INFO stCompetitionInfo;
	stCompetitionInfo.qsDateTime = "2019/8/30 21:00";
	stCompetitionInfo.qsType = QString::fromLocal8Bit("Ӣ��");
	stCompetitionInfo.qsContent = QString::fromLocal8Bit("���� vs ˹�п˳�");

	CViewTemplate <ST_COMPETITION_INFO> *pView = new CViewTemplate <ST_COMPETITION_INFO> ();
	QList<ST_COMPETITION_INFO> obLDataItemList;
	obLDataItemList.push_back(stCompetitionInfo);
	obLDataItemList.push_back(stCompetitionInfo);
	obLDataItemList.push_back(stCompetitionInfo);
	obLDataItemList.push_back(stCompetitionInfo);

	pView->ResetData(obLDataItemList);

	ui.verticalLayout->addWidget(pView);
}

CTestDlg::~CTestDlg()
{
}
