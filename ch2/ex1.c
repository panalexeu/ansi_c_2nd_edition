#include <float.h>
#include <limits.h>
#include <stdio.h>

int main() {
	printf("INTEGERS\n");
	printf("char range (signed): %d - %d\n", SCHAR_MIN, SCHAR_MAX);
	printf("char range (unsigned): %d - %d\n", 0, UCHAR_MAX);
	printf("short range (signed): %d - %d\n", SHRT_MIN, SHRT_MAX);
	printf("short range (unsigned): %d - %d\n", 0, USHRT_MAX);
	printf("int range (signed): %d - %d\n", INT_MIN, INT_MAX);
	printf("int range (unsigned): %d - %u\n", 0, UINT_MAX); 
	printf("long range (signed): %ld - %ld\n", LONG_MIN, LONG_MAX);
	printf("long range (unsigned): %d - %lu\n", 0, ULONG_MAX);
	
	printf("FLOATS\n");
	printf("float: %g - %g\n", -FLT_MAX, FLT_MAX);
	printf("double: %g - %g\n", -DBL_MAX, DBL_MAX);
	return 0; 
} 
