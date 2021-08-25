/*
* ex1.c - First child
*
*  Created on: Nov 5, 2017
*      Author: eliyho tsuri ,dan narkisi
*       Login: eliyhots, danna
*
* On this file the first bubble sort operation on an array,
* after the kid prints how long it took him to sort the array
* of numbers which are transferred by the father,the child fathered
* a third child and waiting file until you finish the binary search
*/
// --------------------- Include Section -----------------------
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdbool.h>
#include <time.h>
#include <process.h>
#include <Windows.h>
#include <string.h>
// ------------------------- Define ----------------------------
#define SIZE 100
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
// ------------------------ Prototype --------------------------
void transfer (char **argv, int my_array[]);
void bubble_sort (int my_array[]);
void swap (int my_array[], int big_num, int small_num);
void create_child_d (int my_array[]);
// -------------------------- Main -----------------------------
int main (int argc, char *argv[])
{
	int my_array[SIZE];
	transfer (argv, my_array);
	bubble_sort (my_array);
	create_child_d (my_array);
	return (EXIT_SUCCESS);
}
// ----------------------- transfer ----------------------------
/*
* The function getting the argv and empty array ,the function
* transfer all the numbers from the argv to the array for the child's
*/
void transfer (char **argv, int my_array[])
{
	int index;
	for (index = 0; index < SIZE; index++)
		my_array[index] = atoi (argv[index + 1]);
}
// ---------------------- bubble sort --------------------------
/*
* this function getting array, min, max numbers,
* the function sorting the array whit bubble sort
* the function return the min,max numbers
*/
void bubble_sort (int my_array[])
{
	time_t start, end;
	int min = SIZE;
	int max = 0;
	int round, place;

	start = time (NULL);
	for (round = 1; round < SIZE * 2; round++)
	{
		for (place = 0; place < (SIZE * 2) - round - 1; place++)
			if (my_array[place] > my_array[place + 1])
				swap (my_array, place, place + 1);
	}
	for (round = 0; round < SIZE; round++)
	{
		if (min > my_array[round])
			min = my_array[round];
		if (max < my_array[round])
			max = my_array[round];
	}
	end = time (NULL);
	// print the time sort function and min, max numbers
	printf ("Bubble Sort: %d %d %d \n", int (end) - int (start), min, max);
}
// ------------------------- swap ------------------------------
/*
* this function getting int array, small number, big number
* the function swap the small and big numbers
*/
void swap (int my_array[], int big_num, int small_num)
{
	int temp = my_array[big_num];
	my_array[big_num] = my_array[small_num];
	my_array[small_num] = temp;
}
// --------------------- create_child_d ------------------------
/*
* The function takes an array of numbers, and produces
* a fourth child ,the function of several guerrillas and
* searching an array by binary search, finally, it prints
* the average time it took her to find the number in an array
*/
void create_child_d (int my_array[])
{
	char child_name[] = "os1_eliyhots_dana_ex1a5.exe ";
	char value_array[SIZE + 300] = "\0";
	char new_argv[SIZE + 300] = "\0";
	char value[SIZE];
	bool child_d;
	int index;

	PROCESS_INFORMATION pif;
	STARTUPINFO soninf;
	ZeroMemory (&soninf, sizeof (soninf));
	soninf.cb = sizeof (soninf);

	for (index = 0; index < SIZE; index++)
	{
		sprintf_s (value, "%d", my_array[index]);
		strcat_s (value_array, value);
	}
	child_d = CreateProcessA (NULL, new_argv, NULL, NULL, false, 0, NULL, NULL, &soninf, &pif);
	if (!child_d)
	{
		puts ("Create Process failed");
		exit (EXIT_FAILURE);
	}

	WaitForSingleObject (pif.hProcess, INFINITE);
	CloseHandle (pif.hProcess);
	CloseHandle (pif.hThread);
}