#include <bits/stdc++.h> 
bool findPattern(string p, string s)
{
    // Write your code here.
    int m = p.size();
    int n = s.size();
    int count = 0;
    for (int i=0;i<n;i++){
        string str = s.substr(i,m);
        if (str==p){
            return true;
        }
        else{
            continue;
        }
    }
    return false;
}
