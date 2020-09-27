#include <iostream>
#include <list>
#include <map>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int iComputerCount = 0;
	int iConnectCount = 0;

	cin >> iComputerCount;
	cin >> iConnectCount;
	
	// 번호는 1번부터
	int iInputIndex = 0;
	int iInputConnect = 0;

	map<int, list<int>> mapNetworks;

	for(int i = 0; i < iConnectCount; ++i)
	{
		cin >> iInputIndex >> iInputConnect;
		mapNetworks[iInputIndex-1].push_back(iInputConnect -1);

		// 반대쪽으로 하는 거 안 넣어주면
		// 1번에 없고 다른데서 1번 가리키면 끝남(한쪽만 넣어주면 방향 그래프 처럼 작동함)
		mapNetworks[iInputConnect - 1].push_back(iInputIndex - 1);
	}

	vector<bool> vecVisit(iComputerCount);

	queue<int> queInputs;
	queInputs.push(0);
	vecVisit[0] = true;

	int iCurIndex;
	int iInfectionCount = 0;

	while (!queInputs.empty())
	{
		iCurIndex = queInputs.front();
		queInputs.pop();

		for (auto iter_list : mapNetworks[iCurIndex])
		{
			if (!vecVisit[iter_list])
			{
				vecVisit[iter_list] = true;
				queInputs.push(iter_list);
				++iInfectionCount;
			}
		}

	}

	cout << iInfectionCount;
}