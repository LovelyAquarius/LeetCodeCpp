#pragma once
#include "PCH.h"
#include "system/sys.h"
//����һ���������� nums ��һ������Ŀ��ֵ target�������ڸ��������ҳ� ��ΪĿ��ֵ target  ���� ���� ���������������ǵ������±ꡣ
//����Լ���ÿ������ֻ���Ӧһ���𰸡����ǣ�������ͬһ��Ԫ���ڴ��ﲻ���ظ����֡�
using namespace std;
class leetcode1 :public Solution
{
public://������
    leetcode1() = delete;
    leetcode1(vector<int> nums, int target) //nums�������������飬target�Ǻ͵�ֵ
        :Solution(), nums(nums), target(target) {}
    virtual ~leetcode1() override {};
public://�㷨����
    //���Խ���ⷨ2���ڽⷨ1
    //�ⷨ1
   virtual Result solve1() override {
        int i=0, j=0;
        array<int, 2> result;
        for (; i < nums.size() - 1; i++)
        {
            for (j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    result[0] = i;
                    result[1] = j;
                    return R2S(result);
                }
            }
        }
        return R2S(result);
    }
    //�ⷨ��
   virtual Result solve2() override {
        //std::unordered_map���ڹ�ϣʵ��
        unordered_map<int, int> map;
        array<int, 2> result{0,0}; // �洢���������

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i]; // ����Ŀ��ֵ�뵱ǰԪ�صĲ�ֵ
            if (map.count(complement)) { // �жϲ�ֵ�Ƿ��ڹ�ϣ����
                result[0] = map[complement]; // �洢��ֵ�ڹ�ϣ���ж�Ӧ���±�
                result[1] = i;// �洢��ǰԪ�ص��±�
                return R2S(result);
            }
            map[nums[i]] = i; // ����ǰԪ�ز����ϣ��
        }
        return R2S(result); // û���ҵ�
    }
   
private:
    string R2S(array<int, 2>& r)
    {
        string s = "[";
        return s + to_string(r[0]) + "," + to_string(r[1]) + "]";
    }
    vector<int> nums;
    int target;
};