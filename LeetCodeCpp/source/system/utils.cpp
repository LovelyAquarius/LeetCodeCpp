#include "PCH.h"
#include "utils.h"
//�����·���ĵ����solution�ļ���
//������Ϊ���ý�����Ŀ�����ˣ������ʹ�ñ�ϵͳ���Լ���һ�����·��
//ֻҪ��solution���λ�þͿ�����
//��Ҫ���ԸĶ���Ŀ�Ĳ��֣��޷������ҿɲ���
const std::string solutionPath = "G:\\Mine\\LeetCode\\Cpp\\LeetCodeCpp\\source\\solutions";

nlohmann::json  GetSampleData(std::string solutionid, std::string sampleid)
{
	std::string path = solutionPath + "\\" + solutionid + "\\" + "sample.json";
	std::ifstream f(path);
	nlohmann::json data = nlohmann::json::parse(f);
	return data[sampleid];
}