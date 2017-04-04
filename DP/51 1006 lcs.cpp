#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int dp[1000][1000] = {0};

int main()
{
	string a,b;
	cin>>a>>b;
	int m = a.size();
	int n = b.size();
	for(int i = 1;i<=m;i++)
	{
		for(int j = 1;j<=n;j++)
		{
			if(a[i-1]==b[j-1])
				dp[i][j] = dp[i-1][j-1] + 1;
			else
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		}
	}	
	string ans;
	int i = m,j = n;
	while(dp[i][j])
	{
		if(dp[i][j]==dp[i-1][j])
			i--;
		else if(dp[i][j]==dp[i][j-1])
			j--;
		else 
		{
			ans.push_back(a[i-1]);
			i--;j--;
		}
	}
	for(int i = ans.size()-1;i>=0;i--)
		cout<<ans[i];
	cout<<endl;
}