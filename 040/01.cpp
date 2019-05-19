#include <iostream>
#include <vector>
#include <deque>
#include <cmath>

using namespace std;

class DoubleNode {
public:
    int value;
    DoubleNode *last;
    DoubleNode *next;
    DoubleNode(int value): value(value), last(nullptr), next(nullptr) {}
};

class Node {
public:
    int value;
    Node *next;
    Node (int value): value(value), next(nullptr) {}
};

DoubleNode *reverseList (DoubleNode *head) {
    DoubleNode *pre = nullptr;
    DoubleNode *cur = head;
    DoubleNode *next = nullptr;

    while (cur != nullptr) {
        next = cur->next;
        cur->next = pre;
        cur->last = next;
        pre = cur;
        cur = next;
    }

    return pre;
}

Node *reverseList (Node *head) {
    Node *pre = nullptr;
    Node *cur = head;
    Node *next = nullptr;

    while (cur != nullptr) {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }

    return pre;
}

int main () {
    Node list1_head(1);
    Node list1_node1(2);
    Node list1_node2(4);
    Node list1_node3(5);

    list1_head.next = &list1_node1;
    list1_node1.next = &list1_node2;
    list1_node2.next = &list1_node3;

    DoubleNode  list2_head(1);
    DoubleNode  list2_node1(2);
    DoubleNode  list2_node2(4);
    DoubleNode  list2_node3(5);

    list2_head.next = &list2_node1;
    list2_node1.next = &list2_node2;
    list2_node2.next = &list2_node3;

    list2_node3.last = &list2_node2;
    list2_node2.last = &list2_node1;
    list2_node1.last = &list2_head;

    Node *head = reverseList(&list1_head);

    DoubleNode *head2 = reverseList(&list2_head);

    return 0;
}

