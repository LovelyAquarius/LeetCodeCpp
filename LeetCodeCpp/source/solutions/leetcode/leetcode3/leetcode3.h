#pragma once
#include "PCH.h"
#include "system/sys.h"

using namespace std;
class leetcode3 :public Solution {
public://构造器
	leetcode3() = delete;
	leetcode3(string s):s(s){}
	virtual ~leetcode3() override {}
public://算法部分
	//两种解法的时间复杂度都是线性的，
	//但是双指针+哈希表的解法空间复杂度比动态规划的解法低，
	//因为它只需要一个哈希表来存储滑动窗口中的字符，
	//而动态规划的解法需要额外维护一个dp数组和一个哈希表
	//解法3在字符集小的时候可以用桶优化，因为不需要哈希了
	//因为字符集越大，桶就越大

	//解法1:双指针滑动窗口+unordered_set哈希
	//O(n)
	virtual Result solve1() override {
		unordered_set<char> set; // 存储当前子串中出现的字符
		//由于unordered_set是哈希表的实现，其插入、删除和查找操作的时间复杂度都是O(1)
		
		int max_len = 0, left = 0, right = 0; // max_len记录不含重复字符的最长子串的长度，left和right分别指向子串的开头和结尾
		while (right < s.size()) { // 右指针向右移动
			if (set.count(s[right]) == 0) { // 如果右指针指向的字符不在集合中
				set.insert(s[right++]); // 将其加入集合中
				max_len = max(max_len, (int)set.size()); // 更新max_len
			}
			else { // 如果右指针指向的字符已经在集合中
				set.erase(s[left++]); // 将左指针处的字符从集合中删除，左指针向右移动
			}
		}
		return R2S(max_len); // 返回max_len

	}

	//解法2:动态规划+哈希
	//O(n)
	virtual Result solve2() override {
		vector<int> dp(s.size(),0); // 定义dp数组
		unordered_map<char, int> map; // 定义一个哈希表，用于记录每个字符上一次出现的位置
		int max_len = 0; 
		//第一次记录
		dp[0] = 1;
		map[s[0]] = 0;
		max_len = 1;
		// 记录最长子串的长度
		for (int i = 1; i < s.size(); i++) {
			
			if (map.count(s[i]) == 0 || i - map[s[i]] > dp[i - 1]) {
				// 如果第i个字符之前没有出现过，或者上一次出现的位置不在当前子串中
				dp[i] = dp[i - 1] + 1; // 将第i个字符加入到当前子串中
			}
			else {
				// 如果第i个字符之前已经出现过，并且上一次出现的位置在当前子串中
				dp[i] = i - map[s[i]]; // 重新计算不含重复字符的最长子串的长度
			}
			map[s[i]] = i; // 更新当前字符出现的位置
			max_len = max(max_len, dp[i]); // 更新最长子串的长度
		}
		return R2S(max_len); // 返回最长子串的长度
	}
	//解法3:双指针+桶优化
	//这个算法只能用于asii字符集
	virtual Result solve3() override {
		vector<int> bucket(128, -1);  // 初始化桶，所有位置的值都为-1
		int start = 0, maxLen = 0;
		for (int i = 0; i < s.size(); ++i) {
			char c = s[i];
			if (bucket[c ] >= start) {  // 如果c在当前子串中出现过
				start = bucket[c] + 1;  // 更新子串的起始位置
			}
			bucket[c ] = i;  // 记录c最后一次出现的位置
			maxLen = max(maxLen, i - start + 1);  // 更新最长子串长度
		}
		return R2S(maxLen);
	}
private:
	string R2S(int r) {
		return to_string(r);
	}
	string s;
};