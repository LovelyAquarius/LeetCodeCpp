#pragma once
#include "PCH.h"
#include "system/sys.h"
class lanqiao202314_01 :public Solution {
public://构造器
	lanqiao202314_01() = delete;
	lanqiao202314_01(const  vector<int >& input):L(input[0]),R(input[1]) {}
	~lanqiao202314_01() {};
public://算法部分

	//解法1:暴力生成遍历
	//分析题目可知要求平方差所生成数字的范围在区间[L,R]里
	//一种思路是遍历这些平方数，并挨个从小到大生成平方数,
	// 0,1,4,9...
	// 由于只需要输出个数，那么就用只记录生成的数量
	virtual Result solve1() override {
		int result = 0;//符合条件的平方数数量
		vector<int > sq;
		unordered_set<int> s;
		sq.push_back(0);
		sq.push_back(1);
		if (0 <= R && 0 >= L) {
			result++;
			s.insert(0);
		}
		for (int n = 3; ; n++) {
			int mindiff= sq.back()- sq[sq.size() - 2];//用来检测最小差值
			for (int i = 0; i < sq.size()-1; i++) {
				int sqd = sq.back() - sq[i];//注意这里随着i增加，生成的平方差递减，这里是有优化空间的
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


	//解法二：另一种思路是遍历x,对于每个x
	//x+z^2是否为平方数，
	virtual Result solve2() override {
		return Result();
	}

private:
	string R2S(const int r) {
		return to_string(r);
	}
	int L, R;
};