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
public://������
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
public://�㷨����
    //���ֽⷨʱ�临�Ӷ�һ������һ���ڿռ������ڵڶ���
    //���ܴӲ��Խ���ϵڶ��ֿ죬������������Ϊ��������С�����ߺ������������
    //Ŀǰ����㷨û�п���[1,7],[4,4]���ֽ�λ�����µĸ�λ������������費����ָ�λ��λ�����
    // 
    //�ⷨһ:����ӵ͵���ģ����ʽ�ӷ�
    //O(n)
    virtual Result solve1() override {
        ListNode* dummyHead = new ListNode(0); // ��������ͷ���
        ListNode* cur = dummyHead; // �����α��㣬��ʼʱָ������ͷ���
        int carry = 0; // ��λ
        while (l1 || l2) { // ͬʱ������������
            int x = (l1 != nullptr) ? l1->val : 0;
            int y = (l2 != nullptr) ? l2->val : 0;
            int sum = x + y + carry;//���������൱�ڴӵ�λ��ʼ��
            carry = sum / 10;
            cur->next = new ListNode(sum % 10); // �����½��
            cur = cur->next; // �α������
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }
        if (carry > 0) { // �������λ�Ľ�λ
            cur->next = new ListNode(carry);
        }
        return R2S(dummyHead->next); // ����������ͷ���
    }
    //�ⷨ����ѹջ��
    //O(n)
    virtual Result solve2() override{ 
        stack<int> s1, s2;  // ��������ջ�����ڴ洢��������Ľڵ�ֵ
        // ����������Ľڵ�ֵ����ѹ���Ӧ��ջ��
        while (l1 != nullptr) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2 != nullptr) {
            s2.push(l2->val);
            l2 = l2->next;
        }
       

        //����ڵ�����һ�£��Ը�λ��0
        if (s1.size() != s2.size()) {
            if (s1.size() < s2.size()) 
                while (s1.size() < s2.size()) {s1.push(0);}
            else
                while (s2.size() < s1.size()) { s2.push(0); }
        }

        stack<int> s3, s4;  // ��������ջ����ʱ��ԭ��������ջ��Ԫ�ط�ѹ������ջ�����ǵ�λ��Ԫ��
        while (!s1.empty()) {
            s3.push(s1.top());
            s1.pop();
        }
        while (!s2.empty()) {
            s4.push(s2.top());
            s2.pop();
        }

        ListNode* head = nullptr;  // ����һ���µ�����ͷ�ڵ�
        ListNode* current = nullptr;  //�����α�
        int carry = 0;  // �����λ����ʼΪ0

        // �������ջ�л���Ԫ�ػ��λ��Ϊ0�������ѭ��
        while (!s3.empty() || !s4.empty() || carry != 0) {
            // ���δ�����ջ��ȡ��ջ��Ԫ�ؽ��мӷ����㣬�����Ͻ�λ
            int sum = carry;
            if (!s3.empty()) {
                sum += s3.top();
                s3.pop();
            }
            if (!s4.empty()) {
                sum += s4.top();
                s4.pop();
            }
            // �����ӵĽ�����ڵ���10������Ҫ��λ
            if (sum >= 10) {
                carry = 1;
                sum -= 10;
            }
            else {
                carry = 0;
            }
            // ����ӵĽ�����뵽������

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