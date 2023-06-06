#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    int buyIndex=0;
    int sellIndex=1;
    int maxProfit=0;
    int n = prices.size();

    while(sellIndex < n) {
        int curProfit = prices[sellIndex] - prices[buyIndex];
        if(curProfit >= maxProfit) {
            maxProfit = curProfit;
        }

        if(prices[sellIndex] < prices[buyIndex]) {
            buyIndex = sellIndex;
        }
        sellIndex++;
    }

    return maxProfit;
}