#include <bits/stdc++.h>

void recrPermute(int index, string &s, vector<string> &ans){
    // base case 
    if (index==s.size()){
        ans.push_back(s);
        return;
    }
    for (int i=index;i<s.length();i++){
        swap(s[i], s[index]);
        recrPermute(index+1, s, ans);
        // swap again to get the other permutation 
        swap(s[i],s[index]);
    }
}

vector<string> findPermutations(string &s) {
    // Write your code here.
    vector<string> ans;
    recrPermute(0,s,ans);
    return ans;

}
