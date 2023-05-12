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

//使用宏TIME_PROFILE时，可以用for循环多次运行同一算法，这样区别更大些
int main() 
{
	App* app = App::getApp();
	
	json sampledata = GetSampleData("personal", "personal1", "002");
	
	//测试算法正确性
	/*{
		personal1 test = personal1(sampledata["number"]);
		TIME_PROFILE(GenerateTitle("personal1", "001", "1"));
		cout << test.solve1();
	}
	{
		personal1 test = personal1(sampledata["number"]);
		TIME_PROFILE(GenerateTitle("personal1", "001", "2"));
		cout << test.solve2();
	}
	{
		personal1 test = personal1(sampledata["number"]);
		TIME_PROFILE(GenerateTitle("personal1", "001", "3"));
		cout << test.solve3();
	}*/
	

	//测试算法快速性
	{
		int i = 0;
		TIME_PROFILE(GenerateTitle("personal1 100000次", "001", "1"));
		while(i++<100000) {
			personal1 test = personal1(sampledata["number"]);
			test.solve1();
		}
		personal1 test = personal1(sampledata["number"]);
		cout << test.solve1();
	}
	{
		int i = 0;
		TIME_PROFILE(GenerateTitle("personal1 100000次", "001", "2"));
		while (i++ < 100000) {
			personal1 test = personal1(sampledata["number"]);
			test.solve2();
		}
		personal1 test = personal1(sampledata["number"]);
		cout << test.solve2();
	}
	{
		int i = 0;
		TIME_PROFILE(GenerateTitle("personal1 100000次", "001", "3"));
		while (i++ < 100000) {
			personal1 test = personal1(sampledata["number"]);
			test.solve3();
		}
		personal1 test = personal1(sampledata["number"]);
		cout << test.solve3();
	}


	
	getchar();
	return 0;
}


