#include <iostream>
#include <vector>
using namespace std;


int main()
{
	// 직사각형 N*M
	int N, M;
	cin >> N >> M;

	vector<vector<int>> vecNumbers;
	vecNumbers.resize(N);

	string strInput;
	for (int i = 0; i < N; ++i)
	{
		cin >> strInput;

		vecNumbers[i].reserve(M);
		for (int j = 0; j < M; ++j)
			vecNumbers[i].push_back(strInput[j] - '0');
	}

	int iSquareSize = N < M ? N : M;
	bool bFind = false;

	while (iSquareSize > 1)
	{
		for (int i = 0; i <= N - iSquareSize; ++i)
		{
			bFind = false;
			for (int j = 0; j <= M - iSquareSize; ++j)
			{
				if ((vecNumbers[i][j] == vecNumbers[i][j + iSquareSize - 1]) &&
					(vecNumbers[i][j] == vecNumbers[i + iSquareSize - 1][j]) &&
					(vecNumbers[i][j] == vecNumbers[i + iSquareSize - 1][j + iSquareSize - 1]))
				{
					bFind = true;
					break;
				}
			}

			if (bFind) break;
		}

		if (bFind) break;
		--iSquareSize;
	}

	if (!bFind)
		cout << 1 << endl;
	else
		cout << iSquareSize * iSquareSize << endl;
}