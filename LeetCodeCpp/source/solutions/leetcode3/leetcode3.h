#pragma once
#include "PCH.h"
#include "system/sys.h"

using namespace std;
class leetcode3 :public Solution {
public://������
	leetcode3() = delete;
	leetcode3(string s):s(s){}
	virtual ~leetcode3() override {}
public://�㷨����
	//���ֽⷨ��ʱ�临�Ӷȶ������Եģ�
	//����˫ָ��+��ϣ��Ľⷨ�ռ临�Ӷȱȶ�̬�滮�Ľⷨ�ͣ�
	//��Ϊ��ֻ��Ҫһ����ϣ�����洢���������е��ַ���
	//����̬�滮�Ľⷨ��Ҫ����ά��һ��dp�����һ����ϣ��
	//�ⷨ3���ַ���С��ʱ�������Ͱ�Ż�����Ϊ����Ҫ��ϣ��
	//��Ϊ�ַ���Խ��Ͱ��Խ��

	//�ⷨ1:˫ָ�뻬������+unordered_set��ϣ
	//O(n)
	virtual Result solve1() override {
		unordered_set<char> set; // �洢��ǰ�Ӵ��г��ֵ��ַ�
		//����unordered_set�ǹ�ϣ���ʵ�֣�����롢ɾ���Ͳ��Ҳ�����ʱ�临�Ӷȶ���O(1)
		
		int max_len = 0, left = 0, right = 0; // max_len��¼�����ظ��ַ�����Ӵ��ĳ��ȣ�left��right�ֱ�ָ���Ӵ��Ŀ�ͷ�ͽ�β
		while (right < s.size()) { // ��ָ�������ƶ�
			if (set.count(s[right]) == 0) { // �����ָ��ָ����ַ����ڼ�����
				set.insert(s[right++]); // ������뼯����
				max_len = max(max_len, (int)set.size()); // ����max_len
			}
			else { // �����ָ��ָ����ַ��Ѿ��ڼ�����
				set.erase(s[left++]); // ����ָ�봦���ַ��Ӽ�����ɾ������ָ�������ƶ�
			}
		}
		return R2S(max_len); // ����max_len

	}

	//�ⷨ2:��̬�滮+��ϣ
	//O(n)
	virtual Result solve2() override {
		vector<int> dp(s.size(),0); // ����dp����
		unordered_map<char, int> map; // ����һ����ϣ�����ڼ�¼ÿ���ַ���һ�γ��ֵ�λ��
		int max_len = 0; 
		//��һ�μ�¼
		dp[0] = 1;
		map[s[0]] = 0;
		max_len = 1;
		// ��¼��Ӵ��ĳ���
		for (int i = 1; i < s.size(); i++) {
			
			if (map.count(s[i]) == 0 || i - map[s[i]] > dp[i - 1]) {
				// �����i���ַ�֮ǰû�г��ֹ���������һ�γ��ֵ�λ�ò��ڵ�ǰ�Ӵ���
				dp[i] = dp[i - 1] + 1; // ����i���ַ����뵽��ǰ�Ӵ���
			}
			else {
				// �����i���ַ�֮ǰ�Ѿ����ֹ���������һ�γ��ֵ�λ���ڵ�ǰ�Ӵ���
				dp[i] = i - map[s[i]]; // ���¼��㲻���ظ��ַ�����Ӵ��ĳ���
			}
			map[s[i]] = i; // ���µ�ǰ�ַ����ֵ�λ��
			max_len = max(max_len, dp[i]); // ������Ӵ��ĳ���
		}
		return R2S(max_len); // ������Ӵ��ĳ���
	}
	//�ⷨ3:˫ָ��+Ͱ�Ż�
	//����㷨ֻ������asii�ַ���
	virtual Result solve3() override {
		vector<int> bucket(128, -1);  // ��ʼ��Ͱ������λ�õ�ֵ��Ϊ-1
		int start = 0, maxLen = 0;
		for (int i = 0; i < s.size(); ++i) {
			char c = s[i];
			if (bucket[c ] >= start) {  // ���c�ڵ�ǰ�Ӵ��г��ֹ�
				start = bucket[c] + 1;  // �����Ӵ�����ʼλ��
			}
			bucket[c ] = i;  // ��¼c���һ�γ��ֵ�λ��
			maxLen = max(maxLen, i - start + 1);  // ������Ӵ�����
		}
		return R2S(maxLen);
	}
private:
	string R2S(int r) {
		return to_string(r);
	}
	string s;
};