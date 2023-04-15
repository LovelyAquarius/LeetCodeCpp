#include "PCH.h"
#include "system/application.h"
#include "system/Solution.h"
#include "system/utils.h"
#include "solutions/leetcode1/leetcode1.h"
#include "system/Time.h"
#include "system/Result.h"
using json = nlohmann::json;


//本项目由github账户：LovelyAquarius制作，本人邮箱740928049@qq.com
//这是一个轻量级的算法测试C++项目，目前还在完善中
//有时间精力的话可能会把它改成一个带ui的项目
//不过对于算法来说不是很重要，重要的是测试算法功能
//暂时就使用控制台来测试吧
//目前仅支持Windows平台
//项目暂时使用premake生成vs项目，有时间我会考虑其他平台的支持，camke支持。


int main() 
{
	//App* app = App::getApp();
	json sampledata = GetSampleData("leetcode1", "002");
	leetcode1 issue_1 = leetcode1(sampledata["nums"], sampledata["target"]);
	{
		TIME_PROFILE(GenerateTitle("leetcode1", "002" ,"暴力法"));
		cout << endl<< issue_1.solve1();
	}
	{
		TIME_PROFILE(GenerateTitle("leetcode1", "002", "哈希法"));
		cout << endl << issue_1.solve2() ;
	}
	
	getchar();
	return 0;
}


