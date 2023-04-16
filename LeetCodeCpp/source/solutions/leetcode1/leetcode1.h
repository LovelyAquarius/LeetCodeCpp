#pragma once
#include "PCH.h"
#include "system/sys.h"
//给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
//你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
using namespace std;
class leetcode1 :public Solution
{
public://构造器
    leetcode1() = delete;
    leetcode1(vector<int> nums, int target) //nums是输入样本数组，target是和的值
        :Solution(), nums(nums), target(target) {}
    virtual ~leetcode1() override {};
public://算法部分
    //测试结果解法2优于解法1
    //解法1
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
    //解法二
   virtual Result solve2() override {
        //std::unordered_map基于哈希实现
        unordered_map<int, int> map;
        array<int, 2> result{0,0}; // 存储结果的数组

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i]; // 计算目标值与当前元素的差值
            if (map.count(complement)) { // 判断差值是否在哈希表中
                result[0] = map[complement]; // 存储差值在哈希表中对应的下标
                result[1] = i;// 存储当前元素的下标
                return R2S(result);
            }
            map[nums[i]] = i; // 将当前元素插入哈希表
        }
        return R2S(result); // 没有找到
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