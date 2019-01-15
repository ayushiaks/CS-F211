#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, k = 1, count = 1, x=0, i=0, j=0, w=0, t=0;
	cin >> n;
	int arr[n+1][n+1]={0};
	while(k<=n/2+1){
		for (i = (n/2)+1-x; i <= (n/2)+k+1; ++i)
		{
			arr[n/2+k][i] = count;
			count++;
			/* code */
		}
		if(count>=n*n)
			break;
		j = i-3;
		i--;
		int sum = 0;
		while(sum!=(2*k-1))
		{
			arr[j][i] = count;
			count++;
			j--;
			// j--;
			sum++;
			// cout <<"in"<<endl;
			/* code */
		}
		
		for (w = i-1; w>=(n/2-k+1); --w)
		{
			arr[j+1][w] = count;
			count++;
		}
		// cout <<i<<j<<endl;
		sum = 0, i=i-k-x-t, j++;
		while(sum!=2*k){
			
			arr[i][j] = count;
			count++;
			sum++;
			i++;
		}
		k++;
		if(k>2)
			x++;
		if(k>1)
			t=1;
	}
	k=0;
	for (i = 1; i <= n; ++i)
	{
		for (j = 1; j <=n; ++j)
		{
			cout << arr[i][j];
			// if(j!=n && j>k)
			// 	cout<<"-";
			// else
				cout<<" ";
			// /* code */
		}
		cout << endl;
		if(k==n/2)
			k=1;
		else
		k++;
		/* code */
	}
}