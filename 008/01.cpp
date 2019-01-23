#include <stack>
#include <cassert>

using namespace std;

int getLastAndRemove(stack<int> &s) {
    int first = s.top();
    s.pop();
    if (s.empty()) return first;
    int last = getLastAndRemove(s);
    s.push(first);
    return last;
}

void reverse(stack<int> &s) {
    if (s.empty()) return;
    int last = getLastAndRemove(s);
    reverse(s);
    s.push(last);
}
int main () {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
   
    reverse(s);
    assert(s.top() == 1);
}
