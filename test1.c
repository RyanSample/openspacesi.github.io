#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#define MAX_LINE_LENGTH 100

//Prototypes:
char *get_line(FILE *fpntr);

int main(int argc, char *argv[]){
char *file_pathname, *first_line;

FILE *fpntr;

//temp check for args
if (argc != 2){
	perror("Usage: FILE\n");
	exit(EXIT_FAILURE);
}
//get source for command line.
file_pathname = argv[1];

//open file for reading:
if((fpntr = fopen(file_pathname, "r")) == NULL){
	perror("Error opening file\n");
	exit(EXIT_FAILURE);
}

//Get first line Print out line:
if((first_line = get_line(fpntr)) == NULL){
	perror("ERROR reading line");
	exit(EXIT_FAILURE);
}

//PRint out line:
printf("First line in file %s:\n%s",file_pathname,first_line);
//close file
fclose(fpntr);

//Normal termination
return EXIT_SUCCESS;
}

//Returns locally created static line buff.
char *get_line(FILE *fpntr){
	static char line_buff[MAX_LINE_LENGTH];
	int ch, num_chars;
	num_chars = 0;
	for(ch = fgetc(fpntr); ch != EOF && ch != '\n'; ch = fgetc(fpntr)){
		line_buff[num_chars++] = ch;	
		
	}
	
	return line_buff;
}
