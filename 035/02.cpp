#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class DoubleNode {
public:
    int value;
    DoubleNode *next;
    DoubleNode *last;
    DoubleNode (int value): value(value), next(nullptr), last(nullptr) {}
};

DoubleNode * removeLastKthNode (DoubleNode  *head, int k) {
    DoubleNode  *cur = head;
    while (cur != nullptr) {
        k--;
        cur = cur->next;
    }

    if (k == 0) {
        head = head->next;
        head->last = nullptr;
    }
    if (k < 0) {
        DoubleNode *cur = head;
        while (++k != 0) cur = cur->next;
        cur->next = cur->next->next;
        if (cur->next != nullptr) {
            cur->next->last = cur;
        }
    }

    return head;
}

int main () {
    DoubleNode  list1_head(1);
    DoubleNode  list1_node1(2);
    DoubleNode  list1_node2(4);
    DoubleNode  list1_node3(5);

    list1_head.next = &list1_node1;
    list1_node1.next = &list1_node2;
    list1_node2.next = &list1_node3;

    list1_node3.last = &list1_node2;
    list1_node2.last = &list1_node1;
    list1_node1.last = &list1_head;

    DoubleNode *head = removeLastKthNode(&list1_head, 1);

    return 0;
}
