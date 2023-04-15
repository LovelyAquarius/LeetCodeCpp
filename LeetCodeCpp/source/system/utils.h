#pragma once
#include <iostream>
#include <nlohmann/json.hpp>

//solutionid����Ŀid�����һ������ô����"leetcode1"
//sampleid �Ƕ�Ӧ��Ŀ�µ�sample.json�ļ�������Ŀ���ݵ�ÿ������������"001"
nlohmann::json  GetSampleData(std::string solutionid, std::string sampleid);


template <std::size_t N>
std::ostream& operator<<(std::ostream& os, std::array<int, N> const& value)
{
	os << '[';
	for (int i = 0; i < N - 1; i++)
	{
		os << value[i] << ',';
	}
	os << value[N - 1] << ']' << std::endl;
	return os;
}