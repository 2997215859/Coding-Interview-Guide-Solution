#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int maxRecFromBottom (const vector<int> &heights) {
    stack<int> s;
    int maxArea = 0;
    for (int i=0;i<heights.size();i++) {
        while (!s.empty() && heights[i] <= heights[s.top()]) {
            int j = s.top();
            s.pop();
            int k = s.empty() ? -1: s.top();
            int area = (i - k - 1) * heights[j];
            maxArea = max(maxArea, area);
        }
        s.push(i);
    }

    while (!s.empty()) {
        int j = s.top();
        s.pop();
        int k = s.empty() ? -1: s.top();
        int area = (heights.size() - k - 1) * heights[j];
        maxArea = max(maxArea, area);
    }

    return maxArea;
}

int main () {
    vector<vector<int>> grids = {
            {1, 0, 1, 1},
            {1, 1, 1, 1},
            {1, 1, 1, 0}
    };

    int M = grids[0].size();
    vector<int> heights(M, 0.0);
    int maxArea = 0;
    for (const auto &line: grids) {
        for (int j=0;j<line.size();j++) {
            heights[j] = line[j] == 0? 0: heights[j] + 1;
        }
        maxArea = max(maxArea, maxRecFromBottom(heights));
    }

    return maxArea;
}
