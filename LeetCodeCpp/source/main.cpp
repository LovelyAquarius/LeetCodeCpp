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
	
	json sampledata = GetSampleData("other", "UVa156_Ananagrams", "001");
	
	UVa156_Ananagrams test_1 = UVa156_Ananagrams(sampledata["words"]);
	{
		TIME_PROFILE(GenerateTitle("UVa156_Ananagrams", "001", "1"));
		cout << test_1.solve1();
	}
	//leetcode4 test_2 = leetcode4(sampledata["nums1"], sampledata["nums2"]);
	//{
	//	TIME_PROFILE(GenerateTitle("leetcode4", "001", "�����ϲ�"));
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


