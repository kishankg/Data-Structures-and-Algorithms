#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
	ll n;
	cin >> n;
	
	string s;
	cin >> s;
	
	int one = 0;
	
	for(ll i=0;i<n;i++)
	{
		if(s[i]=='n') one++;
	}
	
	int zero = (n-one*3)/4;
	
	for(ll i=0;i<one;i++)
		cout << 1 << " ";
	for(ll i=0;i<zero;i++)
		cout << 0 << " ";
	cout << endl;
}
