#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<cmath>
#include<iomanip>
using namespace std;

vector<int> take_input(int n)
{
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int num;
        cin >> num;
        
        v.push_back(num);
    }
    
    return v;
}
vector<int> sumVector(vector<int> v)
{
    vector<int> sum(v.size());
    sum[0] = v[0];
    
    for(int i=1;i<v.size();i++)
    {
        sum[i] = sum[i-1] + v[i];
    }
    return sum;
}

#define ll long long

int main()
 {
	int t;
	cin >> t;
	
	while(t--)
	{
	    ll n;
	    cin >> n;
	    
	    vector<ll> v;
	    
	    for(int i=0;i<n;i++)
	    {
	        ll num;
	        cin >> num;
	        
	        v.push_back(num);
	    }
	    
	    vector<ll> dp(n,INT_MAX);
	    dp[n-1] = 0LL;
	    
	    for(int i=v.size()-1;i>=0;i--)
	    {
	        for(int j=1;j<=v[i];j++)
	        {
	            if((i-j)<0) continue;
	            
	            dp[i-j] = min(dp[i-j],dp[i]+1);
	        }
	    }
	    
	    for(int i=0;i<n;i++)
	        cout << dp[i] << " ";
	    cout << endl;
	    
	    cout << dp[0] << endl;
	}
	return 0;
}
