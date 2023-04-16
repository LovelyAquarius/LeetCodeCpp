#pragma once
#include "PCH.h"
#include "system/sys.h"

using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class leetcode2 :public Solution
{
public://构造器
    leetcode2() = delete;
    leetcode2(vector<int> v1, vector<int> v2) {
        l1 = new ListNode();
        ListNode* C1 = l1;
        l2 = new ListNode();
        ListNode* C2 = l2;
        if (v1.size())
            l1->val = v1[0];
        for (int i = 1; i < v1.size(); i++) {
            ListNode* newnode = new ListNode(v1[i]);
            C1->next = newnode;
            C1 = newnode;
        }
        if (v2.size())
            l2->val = v2[0];
        for (int i = 1; i < v2.size(); i++) {
            ListNode* newnode = new ListNode(v2[i]);
            C2->next = newnode;
            C2 = newnode;
        }
    }
    virtual ~leetcode2() override {
        if (l1) {
            ListNode* next2delete = l1;
            while (next2delete) {
                ListNode* now2delete = next2delete;
                next2delete = next2delete->next;
                delete now2delete;
            }
        }
        if (l2) {
            ListNode* next2delete = l2;
            while (next2delete) {
                ListNode* now2delete = next2delete;
                next2delete = next2delete->next;
                delete now2delete;
            }
        }
    }
public://算法部分
    //解法一
    virtual Result solve1() override {
        ListNode* dummyHead = new ListNode(0); // 定义虚拟头结点
        ListNode* cur = dummyHead; // 定义游标结点，初始时指向虚拟头结点
        int carry = 0; // 进位
        while (l1 || l2) { // 同时遍历两个链表
            int x = (l1 != nullptr) ? l1->val : 0;
            int y = (l2 != nullptr) ? l2->val : 0;
            int sum = x + y + carry;//按题意这相当于从低位开始加
            carry = sum / 10;
            cur->next = new ListNode(sum % 10); // 创建新结点
            cur = cur->next; // 游标结点后移
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }
        if (carry > 0) { // 处理最高位的进位
            cur->next = new ListNode(carry);
        }
        return R2S(dummyHead->next); // 返回真正的头结点
    }
    //解法二
    virtual Result solve2() override{ return Result(); }
private:
    string R2S(ListNode* r) {
        string result;
        ListNode* c = r;
        while (c) {
            result += to_string(c->val) + "->";
            c = c->next;
        }
        if (!result.empty())
            result.erase(result.length() - 2, 2);
        return result;

    }
    ListNode* l1=nullptr, * l2=nullptr;
};