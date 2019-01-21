#include <iostream>
#include <stack>
#include <cassert>

using namespace std;

class MyStack {
    stack<int> stackData;
    stack<int> stackMin;
public:
    void push(int d) {
        stackData.push(d);
        if (stackMin.empty()) {
            stackMin.push(d);
        } else if (d <= stackMin.top()) {
            stackMin.push(d);
        }
    }
    
    int pop() {
        if (stackData.top() == stackMin.top())  stackMin.pop();
        int value = stackData.top();
        stackData.pop();
        return value;
    }

    int getMin () {
        if (stackMin.empty()) {
            cerr << "Current stack has no data" << endl;
            exit(1);
        }
        return stackMin.top();
    }
};

int main () {
    MyStack stack;
    stack.push(3);
    assert(stack.getMin() == 3);
    stack.push(4);
    assert(stack.getMin() == 3);
    stack.push(5);
    stack.push(1);
    assert(stack.getMin() == 1);
    stack.push(2);
    stack.push(1);
    assert(stack.getMin() == 1);
    stack.pop();

    cout << "test pass" << endl;
    return 0;
}
