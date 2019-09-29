#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

/* Initialize global constants */
#define MAXLINECHARS 500
#define MAXSTRINGLEN 100

/* Initialize global variables */
bool iFlag = false;
bool nFlag = false;

/* Initialize helper methods */
int selectOptions(int argCount, char* args[]);
int processFile(char* fileName, char* pattern);
int readLine(char* val1, char* val2, char* fileName, int* number, char* line);

int main(int argCount, char* args[]) {
  char* pattern;
  bool patternFound = false;
  int i;
  for (i = 1; i < argCount; i++) { /* For every parameter passed in. */
    if (!iFlag && strcmp(args[i], "-i") == 0) {
      iFlag = true; /* Sets the i flag once. */
    } else if (!nFlag && strcmp(args[i], "-n") == 0) {
      nFlag = true; /* Sets the n flag once. */
    } else if (!patternFound) { /* Sets the pattern once. */
      pattern = args[i];
      patternFound = true;
    } else { /* Processes the rest of the files and searches for pattern. */
      processFile(args[i], pattern);
    }
  }
  return EXIT_SUCCESS;
}

/*
This method processes the passed in file, line
by line and looks to see if any of the lines
match the pattern. This is done by calling the
readLine method with the appropriate parameters.
*/
int processFile(char* fileName, char* pattern) {
  FILE* document = fopen(fileName, "r");
  char line[MAXLINECHARS]; /* Represents a signle line from file. */
  int number = 1; /* Line count variable. */
  int i;
  if (!document) { /* If document does not exist return an error. */
    fprintf(stderr, "Error when trying to read file: %s\n", fileName);
    return EXIT_FAILURE;
  } else {
    while (fgets(line, MAXLINECHARS, document)) { /* While line left */
      /* Set pointer for function call. */
      char* lineNormal = &line[0];
      int i;
      /* Set pointer for function call. */
      char* lineLower = (char*)malloc(100);
      for (i = 0; i < strlen(lineNormal); i++) {
        lineLower[i] = tolower(lineNormal[i]);
      }
      /* Set pointer for function call. */
      char* patternNormal = (char*)malloc(100);
      for (i = 0; (i < strlen(pattern) && i <= MAXSTRINGLEN); i++) {
        patternNormal[i] = pattern[i];
      }
      /* Set pointer for function call. */
      char* patternLower=(char*)malloc(100);
      for (i = 0; (i < strlen(pattern) && i <= MAXSTRINGLEN); i++) {
        patternLower[i] = tolower(pattern[i]);
      }
      if (iFlag) { /* If not case sensitive lower case both strings. */
        number = readLine(lineLower, patternLower,
                          fileName, &number, lineNormal);
      } else { /* If case sensitive keep the original strings. */
        number = readLine(lineNormal, patternNormal,
                          fileName, &number, lineNormal);
      }
    }
  }
}

/*
This method reads a line to see if the line contains a string
within it. If it does it prints the filename and line. The user
decides wether to use case-sensitive or non case-sensitive format.
*/
int readLine(char* val1, char* val2, char* fileName, int* number, char* line) {
  if (strstr(val1, val2) != NULL) {
    if (nFlag) { /* Decides wether to print line number or not. */
      printf("%s:%d:%s", fileName, *number, line);
    } else {/* No line number printed. */
      printf("%s:%s", fileName, line);
    }
    *number += 1; /* Increment line number. */
  }
  return *number;
}
