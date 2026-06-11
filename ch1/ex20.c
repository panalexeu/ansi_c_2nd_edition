//detab 
#include <stdio.h>

#define MAXSIZE 1000
#define N 4 // should be a symbolic parameter  

char line[MAXSIZE];
char buffer[MAXSIZE]; 
void readline(char []); 
void detab(char [], char[]); 

int main() {
	readline(line); 
	detab(line, buffer); 
	printf("%s", buffer);
	return 0; 
} 


void readline(char line[]) {
	int c, i;
	i=0;
	while ((c = getchar()) != EOF && i<MAXSIZE-1) {
		line[i] = c; 
		++i;
		if (c == '\n')
			break;
	}
	line[i] = '\0'; 
}

void detab(char line[], char buffer[]) {
	int j, j_temp, blanks;
	j = j_temp = blanks = 0;
	for (int i=0;line[i] != '\0';++i) {
		if (line[i] == '\t') {
			blanks = N - (j % N);
			j_temp = j; 
			while (j<j_temp+blanks) {
				buffer[j] = ' '; 
				j++; 
			} 
		} else {
			buffer[j] = line[i]; 
			j++;
		}
	} 
} 
