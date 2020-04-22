/*
 * Common code for two versions of game-of-life program:
 *
 * Function definitions
 * 
 * See game-of-life-util.h for comments explaining what these 
 * functions are supposed to do.
 */
#include <stdio.h>
#include <stdlib.h>

#include "game-of-life-util.h"

bool **build2D(long size) {
	bool *data = malloc(size * size * sizeof(data[0]));
	if (data == NULL) {
		fprintf(stderr, 
			"unable to allocate space for board of size %ld\n",
			size);
		return NULL;
	}
	bool **array2D = malloc(size * sizeof(array2D[0]));
	if (array2D == NULL) {
		fprintf(stderr, 
			"unable to allocate space for board of size %ld\n",
			size);
		return NULL;
	}
	for (long r = 0; r < size; ++r) {
		array2D[r] = &data[r*size];
	}
	return array2D;
}

void free2D(long size, bool **array2D) {
	bool *data = array2D[0];
	free(data);
	free(array2D);
}

void update_board(long size, bool **old_board, bool **new_board) {
	int neighbors;
	bool thisAlive;

	// Board Space Iteration
	for(long i = 0; i < size; ++i) { 
		for(long j = 0; j < size; ++j) {
			neighbors = 0; // reset neighbor number
			
			if(old_board[i][j]) thisAlive = true; 		 	// finds out if the current is alive
			if (!old_board[i][j]) thisAlive = false; 		// finds out if the current is dead
			
			// 			Counting how many neighbors, top left to bottom right
			if(i > 0 && j > 0 && old_board[i-1][j-1]) 				neighbors++; 	// TOPLEFT
			if(i > 0 && old_board[i-1][j]) 							neighbors++;	// TOP
			if(i > 0 && j < size - 1 && old_board[i-1][j+1]) 		neighbors++;	// TOPRIGHT
			if(j > 0 && old_board[i][j-1]) 							neighbors++;	// LEFT
			if(j < size - 1 && old_board[i][j+1]) 					neighbors++;	// RIGHT
			if(i < size - 1 && j > 0 && old_board[i+1][j-1]) 		neighbors++;	// BOTTOMLEFT
			if(i < size - 1 && old_board[i+1][j]) 					neighbors++;	// BOTTOM
			if(i < size - 1 && j < size - 1 && old_board[i+1][j+1]) neighbors++; 	// BOTTOMRIGHT

			// Dead/Alive Qualifications
			if(neighbors == 2 || neighbors == 3) {
				if(thisAlive) new_board[i][j] = true;
				if(!thisAlive && neighbors == 3) new_board[i][j] = true;
				if(!thisAlive && neighbors == 2) new_board[i][j] = false;
			}
			if(neighbors > 3 || neighbors < 2) new_board[i][j] = false;
		}
	}
}

void print_board(long size, bool **board) {
	for (long i = 0; i < size; ++i) {
		for (long j = 0; j < size; ++j) {
			if (board[i][j]) 
				printf("1 ");
			else
				printf(". ");
		}
		putchar('\n');
	}
}
