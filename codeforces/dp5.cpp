//https://codeforces.com/problemset/problem/1097/B

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

bool findPartiion (vector<int> arr, int n,int sum) 
{  
    int i, j; 
      
    if (sum%2 != 0)   
       return false; 
    
    bool part[sum/2+1][n+1]; 
      
    // initialize top row as true 
    for (i = 0; i <= n; i++) 
      part[0][i] = true; 
        
    // initialize leftmost column, except part[0][0], as 0 
    for (i = 1; i <= sum/2; i++) 
      part[i][0] = false;      
       
     // Fill the partition table in botton up manner  
     for (i = 1; i <= sum/2; i++)   
     { 
       for (j = 1; j <= n; j++)   
       { 
         part[i][j] = part[i][j-1]; 
         if (i >= arr[j-1]) 
           part[i][j] = part[i][j] || part[i - arr[j-1]][j-1]; 
       }         
     }     
       
    /* // uncomment this part to print table  
     for (i = 0; i <= sum/2; i++)   
     { 
       for (j = 0; j <= n; j++)   
          printf ("%4d", part[i][j]); 
       printf("\n"); 
     } */ 
       
     return part[sum/2][n]; 
}

void input()
{
	int n;
	cin >> n;

	vector<int> a;
	int num;
	int sum=0;
	for(int i=0;i<n;i++)
	{
		cin >> num;
		sum+=num;
		a.push_back(num);
	}

	sum = sum%360;

	if(sum==0)
	{
		cout << "YES" << endl;
		return;
	}

	// int dp[sum+1][n+1];

	// for(int i=0;i<=n;i++)
	// 	dp[0][i] = 1;

	// for(int i=1;i<=sum;i++)
	// 	dp[i][0] = 0;

	// for(int i=0;i<=sum;i++)
	// {
	// 	for(int j=1;j<=n;j++)
	// 	{
	// 		if(i>=a[j-1])
	// 		{
	// 			int take = dp[i-a[j-1]][j-1];
	// 			int take_no = dp[i][j];

	// 			dp[i][j] = (take || take_no);
	// 		}
	// 		else
	// 		{
	// 			dp[i][j] = dp[i][j-1];
	// 		}
	// 	}
	// }

	if(findPartiion(a,n,sum))
		cout <<  "YES"<< endl;
	else
		cout <<  "NO"<< endl;		
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


