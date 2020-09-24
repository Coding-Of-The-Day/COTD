#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <stack>
using namespace std;

/* boj 에 올리면 틀렸다고 나오는 데 먼 미래에 고치면 수정 바람 */
int main()
{
	int iRoomCount = -1;

	while (true)
	{
		cin >> iRoomCount;
		cin.get();

		if (0 == iRoomCount)
			return 0;

		struct tagRoomInfo
		{
			string strRoomId;
			int iMoney = 0;
			list<int> listCanGo;
			bool bIsVisit = false;
		};

		// 분할해서 전부 넣음
		vector<tagRoomInfo> vecRooms;
		vecRooms.reserve(iRoomCount);

		string strInput;
		string strConvert;
		int iStartIndex;
		int iEndIndex;

		for (int i = 0; i < iRoomCount; ++i)
		{
			tagRoomInfo tRoomInfo;

			getline(cin, strInput);

			iStartIndex = 0;
			iEndIndex = strInput.find(" ");
			strConvert = strInput.substr(iStartIndex, (iEndIndex - iStartIndex));
			tRoomInfo.strRoomId = strConvert;

			iStartIndex = iEndIndex + 1;
			iEndIndex = strInput.find(" ", iStartIndex);
			tRoomInfo.iMoney = stoi(strInput.substr(iStartIndex, (iEndIndex - iStartIndex)));

			while (iStartIndex <= iEndIndex)
			{
				iStartIndex = iEndIndex + 1;
				iEndIndex = strInput.find(" ", iStartIndex);
				tRoomInfo.listCanGo.push_back(stoi(strInput.substr(iStartIndex, (iEndIndex - iStartIndex))) - 1);
				// 방번호라 -1 해야함
			}

			// 마지막은 무조건 0 들어간다 했음
			tRoomInfo.listCanGo.pop_back();
			vecRooms.push_back(tRoomInfo);
		}

		// dfs 로 풀거임
		stack<tagRoomInfo*> stackRooms;
		stackRooms.push(&vecRooms[0]);
		vecRooms[0].bIsVisit = true;
		int iFindIndex = 0;
		int iHaveMoney = 0;

		while (!stackRooms.empty())
		{
			if (stackRooms.top()->strRoomId == "L")
			{
				if (stackRooms.top()->iMoney > iHaveMoney)
					iHaveMoney = stackRooms.top()->iMoney;
			}
			else if (stackRooms.top()->strRoomId == "T")
			{
				iHaveMoney -= stackRooms.top()->iMoney;
				if (iHaveMoney < 0)
				{
					cout << "No" << endl;
					break;
				}
			}

			if (iFindIndex == vecRooms.size() - 1)
			{
				cout << "Yes" << endl;
				break;
			}

			bool bFindChk = false;
			// 다음 탐색 위치 물색
			for (auto iter_list : stackRooms.top()->listCanGo)
			{
				if (!vecRooms[iter_list].bIsVisit)
				{
					iFindIndex = iter_list;
					bFindChk = true;
					break;
				}
			}

			if (!bFindChk)
				stackRooms.pop();
			else
			{
				stackRooms.push(&vecRooms[iFindIndex]);
				vecRooms[iFindIndex].bIsVisit = true;
			}
		}
	}
	return 0;
}