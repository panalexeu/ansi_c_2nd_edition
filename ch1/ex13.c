#include <stdio.h> 

#define BUCKETS 10

main() {
	int i, j, c, wc;
	int buckets[BUCKETS];
	
	i = j = c = wc = 0;  

	for (i=0; i<BUCKETS; ++i)
		buckets[i] = 0; 
	
	while ((c = getchar()) != EOF){
		if (c != ' ' && c != '\n' && c != '\t')
			++wc;
		else if (wc != 0) {
			if (wc >= BUCKETS) wc = BUCKETS - 1;
			buckets[wc] += 1; 
			wc = 0;
		}
	}

	for (i=0; i<BUCKETS; ++i) {
		for (j=0; j<buckets[i]; ++j) {
			putchar('#');
		}
		if (buckets[i] == 0) putchar('.');
		putchar('\n');
	} 
} 
