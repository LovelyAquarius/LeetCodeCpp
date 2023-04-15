#pragma once
#include <iostream>
#include <nlohmann/json.hpp>

//solutionid是题目id比如第一道题那么就是"leetcode1"
//sampleid 是对应题目下的sample.json文件夹中题目数据的每个键名，比如"001"
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