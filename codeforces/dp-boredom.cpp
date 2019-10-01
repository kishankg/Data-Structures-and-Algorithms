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

const ll N = pow(10,5);
ll dp[N+1];

void input()
{
	ll n;
	cin >> n;

	vector<ll> v = vector_input(n);

	ll freq[N+1] = {0};

	for(ll i=0;i<n;i++)
	{
		freq[v[i]]++;
	}

	memset(dp,0,sizeof(dp));

	dp[0] = 0;
	dp[1] = freq[1];

	for(ll i=2;i<=N;i++)
	{
		ll num1 = dp[i-1];
		ll num2 = dp[i-2] + freq[i]*i;

		dp[i] = max(num1,num2);
	}

	cout << dp[N] << endl;
}
 
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout.precision(12);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	input();
}
 