#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
	ll n;
	cin >> n;
	
	vector<ll> v(n);
	int sum = 0;
	
	for(int i=0;i<n;i++)
	{
		cin >> v[i];
		
		sum += v[i];
	}
	
	if(n<3)
	{
		cout << 0 << endl;
		return 0;
	}
	
	if(sum%3)
	{
		cout << 0 << endl;
		return 0;
	}
	
	int sum1 = 0;
	int i=0;
	for(i=0;i<n;i++)
	{
		sum1 += v[i];
		
		if(3*sum1==sum)
		{
			i++;
			break;
		}
	}
	
	int sum2 = 0;
	int count1 = 0;	
	for(;i<n;i++)
	{
		sum2+=v[i];
		
		if(sum2==0) count1++;
		
		if(3*sum2==sum)
		{
			i++;
			break;
		}
	}
	
	int sum3=0;
	int count2 = 0;
	
	for(;i<n;i++)
	{
		sum3+=v[i];
		
		if(sum3==0) count2++;
		
		if(3*sum3==sum)
		{
			i++;
			break;
		}
	}
	
	if(i!=n-1)
	{
		cout << 0 << endl;
		return 0;
	}
	
}
















