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
public://构造器
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
public://算法部分

	//解法1:采用stl queue进行模拟
	//
	virtual Result solve1() override {
		queue<int> q1;//团队的队列
		queue<int> q2[Maxteam];//团队i成员的队列
		vector<string> result;//结果输出语句

		//遍历操作序列
		for (auto operation : operations) {
			if (operation[0] == operation::enqueue) {//入队
				int t = team[operation[1]];
				if (q2[t].empty())
					q1.push(t);
				q2[t].push(operation[1]);
			}
			if (operation[0] == operation::dequeue) {//出队
				int t = q1.front();//最前面的队伍
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
	Team team;//team[x]表示编号x的人所在团队编号
	//operations[x][0]的值为0或1，0表示enqueue操作，1表示dequeue操作
	//operations[x][1]是队员编号操作数，当dequeue操作时这个操作数忽略
	OPERATION operations;
	static const int Maxteam = 1000;//假设至多1000个team
};