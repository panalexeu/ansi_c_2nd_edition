#include <stdio.h>

#define MAXSIZE 4096 

char clean_code[MAXSIZE];

void keep_code(char []); 

int main() {
	keep_code(clean_code);
	printf("%s", clean_code); 
	return 0;
}


void keep_code(char clean_code[]) {
	int i, c, c_temp; 
	i = c = c_temp = 0;
	
	// state variables
	char is_oneline = 0; 
	char is_multiline = 0;
	char is_string = 0;
	char in_comment = 0;

	while((c = getchar()) != EOF && i < MAXSIZE-1) {
		in_comment = is_oneline + is_multiline; 

		// catch string  
		if (c_temp != '\\' && c == '\"' && in_comment == 0) {
			// string exit case 
			if (is_string == 1)
				is_string = 0;
			else 
				is_string = 1; 
				
			clean_code[i] = c;
			++i;
		// catch '//' case
		} else if (c_temp == '/' && c == '/' && is_string == 0) {
			is_oneline = 1;
			is_multiline = 0; 
		// catch '/*' case 
		} else if (c_temp == '/' && c == '*' && is_string == 0) {
			is_oneline = 0; 
			is_multiline = 1; 
		// default assignment case  
		} else if (is_oneline == 0 && is_multiline == 0) {
			clean_code[i] = c;
			++i;
		// oneline clean case (delete up to \n) 
		} else if (is_oneline == 1 && c == '\n') {
			// subtract -1 because of '//' takes two symbols
			clean_code[i-1] = '\n'; 
			is_oneline = 0; 
		} 
		// multiline clean case (delete up to */)
		else if (c_temp == '*' && c == '/') { 
			// subtract -1 because of '//' takes two symbols
			clean_code[i-1] = '\n'; 
			is_multiline = 0; 
		} 

		c_temp = c;
	} 
} 

