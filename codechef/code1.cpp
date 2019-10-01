#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
	int t;
	cin >> t;
	
	while(t--)
	{
		ll n;
		cin >> n;
		
		vector<ll> v(n);
		
		for(int i=0;i<n;i++)
		{
			cin >> v[i];
		}
		
		ll x;
		cin >> x;
		
		int timea = 1;
		int timeb = x;
		
		int left = 0;
		int right = n-1;
		
		vector<ll> a(n);
		vector<ll> b(n);
		int suma = 0;
		for(int i=0;i<n;i++)
		{
			a[i] = suma + v[i];
			suma += v[i]; 
		}
		
		suma = 0;
		for(int i=n-1;i>=0;i--)
		{
			b[i] = suma + v[i]*x;
			suma += v[i]*x;
		}
		
		int cntA = 0;
		
		for(int i=0;i<n;i++)
		{
			if(a[i]<b[i])
			{
				cntA++;
			}
			else if(a[i]==b[i])
			{
				int cntb = (n-1)-cntA;
				
				if(cntA>=cntb) cntA++;
				
			}
			else
			{
				break;
			}
		}
		
		cout << cntA << " " << n-cntA << endl;
	}
}
