#include <iostream>
#include <cstdio>
#include <sstream>
#include <stack>
#include <climits>

using namespace std;

const char l = 'a';
const char m = 'b';
const char r = 'c';

enum Action {
    NoAction, L2M, M2L, M2R, R2M
};

void move (int preAction, stack<int> &ls, stack<int> &ms, stack<int> &rs) {

    if (preAction == L2M) {
        printf("Move %d from %c to %c\n", ls.top(), l, m);
        ms.push(ls.top());
        ls.pop();
    } else if (preAction == M2L) {
        printf("Move %d from %c to %c\n", ms.top(), m, l);
        ls.push(ms.top());
        ms.pop();
    } else if (preAction == M2R) {
        printf("Move %d from %c to %c\n", ms.top(), m, r);
        rs.push(ms.top());
        ms.pop();
    } else if (preAction == R2M) {
        printf("Move %d from %c to %c\n", rs.top(), r, m);
        ms.push(rs.top());
        rs.pop();
    }

}

int findAction (int preAction, const stack<int> &l, const stack<int> &m, const stack<int> &r) {
    if (preAction == NoAction) return L2M;

    if (preAction == L2M || preAction == M2L) {
        return m.top() < r.top() ? M2R: R2M;
    } else {
        return m.top() < l.top() ? M2L: L2M;
    }
}

int hanoi (int num) {

    stack<int> l;
    stack<int> m;
    stack<int> r;

    l.push(INT_MAX);
    m.push(INT_MAX);
    r.push(INT_MAX);

    for (int i=num;i>0;i--) l.push(i);

    int preAction = NoAction;
    int cnt = 0;
    while (r.size() != num + 1) {
        int action = findAction(preAction, l, m, r);
        move(action, l, m, r);
        preAction = action;
        cnt++;
    }

    return cnt;
}

int main () {
    int n = 2;
    int cnt = hanoi(n);
    cout << cnt << endl;
}
