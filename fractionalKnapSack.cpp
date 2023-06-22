#include <bits/stdc++.h> 

bool compare(pair<int,int>a, pair<int,int>b){
    double r1 = (double)a.second/a.first;
    double r2 = (double)b.second/b.first;

    return r1>r2;
}

double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    sort(items.begin(),items.end(),compare);
    double res = 0;
    for (int i=0;i<n;i++){
        if (items[i].first<=w){
            //it can be included 
            res += items[i].second;
            w = w - items[i].first;
        }
        else{
            res = res + (items[i].second *((double)w/items[i].first));
            break;
        }
    }
    return res;

}
