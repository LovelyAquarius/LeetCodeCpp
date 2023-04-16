#pragma once
#include "system/Result.h"
using namespace std;
class Solution 
{
public:
	virtual ~Solution() {};
public:
	//要注意的是对于实现算法的虚函数，由于每个题目要返回的类型不一样，
	// 在每个题目里实现一个对应的私有转换函数，将其转换为result。
	// 这么做是因为
	// (1)对于结果来说我们只要看到字符信息即可，数据本身不重要
	// (2)方便维护这么多的题目和算法
	//默认有两个必须实现的算法，如果只能写一个另一个函数体就只返回空的result
	virtual Result solve1() = 0;
	virtual Result solve2() = 0;
	//有多余的算法自行添加
	//对我来说一个题目能会3个算法已经很逆天了
	virtual Result solve3() { return Result(); };
	virtual Result solve4() { return Result(); };
	virtual Result solve5() { return Result(); };
};
