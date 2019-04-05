#include <iostream>
#include <cstdio>
#include <deque>
#include <vector>
using namespace std;



int main () {

    vector<int> arr = {4,3,5,4,3,3,6,7};
    int w = 3;

    deque<int> d;

    vector<int> res;
    for (int i=0;i<arr.size();i++) {

        while (!d.empty() && arr[d.back()] <= arr[i]) {
            d.pop_back();
        }
        d.push_back(i);

        if (d.front() == i - w) d.pop_front();

        if (i >= w - 1) res.push_back(arr[d.front()]);
    }

    for (int i: res) cout << i << " ";
}
