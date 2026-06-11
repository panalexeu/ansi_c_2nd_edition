// fold
#include <stdio.h>

#define MAXSIZE 1000 
#define N 3

char line[MAXSIZE];
char buffer[MAXSIZE]; 

int getline_(char []);  
void fold(char [], char [], int);

int main() { 
	int len = getline_(line);
	fold(line,buffer,len-1);
	printf("%s", buffer);
	return 0; 
} 

int getline_(char line[]) {
	int i,c;
	i=c=0;
	
	while ((c = getchar()) != EOF && i < MAXSIZE) {
		line[i] = c;
		if (c == '\n')
			break;
		else 
			++i;
	} 
	line[i] = '\0'; 

	return i; 
}

void fold(char line[], char buffer[], int len) {
	int folds = (len + N - 1) / N; 
	int j = 0; 
	int counter = 0;

	if (folds==0) 
		return; 

	for (int i=0; line[i] != '\0'; ++i) {
		++counter;
		buffer[j] = line[i]; 
		if (counter == folds) {
			buffer[++j] = '\n';	
			counter = 0;  
		}  
		++j; 
	}

	buffer[j] = '\0';
}


