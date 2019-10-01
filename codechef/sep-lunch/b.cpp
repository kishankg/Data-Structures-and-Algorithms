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
	ll t;
	cin >> t;
	cout << t << endl;
	while(t--)
	{
		ll n;
		cin >> n;
		
		vector<ll> v = vector_input(n);

		for(int i=0;i<n;i++)
			cout << v[i] << " ";
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
 





// int32_t main()
// {
// 	fastio
// 	#ifndef ONLINE_JUDGE
//     freopen("../codes/input.txt", "r", stdin);
//     freopen("../codes/output.txt", "w", stdout);
//     #endif

//     input();
    
// }


