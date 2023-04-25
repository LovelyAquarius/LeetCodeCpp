#pragma once
#include "PCH.h"
#include "system/sys.h"
class UVa136_UglyNumbers :public Solution {

public://构造器
	UVa136_UglyNumbers() = delete;
	UVa136_UglyNumbers(const int n):n(n)  {}
	~UVa136_UglyNumbers() {};
public://算法部分

	//解法1:采用stl priority_queue保存生成的丑数
	virtual Result solve1() override {
		const int coeffs[3] = { 2,3,5 };

		priority_queue<long long, vector<long long >, greater<long long>> pq;//定义最小堆的优先队列
		set<long long> s;//用来存放从小往大生成的丑数，也可以用其他方式实现重复生成的数的检测
		pq.push(1);
		s.insert(1);
		for (int i = 1;; i++) {
			long long x = pq.top();
			pq.pop();
			if (i == n) {
				return R2S(x);
			}

			for (int coeff : coeffs) {
				long long y = x * coeff;//y是丑数，但可能已经生成过
				if (!s.count(y)) {
					s.insert(y);
					pq.push(y);
				}
			}

		}


	}
	//解法2:动态规划+3指针,这个方法比第一种要快很多	，O(n)
	virtual Result solve2() override {
		long long* a = new long long[n];
		long long p2 = 0, p3 = 0, p5 = 0;//p2,p3,p5记录a数组下标，相当于指针

		// 第一个丑数是1
		a[0] = 1;
		for (long long i = 1; i < n; i++)
		{
			// 计算下一个丑数
			long long t2 = a[p2] * 2, t3 = a[p3] * 3, t5 = a[p5] * 5;
			a[i] = min(t2, min(t3, t5));//找出乘上3个因数后最小的那个，就是下一个丑数

			// 更新指针
			if (a[i] == t2) p2++;
			if (a[i] == t3) p3++;
			if (a[i] == t5) p5++;
		}
		long long result = a[n - 1];
		delete[] a;
		return R2S(result);
	}

private:
	string R2S(const long long& r) {
		string s ="The "+ to_string(n)+" 'th ugly number is ";
		return s+to_string(r)+"\n";
	}
	const int n;//表示要求第n个丑数
};