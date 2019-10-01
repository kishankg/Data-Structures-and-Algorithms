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
#define ll unsigned long long
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

ll input()
{
	ll b,d,s,b1,d1,s1;
	cin >> b >> d >> s;
	ll sum1;
	ll sum = pow(10,19);

	if(b==d && b==s)
	{
		return 0;
	}

	//before breakfast and goes after breakfast
	b1 = max({b,s+1,d+1});
	d1 = b1-1;
	s1 = b1-1;

	sum1 = (b1-b) + (d1-d) + (s1-s);
	sum = min(sum,sum1);

	//before breakfast and goes after dinner
	b1 = max({b,s+1,d});
	d1 = b1;
	s1 = b1-1;

	sum1 = (b1-b) + (d1-d) + (s1-s);
	sum = min(sum,sum1);

	//before breakfast and goes after supper
	b1 = max({b,s,d});
	d1 = b1;
	s1 = b1;

	sum1 = (b1-b) + (d1-d) + (s1-s);
	sum = min(sum,sum1);

	//before dinner and goes after dinner
	d1 = max({b+1,s+1,d});
	b1 = d1-1;
	s1 = d1-1;

	sum1 = (b1-b) + (d1-d) + (s1-s);
	sum = min(sum,sum1);

	//before dinner and goes after supper
	d1 = max({b+1,s,d});
	b1 = d1-1;
	s1 = d1;

	sum1 = (b1-b) + (d1-d) + (s1-s);
	sum = min(sum,sum1);

	//before dinner and goes after breakfast
	d1 = max({b,s,d});
	b1 = d1;
	s1 = d1;

	sum1 = (b1-b) + (d1-d) + (s1-s);
	sum = min(sum,sum1);

	//before supper and goes after supper
	s1 = max({b+1,s,d+1});
	d1 = s1-1;
	b1 = s1-1;

	sum1 = (b1-b) + (d1-d) + (s1-s);
	sum = min(sum,sum1);

	//before supper and goes after breakfast
	s1 = max({b,s,d+1});
	d1 = s1-1;
	b1 = s1;

	sum1 = (b1-b) + (d1-d) + (s1-s);
	sum = min(sum,sum1);

	//before supper and goes after dinner
	s1 = max({b,s,d});
	d1 = s1;
	b1 = s1;

	sum1 = (b1-b) + (d1-d) + (s1-s);
	sum = min(sum,sum1);



	return sum;


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