#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> vecStrings;
bool CompareFunc(string& str1, string& str2) {
	// ����1. ���̰� ª���� ������
	if (str1.length() < str2.length())
		return true;
	else if (str1.length() == str2.length())
	{
		// ����2. �����տ��� ���� �� ������
		int iSum1 = 0;
		int iSum2 = 0;

		for (int i = 0; i < str1.length(); ++i)
		{
			if (isdigit(str1[i]))
				iSum1 += (str1[i] - '0');
		}

		for (int i = 0; i < str2.length(); ++i)
		{
			if (isdigit(str2[i]))
				iSum2 += (str2[i] - '0');
		}

		if (iSum1 < iSum2)
			return true;
		else if (iSum1 == iSum2)
		{
			// ����3. ������ ��
			for (int i = 0; i < str1.length(); ++i)
			{
				// �Ѵ� �����϶� >> ���� ���� ��� 
				// �ϳ��� �����϶�
				// �Ѵ� �����϶�
				if (isdigit(str1[i]) && isdigit(str2[i]) && ((str1[i] - '0') < str2[i] - '0'))
					return true;
				else if (isdigit(str1[i]))
					return true;
				else if (isdigit(str2[i]))
					return false;
				else if (str1[i] < str2[i]) // �Ѵ� ������
					return true;
			}
		}
	}

	return false;
}

int main()
{
	// ���� ª���� �տ�
	// ���� ������ ���� ���� ���� ���� ���̸� �տ�
	// ������ ��(���ĺ��� �� ����)
	
	int iGuitarCount = 0;
	cin >> iGuitarCount;

	string strInput;
	vecStrings.reserve(iGuitarCount);

	for (int i = 0; i < iGuitarCount; ++i)
	{
		cin >> strInput;
		vecStrings.push_back(strInput);
	}

	sort(vecStrings.begin(), vecStrings.end(), CompareFunc);

	for (auto iter : vecStrings)
		cout << iter << endl;
}