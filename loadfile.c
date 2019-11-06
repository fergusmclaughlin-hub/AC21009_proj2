/*
	Name: Fergus McLaughlin
	ID: 170015911
	Module: AC21008
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

	int main (void)
	{
		//create file pointer
		FILE *fPtr;
		//variable to hold ints
		int loadints;
		//opens the file to read from
		fPtr = fopen("filetoload.txt", "r");
		//lets user know it is loading ints
		printf("The Ints to load are :" "\n");
		//fscanf finds the ints in the pointer
		fscanf(fPtr, "%d", &loadints);
		while(!feof (fPtr)) // while the pointer is not at the end of the file
		{
			printf("\n""number: %i""\n", loadints ); // prints out the ints 
			fscanf(fPtr, "%d", &loadints); // scans for new ones
		}
		fclose(fPtr); //closes the file 
	
		//lets the user know the ints have been loaded
		printf("\n""Ints have all been loaded""\n");

		return 0;
	}



