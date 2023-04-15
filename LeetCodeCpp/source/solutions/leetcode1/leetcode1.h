#pragma once
#include "PCH.h"
#include "system/solution.h"
//����һ���������� nums ��һ������Ŀ��ֵ target�������ڸ��������ҳ� ��ΪĿ��ֵ target  ���� ���� ���������������ǵ������±ꡣ
//����Լ���ÿ������ֻ���Ӧһ���𰸡����ǣ�������ͬһ��Ԫ���ڴ��ﲻ���ظ����֡�
using namespace std;
class leetcode1 :public Solution
{
public:
    leetcode1() = delete;
    leetcode1(vector<int> nums, int target) //nums�������������飬target�Ǻ͵�ֵ
        :Solution(), nums(nums), target(target) {}
    array<int, 2> solve1() {
        int i=0, j=0;
        for (; i < nums.size() - 1; i++)
        {
            for (j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    return { i,j };
                }
            }
        }
        return { i,j };
    }
private:
    vector<int> nums;
    int target;
};