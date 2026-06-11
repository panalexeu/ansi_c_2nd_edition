//entab 
#include <stdio.h>

#define MAXSIZE 1000
#define N 4 // should be a symbolic parameter  

char line[MAXSIZE];
char buffer[MAXSIZE]; 
void readline(char []); 
void entab(char [], char[]); 

int main() {
	readline(line); 
	entab(line, buffer); 
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

void entab(char line[], char buffer[]) {
	int i, j = 0, blanks = 0;
	for (i = 0; line[i] != '\0'; ++i) {
		if (line[i] == ' ') {
			buffer[j++] = ' '; // post increment    
			++blanks;
			if ((i + 1) % N == 0) {   
				j -= blanks;          
				buffer[j++] = '\t';   
				blanks = 0;           
			}
		} else {
			buffer[j++] = line[i];
			blanks = 0;
		}
	}
	buffer[j] = '\0';
}
