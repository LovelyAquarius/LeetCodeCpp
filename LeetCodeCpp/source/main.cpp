#include "PCH.h"
#include "system/application.h"
#include "system/sys.h"
//题目
#include "solutions/leetcode1/leetcode1.h"
#include "solutions/leetcode2/leetcode2.h"
#include "solutions/leetcode3/leetcode3.h"

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
	App* app = App::getApp();
	/*json sampledata = GetSampleData("leetcode1", "002");
	leetcode1 issue_1 = leetcode1(sampledata["nums"], sampledata["target"]);
	{
		TIME_PROFILE(GenerateTitle("leetcode1", "002" ,"暴力法"));
		cout << endl<< issue_1.solve1();
	}
	{
		TIME_PROFILE(GenerateTitle("leetcode1", "002", "哈希法"));
		cout << endl << issue_1.solve2() ;
	}*/
	json sampledata = GetSampleData("leetcode3", "003");

	leetcode3 test_1 = leetcode3(sampledata["s"]);
	{
		TIME_PROFILE(GenerateTitle("leetcode3", "002", "1"));
		cout << test_1.solve1();
	}
	leetcode3 test_2 = leetcode3(sampledata["s"]);
	{
		TIME_PROFILE(GenerateTitle("leetcode3", "002", "2"));
		cout << test_2.solve2();
	}
	leetcode3 test_3 = leetcode3(sampledata["s"]);
	{
		TIME_PROFILE(GenerateTitle("leetcode3", "002", "3"));
		cout << test_2.solve3();
	}
	getchar();
	return 0;
}


