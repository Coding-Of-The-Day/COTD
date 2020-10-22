#include <iostream>
#include <vector>
using namespace std;

void BFS(vector<vector<int>>& _vecGrounds, int iCurY, int iCurX)
{
	// �� �̻� �����ų� 0�� ��� ó�� ���ϰ� ���ư��� ��!
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

		// ��ü �����
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
		// 1�� Ž���Ѵ�
		for (int j = 0; j < iVertLen; ++j)
		{
			for (int k = 0; k < iHoriLen; ++k)
			{
				// 1�� ��� BFS �� Ž���ϰ� ����
				// ������ ��� j k ó������ �ٽ� Ž��
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