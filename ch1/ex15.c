#include <stdio.h>

float convert(int);

main() {
	float fahr, celsius;
	int lower, upper, step;

	lower = 0; 
	upper = 300; 
	step = 20; 
	
	printf("| far | cels  |\n");
	printf("| --- | ----- |\n");

	fahr = lower;
	while (fahr <= upper) {
		celsius = convert(fahr);
		printf("| %3.0f | %5.1f |\n", fahr, celsius); 
		fahr += step;
	}
}

float convert(int fahr) { 
	return (5.0/9.0) * (fahr-32);
}
