#include <iostream>
#include <list>
using namespace std;

int main()
{
	int N, L;

	// 1. 물은 정수거리만큼 떨어진 거리에서 샘
	// 2. 물 막고나서 좌우 0.5 간격 줘야 함
	// 3. 테이프의 최소갯수(겹쳐붙이기 가능)

	// 물이 새는 곳 수 N 입력 받음(<= 1000)
	std::cin >> N;

	// 테이프 길이 L 입력 받음(<= 1000)
	std::cin >> L;

	// 물이 새는 곳 위치 입력 받음 (<=1000)
	int iPos;

	int iTapeCount = 0;
	int iTapePoistion = 0;

	// 양 옆에서 0.5 씩 여유 있게 붙여야 함
	L -= 1;

	// 파이프 순서가 거꾸로 들어올 수 있음
	list<int> listPipes;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> iPos;
		listPipes.push_back(iPos);
	}

	listPipes.sort();

	for (auto iter : listPipes)
	{
		if (iTapePoistion < iter)
		{
			iTapePoistion = iter + L;
			++iTapeCount;
		}
	}

	std::cout << iTapeCount;
}