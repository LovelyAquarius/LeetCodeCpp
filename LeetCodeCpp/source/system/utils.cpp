#include "PCH.h"
#include "utils.h"
//�����·���ĵ����solution�ļ���
//������Ϊ���ý�����Ŀ�����ˣ������ʹ�ñ�ϵͳ���Լ���һ�����·��
//ֻҪ��solution���λ�þͿ�����
//��Ҫ���ԸĶ���Ŀ�Ĳ��֣��޷������ҿɲ���
const std::string solutionPath = "G:\\Mine\\LeetCode\\Cpp\\LeetCodeCpp\\source\\solutions";

nlohmann::json  GetSampleData(const std::string& solutiontype, const std::string& solutionid, const std::string& sampleid)
{
	std::string path = solutionPath + "\\" + solutiontype + "\\" + solutionid + "\\" + "sample.json";
	std::ifstream f(path);
	nlohmann::json data = nlohmann::json::parse(f);
	return data[sampleid];
}
std::string  GenerateTitle(const std::string solutionid, const std::string sampleid, const std::string methodName)
{
	std::string s = "��Ŀ��";
	return s + solutionid + "\n" + "���������� " + sampleid + "\n" + "ʹ�÷����� " + methodName + "\n";
}