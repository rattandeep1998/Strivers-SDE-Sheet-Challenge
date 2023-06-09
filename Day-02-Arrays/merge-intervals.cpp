#include <bits/stdc++.h> 

bool sortCol(const vector<int>& v1, const vector<int>& v2)
{
    return v1[0] < v2[0];
}

void sortWithStartTime(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end(), sortCol);
}

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    // Write your code here.
    sortWithStartTime(intervals);

    int n = intervals.size();

    int curIndex = 0;

    for(int i=1; i<n; i++) {
        if(intervals[i][0] >= intervals[curIndex][0] && intervals[i][0] <= intervals[curIndex][1]) {
            intervals[curIndex][1] = max(intervals[curIndex][1], intervals[i][1]);
        } else {
            curIndex++;
            intervals[curIndex][0] = intervals[i][0];
            intervals[curIndex][1] = intervals[i][1];
        }
    }

    vector<vector<int>> result;

    for(int i=0; i<=curIndex; i++) {
        vector<int> curRow;
        for(int j=0; j<2; j++) {
            curRow.push_back(intervals[i][j]);
        }
        result.push_back(curRow);
    }

    return result;
}
