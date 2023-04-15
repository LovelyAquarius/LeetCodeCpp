#pragma once
#include <chrono>
#include <vector>
//这个工具是我以前做的一个计时工具，可以监测程序的运行时间，仅作参考
class  DeltaTime
{
public:
	DeltaTime(float time = 0.0f) :m_Time(time) {}

	operator float() { return m_Time; }
public:
	float GetSeconds()const { return m_Time; }
	float GetMilliseconds()const { return m_Time * 1000.0f; }
private:
	float m_Time;

};

template<typename Fn>
class  AQTimer
{
public:

	AQTimer(const char* name, Fn&& function) :m_Name(name), m_Function(function), Stopped(false)
	{
		m_StartPoint = std::chrono::high_resolution_clock::now();
	}

	~AQTimer()
	{
		if (!Stopped)
			Stop();
	}
	void Stop()
	{
		auto endpoint = std::chrono::high_resolution_clock::now();

		long long start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartPoint).time_since_epoch().count();
		long long end = std::chrono::time_point_cast<std::chrono::microseconds>(endpoint).time_since_epoch().count();
		Stopped = true;

		float duration = (end - start) * 0.001f;
		m_Function({ m_Name, duration });

	}

private:
	const char* m_Name;
	Fn m_Function;
	std::chrono::time_point<std::chrono::steady_clock> m_StartPoint;
	bool Stopped;
};

struct ProfileMessage
{
	const char* Name;
	float Time;
};

//这个宏的使用方式是用一个局部{}花括号括起一个程序块，在退出这个局部程序块时计时并输出。
/*示例
* {
		TIME_PROFILE("测试");
		cout << issue_1.solve1() << endl;
}
//注意在测试的时候尽可能只测试某个算法，而不要把其他数据的io操作等也一起测试了，需要测试的是特定的算法。
*/
//这个测试的数据只能作参考。
#define TIME_PROFILE(name) AQTimer Timer_##__LINE__(name,[&](ProfileMessage profile){std::cout<<profile.Name<<":用时"<<profile.Time<<"ms"<<std::endl;})