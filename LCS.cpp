#include<bits/stdc++.h>
int lcs(string s, string t)
{
	//Write your code here
	int len1 = s.size();
	int len2 = t.size();

	int dp[len1+1][len2+1];
	for (int i=0;i<len1;i++){
		dp[i][0] = 0;
	}
	for (int j=0;j<len2;j++){
		dp[0][j] = 0;
	}

	for (int i=1;i<=len1;i++){
		for(int j=1;j<=len2;j++){
			if (s[i-1]==t[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	return dp[len1][len2];
}
