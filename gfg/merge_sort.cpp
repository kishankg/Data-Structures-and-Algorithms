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

int merge(vector<int> &arr,int l,int m,int r)
{
    int n1 = m-l+1;
    int n2 = r-m;
    
    int L[n1],R[n2];
    
    for(int i=l;i<=m;i++)
    {
        L[i-l] = arr[i];
    }
    
    for(int i=m+1;i<=r;i++)
    {
        R[i-m-1] = arr[i];
    }
    
    int i=0;
    int j=0;
    int k=l;
    int count =0;
    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
            arr[k++] = L[i++]; 
        }
        else
        {
            count += (m+1) - (i+l);
            arr[k++] = R[j++];
        }
    }
    while(i<n1)
    {
        arr[k++] = L[i++];
    }
    while(j<n2)
    {
        arr[k++] = R[j++];
    }
    
    return count;
}

int mergeSort(vector<int> &v,int l,int r)
{
    int count = 0;
    if(l<r)
    {
        int m = (l+r)/2;
        //cout << m << endl;
        count += mergeSort(v,l,m);
        count += mergeSort(v,m+1,r);
        count += merge(v,l,m,r);
    }
    
    return count;
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
	    
	    int count = 0; 
	    cout << mergeSort(v,0,n-1) << endl;
	    
//	    for(int i=0;i<v.size();i++)
//	    	cout << v[i] << " ";
//	    cout << endl;
	}
	return 0;
}
