#include<iostream>
#include <vector>
#include <climits>
#include <stack>
#include <map>

using namespace std;

class Node {
public:
    int value;
    Node *left;
    Node *right;

    Node (int value): value(value), left(nullptr), right(nullptr){}
    Node (): value(0), left(nullptr), right(nullptr) {};
};

void popAndSetMap(stack<int> &s, map<int, int> &m) {
    int t = s.top();
    s.pop();
    if (s.empty()) {
        m[t] = INT_MAX;
    } else {
        m[t] = s.top();
    }
}

map<int, int> findLeftMax (const vector<int>& arr) {
    int n = arr.size();
    map<int, int> res;

    stack<int> s;

    for (int i=0;i<arr.size();i++) {
        while (!s.empty() && s.top() < arr[i]) {
           popAndSetMap(s, res);
        }
        s.push(arr[i]);
    }

    while (!s.empty()) {
        popAndSetMap(s, res);
    }

    return res;
}

map<int, int> findRightMax (const vector<int>& arr) {
    int n = arr.size();
    map<int, int> res;

    stack<int> s;

    for (int i=n-1;i>=0;i--) {
        while (!s.empty() && s.top() < arr[i]) {
            popAndSetMap(s, res);
        }
        s.push(arr[i]);
    }

    while (!s.empty()) {
        popAndSetMap(s, res);
    }

    return res;
}

int main () {
    vector<int> arr = {3, 4, 5, 1, 2};

    vector<Node> nodes(arr.size());
    for (int i=0;i<arr.size();i++) nodes[i] = Node(arr[i]);

    map<int, int> leftMax = findLeftMax(arr);
    map<int, int> rightMax = findRightMax(arr);
    map<int, int> vk;
    for (int i=0;i<arr.size();i++) vk[arr[i]] = i;


    Node *head;
    for (int i=0;i<arr.size();i++) {
        int v = arr[i];

        int parentV = min(leftMax[v], rightMax[v]);

        int parentIndex = vk[parentV];
        if (leftMax[v] == rightMax[v]) {
            head = &nodes[i];
        } else {
            if (nodes[parentIndex].left == nullptr) {
                nodes[parentIndex].left = &nodes[i];
            } else {
                nodes[parentIndex].right = &nodes[i];
            }
        }
    }


    return 0;
}
