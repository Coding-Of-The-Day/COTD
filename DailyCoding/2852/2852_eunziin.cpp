#include <iostream>
#include <string>
using namespace std;

int ConvertTimeToSec(string& strTime)
{
	// 기준점 찾기
	int iFindIdx = strTime.find(":");

	// 기준점 기준으로 시와 분 나눠서 자르고 숫자로 변환하기
	// 처음부터 : 앞까지, : 다음부터 남은 갯수 전체
	string strMin = strTime.substr(0, iFindIdx + 1);
	string strSec = strTime.substr(iFindIdx + 1, strTime.length() - (iFindIdx + 1));

	// 분을 초에 더해서 반환
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
	// 골이 들어간 횟수 
	// N 개의 득점 정보
	// 팀 번호(1,2) + 득점 시간(MM:SS 분초) 분 <= 47 / 초 <= 59

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

		--iInputGoalTeam; // 팀 번호 1 2 로 들어오기 때문에 인덱스로 변환
		iConvertTime = ConvertTimeToSec(strInputGoalTime);

		if(iResultScore[0] > iResultScore[1])
			iResultTime[0] += (iConvertTime - iLastGoalTime);
		else if(iResultScore[0] < iResultScore[1])
			iResultTime[1] += (iConvertTime - iLastGoalTime);

		// 지금까지 이기던 팀에 합산해줘야 하므로
		// 이전까지 스코어 비교해서 시간 넣어준 다음 스코어 합산해줌
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