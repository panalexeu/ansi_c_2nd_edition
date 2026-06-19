#include <stdio.h>
#include <ctype.h>

int main() {
	char s[] = "123.45E6";
	double res, atof(char s[]);

	res = atof(s); 
	printf("%s atof %.9f", s, res);

	return 0;
}


double atof(char s []) {
	double val, power; 
	int i, sign, e_sign, e_val; 

	for (i=0; isspace(s[i]); i++) 
		;

	sign = (s[i] == '-') ? -1 : 1; 
	if (s[i] == '+' || s[i] == '-') 
		i++; 

	for (val=0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0'); 
	if (s[i] == '.')
		i++;
	for (power=1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0'); 
		power /= 10.0;
	}
	
	// handle exponent 
	if (s[i] == 'e' || s[i] == 'E') 
		i++; 

	e_sign = (s[i] == '-') ? -1: 1; 
	if (s[i] == '-') i++; 

	for (e_val=0; isdigit(s[i]); i++)
		e_val = 10 * e_val + (s[i] - '0'); 
	for (int j=0; j < e_val; j++) {
		if (e_sign < 0)
			power /= 10.0; 
		else
			power *= 10.0;
	}

	return sign * val * power;
}

