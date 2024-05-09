//4. Modify the previous Makefile to include a header file named helper.h. Ensure that changes to helper.h trigger recompilation to helper.c and main.c.
#include "helper.h"
int main()
{
	printf("Main function\n");
	fun();
	return 0;
}
