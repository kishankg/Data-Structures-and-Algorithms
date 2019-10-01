//Running median of stream

//Running median of stream

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

#define ll long long

int main()
 {
		ll n;
	    cin >> n;
	    
	    priority_queue<int> maxUp;
	    priority_queue <int, vector<int>, greater<int>> minUp;
        
        int num;	    
	    for(int i=0;i<n;i++)
	    {
	        cin >> num;
            
            if(minUp.size()==0 && maxUp.size()==0)	        
	        {
	        	//cout << "E1" << endl;
	            minUp.push(num);
	        }    
	        else if(maxUp.size()>0 && num<maxUp.top())
	        {
	        	//cout << "E2" << endl;
                maxUp.push(num);
        	}
            else if(minUp.size()>0 && num>minUp.top())
	        {
	        	//cout << "E3" << endl;
	            minUp.push(num);
	       	}
	        else
	        {
	        	cout << "E4" << endl;
	           	minUp.push(num);
	        }
	        
	        //cout << maxUp.size() << " " << minUp.size() << endl;
	        int maxs = maxUp.size();
	        int mins = minUp.size();
	        if(abs(maxs-mins)>=2)
	        {
	        	if(mins-maxs>=2)
			    {
			    	//cout << "E5" << endl;
			        num = minUp.top();
			        minUp.pop();
			        maxUp.push(num);
			    }
			    else
			    {
			    	//cout << "E6" << endl;
			        num = maxUp.top();
			        maxUp.pop();
			        minUp.push(num);
			    }
	        }
	        
	        if(minUp.size()>maxUp.size())
	        {
	         	//cout << "E7" << endl;
	            cout << minUp.top() << endl;
	       	}
	        else if(minUp.size()<maxUp.size())
	        {
	        	//cout << "E8" << endl;
	            cout << maxUp.top() << endl;
	        }   
	        else
	        {
	        	//cout << "E9" << endl;
	            cout << (minUp.top()+maxUp.top())/2 << endl;
	        }
	    }	
	    
	    //cout << endl;
	return 0;
}
