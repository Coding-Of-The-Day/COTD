#include <iostream>
#include <list>
using namespace std;

int main()
{
	int N, L;

	// 1. ���� �����Ÿ���ŭ ������ �Ÿ����� ��
	// 2. �� ������ �¿� 0.5 ���� ��� ��
	// 3. �������� �ּҰ���(���ĺ��̱� ����)

	// ���� ���� �� �� N �Է� ����(<= 1000)
	std::cin >> N;

	// ������ ���� L �Է� ����(<= 1000)
	std::cin >> L;

	// ���� ���� �� ��ġ �Է� ���� (<=1000)
	int iPos;

	int iTapeCount = 0;
	int iTapePoistion = 0;

	// �� ������ 0.5 �� ���� �ְ� �ٿ��� ��
	L -= 1;

	// ������ ������ �Ųٷ� ���� �� ����
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