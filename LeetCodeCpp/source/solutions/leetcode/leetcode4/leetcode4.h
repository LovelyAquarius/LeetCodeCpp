#pragma once
#include "PCH.h"
#include "system/sys.h"

using namespace std;
class leetcode4 :public Solution {
public://构造器
	leetcode4() = delete;
	leetcode4(vector<int> nums1, vector<int> nums2 ):nums1(nums1), nums2(nums2){}
	virtual ~leetcode4() override {}
public://算法部分
	

	//解法1:二分查找 这个解法的时间复杂度只有O(log min(m+n)) ，甚至比题目要求更快
	//O(n)
	virtual Result solve1() override {
		int m = nums1.size();
		int n = nums2.size();//记录两个数组长度

		if ( m<= n ) {//第一个数组较短,这么做是为了让二分查找的时间复杂度更低
			int k = (m + n +1) / 2; // 要求的中位数,第k个数
			int left = 0, right = m - 1; // nums1 的二分查找范围
			while (left < right ) {
				int m1 = left + (right - left) / 2; // nums1 的中间位置下标
				int n1 = k -  m1 - 2; // nums2 需要查找的位置
				if (nums1[m1] < nums2[n1])// nums1 中间位置的值小于 nums2 需要查找的值，则继续在 nums1 的右半部分查找
					left = m1 + 1;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
				else right = m1; // 否则在 nums1 的左半部分查找
			}
	
			
			int a = left ; //这相当于如果总元素是奇数，则左边会多一个
			int b = k - a - 2<0 ? 0 : k - a - 2; //b是有可能小于等于0的，比如两个数组均只有一个元素时
			int c1 = max(a < 0 ? INT_MIN : nums1[a], b <= 0 ? INT_MIN : nums2[b]); // c1 为左侧最大值(未调整)
			int c2 = min(a + 1 >= m ? INT_MAX : nums1[a+1], b+1 >= n ? INT_MAX : nums2[b+1]); // c2 为右侧最小值(未调整)
			int c3 = c1 < c2 ? c1 : c2;// c3 为左侧最大值
			int c4 = c1 < c2 ? c2 : c1;//c4 为右侧最小值
			if ((m + n) % 2 == 1) return R2S(c3); // 如果总元素数为奇数，则直接返回左侧最大值
			else return R2S((c3 + c4) / 2.0); // 返回中位数
		}
		else {//第二个数组较短
			int k = (n + m + 1) / 2; 
			int left = 0, right = n - 1; 
			while (left < right) {
				int n1 = left + (right - left - 1) / 2; // nums2 的中间位置
				int m1 = k - n1 - 2; // nums1 需要查找的位置
				if (nums2[n1] < nums1[m1])
					left = n1 + 1; // nums1 中间位置的值小于 nums2 需要查找的值，则继续在 nums1 的右半部分查找
				else right = n1; // 否则在 nums1 的左半部分查找
			}
			int a = left; //这相当于如果总元素是奇数，则左边会多一个
			int b = k - a - 2 < 0 ? 0 : k - a - 2; //b是有可能小于等于0的，比如两个数组均只有一个元素时
			int c1 = max(a < 0 ? INT_MIN : nums2[a], b <= 0 ? INT_MIN : nums1[b]); // c1 为左侧最大值(未调整)
			int c2 = min(a + 1 >= m ? INT_MAX : nums2[a + 1], b + 1 >= n ? INT_MAX : nums1[b + 1]); // c2 为右侧最小值(未调整)
			int c3 = c1 < c2 ? c1 : c2;// c3 为左侧最大值
			int c4 = c1 < c2 ? c2 : c1;//c4 为右侧最小值
			if ((m + n) % 2 == 1) return R2S(c3); // 如果总元素数为奇数，则直接返回左侧最大值
			else return R2S((c3 + c4) / 2.0); // 返回中位数
		}
	}

	//解法2:动态规划+哈希
	//O(n)
	virtual Result solve2() override {
		return Result();
	}
	//错误解法3:暴力合并，这个解法虽然可以得到正确输出，但是不满足O(log(m+n))的要求
	//合并两个有序数组的时间复杂度是 O(m+n)
	//注意这里如果使用stl的sort花费时间会更长，所以采用手动归并排序
	//这个解法可以当作对比参考
	virtual Result solve3() override {
			int m = nums1.size();
			int n = nums2.size();
			int t = m + n;
			vector<int> nums(t);
				int i = 0, j = 0, k = 0;
				while (i < m && j < n) {
					if (nums1[i] <= nums2[j]) 
						nums[k++] = nums1[i++];
					else 
						nums[k++] = nums2[j++];
				}
				while (i < m) 
					nums[k++] = nums1[i++];
				while (j < n) 
					nums[k++] = nums2[j++];

				if (t % 2 == 0) 
					return R2S((nums[t / 2 - 1] + nums[t / 2]) / 2.0);
				else 
					return R2S(nums[t / 2]);
	}
private:
	string R2S(double r) {
		return to_string(r);
	}
	vector<int> nums1;
	vector<int> nums2;
};