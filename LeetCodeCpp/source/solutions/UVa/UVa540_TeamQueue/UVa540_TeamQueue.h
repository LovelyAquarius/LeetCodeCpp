#pragma once
#include "PCH.h"
#include "system/sys.h"
class UVa540_TeamQueue :public Solution {
	using Team = map<int, int>;
	using OPERATION = vector<array<int,2> >;
	enum operation {
		enqueue=0,
		dequeue=1
	};
public://������
	UVa540_TeamQueue() = delete;
	UVa540_TeamQueue(const  vector<vector<int >>& members, const  vector<vector<int >>& ops)  {
		for (int i = 0; i < members.size(); i++) {
			for (int j = 0; j < members[i].size(); j++) {
				team[members[i][j]] = i;
			}
		}

		for (int i = 0; i < ops.size(); i++) {
			operations.push_back({ ops[i][0] ,ops[i][1] });
		}
	}
	~UVa540_TeamQueue() {};
public://�㷨����

	//�ⷨ1:����stl queue����ģ��
	//
	virtual Result solve1() override {
		queue<int> q1;//�ŶӵĶ���
		queue<int> q2[Maxteam];//�Ŷ�i��Ա�Ķ���
		vector<string> result;//���������

		//������������
		for (auto operation : operations) {
			if (operation[0] == operation::enqueue) {//���
				int t = team[operation[1]];
				if (q2[t].empty())
					q1.push(t);
				q2[t].push(operation[1]);
			}
			if (operation[0] == operation::dequeue) {//����
				int t = q1.front();//��ǰ��Ķ���
				result.push_back(to_string(q2[t].front()));
				q2[t].pop();
				if (q2[t].empty())
					q1.pop();
			}
		}
		return R2S(result);
	}






	virtual Result solve2() override {
		return Result();
	}

private:
	string R2S(const vector<string>& r) {
		string s;
		for (string w : r) {
			s += (w + "\n");
		}
		return s;
	}
	Team team;//team[x]��ʾ���x���������Ŷӱ��
	//operations[x][0]��ֵΪ0��1��0��ʾenqueue������1��ʾdequeue����
	//operations[x][1]�Ƕ�Ա��Ų���������dequeue����ʱ�������������
	OPERATION operations;
	static const int Maxteam = 1000;//��������1000��team
};