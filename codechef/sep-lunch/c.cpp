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
	//cout << t << endl;
	while(t--)
	{
		ll n,q;
		cin >> n >> q;

		vector<ll> v = vector_input(n-1);

		ll adjDiff[n-1];
		adjDiff[0] = v[0];
	
		for(ll i=1;i<n-1;i++)
		{
			adjDiff[i] = v[i-1]-v[i];
		}

		ll sum[n-1];
		sum[0] = 0;

		for(ll i=1;i<n-1;i++)
		{
			sum[i] = sum[i-1]+adjDiff[i];
		}

		// for(ll i=0;i<n-1;i++)
		// 	cout << adjDiff[i] << " ";
		// cout << endl;
		// for(ll i=0;i<n-1;i++)
		// 	cout << sum[i] << " ";
		// cout << endl;

		for(int i=0;i<q;i++)
		{
			int a,b;
			cin >> a >> b;
			a--;
			b--;
			if(a>b) swap(a,b);

			if((b-a)%2==0)
			{
				cout << "UNKNOWN" << endl;
				continue;
			}
			else
			{
				int sum1 = v[a];
				int minu = true;
				for(ll j=a+1;j<=b-1;j++)
				{
					if(minu)
						sum1 -=v[j];
					else
						sum1 +=v[j];
					
					if(minu) minu = false;
					else minu = true;
				}	//sum1 -= v[j];
				cout << sum1 << endl;
			// 	if(b==a+1)
			// 	{
			// 		cout << v[a] << endl;
			// 		continue;
			// 	}
			// 	cout << v[a]-sum[b-1]+sum[a+1] << endl;
			}
		}
	}
}
 
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout.precision(12);
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


