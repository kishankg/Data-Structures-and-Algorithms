#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<cmath>
#include<iomanip>
using namespace std;

int n,m;
vector<vector<int>> edges;

struct pizza
{
	int first;
	int second;
};

vector<pizza> p;
pizza temp;
temp.first = 1;
temp.second = 1;

p.push_back(temp);

temp.first = 1;
temp.second = 2;

p.push_back(temp);

temp.first = 1;
temp.second = 3;

p.push_back(temp);

temp.first = 1;
temp.second = 4;

p.push_back(temp);

temp.first = 1;
temp.second = 5;

p.push_back(temp);

temp.first = 1;
temp.second = 6;

p.push_back(temp);

temp.first = 2;
temp.second = 2;

p.push_back(temp);

temp.first = 2;
temp.second = 3;

p.push_back(temp);

temp.first = 2;
temp.second = 4;

p.push_back(temp);

temp.first = 2;
temp.second = 5;

p.push_back(temp);

temp.first = 2;
temp.second = 6;

p.push_back(temp);

temp.first = 3;
temp.second = 3;

p.push_back(temp);

temp.first = 3;
temp.second = 4;

p.push_back(temp);

temp.first = 3;
temp.second = 5;

p.push_back(temp);

temp.first = 3;
temp.second = 6;

p.push_back(temp);

temp.first = 4;
temp.second = 4;

p.push_back(temp);

temp.first = 4;
temp.second = 5;

p.push_back(temp);

temp.first = 4;
temp.second = 6;

p.push_back(temp);

temp.first = 5;
temp.second = 5;

p.push_back(temp);

temp.first = 5;
temp.second = 6;

p.push_back(temp);

temp.first = 6;
temp.second = 6;

p.push_back(temp);

void solve()
{
	int vert[n+1] = {0};
	
	vector<int> v0;
	vector<int> v1 = {1,2,3,4,5,6};
	vector<int> v2 = {2,3,4,5,6};
	vector<int> v3 = {3,4,5,6};
	vector<int> v4 = {4,5,6};
	vector<int> v5 = {5,6};
	vector<int> v6 = {6};
	
	vector<vector<int>> type;
	type.push_back(v0);
	type.push_back(v1);
	type.push_back(v2);
	type.push_back(v3);
	type.push_back(v4);
	type.push_back(v5);
	type.push_back(v6);
	
	
	
	
	for(int i=1;i<=n;i++)
	{
		vector<int> edge = edges[i];
		
		for(int j=0;j<edge.size();j++)
		{
			for(int k=0;k<21;k++)
			{
				vert[i] = k.first;
				vert[edge[j]] = k.second;
				
				solveUtil();
				
				vert[i] = k.second;
				vert[edge[j]] = k.first;
				
				solveUtil();
				
				vert[i] = 0;
				vert[edge[j]] = 0;
				
				solveUtil();
			}
		}
	}
}

int main()
{
	//int n,m;
	cin >> n >> m;
	
	vector<vector<int>> edge1(n+1);
	
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin >> x >> y;
		
		edge1[x].push_back(y);
		edge1[y].push_back(x);
	}
	
	solve();
	
}
