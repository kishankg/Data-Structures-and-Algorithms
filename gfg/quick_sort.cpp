#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>& v,int low,int high)
{
	int pivot = v[high];
	
	int i = low-1;
	
	for(int j=low;j<high;j++)
	{
		if(v[j]<pivot)
		{
			i++;
			swap(v[i],v[j]);
		}
	}
	swap(v[high],v[i+1]);
	return (i+1);
}

void quickSort(vector<int>& v,int l,int r)
{
	if(l<r)
	{
		int pi = partition(v,l,r);
		
		quickSort(v,l,pi-1);
		quickSort(v,pi+1,r);
	}
}
int main()
{
	int n;
	cin >> n;
	
	vector<int> v(n);
	
	for(int i=0;i<n;i++) cin >> v[i];
	
	quickSort(v,0,n-1);
	
	for(int i=0;i<n;i++) cout << v[i] << " ";
	cout << endl;
}
