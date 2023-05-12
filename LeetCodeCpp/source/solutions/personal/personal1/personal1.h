#pragma once
#include "PCH.h"
#include "system/sys.h"

//这个问题看似简单，但其实处理起来要考虑很多东西
class personal1 :public Solution {
public://构造器
	personal1() = delete;
	personal1(const int number) :number(number){ 
}
	virtual ~personal1() override {}
public://算法部分
	

	//解法1:二分法
	// 将查找范围从1到number的一半进行缩小，找到平方根。
	// 更推荐这个算法
	// 算法的时间复杂度为O(log n)
	
	virtual Result solve1() override {
		if (number < 0) {
			return R2S(false); // 负数不是平方数
		}

		if (number <= 1) {
			return R2S(true); // 0和1是平方数
		}

		int left = 1; // 左边界从1开始
		int right = number / 2; // 右边界从number的一半开始
		while (left <= right) {
			int mid = left + (right - left) / 2; // 计算中间值

			// 如果中间值的平方等于number，则返回true
			if (mid * mid ==number) {
				return R2S(true);
			}

			// 如果中间值的平方大于number，将右边界调整到mid-1
			if (mid > number / mid) {
				right = mid - 1;
			}
			else {
				// 如果中间值的平方小于number，将左边界调整到mid+1
				left = mid + 1;
			}
		}
		return R2S(false);
	}

	//解法2:牛顿迭代法
	// 原理是这样的
	// 求解方程x^2 - number = 0的根
	// 迭代公式x = (x + number / x) / 2
	// 关于这个公式的推导，用的是泰勒级数展开，这里暂时没法文字推导了。
	// 牛顿迭代法通常具有快速收敛的特性，尤其是对于具有光滑且单峰性的函数。在判断一个数是否为平方数的问题中，通过不断迭代使用牛顿迭代法，高效地逼近平方根，从而判断给定数是否为平方数
	// 这个方法在某种程度上要比二分更快
	// 不过这个方法在实现上存在算术溢出的风险，也就是最大能判断的值将有限制，这个取决于longlong能存多大的值
	//O(log n)
	
	virtual Result solve2() override {
		if (number < 0) {
			return R2S(false); // 负数不是平方数
		}

		if (number <= 1) {
			return R2S(true); // 0和1是平方数
		}

		long long x = number; // 使用long类型进行计算，防止整数溢出

		while (x * x > number) {
			x = (x + number / x) / 2; // 牛顿迭代法的公式
		}

		return R2S(x * x == number); // 当x的平方等于number时返回true，否则返回false
	}
	//解法3:暴力法，用作参考
	//具体思路是从0开始遍历每个整数的平方是否是这个数
	//当遍历到的某个整数的平方大于这个数就停止遍历
	//很显然这个方法会随着平方数值变得越来越大，效率越来越低
	//O(√n)
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