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

	// 가격 <= 1000
	// packPrice 는 한통에 6줄 들어있는데 6줄 이상 필요할 수도 있으므로 계산해야함
	int iPackPrice = 0;
	int iCombinePrice = 0;
	int iMinimumPrice = iSinglePrice * N;
	int iComparePrice = 0;

	// 1. 단품으로만 구매 ( 전 브랜드 중 가장 저렴이로 계산해두면 됨 = iMinimumPrice 초기화값 )
	// 2. 단품 + 패키지
	// 3. 패키지로만
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