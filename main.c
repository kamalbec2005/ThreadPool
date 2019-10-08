#include <stdio.h>
#include "sv2x_sec_wrap.h"

int main(int argc, char **argv)
{
	if (SEC_SUCCESS != wrap_init())
	{
		return -1;
	}

	return 0;
}
