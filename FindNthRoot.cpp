// int multiply(int num, int n){
//   int ans = 1;
//   for (int i=1;i<=n;i++){
//     ans = ans*num;
//   }
//   return ans;
// }
#include<bits/stdc++.h>
int NthRoot(int n, int m) {
  // Write your code here.
  int low = 1;
  int high = m;

  while(low <= high)
  {
    int mid = low + (high-low)/2;

    if(pow(mid, n) == m)
      return mid;
    else if(pow(mid, n) > m)
      high = mid - 1;
    else
      low = mid + 1;
  }

  return -1;
}
