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

int main()
 {
	int t;
	cin >> t;
	
	while(t--)
    {
        int n;
        cin >> n;
        
        vector<int> coins = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
     
        for(int i=coins.size()-1;i>=0;i--)
        {
        	if(n==0) break;
        	
            if(coins[i]>n) continue;
            
            int count = n/coins[i];
            
            for(int j=0;j<count;j++)
            	cout << coins[i] << " ";
            n = n%coins[i];
            
        }
        
        cout << endl;
    }
	return 0;
}
