#include <bits/stdc++.h> 

typedef long long ll;

long long maxSubarraySum(int arr[], int n)
{
    // Kadane's Algorithm

    ll maxEndingHere = 0;
    ll maxSoFar = 0;

    for(int i=0; i<n; i++) {
        maxEndingHere = maxEndingHere + arr[i];

        if(maxEndingHere > maxSoFar) {
            maxSoFar = maxEndingHere;
        }

        if (maxEndingHere < 0) {
          maxEndingHere = 0;
        }
    }

    return maxSoFar;
}