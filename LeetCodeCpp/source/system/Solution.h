#pragma once
#include "system/Result.h"
using namespace std;
class Solution 
{
public:
	virtual ~Solution() {};
public:
	//Ҫע����Ƕ���ʵ���㷨���麯��������ÿ����ĿҪ���ص����Ͳ�һ����
	// ��ÿ����Ŀ��ʵ��һ����Ӧ��˽��ת������������ת��Ϊresult��
	// ��ô������Ϊ
	// (1)���ڽ����˵����ֻҪ�����ַ���Ϣ���ɣ����ݱ�����Ҫ
	// (2)����ά����ô�����Ŀ���㷨
	//Ĭ������������ʵ�ֵ��㷨�����ֻ��дһ����һ���������ֻ���ؿյ�result
	virtual Result solve1() = 0;
	virtual Result solve2() = 0;
	//�ж�����㷨�������
	//������˵һ����Ŀ�ܻ�3���㷨�Ѿ���������
	virtual Result solve3() { return Result(); };
	virtual Result solve4() { return Result(); };
	virtual Result solve5() { return Result(); };
};
