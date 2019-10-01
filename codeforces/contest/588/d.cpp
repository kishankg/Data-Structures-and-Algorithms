#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<cmath>
#include<iomanip>
using namespace std;

#define ull unsigned long long

struct st
{
	vector<int> bits;
	ull intel;
};

bool conflict(vector<int> bit1,vector<int> bit2)
{
	for(int i=0;i<64;i++)
	{
		if(bit1[i]==1 && bit2[i]==1) return true;
	}
	return false;
}

map<int,map<int,int>> non;

int main()
{
	non.clear();
	
	int n;
	cin >> n;
	
	ull a,b;
	vector<st> v(n);
	
	for(int i=0;i<n;i++)
	{
		cin >> a >> v[i].intel;
		
		vector<int> bit(64,0);	
		int j=0;
		while(a)
		{	
			if(a%2)
			{
				bit[j]=1;
			}
			j++;
			a = a/2;
		}
		
		v[i].bits = bit;
	}
	
	int ans = 0;
	
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(!conflict(v[i].bits,v[j].bits))
			{
				non[i][j] = 1;
			}
		}
	}
	
	for(int i=0;i<n-1;i++)
	{
		int sum = v[i].intel;
		if(h.find(i)==h.end()) continue;
		
		map<int,int> temp = h[i];
		
		while(temp.size()>0)
		{
			int ind = temp.begin()->first;
			sum += v[ind].intel;
		}
		
		ans = max(ans,sum);
	}
	
	cout << ans << endl;
}
