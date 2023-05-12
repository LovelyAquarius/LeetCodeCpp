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
	
	json sampledata = GetSampleData("personal", "personal1", "002");
	
	//�����㷨��ȷ��
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
	

	//�����㷨������
	{
		int i = 0;
		TIME_PROFILE(GenerateTitle("personal1 100000��", "001", "1"));
		while(i++<100000) {
			personal1 test = personal1(sampledata["number"]);
			test.solve1();
		}
		personal1 test = personal1(sampledata["number"]);
		cout << test.solve1();
	}
	{
		int i = 0;
		TIME_PROFILE(GenerateTitle("personal1 100000��", "001", "2"));
		while (i++ < 100000) {
			personal1 test = personal1(sampledata["number"]);
			test.solve2();
		}
		personal1 test = personal1(sampledata["number"]);
		cout << test.solve2();
	}
	{
		int i = 0;
		TIME_PROFILE(GenerateTitle("personal1 100000��", "001", "3"));
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


