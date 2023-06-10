// #include <bits/stdc++.h> 

// bool ispalindrome(string s, int start, int end){
//     while (start<=end){
//         if (s[start++] != s[end--]){
//             return false;
//         }
//     }
//     return true;
// }

// void helper(int index, string &s,vector<vector<string>> &ans,
//  vector<vector<string>> &path){
//     if (index==s.size()){
//         ans.push_back(path);
//         return;
//     }
//     for (int i=index;i<s.size();i++){
//         if (ispalindrome(s,index,i)){
//             path.push_back(s.substr(index,i-index+1));
//             helper(index+1,s,ans, path);
//             path.pop_back();
//             // to take the other case where this partition is not included
//         }
//     }
// }

// vector<vector<string>> partition(string &s) 
// {
//     // Write your code here.
//     vector<vector<string>> ans;
//     vector<string> path;
//     helper(0,s,ans,path);
//     return ans;

// }
#include <bits/stdc++.h>
bool isPalindrome(string &s,int start,int end){
    while(start<=end){
        if(s[start]!=s[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
}

void func(int index , string &s,vector<vector<string>>&ans,vector<string>&path)
{
    if(index==s.size()){
        ans.push_back(path);
        return;
    }
    for(int i=index;i<s.size();i++){
        if(isPalindrome(s,index,i)){
            path.push_back(s.substr(index,i-index+1));
            func(i+1,s,ans,path);
            path.pop_back();
        }
    }
    
}

vector<vector<string>> partition(string &s) 
{
    vector<vector<string>>ans;
    vector<string>path;
    func(0,s,ans,path);
    return ans;
}
