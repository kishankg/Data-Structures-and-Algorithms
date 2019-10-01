//Sudoku Problem

#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<cmath>
#include<iomanip>
using namespace std;

bool isSafe(int r,int c,int num,int mat[9][9])
{
    if(r>=9 || c>=9 || r<0 || c<0 && mat[r][c]!=0) return false;
    
    //check in row
    for(int i=0;i<9;i++)
    {
        //if(i==r) continue;
        
        if(mat[i][c]==num) return false;
    }
    
    //check in col
    for(int i=0;i<9;i++)
    {
        //if(i==c) continue;
        
        if(mat[r][i]==num) return false;
    }
    
    //check in square
    int row = r-r%3;
    int col = c-c%3;
    
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(mat[i+row][j+col]==num) return false;
        }
    }
    
    return true;
}

int ans[9][9];

bool solved(int mat[9][9])
{
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			if(mat[i][j]==0) return false;
		}
	}
	
	return true;
}
void solve(int r,int c,int mat[9][9])
{
	
	if(solved(mat))
	{
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
			{
				ans[i][j] = mat[i][j];
			}
		}
		cout << "YES" << endl;
		//ans = mat;
		return;
	}
	
	if(c==9)
	{
		r++;
		c=0;
		if(r==9) return;
	}
	
	//cout << r << " " << c << endl;
    
    if(mat[r][c]!=0)
    {
    	solve(r,c+1,mat);
    }
    else
    {
    	for(int k=1;k<=9;k++)
		{
			if(isSafe(r,c,k,mat))
			{
				mat[r][c] = k;
	  
				solve(r,c+1,mat);
				
				mat[r][c] = 0;
			}
		}
    }
    
}

int main()
 {
	int t;
	cin >> t;
	
	while(t--)
	{
	    int mat[9][9];
	    //vector<int> column(9,0);
	    //vector<vector<int>> mat(9,column);
	    
	    for(int i=0;i<9;i++)
	    {
	        for(int j=0;j<9;j++)
	        {
	            //int num;
	            cin >> mat[i][j];
	        }
	    }
	    
	    //cout << "YES" << endl;
	    //bool ans = false,
	    //ans = mat;
	    solve(0,0,mat);
	    
	    for(int i=0;i<9;i++)
	    {
	        for(int j=0;j<9;j++)
	        {
	            cout << ans[i][j] << " ";
	        }
	        
	        cout << endl;
	    }
	}
	
	
	return 0;
}
