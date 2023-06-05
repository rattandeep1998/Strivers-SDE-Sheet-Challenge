#include <bits/stdc++.h>

void setZeros(vector<vector<int>> &matrix)
{
	int n = matrix.size();
	int m = matrix[0].size();

	vector<int> zeroRowIndices(n, 0);
	vector<int> zeroColIndices(m, 0);

	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(matrix[i][j] == 0) {
				zeroRowIndices[i] = 1;
				zeroColIndices[j] = 1;
			}
		}
	}

	for(int i=0; i<n; i++) {
		if(zeroRowIndices[i] == 1) {
			for(int j=0; j<m; j++) {
				matrix[i][j] = 0;
			}
		}
	}

	for(int j=0; j<m; j++) {
		if(zeroColIndices[j] == 1) {
			for(int i=0; i<n; i++) {
				matrix[i][j] = 0;
			}
		}
	}
}