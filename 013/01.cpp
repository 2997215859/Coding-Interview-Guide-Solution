#include <stack>
#include <iostream>

using namespace std;
void sortStackByStack (stack<int> &s) {
    stack<int> help;
    int cur = 0;
    while (!s.empty()) {
        cur = s.top();
        s.pop();

        while (!help.empty()) {
            if (help.top() > cur) {break;}

            s.push(help.top());
            help.pop();

        }

        help.push(cur);
    }

    while (!help.empty()) {
        s.push(help.top());
        help.pop();
    }
}

int main () {
    stack<int> test;
    test.push(2);
    test.push(3);
    test.push(1);
    test.push(5);
    test.push(4);

    sortStackByStack(test);
    while (!test.empty()) {
        cout << test.top() << endl;
        test.pop();
    }
}
