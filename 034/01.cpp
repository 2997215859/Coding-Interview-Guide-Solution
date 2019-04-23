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

void printCommonPart(Node *head1, Node *head2) {
    cout << "Common Part: " << endl;
    while (head1 != nullptr && head2 != nullptr ) {
        if (head1->value < head2->value) {
            head1 = head1->next;
        } else if (head1->value > head2->value) {
            head2 = head2->next;
        } else {
            cout << head1->value << " ";
            head1 = head1->next;
            head2 = head2->next;
        }
    }
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

    printCommonPart(&list1_head, &list2_head);
}
