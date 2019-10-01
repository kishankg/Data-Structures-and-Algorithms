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

void input()
{

	ll n;
	cin >> n;

	ll b = n/7 + 1;
	ll num = INT_MAX;
	ll a1,b1;
	for(ll i=0;i<=b;i++)
	{
		ll a = n - i*7;

		if(a<0) continue;

		if(a%4==0)
		{
			a = a/4;
			if(num>a+i)
			{
				num = a+i;
				a1 = a;
				b1 = i;
			}
		}
	}

	if(num==INT_MAX) cout << -1 << endl;
	else
	{
		for(ll i=0;i<a1;i++)
			cout << 4;
		for(ll i=0;i<b1;i++)
			cout << 7;
	}
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
	input();
}