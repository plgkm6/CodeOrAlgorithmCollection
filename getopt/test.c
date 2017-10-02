#include "getopt.h"
#include <stdio.h>

int main(int argc, char*argv[]) {
	int c;

	while ((c = getopt(argc, argv, "ngl:")) != -1)
	{
		switch (c)
		{
		case 'n':
			printf("My name is Gkm.\n");
			break;
		case 'g':
			printf("Her name is LslTx.\n");
			break;
		case 'l':
			printf("Our love is %s\n", optarg);
			break;
		}
	}
	return 0;
}