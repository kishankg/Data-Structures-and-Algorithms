#include<bits/stdc++.h>
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
#include <assert.h>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cstdio>
#include <random>
#include <chrono>
#define ld long double
#define pb push_back
#define eb emplace_back
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define int long long
using namespace std ;

const int INF = 2e9;
const int MOD = 1e9 + 7;

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

struct cohe
{
	ll x;
	ll h;
};

int func(vector<cohe> v,int index,int prev)
{
	ll n = v.size();
	if(index>=n-1) return 0;

	int ans = 0;
	//leave
	int ans1 = func(v,index+1,v[index].x);

	//left x-h
	int ans2 = 0;
	ll h = v[index].h;
	ll x = v[index].x;
	if(prev<x-h)
	{
		ans2 = 1+func(v,index+1,v[index].x);
	}

	//right x+h
	int ans3 = 0;
	if(v[index+1].x>x+h)
	{
		ans3 = 1+func(v,index+1,v[index].x+h);
	}

	int tree = max({ans1,ans2,ans3});
	return tree;
}

ll input()
{
	ll n;
	cin >> n;

	vector<cohe> v(n);
	for(ll i=0;i<n;i++)
	{
		cin >> v[i].x >> v[i].h;
	}

	if(n<=2) return n;

	ll dp[n][3];
	memset(dp,0,sizeof(dp));
	dp[0][0] = 0;
	dp[0][1] = 1;
	dp[0][2] = 0;

	if(v[1].x > (v[0].x + v[0].h))
		dp[0][2] = 1;
	
	for(ll i=1;i<n-1;i++)
	{
		dp[i][0] = max({dp[i-1][0],dp[i-1][1],dp[i-1][2]});

		if(v[i].x - v[i].h > v[i-1].x)
			dp[i][1] = max({dp[i][1], 1 + dp[i-1][0], 1+ dp[i-1][1]});

		if((v[i].x - v[i].h) > (v[i-1].x + v[i-1].h))
			dp[i][1] = max(dp[i][1],1+dp[i-1][2]);

		if(v[i+1].x > (v[i].x + v[i].h))
			dp[i][2] = 1+ max({dp[i-1][0],dp[i-1][1],dp[i-1][2]});
	}

	//cout << dp[n-2][0] << " " << dp[n-2][1] << " " << dp[n-2][2] << endl;
	return 1 + max({dp[n-2][0],dp[n-2][1],dp[n-2][2]});
}
 
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout.precision(12);
	#ifndef ONLINE_JUDGE
	freopen("../codes/input.txt", "r", stdin);
	freopen("../codes/output.txt", "w", stdout);
	#endif
	cout << input() << endl;
}