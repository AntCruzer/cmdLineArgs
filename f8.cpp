// INCLUDES
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#pragma warning(disable: 4996)	// required by Visual Studio



// STRUCT DEFINITION
struct MyData
{
	int howMany;                // positive int
	char theText[21];           // text
	char directoryPath[21];		// output file directory
	char filename[21];          // output file name
};



// CONSTANT
const int NUM_ARGS = 5;			// 4 cmd-line args + executable file (command)
								


int main(int argc, char* argv[])
{
	// check number of args provided
	if (argc < NUM_ARGS)
	{
		printf("Not enough arguments\n");
		return 1;
	}
	if (argc > NUM_ARGS)
	{
		printf("Too many arguments\n");
		return 2;
	}

	// DECLARE STRUCT VARIABLE
	struct MyData myArgs;

	// ASSIGN STRUCT FIELDS
	myArgs.howMany = atoi(argv[1]);
	strcpy(myArgs.theText, argv[2]);
	strcpy(myArgs.directoryPath, argv[3]);
	strcpy(myArgs.filename, argv[4]);
	strcat(myArgs.directoryPath, myArgs.filename);


	// OUTPUT FILE

	FILE* fp = NULL;

	// create/open file to write
	fp = fopen(myArgs.directoryPath, "w"); // don't hard code

	// check for error upon opening
	if (fp == NULL)
	{
		// dircetory does net yet exist
		printf("Can't open file for writing\n");
		return -1;
	}

	// write number of lines according to howMany
	for (int i = 0; i < myArgs.howMany; i++)
	{
		if (fprintf(fp, "%s\n", myArgs.theText) < 0)
		{
			printf("Can't write line to file\n");
			return -2;
		}
	}

	// close file
	if (fclose(fp) != 0)
	{
		// the closing of the file failed
		printf("Can't close file opened for writing\n");
		return -3;
	}

	return 0;
}