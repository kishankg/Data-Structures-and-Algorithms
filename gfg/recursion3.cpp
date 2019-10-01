#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<cmath>
#include<iomanip>
using namespace std;
map<vector<int>,int> final1;

void find(vector<int> coins,int target,int index,vector<int> ans)
{
//    if(target==0)
//    {
//       cout << "Entered<" << endl;
//    }
    if(index>coins.size())
    {
        if(target==0)
        {
            //cout << "Entered>" << endl;
            sort(ans.begin(),ans.end());
            final1[ans] = 1;
        }
        
        return;
    }
    
    if(target==0)
    {
        sort(ans.begin(),ans.end());
        //cout << "Entered>" << endl;
        final1[ans] = 1;
        return;
    }
    else if(target<0)
    {
        return;
    }
    else
    {
        find(coins,target,index+1,ans);
        vector<int> temp = ans;
        temp.push_back(coins[index]);
        find(coins,target-coins[index],index+1,temp);
    }
}

int main()
{
	int t;
	cin >> t;
	while(t--)
    {
        final1.clear();
        int n;
	    cin >> n;   
	    
	    vector<int> a;
	    for(int i=0;i<n;i++)
	    {
	        int num;
	        cin >> num;
	        
	        a.push_back(num);
	    }
	    
	    int b;
	    cin >> b;
	    
	    sort(a.begin(),a.end());
	    vector<int> ans;
	    
	    find(a,b,0,ans);
	    
	    if(final1.size()==0)
	    {
	    	cout << "Empty" << endl;
	    	continue;
	    }
	    
	    while(final1.size()>0)
	    {
	        vector<int> v = final1.begin()->first;
	        
	        cout << "(";
	        for(int i=0;i<v.size();i++)
	        {
	            cout << v[i];
	            
	            if(i!=v.size()-1)
	            {
	            	cout << " ";
	            }
	        }
	        cout << ")";
	        
	        final1.erase(v);
	    }
	    cout << endl;
	   // for(int i=0;i<final.size();i++)
	   // {
	   //     cout << "(";

	   //     for(int j=0;j<final[i].size();j++)
	   //     {
	   //         cout << final[i][j];
	            
	   //         if(j!=final[i].size()-1)
	   //         {
	   //             cout << " ";
	   //         }
	   //     }
	        
	   //     cout << ")";
	   // }
	    
	    //cout << endl;
    }
}
