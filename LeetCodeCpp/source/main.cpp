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


