#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<cmath>
#include<iomanip>
using namespace std;


int main()
{
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	
	int sum = a+b+c+d;
	
	if(sum%2!=0)
	{
		cout << "NO" << endl;
		return 0;
	}
	
	if(a+b == sum/2 || a+c==sum/2 || a+d==sum/2)
	{
		cout << "YES" << endl;
		return 0;
	}
	
	if(a==b+c+d || b==a+c+d || c==a+b+d || d==a+c+b)
	{
		cout << "YES" << endl;
		return 0;
	}
	
	cout << "NO" << endl;
		return 0;
	
	
}
