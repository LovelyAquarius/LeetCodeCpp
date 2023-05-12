#pragma once
#include "PCH.h"
#include "system/sys.h"

using namespace std;
class leetcode5 :public Solution {
public://������
	leetcode5() = delete;
	leetcode5(const string& s) :s(s) { }
	virtual ~leetcode5() override {}
public://�㷨����
	

	//�ⷨ1:����������ɢ
	//O(n)
	virtual Result solve1() override {
		int maxlength = 0;
		int start = 0, end = 0;
		for (int i = 0; i < s.length(); i++) 
		{
			int left1 = i, right1 = i;
			int left2 = i, right2 = i== s.length() ?i:i+1;
			while (left1 > 0 && right1 < s.length() - 1) {//���ĵ���Ԫ��
				if (s[left1 - 1] == s[right1 + 1]) {
					left1--; right1++;
				}
				else
					break;
			}

			//����������Ԫ��
			if (s[left2] != s[right2]) {//���ж�������Ԫ���Ƿ����
				right2--;
			}
			else {
				while (left2 > 0 && right2 < s.length() - 1 && left2 != right2) {
					if (s[left2 - 1] == s[right2 + 1]) {
						left2--; right2++;
					}
					else
						break;
				}
			}
			

			if (right1 - left1 + 1 > maxlength) {
				maxlength = right1 - left1 + 1;
				start = left1;
				end = right1;
			}
			if (right2 - left2 + 1 > maxlength) {
				maxlength = right2 - left2 + 1;
				start = left2;
				end = right2;
			}
		}
		return s.substr(start, end - start +1);
	}

	//�ⷨ2:��̬�滮
	
	virtual Result solve2() override {
		const int size = int(s.length());
		int max = 1;//��¼����ĳ���
		int start = 0;//��¼�������ʼλ��
		if (size <= 1) {
			return s;
		}
		//dp[i][j],i��ʾ�Ӵ���λ�ã�j��ʾ�Ӵ���λ��,i<j
		auto dp = new bool*[size];
		for (int row = 0; row < size; row++) {
			dp[row] = new bool[size];
		}
		for (int i = 0; i < size; i++) {
			dp[i][i] = true;//�Խ���Ԫ��ȫ�ǻ���
			if (i + 1 < size) {
				if ((dp[i][i + 1] = s[i] == s[i + 1] ? true : false) && max < 2) {//�Խ����Ϸ���Ԫ�ؿɶ����ж��Ƿ�Ϊ����
					max = 2; start = i;
				}
			}
		}//��ʼ�����

		for (int width = 2; width < size; width++) {//����б���Ͻ���״̬ת��
			//����ϸ���ϻ������Ż���������˼·��������
			for (int i = 0; i < size; i++) {
				if (i + width < size) {
					if ( (dp[i][i + width] = s[i] == s[i + width] && dp[i + 1][i + width - 1]) && width+1>max) {
						max = width + 1; start = i;
					}
				}
			}
		}
		return s.substr(start, max);
	}

	virtual Result solve3() override {
		return Result();
	}


private:
	const string s;
};