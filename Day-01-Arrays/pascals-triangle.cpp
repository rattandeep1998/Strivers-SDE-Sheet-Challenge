#include <bits/stdc++.h>

typedef long long ll;

vector<vector<long long int>> printPascal(int n) 
{
  // Write your code here.
  vector<vector<ll>> pt;

  vector<ll> firstRow;
  firstRow.push_back(1);

  pt.push_back(firstRow);


  for(int i=2; i<=n; i++) {
    int col=i-2;

    vector<ll> curRow;
    curRow.push_back(1);

    for(int j=0; j<col; j++) {
      curRow.push_back(pt[i-2][j] + pt[i-2][j+1]);
    }
    curRow.push_back(1);
    pt.push_back(curRow);
  }
  
  return pt;
}
