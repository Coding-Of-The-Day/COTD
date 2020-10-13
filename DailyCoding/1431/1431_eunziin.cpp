#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> vecStrings;
bool CompareFunc(string& str1, string& str2) {
	// 조건1. 길이가 짧은게 앞으로
	if (str1.length() < str2.length())
		return true;
	else if (str1.length() == str2.length())
	{
		// 조건2. 숫자합에서 작은 게 앞으로
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
			// 조건3. 사전순 비교
			for (int i = 0; i < str1.length(); ++i)
			{
				// 둘다 숫자일때 >> 작은 수일 경우 
				// 하나만 숫자일때
				// 둘다 문자일때
				if (isdigit(str1[i]) && isdigit(str2[i]) && ((str1[i] - '0') < str2[i] - '0'))
					return true;
				else if (isdigit(str1[i]))
					return true;
				else if (isdigit(str2[i]))
					return false;
				else if (str1[i] < str2[i]) // 둘다 문자임
					return true;
			}
		}
	}

	return false;
}

int main()
{
	// 길이 짧은거 앞에
	// 길이 같으면 숫자 합을 더해 작은 값이면 앞에
	// 사전순 비교(알파벳이 더 작음)
	
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