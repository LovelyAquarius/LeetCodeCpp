#pragma once
#include "PCH.h"
#include "system/sys.h"
class UVa156_Ananagrams :public Solution {
public://构造器
	UVa156_Ananagrams() = delete;
	UVa156_Ananagrams(const vector<string>& words) :words(words) {}
	~UVa156_Ananagrams() {};
public://算法部分

	//解法1:stl map
	//时间复杂度为O(NlogN)，其中N为单词数量
	virtual Result solve1() override {
		map<string, int> freq; // 统计单词出现次数的map
		vector<string> ans; // 保存答案的vector
		for (string s : words) {
			string n = normalize(s); // 转换为小写并排序后的字符串
			if (freq.count(n) == 0) { // 如果该字符串第一次出现
				freq[n] = 0; // 将其插入到map中
			}
			freq[n]++; // 统计该字符串出现次数
		}
		for (string w : words) {
			if (freq[normalize(w)] == 1) { // 如果该字符串只出现了一次
				ans.push_back(w); // 将其加入答案vector
			}
		}
		sort(ans.begin(), ans.end()); // 对答案vector排序
		return R2S(ans);
	}

	virtual Result solve2() override {
		return Result();
	}

private:
	// 将字符串转换为小写并排序
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