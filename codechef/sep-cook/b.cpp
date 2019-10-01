#include<bits/stdc++.h>
using namespace std;

#define ll long long

bool findPartiion(vector<int> v) 
{ 
	ll n = v.size();
    
    ll sum = 0; 
    ll i, j; 
    
    for (i = 0; i < n; i++) 
      sum += v[i]; 
      
    if (sum%2 != 0)   
       return false; 
    
    ll part[sum/2+1][n+1]; 
      
    for (i = 0; i <= n; i++) 
      part[0][i] = true; 
        
    for (i = 1; i <= sum/2; i++) 
      part[i][0] = false;      
       
     for (i = 1; i <= sum/2; i++)   
     { 
       for (j = 1; j <= n; j++)   
       { 
         part[i][j] = part[i][j-1]; 
         if (i >= v[j-1]) 
           part[i][j] = part[i][j] || part[i - v[j-1]][j-1]; 
       }         
     }     
       
     return part[sum/2][n]; 
}      

int main()
{
	ll t;
	cin >> t;
	
	while(t--)
	{
		ll a,b,c;
		cin >> a >> b >> c;
		
		c = c%2;
		
		if(c%2==0 && a%2==0 && b%2==0) cout << "YES" << endl;
		else if(c%2==0 && a%2!=0) cout << "NO" << endl;
		else if(c%2!=0 && a%2==0) cout << "YES" << endl;
		else
		{
			a1 = a%2;
			b1 = b%2;
			c1 = c%2;
			
			if(a1 && c1 && !b1)
			{
				if(b>=2) cout << "YES" << endl;
				else cout << "NO" << endl; 
			}
			else if(a1+b1==c1) cout << "YES" << endl;
			else if()	
		}
		
//		int n = a+b+c;
//		vector<int> v;
//		
//		while(a--)
//		{
//			v.push_back(1);
//		}
//		while(b--)
//		{
//			v.push_back(2);
//		}
//		while(c--)
//		{
//			v.push_back(3);
//		}
//		
//		if(findPartiion(v))
//			cout << "YES" << endl;
//		else
//			cout << "NO" << endl;
	}
}
