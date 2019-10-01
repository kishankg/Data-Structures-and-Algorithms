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
	int n;
	cin >> n;

	vector<ll> v = vector_input(n);

	int start[n] = {0};
	int start1[n] = {0};
	int sum = 0;

	for(int i=0;i<n-1;i+=2)
	{
		sum += v[i]+v[i+1]; 
		
		if(sum>=10)
		{
			if(i!=0)
				start[i] = start[i-1];
			start[i+1] = start[i]+1;

			sum = sum%10;
		}
		else
		{
			if(i!=0)
				start[i] = start[i-1];
			start[i+1] = start[i];
		}
	}

	sum = 0;
	for(int i=1;i<n-1;i+=2)
	{
		sum += v[i]+v[i+1]; 
		
		if(sum>=10)
		{
			if(i!=0)
				start1[i] = start1[i-1];
			start1[i+1] = start1[i]+1;

			sum = sum%10;
		}
		else
		{
			if(i!=0)
				start1[i] = start1[i-1];
			start1[i+1] = start1[i];
		}
	}

	// for(int i=0;i<n;i++)
	// 	cout << start[i] << " ";
	// cout << endl;

	// for(int i=0;i<n;i++)
	// 	cout << start1[i] << " ";
	// cout << endl;

	int q;
	cin >> q;

	for(int i=0;i<q;i++)
	{
		int l,r;
		cin >> l >> r;
		l--;
		r--;

		if(l%2==0) //start
		{
			if(l==0)
			{
				cout << start[r] << endl;
			}
			else
			{
				cout << start[r]-start[l-1] << endl;
			}
		}
		else //start1
		{
			if(l==0)
			{
				cout << start1[r] << endl;
			}
			else
			{
				cout << start1[r]-start1[l-1] << endl;
			}
		}
	}
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
 





// int32_t main()
// {
// 	fastio
// 	#ifndef ONLINE_JUDGE
//     freopen("../codes/input.txt", "r", stdin);
//     freopen("../codes/output.txt", "w", stdout);
//     #endif

//     input();
    
// }


