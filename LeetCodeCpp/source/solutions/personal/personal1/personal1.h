#pragma once
#include "PCH.h"
#include "system/sys.h"

//������⿴�Ƽ򵥣�����ʵ��������Ҫ���Ǻܶණ��
class personal1 :public Solution {
public://������
	personal1() = delete;
	personal1(const int number) :number(number){ 
}
	virtual ~personal1() override {}
public://�㷨����
	

	//�ⷨ1:���ַ�
	// �����ҷ�Χ��1��number��һ�������С���ҵ�ƽ������
	// ���Ƽ�����㷨
	// �㷨��ʱ�临�Ӷ�ΪO(log n)
	
	virtual Result solve1() override {
		if (number < 0) {
			return R2S(false); // ��������ƽ����
		}

		if (number <= 1) {
			return R2S(true); // 0��1��ƽ����
		}

		int left = 1; // ��߽��1��ʼ
		int right = number / 2; // �ұ߽��number��һ�뿪ʼ
		while (left <= right) {
			int mid = left + (right - left) / 2; // �����м�ֵ

			// ����м�ֵ��ƽ������number���򷵻�true
			if (mid * mid ==number) {
				return R2S(true);
			}

			// ����м�ֵ��ƽ������number�����ұ߽������mid-1
			if (mid > number / mid) {
				right = mid - 1;
			}
			else {
				// ����м�ֵ��ƽ��С��number������߽������mid+1
				left = mid + 1;
			}
		}
		return R2S(false);
	}

	//�ⷨ2:ţ�ٵ�����
	// ԭ����������
	// ��ⷽ��x^2 - number = 0�ĸ�
	// ������ʽx = (x + number / x) / 2
	// ���������ʽ���Ƶ����õ���̩�ռ���չ����������ʱû�������Ƶ��ˡ�
	// ţ�ٵ�����ͨ�����п������������ԣ������Ƕ��ھ��й⻬�ҵ����Եĺ��������ж�һ�����Ƿ�Ϊƽ�����������У�ͨ�����ϵ���ʹ��ţ�ٵ���������Ч�رƽ�ƽ�������Ӷ��жϸ������Ƿ�Ϊƽ����
	// ���������ĳ�̶ֳ���Ҫ�ȶ��ָ���
	// �������������ʵ���ϴ�����������ķ��գ�Ҳ����������жϵ�ֵ�������ƣ����ȡ����longlong�ܴ����ֵ
	//O(log n)
	
	virtual Result solve2() override {
		if (number < 0) {
			return R2S(false); // ��������ƽ����
		}

		if (number <= 1) {
			return R2S(true); // 0��1��ƽ����
		}

		long long x = number; // ʹ��long���ͽ��м��㣬��ֹ�������

		while (x * x > number) {
			x = (x + number / x) / 2; // ţ�ٵ������Ĺ�ʽ
		}

		return R2S(x * x == number); // ��x��ƽ������numberʱ����true�����򷵻�false
	}
	//�ⷨ3:�������������ο�
	//����˼·�Ǵ�0��ʼ����ÿ��������ƽ���Ƿ��������
	//����������ĳ��������ƽ�������������ֹͣ����
	//����Ȼ�������������ƽ����ֵ���Խ��Խ��Ч��Խ��Խ��
	//O(��n)
	virtual Result solve3() override {
		int temp = 0;
		int i = 0;
		bool result = false;
		while (temp < number) {
			temp = i * i;
			if (temp == number) {
				result = true;
				break;
			}
			i++;
		}
		return R2S(result);
	}


private:
	std::string R2S(bool r) {
		return r ? "ture" : "false";
	}
	 const int number;
};