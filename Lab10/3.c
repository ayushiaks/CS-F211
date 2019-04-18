#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<stdbool.h>

#define min(a, b) (a<b?a:b);
#define s(x) scanf("%d", &x);
#define p(x) printf("%d\n", x);

int k, n, heap[100];

int compare(const void *a, const void *b){
	return *(int*)b-*(int*)a;
}

void push(int a, int i){
	heap[i] = a;
	qsort(heap, n, sizeof(int), compare);

}

int findmedian(int size){
	int med;
	if(size%2==0){
        // p(size)
		med = (heap[size/2]+heap[size/2-1])/2;
	}
	else
	{
        // p(size)
		med = heap[size/2];
	}
	return med;
	
	
}

int main(){
	s(n)
	// s(k)
	for (int i = 0; i < n; ++i)
	{
		int a;
		s(a)
		push(a, i);
		p(findmedian(i+1))
		/* code */
	}
	
}