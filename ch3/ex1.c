#include <stdio.h> 
#include <time.h>

int binsearch(int, unsigned short[], int); 
int binsearch_new(int, unsigned short[], int); 

int main() {
	int size = 65536; // 2^16, short unsigned 
	short unsigned array[size];
	for (int i=0;i<size;++i) array[i] = i;
	
	int num = 0;
	
	clock_t start = clock(); 
	binsearch(num, array, size); 
	clock_t end = clock();
	printf("binsearch exec time: %f\n", (double) (end - start) / CLOCKS_PER_SEC);

	start = clock(); 
	binsearch_new(num, array, size); 
	end = clock();
	printf("binsearch_new exec time: %f\n", (double) (end - start) / CLOCKS_PER_SEC);

	return 0;
}

int binsearch(int x, unsigned short v[], int n) {
	int low, high, mid; 

	low = 0; 
	high = n-1; 
	while (low <= high) {
		mid = (low + high) / 2;

		if (x < v[mid])
			high = mid - 1; 
		else if (x > v[mid])
			low = mid + 1; 
		else 
			return mid; 
	}

	return -1; 
}

/* 
hard to measure but this one should be faster: 
binsearch - does two comparisons when x > v[mid], and one otherwise, so the worst case is 
when x is at the rightmost of the sorted array. 
binsearch_new - always does 1 comparison (if/else) in the loop, plus 1 comparison at the end outside the loop.
*/
int binsearch_new(int x, unsigned short v[], int n) {
	int low, high, mid; 

	low = 0; 
	high = n-1; 
	while (low <= high) {
		mid = (low + high) / 2;

		if (x < v[mid])
			high = mid - 1;
		else
			low = mid + 1; 
	}

	return (v[mid] == x)? mid : -1; 	
} 
