// #include <bits/stdc++.h>

// int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
//     // Write your code here.
//     if (n==0){
//         return 0;
//     }
//     int longest = 1;
//     unordered_set<int>st;
//     for (int i=0;i<n;i++){
//         st.insert(arr[i]);
//     }
//     for (auto it: st){
//         if (st.find(it=1)==st.end()){
//             int cnt = 1;
//             int x = it;
//             while (st.find(x+1) != st.end()){
//                 x = x+1;
//                 cnt = cnt + 1;
//             }
//             longest= max(longest,cnt);
//         }
//     }
//     return longest;
// }
#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &nums, int n)
{
    unordered_set<int> st(nums.begin(), nums.end());
    int longest = 0;

    for(int i=0; i<n; i++)
    {
        if(st.find(nums[i]-1) == st.end())
        {
            int length = 1;

            for(int j=1; st.find(nums[i]+j) != st.end(); j++, length++);

            longest = max(length, longest);
        }
    }

    return longest;
}
