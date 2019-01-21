#include <iostream>
#include <stack>

using namespace std;
class MyQueue {
    stack<int> stackPush;
    stack<int> stackPop;
public:
    void add (int value) {
	stackPush.push(value);
    }
    int poll () {
        if (stackPop.empty()) {
            if (stackPush.empty()) {
                cerr << "Current has no data" << end;
                exit(1);
            }
            while (!stackPush.empty()) {
                stackPop.push(stackPush.top());
                stackPush.pop();
            }
        }
        int value = stackPop.top();
        stackPop.pop();
        return value;
    }
    int peek () {
        if (stackPop.empty()) {
            if (stackPush.empty()) {
                cerr << "Current has no data" << end;
                exit(1);
            }
            while (!stackPush.empty()) {
                stackPop.push(stackPush.top());
                stackPush.pop();
            }
        }
        return stackPop.top();
    }
}
