#pragma once

#define SIZE  3000
#define SIZE2  2000
#define COLONSIZE 9
#define POINTSIZE 11

#include <stdbool.h>



typedef struct{
	int bestOffset;
	double bestScore;

}MutantData;



char compareChars(char seq1,char seq2);
double calculateScore(int maxOffset,int resultsLen,char results[maxOffset][resultsLen],int offset,double *w);
bool areInsideThisGroup(char seq1,char seq2,char** group,int groupSize);
void printFinalScores(double* arr, int size);
int findOffsetWithHighestScore(int maxHyphens,int maxOffsets,double arr[maxHyphens][maxOffsets],int hyphen);
char* createNewMutant(char* seq2,int size,int hyphenPosition);
int findMutantWithHighestScore(MutantData* mutantData, int size);

