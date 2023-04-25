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
	
	json sampledata = GetSampleData("other", "UVa136_UglyNumbers", "002");
	
	
	{
		UVa136_UglyNumbers test_2 = UVa136_UglyNumbers(sampledata["n"]);
		TIME_PROFILE(GenerateTitle("UVa136_UglyNumbers", "001", "2"));
		cout << test_2.solve2();
	}
	{
		UVa136_UglyNumbers test_1 = UVa136_UglyNumbers(sampledata["n"]);
		TIME_PROFILE(GenerateTitle("UVa136_UglyNumbers", "001", "1"));
		cout << test_1.solve1();
	}

	
	getchar();
	return 0;
}


