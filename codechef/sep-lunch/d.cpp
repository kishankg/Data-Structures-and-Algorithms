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
		string s,r;
		cin >> s >> r;

		string ans = r;
		int freq[26] = {0};

		for(int i=0;i<r.length();i++)
			freq[r[i]-'a']++;

		int flag=0;
		for(int i=0;i<s.length();i++)
		{
			freq[s[i]-'a']--;

			if(freq[s[i]-'a']<0)
			{
				flag=1;
				break;
			}
		}

		if(flag)
		{
			cout << "Impossible" << endl;
			continue;
		}

		// for(int i=0;i<s.length();i++)
		// 	ans[i] = s[i];

		int j = 0;
		int comIndex = 0;
		flag=0;
		
		for(int i=0;i<26;i++)
		{
			int times = freq[i];
			if(times==0) continue;

			char c = 'a'+i;

			if(flag==0)
			{
				if(c<s[0])
				{
					for(int k=0;k<times;k++)
						ans[j++] = 'a'+i;
				}
			}
			else
			{
				for(int k=0;k<times;k++)
					ans[j++] = 'a'+i;
			}

		}

		cout << ans << endl;
	}
}
 
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout.precision(12);
	// #ifndef ONLINE_JUDGE
	// freopen("../codes/input.txt", "r", stdin);
	// freopen("../codes/output.txt", "w", stdout);
	// #endif
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


