#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "unistd.h"
#include <sys/stat.h>

#include "store.h"

int main(int argc, char * argv[])
{
	chdir("sav");
		
	{	// Supply a command line argument to modify x
		
		int x = -1;
		if(argc <= 1)
		{
			LOAD(x);
			if(x == -1)
				printf("x is the initial value.\n");
			else
				printf("x is %d\n", x);
		}
		else
		{
			x = atoi( argv[1] );
			SAVE(x);
			printf("Saved x as %d\n", x);
		}
	}
	
	
	
	
	{	// Static arrays can be saved just like any variable
		srand(time(NULL));
	
		char arr[100];
		for(int i = 0; i<100 ; i++ )
		{	
			arr[i] = rand();
			while(isspace(arr[i]) || iscntrl(arr[i]))
				arr[i]++;
		}
		arr[99] ='\0';

		printf("%s\n",arr);
	
		SAVE(arr);
		LOAD(arr);
	
		printf("%s\n",arr);
	}
	
	
	
	
	{	// Register variables to save/load global state
		char a[] = "This is a test!";
		char b[] = "So is this!";
		char c[] = "And another!";
	
		REG(a);
		REG(b);
		REG(c);
	
		saveAll();
		loadAll();
	
		printf("%s %s %s\n", a, b, c);
	}	
	
	return 0;
}