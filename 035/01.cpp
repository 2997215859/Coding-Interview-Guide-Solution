#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Node {
public:
    int value;
    Node *next;
    Node (int value): value(value), next(nullptr) {}
};

Node* removeLastKthNode (Node *head, int k) {
    Node *cur = head;
    while (cur != nullptr) {
        k--;
        cur = cur->next;
    }

    if (k == 0) head = head->next;
    if (k < 0) {
        Node *cur = head;
        while (++k != 0) cur = cur->next;
        cur->next = cur->next->next;
    }

    return head;
}

int main () {
    Node list1_head(1);
    Node list1_node1(2);
    Node list1_node2(4);
    Node list1_node3(5);

    list1_head.next = &list1_node1;
    list1_node1.next = &list1_node2;
    list1_node2.next = &list1_node3;

    Node list2_head(0);
    Node list2_node1(2);
    Node list2_node2(3);
    Node list2_node3(5);

    list2_head.next = &list2_node1;
    list2_node1.next = &list2_node2;
    list2_node2.next = &list2_node3;

    Node *head = removeLastKthNode(&list1_head, 4);

    return 0;
}
