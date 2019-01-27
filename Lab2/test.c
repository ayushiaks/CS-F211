#include<stdio.h>
int c;
int *add(int *a, int *b){
	c = *a + *b;
	return &c;
}

int main(){
	int a = 2, b=4;
	int *pt = add(&a, &b);
	printf("%d\n", *pt);
}