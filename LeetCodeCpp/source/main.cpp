#include "PCH.h"
#include "system/Solution.h"
#include "system/utils.h"
#include "solutions/leetcode1/leetcode1.h"
#include "system/Time.h"
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
	//vector<int> nums{ 2, 7, 11, 15 };
	//int target=9;
	json sampledata = GetSampleData("leetcode1", "001");
	leetcode1 issue_1 = leetcode1(sampledata["nums"], sampledata["target"]);
	{
		TIME_PROFILE("����");
		cout << issue_1.solve1() << endl;
	}
	
	//cout << GetSampleData("leetcode1","001")["target"] << endl;
	getchar();
	return 0;
}


