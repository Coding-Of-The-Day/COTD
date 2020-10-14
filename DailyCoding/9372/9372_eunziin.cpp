#include <iostream>
using namespace std;

int main()
{
	// 최소 비용 신장 트리 문제
	// 테스트 케이스 입력
	// 테스트 케이스만큼 반복
	int iTestCase = 0;
	cin >> iTestCase;

	while (iTestCase-- > 0)
	{
		int N, M;
		cin >> N >> M;

		int a, b;
		for (int i = 0; i < M; ++i)
			cin >> a >> b;

		cout << (N - 1) << endl;
	}
}