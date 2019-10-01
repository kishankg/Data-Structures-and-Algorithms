#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
	string s;
	cin >> s;
	
	ll len = s.length();
	
	vector<vector<int>> v(26);

	for(int i=0;i<len;i++)
	{
		v[s[i]-'a'].push_back(i);
	}
	
	for(ll i=0;i<len;i++)
	{
		bool ann = true;
		ll l = i;
		ll r = i+1;
		
		while(1)
		{
			char curr = s[l];
			string currS = s.substr(l,r);
			
			if(l==0)
			{
				if(!ann) cout << "Ann" << endl;
				else cout << "Mike" << endl;
				break;
			}
			
			int len1 = curr-'a';
			int flag=0;
			for(int j=0;j<len1;j++)
			{
				int size = v[j].size();
				if(size==0) continue;
				if(v[j][0]>l) continue;
				
				flag=1;
			}
			
			if(flag==1)
			{
				if(!ann) cout << "Mike" << endl;
				else cout << "Ann" << endl;
				
				break;
			}
			
			flag=0;
			
			for(int j=0;j<v[len1].size();j++)
			{
				if(v[len1][j]>=l)
				{
					if(!ann) cout << "Ann" << endl;
					else cout << "Mike" << endl;
					break;
				}
				else
				{
					string extend = s.substr(v[len1][j],r);
					//cout << extend << " " << currS << endl;
					if(extend<currS)
					{
						if(ann) cout << "Mike" << endl;
						else cout << "Ann" << endl;
						
						break;
					}
					else
					{
						if(!ann) cout << "Ann" << endl;
						else cout << "Mike" << endl;
						break;
					}
				}
			}
			break;
			ann = !ann;
		}
	}
}
