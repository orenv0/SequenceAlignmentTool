#include "myProto.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

const char *colonGroup[] = { "NDEQ", "NEQK", "STA", "MILV", "QHRK", "NHQK",
		"FYW", "HY", "MILF" };
const char *pointGroup[] = { "SAG", "ATV", "CSA", "SGND", "STPA", "STNK",
		"NEQHRK", "NDEQHK", "SNDEQK", "HFY", "FVLIM" };


char compareChars(char seq1, char seq2) {
	if (seq1 == seq2)
		return '*';
	else if (areInsideThisGroup(seq1, seq2, (char**) colonGroup, COLONSIZE))
		return ':';
	else if (areInsideThisGroup(seq1, seq2, (char**) pointGroup, POINTSIZE))
		return '.';
	else if (seq2 == '-')
		return '-';
	else
		return ' ';
}
double calculateScore(int maxOffset ,int resultsLen,char results[maxOffset][resultsLen],int offset, double *w) {
	int i, stars = 0, colons = 0, points = 0, spaces = 0;
	double score = 0;
	for (i = 0; i < resultsLen+1; i++) {
		if (results[offset][i] == '*')
			stars++;
		else if (results[offset][i] == ':')
			colons++;
		else if (results[offset][i] == '.')
			points++;
		else if (results[offset][i] == '-')
			continue;
		else
			spaces++;

	}

	score = w[0] * stars - w[1] * colons - w[2] * points - w[3] * spaces;
	return score;
}
bool areInsideThisGroup(char seq1, char seq2, char **group, int groupSize) {
	int i;
	for (i = 0; i < groupSize; i++) {
		if (strchr((char*) group[i], seq1) != NULL
				&& strchr((char*) group[i], seq2) != NULL)
			return true;

	}
	return false;
}
int findOffsetWithHighestScore(int maxHyphens,int maxOffsets,double arr[maxHyphens][maxOffsets],int hyphen) {
	int i, bestOffset = 0;
	double maxScore = 0;

	for (i = 0; i < maxOffsets; i++) {
		if (arr[hyphen][i] > maxScore) {
			maxScore = arr[hyphen][i];
			bestOffset = i;
		}

	}
	return bestOffset;
}

void printFinalScores(double *arr, int size) {
	int i;
	for (i = 0; i < size; i++) {
		printf("offset: %d, score: %.1f\n", i, arr[i]);
	}
}
char* createNewMutant(char* seq2,int size,int hyphenPosition){
	int i;
	char* mutant = (char*)malloc((SIZE2)*sizeof(char));
	for(i=0;i<hyphenPosition;i++){
		mutant[i]= seq2[i];
	}
	mutant[hyphenPosition]='-';
	for(i=hyphenPosition+1;i<size+1;i++){
			mutant[i]= seq2[i-1];
		}

	return mutant;
}
int findMutantWithHighestScore(MutantData* mutantsData, int size){
	int i, bestMutant = 0;
	double maxScore = 0;

	for (i = 0; i < size; i++) {
		if (mutantsData[i].bestScore > maxScore) {
			maxScore = mutantsData[i].bestScore;
			bestMutant = i;
		}

	}
	return bestMutant;
}

