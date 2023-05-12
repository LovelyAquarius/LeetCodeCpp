#pragma once
#include "PCH.h"
#include "system/sys.h"
class lanqiao202314_01 :public Solution {
public://������
	lanqiao202314_01() = delete;
	lanqiao202314_01(const  vector<int >& input):L(input[0]),R(input[1]) {}
	~lanqiao202314_01() {};
public://�㷨����

	//�ⷨ1:�������ɱ���
	//������Ŀ��֪Ҫ��ƽ�������������ֵķ�Χ������[L,R]��
	//һ��˼·�Ǳ�����Щƽ��������������С��������ƽ����,
	// 0,1,4,9...
	// ����ֻ��Ҫ�����������ô����ֻ��¼���ɵ�����
	virtual Result solve1() override {
		int result = 0;//����������ƽ��������
		vector<int > sq;
		unordered_set<int> s;
		sq.push_back(0);
		sq.push_back(1);
		if (0 <= R && 0 >= L) {
			result++;
			s.insert(0);
		}
		for (int n = 3; ; n++) {
			int mindiff= sq.back()- sq[sq.size() - 2];//���������С��ֵ
			for (int i = 0; i < sq.size()-1; i++) {
				int sqd = sq.back() - sq[i];//ע����������i���ӣ����ɵ�ƽ����ݼ������������Ż��ռ��
				if (sqd <= R && sqd >= L && !s.count(sqd)) {
					result++;
					s.insert(sqd);
				}
			}
			if (mindiff > R)
				break;
			else {
				sq.push_back((n - 1)*(n-1));
			}
				
		}
		return R2S(result);
	}


	//�ⷨ������һ��˼·�Ǳ���x,����ÿ��x
	//x+z^2�Ƿ�Ϊƽ������
	virtual Result solve2() override {
		return Result();
	}

private:
	string R2S(const int r) {
		return to_string(r);
	}
	int L, R;
};