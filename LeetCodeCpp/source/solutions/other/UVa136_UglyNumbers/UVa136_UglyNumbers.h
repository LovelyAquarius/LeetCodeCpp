#pragma once
#include "PCH.h"
#include "system/sys.h"
class UVa136_UglyNumbers :public Solution {

public://������
	UVa136_UglyNumbers() = delete;
	UVa136_UglyNumbers(const int n):n(n)  {}
	~UVa136_UglyNumbers() {};
public://�㷨����

	//�ⷨ1:����stl priority_queue�������ɵĳ���
	virtual Result solve1() override {
		const int coeffs[3] = { 2,3,5 };

		priority_queue<long long, vector<long long >, greater<long long>> pq;//������С�ѵ����ȶ���
		set<long long> s;//������Ŵ�С�������ɵĳ�����Ҳ������������ʽʵ���ظ����ɵ����ļ��
		pq.push(1);
		s.insert(1);
		for (int i = 1;; i++) {
			long long x = pq.top();
			pq.pop();
			if (i == n) {
				return R2S(x);
			}

			for (int coeff : coeffs) {
				long long y = x * coeff;//y�ǳ������������Ѿ����ɹ�
				if (!s.count(y)) {
					s.insert(y);
					pq.push(y);
				}
			}

		}


	}
	//�ⷨ2:��̬�滮+3ָ��,��������ȵ�һ��Ҫ��ܶ�	��O(n)
	virtual Result solve2() override {
		long long* a = new long long[n];
		long long p2 = 0, p3 = 0, p5 = 0;//p2,p3,p5��¼a�����±꣬�൱��ָ��

		// ��һ��������1
		a[0] = 1;
		for (long long i = 1; i < n; i++)
		{
			// ������һ������
			long long t2 = a[p2] * 2, t3 = a[p3] * 3, t5 = a[p5] * 5;
			a[i] = min(t2, min(t3, t5));//�ҳ�����3����������С���Ǹ���������һ������

			// ����ָ��
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
	const int n;//��ʾҪ���n������
};