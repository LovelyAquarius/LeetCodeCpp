#include "PCH.h"
#include "system/application.h"
#include "system/sys.h"
#include "exercise.h"


using json = nlohmann::json;


//����Ŀ��github�˻���LovelyAquarius��������������aq740928049@gmail.com
//����һ�����������㷨����C++��Ŀ��Ŀǰ����������
//��ʱ�侫���Ļ����ܻ�����ĳ�һ����ui����Ŀ
//���������㷨��˵���Ǻ���Ҫ����Ҫ���ǲ����㷨����
//��ʱ��ʹ�ÿ���̨�����԰�
//Ŀǰ��֧��Windowsƽ̨
//��Ŀ��ʱʹ��premake����vs��Ŀ����ʱ���һῼ������ƽ̨��֧�֣�camke֧�֡�

//ʹ�ú�TIME_PROFILEʱ��������forѭ���������ͬһ�㷨�������������Щ
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
		TIME_PROFILE(GenerateTitle("leetcode5 30��", "001", "1"));
		while(i++<100000) {
			leetcode5 test = leetcode5(sampledata["s"]);
		}
		leetcode5 test = leetcode5(sampledata["s"]);
		cout << test.solve1();
	}
	{
		int i = 0;
		TIME_PROFILE(GenerateTitle("leetcode5 30��", "001", "2"));
		while (i++ < 100000) {
			leetcode5 test = leetcode5(sampledata["s"]);
		}
		leetcode5 test = leetcode5(sampledata["s"]);
		cout << test.solve1();
	}*/


	
	getchar();
	return 0;
}


