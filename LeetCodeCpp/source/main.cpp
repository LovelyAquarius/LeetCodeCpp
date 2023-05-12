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
	
	json sampledata = GetSampleData("other", "lanqiao202314_01", "001");
	
	
	{
		lanqiao202314_01 test = lanqiao202314_01(sampledata["input"]);
		TIME_PROFILE(GenerateTitle("lanqiao202314_01", "001", "1"));
		cout << test.solve1();
	}
	/*{
		leetcode5 test = leetcode5(sampledata["s"]);
		TIME_PROFILE(GenerateTitle("leetcode5", "001", "2"));
		cout << test.solve2();
	}*/
	
	/*{
		int i = 0;
		TIME_PROFILE(GenerateTitle("leetcode5 30次", "001", "1"));
		while(i++<100000) {
			leetcode5 test = leetcode5(sampledata["s"]);
		}
		leetcode5 test = leetcode5(sampledata["s"]);
		cout << test.solve1();
	}
	{
		int i = 0;
		TIME_PROFILE(GenerateTitle("leetcode5 30次", "001", "2"));
		while (i++ < 100000) {
			leetcode5 test = leetcode5(sampledata["s"]);
		}
		leetcode5 test = leetcode5(sampledata["s"]);
		cout << test.solve1();
	}*/


	
	getchar();
	return 0;
}


