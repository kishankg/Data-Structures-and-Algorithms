#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
	ll t;
	cin >> t;
	
	while(t--)
	{
		ll str,in,exp;
		cin >> str >> in >> exp;
		
		ll addS = max(0LL, (exp+in-str+2)/2);
		
		cout << max(0LL, exp-addS+1) << endl;
	}
}
