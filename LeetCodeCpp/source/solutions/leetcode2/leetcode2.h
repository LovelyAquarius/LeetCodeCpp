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
    //两种解法时间复杂度一样，第一种在空间上优于第二种
    //尽管从测试结果上第二种快，不过这大概是因为数据样本小，或者和语言特性相关
    //目前这个算法没有考虑[1,7],[4,4]这种进位会多出新的高位的情况，并假设不会出现高位进位的情况
    // 
    //解法一:链表从低到高模拟竖式加法
    //O(n)
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
    //解法二：压栈法
    //O(n)
    virtual Result solve2() override{ 
        stack<int> s1, s2;  // 定义两个栈，用于存储两个链表的节点值
        // 把两个链表的节点值依次压入对应的栈中
        while (l1 != nullptr) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2 != nullptr) {
            s2.push(l2->val);
            l2 = l2->next;
        }
       

        //如果节点数不一致，对高位补0
        if (s1.size() != s2.size()) {
            if (s1.size() < s2.size()) 
                while (s1.size() < s2.size()) {s1.push(0);}
            else
                while (s2.size() < s1.size()) { s2.push(0); }
        }

        stack<int> s3, s4;  // 定义两个栈，这时把原来的两个栈的元素反压，这样栈顶才是低位的元素
        while (!s1.empty()) {
            s3.push(s1.top());
            s1.pop();
        }
        while (!s2.empty()) {
            s4.push(s2.top());
            s2.pop();
        }

        ListNode* head = nullptr;  // 定义一个新的链表头节点
        ListNode* current = nullptr;  //定义游标
        int carry = 0;  // 定义进位，初始为0

        // 如果两个栈中还有元素或进位不为0，则继续循环
        while (!s3.empty() || !s4.empty() || carry != 0) {
            // 依次从两个栈中取出栈顶元素进行加法运算，并加上进位
            int sum = carry;
            if (!s3.empty()) {
                sum += s3.top();
                s3.pop();
            }
            if (!s4.empty()) {
                sum += s4.top();
                s4.pop();
            }
            // 如果相加的结果大于等于10，则需要进位
            if (sum >= 10) {
                carry = 1;
                sum -= 10;
            }
            else {
                carry = 0;
            }
            // 将相加的结果插入到新链表

            ListNode* node = new ListNode(sum);
            if(current)
                current->next = node;
            current = node;

            if (!head)
                head = node;
        }
        return R2S(head);
    }
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