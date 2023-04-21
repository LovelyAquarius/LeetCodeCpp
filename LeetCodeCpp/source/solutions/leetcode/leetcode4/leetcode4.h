#pragma once
#include "PCH.h"
#include "system/sys.h"

using namespace std;
class leetcode4 :public Solution {
public://������
	leetcode4() = delete;
	leetcode4(vector<int> nums1, vector<int> nums2 ):nums1(nums1), nums2(nums2){}
	virtual ~leetcode4() override {}
public://�㷨����
	

	//�ⷨ1:���ֲ��� ����ⷨ��ʱ�临�Ӷ�ֻ��O(log min(m+n)) ����������ĿҪ�����
	//O(n)
	virtual Result solve1() override {
		int m = nums1.size();
		int n = nums2.size();//��¼�������鳤��

		if ( m<= n ) {//��һ������϶�,��ô����Ϊ���ö��ֲ��ҵ�ʱ�临�Ӷȸ���
			int k = (m + n +1) / 2; // Ҫ�����λ��,��k����
			int left = 0, right = m - 1; // nums1 �Ķ��ֲ��ҷ�Χ
			while (left < right ) {
				int m1 = left + (right - left) / 2; // nums1 ���м�λ���±�
				int n1 = k -  m1 - 2; // nums2 ��Ҫ���ҵ�λ��
				if (nums1[m1] < nums2[n1])// nums1 �м�λ�õ�ֵС�� nums2 ��Ҫ���ҵ�ֵ��������� nums1 ���Ұ벿�ֲ���
					left = m1 + 1;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
				else right = m1; // ������ nums1 ����벿�ֲ���
			}
	
			
			int a = left ; //���൱�������Ԫ��������������߻��һ��
			int b = k - a - 2<0 ? 0 : k - a - 2; //b���п���С�ڵ���0�ģ��������������ֻ��һ��Ԫ��ʱ
			int c1 = max(a < 0 ? INT_MIN : nums1[a], b <= 0 ? INT_MIN : nums2[b]); // c1 Ϊ������ֵ(δ����)
			int c2 = min(a + 1 >= m ? INT_MAX : nums1[a+1], b+1 >= n ? INT_MAX : nums2[b+1]); // c2 Ϊ�Ҳ���Сֵ(δ����)
			int c3 = c1 < c2 ? c1 : c2;// c3 Ϊ������ֵ
			int c4 = c1 < c2 ? c2 : c1;//c4 Ϊ�Ҳ���Сֵ
			if ((m + n) % 2 == 1) return R2S(c3); // �����Ԫ����Ϊ��������ֱ�ӷ���������ֵ
			else return R2S((c3 + c4) / 2.0); // ������λ��
		}
		else {//�ڶ�������϶�
			int k = (n + m + 1) / 2; 
			int left = 0, right = n - 1; 
			while (left < right) {
				int n1 = left + (right - left - 1) / 2; // nums2 ���м�λ��
				int m1 = k - n1 - 2; // nums1 ��Ҫ���ҵ�λ��
				if (nums2[n1] < nums1[m1])
					left = n1 + 1; // nums1 �м�λ�õ�ֵС�� nums2 ��Ҫ���ҵ�ֵ��������� nums1 ���Ұ벿�ֲ���
				else right = n1; // ������ nums1 ����벿�ֲ���
			}
			int a = left; //���൱�������Ԫ��������������߻��һ��
			int b = k - a - 2 < 0 ? 0 : k - a - 2; //b���п���С�ڵ���0�ģ��������������ֻ��һ��Ԫ��ʱ
			int c1 = max(a < 0 ? INT_MIN : nums2[a], b <= 0 ? INT_MIN : nums1[b]); // c1 Ϊ������ֵ(δ����)
			int c2 = min(a + 1 >= m ? INT_MAX : nums2[a + 1], b + 1 >= n ? INT_MAX : nums1[b + 1]); // c2 Ϊ�Ҳ���Сֵ(δ����)
			int c3 = c1 < c2 ? c1 : c2;// c3 Ϊ������ֵ
			int c4 = c1 < c2 ? c2 : c1;//c4 Ϊ�Ҳ���Сֵ
			if ((m + n) % 2 == 1) return R2S(c3); // �����Ԫ����Ϊ��������ֱ�ӷ���������ֵ
			else return R2S((c3 + c4) / 2.0); // ������λ��
		}
	}

	//�ⷨ2:��̬�滮+��ϣ
	//O(n)
	virtual Result solve2() override {
		return Result();
	}
	//����ⷨ3:�����ϲ�������ⷨ��Ȼ���Եõ���ȷ��������ǲ�����O(log(m+n))��Ҫ��
	//�ϲ��������������ʱ�临�Ӷ��� O(m+n)
	//ע���������ʹ��stl��sort����ʱ�����������Բ����ֶ��鲢����
	//����ⷨ���Ե����ԱȲο�
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