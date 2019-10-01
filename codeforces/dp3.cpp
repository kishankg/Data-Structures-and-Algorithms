//https://codeforces.com/problemset/problem/455/A
//Boredom

#include<bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> vector_input(ll n)
{
	vector<ll> v;
	
	for(ll i=0;i<n;i++)
	{
		ll num;
		cin >> num;
		
		v.push_back(num);
	}
	
	return v;
}

vector<ll> input()
{
	ll t;
	cin >> t;
	
	while(t--)
	{
		ll n;
		cin >> n;
		
		vector<int> v = vector_input(n);
		
		int dp[n][n];
		
		for(int i=0;i<n;i++)
			dp[i][i] = v[i];
		
		for(int i=0;i<n-1;i++)
			dp[i][i+1] = max(v[i],v[i+1]);
			
		for(int gap=2;gap<=n;gap++)
		{
			for(int j=)
			for(int i=0;i<n;j++)
			{
				dp[i][i+gap]
			}
		}
	}
}

int main()
{
	input();
}
