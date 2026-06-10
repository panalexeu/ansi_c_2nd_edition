#include <stdio.h>

#define MAXLINE 50 
#define BUFFER_SIZE 200 
#define THRESH 10 

int getline_(char[], int);
int buffer_copy(char[], char[], int);
void print_buffer(char[], int); 

int main() {
	int len; 
	int pointer = 0;
	char line[MAXLINE]; 
	char buffer[BUFFER_SIZE]; 
	

	while ((len = getline_(line, MAXLINE)) > 0) {
		if (len > THRESH) {
			pointer = buffer_copy(buffer, line, pointer);
			if (pointer == BUFFER_SIZE) {
				print_buffer(buffer, pointer); 
				return 1; 
			}
		} 
	}

	print_buffer(buffer, pointer);

	return 0;
}

int getline_(char s[], int lim) {
	int c,i;
	
	i = 0; 
	while ((c = getchar()) != EOF && c != '\n' && i < lim-1) {
		s[i] = c; 
		++i;
	}		
	if (c == '\n') {
		s[i] = c;
		i++; 
	}
	s[i-1] = '\n';
	s[i] = '\0'; 
	
	return i; 
}

int buffer_copy(char buffer[], char line[], int pointer) {
	int i = 0; 
	while (i < MAXLINE && pointer < BUFFER_SIZE) {
		buffer[pointer] = line[i]; 
		if (buffer[pointer] == '\0')
			return ++pointer; 
		++pointer;
		++i; 
	}
	return pointer;
}

void print_buffer(char buffer[], int pointer) {
	int i;
	for (i=0; i<pointer; ++i) {
		if (buffer[i] != '\0')
			putchar(buffer[i]);
	} 
}  
