#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define MAX_SIZE 9 // 8 symbols to write hex number, one for \0

char line[MAX_SIZE]; 
int htoi(char []); 
void read_line(char []); 


int main() {
	int res; 
	read_line(line);
	printf("%s\n", line);
	res = htoi(line); 
	printf("%s_16 => %d_10", line, res);
	return 0; 
}



void read_line(char s[]) {
	char c;
	int i = 0; 
	while (i<MAX_SIZE-1 && (c=getchar()) != '\n' && c != EOF) {
		s[i] = c; 
		++i; 
	} 
	s[i] = '\0'; 
}

int htoi(char s[]) {
	int val, dec, strip, i, j;
	val = dec = strip = i = j = 0;
	int buffer[MAX_SIZE];
	for (int k=0;k<MAX_SIZE;++k) 
		buffer[k] = 0; 
	
	// strip 0x or 0X chars if any 
	if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) 
		i=strip=2;
		
	// update buffer with decimal values 
	while (s[i] != '\0') {
		// parse hex alphabet into decimals 
		if (s[i] >= 'A' && s[i] <= 'F')
			buffer[j] = s[i] - 'A' + 10; 
		else if (s[i] >= '0' && s[i] <= '9')
			buffer[j] = s[i] - '0'; 
		++i; ++j; 
	}
	
	// conversion to dec value
	int counter = i-strip-1; 
	for (int k=0; k<MAX_SIZE;++k) {
		val += buffer[k] * pow(16, counter);
		--counter;
	} 

	// debug print 
	/*for (int j=0;j<MAX_SIZE;++j)
		printf("%d", buffer[j]);
	printf("\n");*/

	return val;
} 
