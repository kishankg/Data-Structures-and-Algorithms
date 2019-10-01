#include<bits/stdc++.h>
using namespace std;

#define ll long long


int main()
{
	ll n;
	cin >> n;
	
	//vector<int> col(5,0);
	vector<vector<int>> v(n);
	
	ll maxNum = INT_MIN;
	
	for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<n;j++)
		{
			ll num;
			cin >> num;
			
			maxNum = max(maxNum,num);
			v[j].push_back(num);
		}
	}
	
	//bool prime[maxNum+1] = SieveOfEratosthenes(maxNum);
	
	for(ll i=0;i<n;i++)
	{
		sort(v[i].begin(),v[i].end());
	}
	
	for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<n;j++)
		{
			cout << v[i][j] << " ";
		}
		
		cout << endl;
	}
	
	//vector<ll> ans;
	
	for(ll i=0;i<n;i++)
	{
		ll num = v[i][n-1];
		for(ll j=0;j<n-1;j++)
		{
			if(v[i][j]==v[i][j+1]) continue;
			ll diff = abs(v[i][j]-v[i][j+1]);
			num = min(num,diff);
		}
		cout << 1 << " ";
		//ans.push_back(num);
	}
	cout << endl;

}
