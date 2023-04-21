#pragma once
#include "PCH.h"
#include "system/sys.h"
class UVa156_Ananagrams :public Solution {
public://������
	UVa156_Ananagrams() = delete;
	UVa156_Ananagrams(const vector<string>& words) :words(words) {}
	~UVa156_Ananagrams() {};
public://�㷨����

	//�ⷨ1:stl map
	//ʱ�临�Ӷ�ΪO(NlogN)������NΪ��������
	virtual Result solve1() override {
		map<string, int> freq; // ͳ�Ƶ��ʳ��ִ�����map
		vector<string> ans; // ����𰸵�vector
		for (string s : words) {
			string n = normalize(s); // ת��ΪСд���������ַ���
			if (freq.count(n) == 0) { // ������ַ�����һ�γ���
				freq[n] = 0; // ������뵽map��
			}
			freq[n]++; // ͳ�Ƹ��ַ������ִ���
		}
		for (string w : words) {
			if (freq[normalize(w)] == 1) { // ������ַ���ֻ������һ��
				ans.push_back(w); // ��������vector
			}
		}
		sort(ans.begin(), ans.end()); // �Դ�vector����
		return R2S(ans);
	}

	virtual Result solve2() override {
		return Result();
	}

private:
	// ���ַ���ת��ΪСд������
	string normalize(const string& s)
	{
		string res = s;
		transform(res.begin(), res.end(), res.begin(), ::tolower);
		sort(res.begin(), res.end());
		return res;
	}
	string R2S(const vector<string>& r) {
		string s;
		for (string w : r) {
			s += (w + "\n");
		}
		return s;
	}
	const vector<string> words;
};