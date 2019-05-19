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

Node *removeByRadio(Node *head, int a, int b) {

    int n = 0;
    Node *cur = head;
    while (cur != nullptr) {
        n++;
        cur = cur->next;
    };

    int k = ceil(n * (a + 0.0) / b);

    if (k == 1) return head->next;

    if (k < 1) return head;

    Node *pre = head;
    while (--k != 1) {
        pre = pre->next;
    }

    pre->next = pre->next->next;

    return head;

}

Node* removeMideNode(Node *head) {
    if (head == nullptr || head->next == nullptr) return head;

    if (head->next->next == nullptr) return head->next;

    Node *pre = head;
    Node *cur = head->next->next;
    while (cur->next != nullptr && cur->next->next != nullptr) {
        pre = pre->next;
        cur = cur->next->next;
    }

    pre->next = pre->next->next;
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

    Node *head = removeMideNode(list1_head.next->next);

    Node *head2 = removeByRadio(&list1_head, 1, 5);

    return 0;
}

