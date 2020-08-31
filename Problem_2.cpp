#include<bits/stdc++.h>

using namespace std;

//Logic : 0-1 Knapsack algorithm using dynamic programming
long long knapsack(vector<long long> brick_strength, int m, long long sum){
	long long dp[m+1][sum/2+1];
	for(int i=0; i<=m; i++)
	   dp[i][0]=0;
	for(long long i=0; i<=sum/2; i++)
	   dp[0][i]=0;
	for(int i=1; i<=m; i++){
		for(long long j=1; j<=sum/2;j++){
			dp[i][j]=dp[i-1][j];
			if(brick_strength[i-1]<=j)
			   dp[i][j] = max(dp[i-1][j-brick_strength[i-1]]+brick_strength[i-1], dp[i][j]);
		}
	}
	/*
	for(int i=1;i<=m;i++){
		for(long long j=1; j<=sum/2;j++)
		   cout<<dp[i][j]<<" ";
		cout<<"\n";
	}*/
	return dp[m][sum/2];
}

main(){
	int n,m;
	long long sum=0;
	cin>>n>>m;
	vector<long long> brick_strength(m);
	for(int i=0; i<m; i++){
	    cin>>brick_strength[i];
	    sum+=brick_strength[i];
    }
    if(n==1)
       cout<<sum;
    else 
       cout<<knapsack(brick_strength,m,sum);
}
