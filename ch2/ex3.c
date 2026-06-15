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
	printf("%s_16\n", line);
	res = htoi(line); 
	printf("%d_10\n", res);
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
	int i = 0, val = 0;  
	
	// strip 0x or 0X chars if any 
	if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) 
		i = 2;
		
	while (s[i] != '\0') {
		// parse hex alphabet into decimals 
		if (s[i] >= 'A' && s[i] <= 'F') s[i] = s[i] - 'A' + 10; 
		else if (s[i] >= 'a' && s[i] <= 'f') s[i] = s[i] - 'a' + 10; 
		else if (s[i] >= '0' && s[i] <= '9') s[i] = s[i] - '0'; 
		// shif left by hex position, add digit
		val = val * 16 + s[i]; 
		++i; 
	}
	
	return val;
} 
