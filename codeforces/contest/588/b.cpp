#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<cmath>
#include<iomanip>
using namespace std;

#define ll long long

int main()
{
	ll n,k;
	cin >> n >> k;
	
	string s;
	cin >> s;
	
	if(n==1 && k>=1)
	{
		cout << 0 << endl;
		return 0;
	}
	
	
	for(int i=0;i<n;i++)
	{
		if(k==0) break;
		
		if(i==0 && s[i]!='1')
		{
			s[i] = '1';
			k--;
		}
		else if(i==0 && s[i]=='1') continue;
		else if(s[i]!='0')
		{
			s[i] = '0';
			k--;
		}
		
	}
	
	cout << s << endl;
}
