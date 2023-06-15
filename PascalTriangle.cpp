// #include <bits/stdc++.h>

// vector<int> generateRow(int row){
//   long long ans = 1;
//   vector<long long int> ansRow;
//   ansRow.push_back(1);
//   for (int col=1;col<row;col++){
//     ans = ans * (row-col);
//     ans = (ans)/col;
//     ansRow.push_back(ans);
//   }
// }

// vector<vector<long long int>> printPascal(int n) 
// {
//   // Write your code here.
//   vector<vector<long long int>> ans;
//   for (int i=1;i<=n;i++){
//     ans.push_back(generateRow(i));
//   }
//   return ans;
// }

#include <bits/stdc++.h> 

 

vector<long long int> level(vector<long long int> prev) {

  vector<long long int> temp;

  temp.push_back(1);

  for(int i=1; i<prev.size(); i++) {

    long long int t = prev[i-1]+prev[i];

    temp.push_back(t);

  }

  temp.push_back(1);

  return temp;

}

 

vector<vector<long long int>> printPascal(int n) 

{

  vector<vector<long long int>> ans;

  vector<long long int> a;

  a.push_back(1);

  ans.push_back(a);

  n--;

  int cnt = 0;

 

  while(n--) {

    ans.push_back(level(ans[cnt++]));

  }

 

  return ans;

}
