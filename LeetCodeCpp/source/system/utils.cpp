#include "PCH.h"
#include "utils.h"
//把这个路径改到你的solution文件夹
//这里因为懒得进行项目配置了，如果想使用本系统请自己改一下这个路径
//只要到solution这个位置就可以了
//不要擅自改动项目的布局，无法运行我可不管
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
	std::string s = "题目：";
	return s + solutionid + "\n" + "输入样本： " + sampleid + "\n" + "使用方法： " + methodName + "\n";
}