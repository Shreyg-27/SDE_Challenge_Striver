int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	// Write your code here
	int dp[1001][1001];
	for (int i=0;i<=w;i++){
		dp[0][i] = 0;
	}
	for (int j=0;j<=n;j++){
		dp[j][0] = 0;
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=w;j++){
			if (weights[i-1]<=j){
				dp[i][j] = max(values[i-1]+dp[i-1][j-weights[i-1]],dp[i-1][j]);
			}
			else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	return dp[n][w];
}
