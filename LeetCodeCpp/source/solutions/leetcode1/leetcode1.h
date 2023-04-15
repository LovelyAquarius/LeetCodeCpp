#pragma once
#include "PCH.h"
#include "system/solution.h"
//给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
//你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
using namespace std;
class leetcode1 :public Solution
{
public:
    leetcode1() = delete;
    leetcode1(vector<int> nums, int target) //nums是输入样本数组，target是和的值
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