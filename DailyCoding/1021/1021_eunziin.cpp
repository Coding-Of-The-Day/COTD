#include <iostream>
#include <deque>
using namespace std;

void MovePointer(deque<int>& _deqNums, int& iIndex, bool bMoveDirectionIsLeft = true)
{
	int iLoopCount = _deqNums.size();
	if (bMoveDirectionIsLeft)
	{
		--iIndex;
		while (iIndex < 0 || -1 == _deqNums[iIndex])
		{
			--iIndex;
			if (iIndex < 0) iIndex = _deqNums.size() - 1;

			--iLoopCount;
			if (iLoopCount < 0) break;
		}
	}
	else
	{
		++iIndex;
		while (iIndex >= _deqNums.size() || -1 == _deqNums[iIndex])
		{
			++iIndex;

			if (iIndex >= _deqNums.size()) iIndex = 0;

			--iLoopCount;
			if (iLoopCount < 0) break;
		}
	}
}

int main()
{
	int iCQueueSize;
	int iPickCount;

	cin >> iCQueueSize >> iPickCount;

	int iFindNum = 0;

	deque<int> deqNums;

	for (int i = 0; i < iCQueueSize; ++i)
		deqNums.push_back(i + 1);

	int iFindMoveCnt = 0;
	int iCurIndex = 0;
	int iLeftIndex, iRightIndex;
	int iTotalMoveCnt = 0;

	for (int i = 0; i < iPickCount; ++i)
	{
		cin >> iFindNum;

		iFindMoveCnt = 0;

		iLeftIndex = iCurIndex;
		iRightIndex = iCurIndex;

		while (true)
		{
			if (iFindNum == deqNums[iLeftIndex])
			{
				// 찾은 다음 포인터 부터 현재 포인터가 된다.(무조건 오른쪽 회전)
				deqNums[iLeftIndex] = -1;
				MovePointer(deqNums, iLeftIndex, false);
				iCurIndex = iLeftIndex;
				break;
			}
			if (iFindNum == deqNums[iRightIndex])
			{
				deqNums[iRightIndex] = -1;
				MovePointer(deqNums, iRightIndex, false);
				iCurIndex = iRightIndex;
				break;
			}

			MovePointer(deqNums, iLeftIndex, true);
			MovePointer(deqNums, iRightIndex, false);

			++iFindMoveCnt;
		}
		iTotalMoveCnt += iFindMoveCnt;
	}

	cout << iTotalMoveCnt << endl;
}