#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define s(x) scanf("%d", &x);
#define p(x) printf("%d\n", x);
#define p2(x, y) printf("%d %d\n", x, y);
#define max(a, b) (a>b?a:b)



int findMaxA(int n){
	if(n<=6)
		return n;
	int screen[n]; 	
	for(int i = 1; i<=6;i++){
		screen[i] = i;
	}


	for (int i = 7; i<= n ; ++i)
	{
		screen[i] = 0;
		for(int j = 1; j<i-2; j++){
			int curr = (i-j-1)*screen[j]; 
            if (curr > screen[i]) 
                screen[i] = curr; 
		}
		
		/* code */
	}
	return screen[n];
}


int main(){
	int n;
	s(n)
	p(findMaxA(n))
}