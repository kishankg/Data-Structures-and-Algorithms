//N-Queen Problem

#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<cmath>
#include<iomanip>
using namespace std;

vector<int> take_input(int n)
{
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int num;
        cin >> num;
        
        v.push_back(num);
    }
    
    return v;
}
vector<int> sumVector(vector<int> v)
{
    vector<int> sum(v.size());
    sum[0] = v[0];
    
    for(int i=1;i<v.size();i++)
    {
        sum[i] = sum[i-1] + v[i];
    }
    return sum;
}

int n;
vector<vector<int>> ans;

bool isSafe(int row,int col,int board[n][n])
{
    if(row<0 || col<0 || row>=n || col>=n || board[row][col]!=0) return false;
    
    //Check in row
    for(int i=0;i<n;i++)
    {
        if(board[i][col]!=0) return false;
    }

    //Check in col
    for(int i=0;i<n;i++)
    {
        if(board[row][i]!=0) return false;
    }
    
    //Check in (i-1,j-1) direction
    int i=row;
    int j=col;
    while(i>0 && j>0)
    {
        if(board[i][j]!=0) return false;
        i--;
        j--;
    }
    //Check in (i-1,j+1) direction
    i=row;
    j=col;
    while(i>0 && j<n)
    {
        if(board[i][j]!=0) return false;
        i--;
        j++;
    }
    
    //Check in (i+1,j-1) direction
    i=row;
    j=col;
    while(i<n && j>0)
    {
        if(board[i][j]!=0) return false;
        i++;
        j--;
    }
    
    //Check in (i+1,j+1) direction
    i=row;
    j=col;
    while(i<n && j<n)
    {
        if(board[i][j]!=0) return false;
        i++;
        j++;
    }
    
    return true;
}

vector<int> places;

void placeUtil(int index,int board[n][n])
{
    if(index==n)
    {
        if(places.size()==n)
            ans.push_back(places);
        return;
    }
    
    for(int col=0;col<n;col++)
    {
        if(isSafe(index,col,board))
        {
            board[index][col] = 1;
            places.push_back(col);
            
            placeUtil(index+1,board);
            
            places.pop_back();
            board[index][col] = 0;
        }
    }
}

void place()
{
    int board[n][n] = {0};
    
    placeUtil(0,board);
}
int main()
 {
	int t;
	cin >> t;
	
	while(t--)
	{
	    ans.clear();
	    //int n;
	    cin >> n;
	    
	    place();
	    
	    if(ans.size()==0)
	    {
	        cout << -1 << endl;
	        continue;
	    }
	    
	    for(int i=0;i<ans.size();i++)
	    {
	        cout << "[";
	        for(int j=0;j<ans[i].size();j++)
	        {
	            cout << ans[i][j] << " ";
	        }
	        cout >> "] ";
	    }
	    
	    cout << endl;
	}
	return 0;
}
