#include <stdlib.h>
#include <stdio.h>
#include <string>
#include "getopt.h"

using namespace std;

int main(int argc, char* argv[]) {
	const int num = 3;
	const char* args = ":hP::p:";
	const struct option args_long[] = {
		{"help", no_argument, 0, 'h'},
		{"Passwd", optional_argument, 0, 'P'},
		{"port", required_argument, 0, 'p'},
		{ 0, 0, 0, 0 }
	};
	int a;
	int index;
	bool th = false;
	bool tP = false;
	bool tp = false;

	while ((a = getopt_long(argc, argv, args, args_long, &index)) != -1)
	{
		switch (a) {
		case 'h': {
			if (th == false)
			{
				printf("Arg: Help\n");
				th = true;
			}
			break;
		};

		case 'P': {
			if (tP == false)
			{
				if (optarg == NULL)
				{
					printf("Arg: Password\n");
					tP = true;
				}
				else
				{
					printf("Arg: Password = %s\n", optarg);
					tP = true;
				}
			}
			break;
		};

		case 'p': {
			if (tp == false)
			{
				if ((optarg[0] < '0') || (optarg[0] > '9'))
				{
					printf("Missing argument for -p\n");
					break;
				}
				else
				{
					printf("Arg: Port = %s\n", optarg);
					tp = true;
				}
			}
			break;
		};

		case '?': {
			printf("Unknown option: %c\n", optopt);
			break;
		}

		case ':': {
			printf("Missing argument for %c\n", optopt);
			break;
		}
		};
	};
	return 0;
};
