#include "PCH.h"
#include "Result.h"
std::ostream& operator<<(std::ostream& os, Result result)
{
	os << result.getInfo() << std::endl;
	return os;
}