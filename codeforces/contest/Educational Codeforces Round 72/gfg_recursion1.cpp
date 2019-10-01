#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<cmath>
#include<iomanip>
using namespace std;

int m,n;
map<pair<int,int>,int> visited;
void fill(int x,int y,int num,vector<vector<int>>& row,int target)
{
    if(x>=m || y>=n || x<0 || y<0) return;
    
    pair<int,int> p = make_pair(x,y);
    
    if(visited.find(p)!=visited.end()) return;
    visited[p] = 1;
    //cout << x << " " << y << " " << target << endl;
    //cout << mem[x][y] << "==" << endl;
    
    if(row[x][y]!=target) return;
    
	row[x][y] = num;
    
    fill(x+1,y,num,row,target);
    fill(x-1,y,num,row,target);
    fill(x,y+1,num,row,target);
    fill(x,y-1,num,row,target);
    
    
}
int main()
 {
	int t;
	cin >> t;
	
	while(t--)
	{
	    cin >> m >> n;
	    mem.clear();
	    
	    vector<int> col(n,0);
	    vector<vector<int>> row(m,col);
	    
	    for(int i=0;i<m;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            cin >> row[i][j];
	        }
	    }
	    
	    int x,y,num;
	    cin >> x >> y >> num;
	    
	    fill(x,y,num,row,row[x][y]);
	    
	    for(int i=0;i<m;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            cout << row[i][j] << " ";
	        }
	    }
	    
	    cout << endl;
	}
	
	return 0;
}
