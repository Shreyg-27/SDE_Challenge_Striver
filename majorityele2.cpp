#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{
    // Write your code here.
    int cnt1 = 0;
    int cnt2 = 0;
    int ele1 = INT_MIN;
    int ele2 = INT_MIN;
    for (int i=0;i<arr.size();i++){
        if (cnt1==0 && arr[i]!=ele2){
            cnt1 = 1;
            ele1 = arr[i];
        }
        else if (cnt2==0 && arr[i]!=ele1){
            cnt2 = 1;
            ele2 = arr[i];
        }
        else if(arr[i]==ele1){
            cnt1++;
        }
        else if(arr[i]==ele2){
            cnt2++;
        }
        else{
            cnt1--;
            cnt2--;
        }
    }
    vector<int> ls;
    cnt1=0;
    cnt2 = 0;
    for (int i=0;i<arr.size();i++){
        if (ele1 == arr[i]){
            cnt1++;
        }
        if (ele2==arr[i]){
            cnt2++;
        }
    }
    int mini = int(arr.size()/3) + 1;
    if (cnt1>=mini){
        ls.push_back(ele1);
    }
    if (cnt2>=mini){
        ls.push_back(ele2);
    }
    sort(ls.begin(),ls.end());
    return ls;

}
