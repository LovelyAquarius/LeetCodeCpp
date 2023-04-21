#include "PCH.h"
#include "system/application.h"
#include "system/sys.h"
#include "exercise.h"


using json = nlohmann::json;


//本项目由github账户：LovelyAquarius制作，本人邮箱aq740928049@gmail.com
//这是一个轻量级的算法测试C++项目，目前还在完善中
//有时间精力的话可能会把它改成一个带ui的项目
//不过对于算法来说不是很重要，重要的是测试算法功能
//暂时就使用控制台来测试吧
//目前仅支持Windows平台
//项目暂时使用premake生成vs项目，有时间我会考虑其他平台的支持，camke支持。


int main() 
{
	App* app = App::getApp();
	
	json sampledata = GetSampleData("other", "UVa156_Ananagrams", "001");
	
	UVa156_Ananagrams test_1 = UVa156_Ananagrams(sampledata["words"]);
	{
		TIME_PROFILE(GenerateTitle("UVa156_Ananagrams", "001", "1"));
		cout << test_1.solve1();
	}
	//leetcode4 test_2 = leetcode4(sampledata["nums1"], sampledata["nums2"]);
	//{
	//	TIME_PROFILE(GenerateTitle("leetcode4", "001", "暴力合并"));
	//	cout << test_2.solve1();
	//}
	//leetcode3 test_3 = leetcode3(sampledata["s"]);
	//{
	//	TIME_PROFILE(GenerateTitle("leetcode3", "002", "3"));
	//	cout << test_2.solve3();
	//}
	getchar();
	return 0;
}


