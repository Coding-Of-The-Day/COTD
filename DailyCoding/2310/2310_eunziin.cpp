#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <stack>
using namespace std;

/* boj �� �ø��� Ʋ�ȴٰ� ������ �� �� �̷��� ��ġ�� ���� �ٶ� */
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

		// �����ؼ� ���� ����
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
				// ���ȣ�� -1 �ؾ���
			}

			// �������� ������ 0 ���� ����
			tRoomInfo.listCanGo.pop_back();
			vecRooms.push_back(tRoomInfo);
		}

		// dfs �� Ǯ����
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
			// ���� Ž�� ��ġ ����
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