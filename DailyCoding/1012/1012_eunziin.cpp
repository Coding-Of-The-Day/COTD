#include <iostream>
#include <vector>
using namespace std;

void BFS(vector<vector<int>>& _vecGrounds, int iCurY, int iCurX)
{
	// 더 이상 못가거나 0일 경우 처리 안하고 돌아가야 함!
	if (iCurY < 0 || iCurX < 0 || iCurY >= _vecGrounds.size() || iCurX >= _vecGrounds[0].size() || 0 == _vecGrounds[iCurY][iCurX])
	{
		return;
	}

	_vecGrounds[iCurY][iCurX] = 0;

	BFS(_vecGrounds, iCurY, iCurX + 1);
	BFS(_vecGrounds, iCurY, iCurX - 1);
	BFS(_vecGrounds, iCurY+1, iCurX);
	BFS(_vecGrounds, iCurY-1, iCurX);
}

int main()
{
	vector<vector<int>> vecGrounds;

	int iTestCase;
	cin >> iTestCase;


	for (int i = 0; i < iTestCase; ++i)
	{
		int iHoriLen, iVertLen, iPosCount;
		cin >> iHoriLen >> iVertLen >> iPosCount;

		// 전체 지우기
		vecGrounds.clear();

		vecGrounds.resize(iVertLen);
		for (int j = 0; j < iVertLen; ++j)
			vecGrounds[j].resize(iHoriLen);

		int inputX, inputY;
		for (int j = 0; j < iPosCount; ++j)
		{
			cin >> inputX >> inputY;
			vecGrounds[inputY][inputX] = 1;
		}

		int iWormCount = 0;
		// 1을 탐색한다
		for (int j = 0; j < iVertLen; ++j)
		{
			for (int k = 0; k < iHoriLen; ++k)
			{
				// 1일 경우 BFS 로 탐색하고 나서
				// 남았을 경우 j k 처음부터 다시 탐색
				if (1 == vecGrounds[j][k])
				{
					BFS(vecGrounds, j, k);
					++iWormCount;
				}
			}
		}

		cout << iWormCount << endl;
	}

	return 0;
}