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


Node *reversePart (Node *head, int from, int to) {

    Node *cur = head;
    int N = 0;
    Node *tpre = nullptr;
    Node *tpos = nullptr;
    while (cur != nullptr) {
        N++;
        if (N == from - 1) tpre = cur;
        if (N == to + 1) tpos = cur;
        cur = cur->next;
    }

    if (from > to || from < 1 || to > N) return head;


    Node *pre = tpos;
    Node *next = nullptr;
    cur = (tpre == nullptr? head: tpre->next);
    while (cur != tpos) {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }

    if (tpre != nullptr) {
        tpre->next = pre;
        return head;
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


    Node *head = reversePart(&list1_head, 1, 4);

    return 0;
}

