#pragma once
#include <iostream>
class Result 
{
public:
	Result(std::string resultInfo):resultInfo(resultInfo){}
	std::string getInfo() { return resultInfo; }
private:
	std::string resultInfo="no data!";
};

std::ostream& operator<<(std::ostream& os, Result result)
{
	os << result.getInfo()<< std::endl;
	return os;
}
