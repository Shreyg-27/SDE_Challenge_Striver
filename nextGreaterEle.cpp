#include <bits/stdc++.h> 

vector<int> nextGreater(vector<int> &arr, int n) {
    // Write your code here
    vector<int> ans(n,-1);
    stack<int> st;
    // we need to traverse the array twice 
    for (int i =n-1;i>=0;i--){
        while (!st.empty() && st.top() <= arr[i]){
            st.pop(); // remove the ele 
        }
        if (i<n){
        if (!st.empty()) ans[i] = st.top();
    }
    st.push(arr[i]);
    }
    return ans;
    

}
