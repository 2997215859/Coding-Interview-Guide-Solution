#include <iostream>
#include <cstdio>
#include <queue>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

const char l = 'a';
const char m = 'b';
const char r = 'c';

void move (int floor, char from, char to) {
    printf("Move %d from %c to %c\n", floor, from, to);
}

int process (int num, char from, char to) {
    if (num == 1) { // 1. 塔数为1时，递归终止条件
        if (from == m || to == m) {
            move(1, from, to);
            return 1;
        } else {
            move(1, from, m);
            move(1, m, to);
            return 2;
        }
    }

    if (from == m || to == m) {
        char another = (from == l || to == l) ? r: l;

        int part1 = process(num-1, from, another);
        int part2 = 1;
        move(num, from, to);
        int part3 = process(num-1, another, to);
        return part1 + part2 + part3;
    } else {

        int part1 = process(num-1, from, to);
        int part2 = 1;
        move(num, from, m);
        int part3 = process(num-1, to, from);
        int part4 = 1;
        move(num, m, to);
        int part5 = process(num-1, from, to);
        return part1 + part2 + part3 + part4 + part5;
    }
}

int hanoi (int num) {
    if (num < 1) return 0;
    return process(num, l, r);
}

int main () {
    int n = 2;
    int cnt = hanoi(n);
    printf("move cnt: %d \n", cnt);
}
