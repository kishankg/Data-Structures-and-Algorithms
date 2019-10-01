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

map<pair<int,bool>,ll> h;
ll func(int n,bool used,int d,int k)
{
	if(n<0) return 0;
	
	if(n==0 && used==true) return 1;
	if(n==0 && used==false) return 0;
	
	pair<int,bool> p;
	p.first = n;
	p.second = used;

	if(h.find(p)!=h.end()) return h[p];
	//already used
	//cout << n << " " << used << endl;
	ll ans = 0;

	if(used==true)
	{
		for(ll i=1;i<=k;i++)	
		{
			ans += func(n-i,true,d,k);
		}
	}
	else
	{
		for(ll i=1;i<=k;i++)
		{
			if(i>=d)
				ans += func(n-i,true,d,k);
			else
				ans += func(n-i,false,d,k);
		}
	}

	ans = ans%MOD;
	h[p] = ans;
	return ans;
}

ll input()
{
	h.clear();
	ll n,k,d;
	cin >> n >> k >> d;

	return func(n,false,d,k);

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