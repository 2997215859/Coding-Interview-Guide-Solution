#include <iostream>
#include <vector>
#include <deque>
#include <cmath>

using namespace std;

class Node {
public:
    int value;
    Node *next;
    Node (int value): value(value), next(nullptr) {}
};


int getLive (int i, int m) {
    if (i == 1) return 1;
    return ((getLive(i-1, m) + m -1) % i + 1);
}

Node *josephusKill2 (Node *head, int m) {
    if (head == nullptr || head->next == head || m < 1) return head;

    Node *cur = head->next;
    int N = 1;
    while (cur != head) {
        N++;
        cur = cur->next;
    }

    int num = getLive(N, m);
    while (--num != 0) {
        head = head->next;
    }

    head->next = head;
    return head;
}

Node *josephusKill (Node *head, int m) {

    if (head == nullptr || head->next == head || m < 1) return head;

    Node *last = head;
    while (last->next != head) last = last->next;


    Node *cur = head;
    Node *pre = last;
    int cnt = 0;
    while (cur->next != cur) {
        if (++cnt == m) { // 删除当前节点
            pre->next = cur->next;
            cnt = 0;
        } else {
            pre = pre->next;
        }
        cur = pre->next;
    }

    return cur;
}

int main () {
    Node list1_head(1);
    Node list1_node1(2);
    Node list1_node2(4);
    Node list1_node3(5);

    list1_head.next = &list1_node1;
    list1_node1.next = &list1_node2;
    list1_node2.next = &list1_node3;
    list1_node3.next = &list1_head;


    Node *head = josephusKill2(&list1_head, 2);

    return 0;
}

