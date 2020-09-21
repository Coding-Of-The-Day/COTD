#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;

	// ���� �� �ִ� ���� �� ���
	int iCount = 0;
	for (int i = 1; i < N; ++i)
		iCount += i;

	// �Է�
	double* pNumArr = new double[N];
	for (int i = 0; i < N; ++i)
		cin >> pNumArr[i];

	double dMaxValue = 0;

	// 1���ٰ� ���ϸ� ���� �����Ƿ� 1�� �ʱ�ȭ�Ѵ�.
	double* pNumMemo = new double[N];
	for (int i = 0; i < N; ++i)
		pNumMemo[i] = 1.0;

	//������ ������
	//memcpy(pNumMemo, pNumArr, sizeof(float) * N);
	
	// ���ڸ��� ���ϸ鼭 �ִ밪 �˻�
	// 0~N ���� ����
	for (int i = 0; i < N; ++i)
	{
		for (int j = i; j < N; ++j)
		{
			pNumMemo[i] *= pNumArr[j];

			if (dMaxValue < pNumMemo[i])
				dMaxValue = pNumMemo[i];
		}
	}

	//�ڵ� �ݿø���
	//��ü ���� �� 3���� �����ϴ� ����
	//fixed �ڿ� �;� �Ҽ��� �Ʒ� �ڸ� �� ���� �ϴ� ���̰� ������ ��ü ���� �ڸ����� �����Ѵ�
	cout << fixed;
	cout.precision(3);

	cout << dMaxValue << endl;

	delete[] pNumArr;
	delete[] pNumMemo;

	return 0;
}