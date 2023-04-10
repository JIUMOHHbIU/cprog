#include <stdio.h>

#include "rc.h"

void view_rc(int rc)
{
	if (rc == ERR_NO)
	{
		printf("No error has been found\n");
	}
	else if (rc == ERR_INPUT)
	{
		printf("An error has been catched during input processing\n");	
	}
}