#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
	ll t;
	cin >> t;
	
	while(t--)
	{
		ll a,b;
		cin >> a >> b;
		
		ll sum = a+b;
		
		int match[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
		
		int count = 0;
		
		while(sum)
		{
			int i = sum%10;
			count += match[i];
			
			sum = sum/10;
		}
		
		cout << count << endl;
	}
}
