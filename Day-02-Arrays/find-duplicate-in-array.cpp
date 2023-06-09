#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n){
	// Write your code here.
	vector<int> mp(n, 0);

	for(int i=0; i<n; i++) {
		if(mp[arr[i]] == 1) {
			return arr[i];
		} else {
			mp[arr[i]] = 1;
		}
	}

	return arr[0];
}
