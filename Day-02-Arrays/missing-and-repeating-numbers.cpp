#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	int x,y;

	for(int i=0; i<n; i++) {
		int cur = abs(arr[i]);

		if(arr[cur-1] < 0) {
			y = cur;
		} else {
			arr[cur-1] = -1*arr[cur-1];
		}
	}

	for(int i=0; i<n; i++) {
		if(arr[i] > 0) {
			x = i+1;
		}
	}

	pair<int, int> p(x,y);

	return p;
}
