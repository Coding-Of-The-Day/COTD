#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;

	// 나올 수 있는 가짓 수 계산
	int iCount = 0;
	for (int i = 1; i < N; ++i)
		iCount += i;

	// 입력
	double* pNumArr = new double[N];
	for (int i = 0; i < N; ++i)
		cin >> pNumArr[i];

	double dMaxValue = 0;

	// 1에다가 곱하면 본인 나오므로 1로 초기화한다.
	double* pNumMemo = new double[N];
	for (int i = 0; i < N; ++i)
		pNumMemo[i] = 1.0;

	//컴파일 에러남
	//memcpy(pNumMemo, pNumArr, sizeof(float) * N);
	
	// 한자리씩 곱하면서 최대값 검색
	// 0~N 까지 훑음
	for (int i = 0; i < N; ++i)
	{
		for (int j = i; j < N; ++j)
		{
			pNumMemo[i] *= pNumArr[j];

			if (dMaxValue < pNumMemo[i])
				dMaxValue = pNumMemo[i];
		}
	}

	//자동 반올림됨
	//전체 숫자 수 3개로 제한하는 것임
	//fixed 뒤에 와야 소수점 아래 자리 수 제한 하는 것이고 없으면 전체 숫자 자리수를 제한한다
	cout << fixed;
	cout.precision(3);

	cout << dMaxValue << endl;

	delete[] pNumArr;
	delete[] pNumMemo;

	return 0;
}