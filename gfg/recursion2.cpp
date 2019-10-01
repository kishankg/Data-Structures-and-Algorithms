#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<cmath>
#include<iomanip>
using namespace std;
int m,n;
int recur(int x,int y)
{
    if(x>=m) return 0;
    if(y>=n) return 0;
    
    if(x==m-1) return 1;
    if(y==n-1) return 1;
    
    int ans = 2 + recur(x+1,y) + recur(x,y+1);
    
    return ans;
}

int main()
 {
	//code
	int t;
	cin >> t;
	
	while(t--)
	{
	    cin >> m >> n;
	    
	    if(m==1 || n==1)
	    {
	        cout << 1 << endl;
	        continue;
	    }
	    //cout << recur(0,0) << endl;
	    int dp[m][n];
	    
	    for(int i=0;i<m;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            if(i==0 || j==0)
	            {
	                dp[i][j] = 1;
	            }
	            else
	            {
	                dp[i][j] = 0;
	            }
	        }
	    }
	    
	    for(int i=0;i<m;i++)
	    {
	    	for(int j=0;j<n;j++)
	    	{
	    		dp[i][j] = dp[i-1][j] + dp[i][j-1];
	    	}
	    }
	    
	    cout << dp[r-1][c-1] << endl;
	    
	}
	return 0;
}
