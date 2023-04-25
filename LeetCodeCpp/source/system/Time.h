#pragma once
#include <chrono>
#include <vector>
#include "system/application.h"
//�������������ǰ����һ����ʱ���ߣ����Լ����������ʱ�䣬�����ο�
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
class  Timer
{
public:

	Timer(const std::string& name, Fn&& function) :m_Name(name), m_Function(function), Stopped(false)
	{
		m_StartPoint = std::chrono::high_resolution_clock::now();
	}

	~Timer()
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
	std::string m_Name;
	Fn m_Function;
	std::chrono::time_point<std::chrono::steady_clock> m_StartPoint;
	bool Stopped;
};

struct ProfileMessage
{
	const std::string Name;
	float Time;
};

//������ʹ�÷�ʽ����һ���ֲ�{}����������һ������飬���˳�����ֲ������ʱ��ʱ�������
//ע���ڲ��Ե�ʱ�򾡿���ֻ����ĳ���㷨������Ҫ���������ݵ�io������Ҳһ������ˣ���Ҫ���Ե����ض����㷨��

//������Ե�����ֻ�����ο���
//Ŀǰ�����ʽ�Ǵ��ڲ�������ģ���Ϊ��һЩ���л���ںܶ಻Ӧ�ò�����Եĺ�������ȫ������
#define TIME_PROFILE(name) Timer Timer_##__LINE__(name,[&](ProfileMessage profile){std::cout<<profile.Name<<"��ʱ:"<<profile.Time<<"ms"<<std::endl;})