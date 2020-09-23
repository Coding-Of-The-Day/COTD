#include <iostream>
#include <string>
#include <list>
#include <map>
using namespace std;

#define ALPHABET_CNT 26

int main()
{
	// 팰린드롬 문제
	// ABBA, ABABA 처럼 서로 대칭되는 문자열
	string strInput;
	cin >> strInput;

	map<int, int> mapAlphabets;
	for (size_t i = 0; i < strInput.length(); ++i)
		++mapAlphabets[strInput[i] - 65];

	string strPalindrome;

	char chFindOdd = '\0';
	int iCycleCount = 0;

	// 앞부분 추가
	for (auto& iter : mapAlphabets)
	{
		if (1 == (iter.second % 2))
		{
			if ('\0' == chFindOdd)
			{
				chFindOdd = iter.first + 65;
				--iter.second;
			}
			else
			{
				cout << "I'm Sorry Hansoo";
				return 0;
			}
		}

		iCycleCount = iter.second / 2;

		for (int j = 0; j < iCycleCount; ++j)
		{
			strPalindrome += iter.first + 65;
			--iter.second;
		}
	}

	// 중간 알파벳 추가
	if('\0' != chFindOdd)
	strPalindrome += chFindOdd;

	// 남은 알파벳 추가
	for (auto iter = mapAlphabets.rbegin(); iter != mapAlphabets.rend(); ++iter)
	{
		for (int j = iter->second - 1; j >= 0; --j)
			strPalindrome += iter->first + 65;
	}

	cout << strPalindrome;
	return 0;
}