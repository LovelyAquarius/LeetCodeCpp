#include "PCH.h"
#include "system/application.h"
#include "system/Solution.h"
#include "system/utils.h"
#include "solutions/leetcode1/leetcode1.h"
#include "system/Time.h"
#include "system/Result.h"
using json = nlohmann::json;


//����Ŀ��github�˻���LovelyAquarius��������������740928049@qq.com
//����һ�����������㷨����C++��Ŀ��Ŀǰ����������
//��ʱ�侫���Ļ����ܻ�����ĳ�һ����ui����Ŀ
//���������㷨��˵���Ǻ���Ҫ����Ҫ���ǲ����㷨����
//��ʱ��ʹ�ÿ���̨�����԰�
//Ŀǰ��֧��Windowsƽ̨
//��Ŀ��ʱʹ��premake����vs��Ŀ����ʱ���һῼ������ƽ̨��֧�֣�camke֧�֡�


int main() 
{
	//App* app = App::getApp();
	json sampledata = GetSampleData("leetcode1", "002");
	leetcode1 issue_1 = leetcode1(sampledata["nums"], sampledata["target"]);
	{
		TIME_PROFILE(GenerateTitle("leetcode1", "002" ,"������"));
		cout << endl<< issue_1.solve1();
	}
	{
		TIME_PROFILE(GenerateTitle("leetcode1", "002", "��ϣ��"));
		cout << endl << issue_1.solve2() ;
	}
	
	getchar();
	return 0;
}


