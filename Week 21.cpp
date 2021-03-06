// ConsoleApplication11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include "string.h"
#include "stdlib.h"

FILE * openFile(char *fileName, char *mode);
void closeFile(FILE *fptr);
void appendFile(FILE *fptr, char data[]);
void searchFile(FILE *fptr, char data[]);
void readFile(FILE *fptr);

struct Date
{
	int day;
	int month;
	int year;
};

struct Time
{
	int hour;
	int mins;
};

struct worktime
{
	int employeeID;
	struct Date date;
	struct Time startTime;
	struct Time endTime;
};

void main() {
	int swtch = 3;
	FILE *fptr;
	while (swtch != 4) {
		char choice[3] = "aa";
		char filename[30];
		char line[150];
		char restOfLine[100];
		int i,j,k = 0;
		puts("\nEnter your choice (/a = Append to a file,/p = Print file,/s = Search file,/e to Exit) \nFormat for /a = C:\\filename.txt /a 1001 12/10/2018 08:45 17:30 \nFormat for /s = C:\\filename.txt /s 1001 \n");
		scanf("%s", &line);
		for (i = 0; i < 100; i++) {
			while (line[i] != ' ') {
				line[i] = filename[i];
			}i++;
			filename[i] = '\0';
			while (line[i] != ' ') {
				line[i] = choice[j];
				j++;
			}i++;
			while (line[i] != '\0') {
				line[i] = restOfLine[k];
				k++;
			}k++;
			restOfLine[k] = '\0';
		}
		if (strcmp(choice, "/a") != NULL) swtch = 0;
		if (strcmp(choice, "/r") != NULL) swtch = 1;
		if (strcmp(choice, "/s") != NULL) swtch = 2;
		if (strcmp(choice, "/a") != NULL) swtch = 4;
		switch (swtch) {
		case 0:
			fptr = openFile(filename, "a");
			appendFile(fptr, restOfLine);

		case 1:
			fptr = openFile(filename, "r");
			readFile(fptr);

		case 2:
			fptr = openFile(filename, "r");
			searchFile(fptr, restOfLine);

		case 4:
			break;

		default:
			puts("\nInvalid choice \n");
			break;

		}
	}
}

FILE * openFile(char *fileName, char *mode)
{

	FILE *fptr = fopen(fileName, mode);

	if (fptr == NULL)
	{
		printf("Error opening file ! \n");
	}
	return fptr;
}
void closeFile(FILE *fptr)
{
	fclose(fptr);
}

void appendFile(FILE *fptr, char data[])
{
	char line[100];
	char temp[20];
	worktime appendToFile[10];
	int i, j, k = 0;
	while (!feof(fptr)) {
		fgets(line, 100, fptr);
	}
	while (data[i] != '\0') {
		k = 0;
		while (data[i] != ' ') {
			data[i] = temp[i];
			i++;
		}i++;
		temp[i] = '\0';
		appendToFile[j].employeeID = atoi(temp);
		while (data[i] != ' ') {
			data[i] = temp[k];
			i++;
			k++;
		}k++;
		i++;
		temp[k] = '\0';
		k = 0;
		appendToFile[j].date.day = (temp[0] * 10) + temp[1];
		appendToFile[j].date.month = (temp[3] * 10) + temp[4];
		appendToFile[j].date.day = (temp[6] * 10) + temp[7];
		while (data[i] != ' ') {
			data[i] = temp[k];
			i++;
			k++;
		}k++;
		temp[k] = '\0';
		i++;
		appendToFile[j].startTime.hour = (temp[0] * 10) + temp[1];
		appendToFile[j].startTime.mins = (temp[3] * 10) + temp[4];
		k = 0;
		while (data[i] != ' ') {
			data[i] = temp[k];
			i++;
			k++;
		}k++;
		temp[k] = '\0';
		appendToFile[j].endTime.hour = (temp[0] * 10) + temp[1];
		appendToFile[j].endTime.mins = (temp[3] * 10) + temp[4];
		j++;
	}closeFile(fptr);
}

void readFile(FILE *fptr){
	char line[100];
	while (!feof(fptr)) {
		fgets(line, 100, fptr);
		printf("\n%s", line);
	}closeFile(fptr);
}

void searchFile(FILE *fptr, char data[]) {
	int id = atoi(data);
	int cmpId;
	int i = 0;
	char line[100];
	while (!feof(fptr)) {
		fgets(line, 100, fptr);
		while (line[i] != ',') i++;
		i = i + 2;
		cmpId = (line[i] * 10 ^ 3) + (line[i + 1] * 10 ^ 2) + (line[i + 2] * 10) + line[i + 3];
		if (id = cmpId) {
			printf("\n%s", line);
		}
	}closeFile(fptr);
}