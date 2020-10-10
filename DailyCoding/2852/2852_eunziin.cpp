#include <iostream>
#include <string>
using namespace std;

int ConvertTimeToSec(string& strTime)
{
	// ������ ã��
	int iFindIdx = strTime.find(":");

	// ������ �������� �ÿ� �� ������ �ڸ��� ���ڷ� ��ȯ�ϱ�
	// ó������ : �ձ���, : �������� ���� ���� ��ü
	string strMin = strTime.substr(0, iFindIdx + 1);
	string strSec = strTime.substr(iFindIdx + 1, strTime.length() - (iFindIdx + 1));

	// ���� �ʿ� ���ؼ� ��ȯ
	return (stoi(strMin) * 60) + stoi(strSec);
}

string ConvertSecToTime(int iTime)
{
	string strMin = to_string(iTime / 60);
	string strSec = to_string(iTime % 60);

	if (strMin.length() < 2) strMin = "0" + strMin;
	if (strSec.length() < 2) strSec = "0" + strSec;

	return (strMin + ":" + strSec);
}

int main()
{
	// ���� �� Ƚ�� 
	// N ���� ���� ����
	// �� ��ȣ(1,2) + ���� �ð�(MM:SS ����) �� <= 47 / �� <= 59

	int iLoopCnt = 0;
	cin >> iLoopCnt;

	int iLastGoalTime = 0;
	int iInputGoalTeam = 0;
	string strInputGoalTime = "00:00";

	int iConvertTime = 0;
	int iResultTime[2]{ 0,0 };
	int iResultScore[2]{ 0,0 };

	for (int i = 0; i < iLoopCnt; ++i)
	{
		cin >> iInputGoalTeam >> strInputGoalTime;

		--iInputGoalTeam; // �� ��ȣ 1 2 �� ������ ������ �ε����� ��ȯ
		iConvertTime = ConvertTimeToSec(strInputGoalTime);

		if(iResultScore[0] > iResultScore[1])
			iResultTime[0] += (iConvertTime - iLastGoalTime);
		else if(iResultScore[0] < iResultScore[1])
			iResultTime[1] += (iConvertTime - iLastGoalTime);

		// ���ݱ��� �̱�� ���� �ջ������ �ϹǷ�
		// �������� ���ھ� ���ؼ� �ð� �־��� ���� ���ھ� �ջ�����
		++iResultScore[iInputGoalTeam];

		iLastGoalTime = iConvertTime;
	}

	string strEndTime = "48:00";
	if (iResultScore[0] > iResultScore[1])
		iResultTime[0] += (ConvertTimeToSec(strEndTime) - iLastGoalTime);
	else if (iResultScore[0] < iResultScore[1])
		iResultTime[1] += (ConvertTimeToSec(strEndTime) - iLastGoalTime);

	cout << ConvertSecToTime(iResultTime[0]) << endl;
	cout << ConvertSecToTime(iResultTime[1]) << endl;
}