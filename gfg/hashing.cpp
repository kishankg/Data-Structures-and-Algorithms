//Array Pair Sum Divisibility Problem

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
	    
	    vector<int> v = take_input(n);
	    
	    int k;
	    cin >> k;
	    
	    map<int,int> h;
	    for(int i=0;i<n;i++)
	    {
	        h[v[i]%k]++; 
	    }
	    //cout << h[0] << endl;
	    bool ans = true;
	    for(int i=0;i<n;i++)
	    {
	    	int rem = v[i]%k;
	    	//cout << rem << " " << h[rem]%2 << endl;
	    	//int num = h[rem]%2;
	    	if(rem==0 && h[rem]%2 == 0) continue;
	    	else if(rem*2==k && h[rem]%2==0) continue;
	    	else if(h[rem]==h[k-rem]) continue;
	    	
	    	ans = false;
	    	break;
	    }
	    
	    if(ans)
	    {
	        cout << "True" << endl;
	    }
	    else
	    {
	        cout << "False" << endl;
	    }
	}
	return 0;
}

//#include<iostream>
//#include<bits/stdc++.h>
//#include<vector>
//#include<cmath>
//#include<iomanip>
//using namespace std;

//vector<int> take_input(int n)
//{
//    vector<int> v;
//    for(int i=0;i<n;i++)
//    {
//        int num;
//        cin >> num;
//        
//        v.push_back(num);
//    }
//    
//    return v;
//}
//vector<int> sumVector(vector<int> v)
//{
//    vector<int> sum(v.size());
//    sum[0] = v[0];
//    
//    for(int i=1;i<v.size();i++)
//    {
//        sum[i] = sum[i-1] + v[i];
//    }
//    return sum;
//}

//int main()
// {
//	int t;
//	cin >> t;
//	
//	while(t--)
//	{
//	    int n;
//	    cin >> n;
//	    
//	    //vector<int> v = take_input(n);
//	    
//	    map<int,int> h;
//	    int maxe = 0;
//	    for(int i=0;i<n;i++)
//	    {
//	        int num;
//	        cin >> num;
//	        
//	        maxe = max(maxe,num);
//	        h[num]++;    
//	    }
//	    
//	    int k;
//	    cin >> k;
//	    
//	    while(h.size()>0)
//	    {
//	        int num = h.begin()->first;
//	        
//	        int x = num/k;
//	        x++;
//	        
//	        int flag=0;
//	        //cout << num << "->";
//	        while(k*x<=(maxe+num))
//	        {
//	            //cout << k*x << endl;
//	            int target = k*x - num;
//	            
//	            if(h.find(target)!=h.end())
//	            {
//	            	if(target==num && h[num]==1)
//	            	{
//	            		x++;
//	            		continue;
//	            	}
//	                h[target]--;
//	                h[num]--;
//	                
//	                if(h[target]==0) h.erase(target);
//	                if(h[num]==0) h.erase(num);
//	                flag=1;
//	                break;
//	            }
//	            else
//	            {
//	                x++;
//	            }
//	            //x++;
//	        }
//	        
//	        if(flag==0) break;
//	    }
//	    
//	    if(h.size()==0)
//	    {
//	        cout << "True" << endl;
//	    }
//	    else
//	    {
//	        cout << "False" << endl;
//	    }
//	}
//	return 0;
//}
