#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int solve (const vector<int> &arr, int num) {

    deque<int> qmax;
    deque<int> qmin;

    int i = 0;
    int j = 0;

    int len = arr.size();

    int res = 0;

    while (i < len) {
        while (j < len) {
            while (!qmax.empty() && arr[qmax.back()] <= arr[j]) {
                qmax.pop_back();
            }
            qmax.push_back(j);
            while (!qmin.empty() && arr[qmin.back()] >= arr[j]) {
                qmin.pop_back();
            }
            qmin.push_back(j);

            if (arr[qmax.front()] - arr[qmin.front()] > num) break;

            j++;
        }

        if (qmax.front() == i) qmax.pop_front();
        if (qmin.front() == i) qmin.pop_front();

        res += j - i;

        i++;
    }

    return res;
}

int main () {
//    vector<int> arr = {4, 3, 5, 4, 3, 3, 6, 7};
    vector<int> arr = {4, 3, 5};
    int num = 3;

    int res = solve(arr, num);
    cout << res << endl;
}
