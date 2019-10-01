//https://codeforces.com/problemset/problem/1176/C

#include<bits/stdc++.h>
using namespace std;

#define ll long long

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


int main()
{
	ll n;
		cin >> n;
		
		vector<ll> v = vector_input(n);
		int flag[6] = {0};
		
		for(ll i=0;i<n;i++)
		{
			if(v[i]==4)
			{
				flag[0]++;
			}
			else if(v[i]==8)
			{
				if(flag[0])
				{
					flag[1]++;
					flag[0]--;
				}
			}
			else if(v[i]==15)
			{
				if(flag[1])
				{
					flag[2]++;
					flag[1]--;
				}
			}
			else if(v[i]==16)
			{
				if(flag[2])
				{
					flag[3]++;
					flag[2]--;
				}
			}
			else if(v[i]==23)
			{
				if(flag[3])
				{
					flag[4]++;
					flag[3]--;
				}
			}
			else
			{
				if(flag[4])
				{
					flag[5]++;
					flag[4]--;
				}
			}
			
		}
		
		cout << n-flag[5]*6 << endl;
}
