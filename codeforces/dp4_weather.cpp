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
#define ll long long
#define ld long double
#define pb push_back
#define eb emplace_back
#define int long long
using namespace std;
 
const int INF = 2e9;
const int MOD = 1e9 + 7;
 
void solve() {
	int n;
    cin >> n;
	
	vector<ll> t;
	ll num;
	for(int i=0;i<n;i++)
	{
		cin >> num;
		t.push_back(num);
	}
 
    int dpp[n] = {0};
    int dpn[n] = {0};
    
    if(t[0]>=0) dpn[0] = 1;
    if(t[n-1]<=0) dpp[n-1]=1;
    
    for(int i=n-2;i>=0;i--)
    {
    	if(t[i]<=0)
    		dpp[i] = dpp[i+1]+1;
    	else
    		dpp[i] = dpp[i+1];
    }
    
    for(int i=1;i<n;i++)
    {
    	if(t[i]>=0)
    		dpn[i] = dpn[i-1]+1;
    	else
    		dpn[i] = dpn[i-1];
    }
    
    int ans = INT_MAX;
 
    for(int i=0;i<n-1;i++)
    {
    	ans = min(ans,dpn[i]+dpp[i+1]);
    }
    cout << ans << endl;
}
 
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout.precision(12);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	solve();
}