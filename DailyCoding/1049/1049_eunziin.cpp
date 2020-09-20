#include <iostream>
using namespace std;

int main()
{
	int N, M;

	cin >> N >> M;

	int* pPackPrice = new int[M] {};
	int* pSinglePrice = new int[M] {};

	int iSinglePrice = 1000;

	for (int i = 0; i < M; ++i)
	{
		cin >> pPackPrice[i] >> pSinglePrice[i];

		if (iSinglePrice > pSinglePrice[i])
			iSinglePrice = pSinglePrice[i];
	}

	// ���� <= 1000
	// packPrice �� ���뿡 6�� ����ִµ� 6�� �̻� �ʿ��� ���� �����Ƿ� ����ؾ���
	int iPackPrice = 0;
	int iCombinePrice = 0;
	int iMinimumPrice = iSinglePrice * N;
	int iComparePrice = 0;

	// 1. ��ǰ���θ� ���� ( �� �귣�� �� ���� �����̷� ����صθ� �� = iMinimumPrice �ʱ�ȭ�� )
	// 2. ��ǰ + ��Ű��
	// 3. ��Ű���θ�
	for (int i = 0; i < M; ++i)
	{
		iPackPrice = pPackPrice[i] * ceil(N/6.f);
		iCombinePrice = (pPackPrice[i] * (N/6)) + iSinglePrice * (N%6);

		iComparePrice = iPackPrice < iCombinePrice ? iPackPrice : iCombinePrice;
		iMinimumPrice = iMinimumPrice < iComparePrice ? iMinimumPrice : iComparePrice;
	} 

	delete[] pPackPrice;
	delete[] pSinglePrice;

	cout << iMinimumPrice;

	return 0;
}