#include<bits/stdc++.h>
using namespace std;

#define ll long long

bool func(int index,vector<int> v,int currSum,int target)
{
	if(index==v.size())
	{
		return currSum == target;
	}
	
	if(currSum == target) return true;
	
	return (func(index+1,v,currSum+v[index],target) | func(index+1,v,currSum,target));
}

int main()
{
	int t;
	cin >> t;
	
	while(t--)
	{
		int n;
		cin >> n;
		
		vector<int> v(n);
		
		for(int i=0;i<n;i++)
		{
			cin >> v[i];
		}
		
		int sum;
		cin >> sum;
		
		bool dp[sum+1][n];
		
		for(int i=0;i<=sum;i++)
		{
			for(int j=0;j<=n;j++)
			{
				if(i==0)
				{
					dp[i][j] = true;
				}
				if(i!=0 && j==0)
				{
					dp[i][j] = false;
				}
				else if(i>=v[j-1])
				{
					dp[i][j] = dp[i][j-1] || dp[i-v[j-1]][j-1];
				}
				else
				{
					dp[i][j] = dp[i][j-1];
				}
			}
		}
		
		cout << dp[sum][n] << endl;
		//bool ans = func(0,v,0,sum);
		
		//if(ans) cout << "YES" << endl;
		//else cout << "NO" << endl;
	}
}
