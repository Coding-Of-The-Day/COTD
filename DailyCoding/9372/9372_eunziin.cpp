#include <iostream>
using namespace std;

int main()
{
	// �ּ� ��� ���� Ʈ�� ����
	// �׽�Ʈ ���̽� �Է�
	// �׽�Ʈ ���̽���ŭ �ݺ�
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