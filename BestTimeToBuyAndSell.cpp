#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.
    int max_profit = 0;
    int n = prices.size();
    int min_price = INT_MAX;
    for (int i=0;i<n;i++){
        min_price = min(min_price, prices[i]);
        max_profit = max(max_profit, prices[i]-min_price);
    }
    return max_profit;
}
