// Problem3-11-1_FrequencyStatistics.c : Defines the entry point for the console application.
//

#include "stdafx.h"

#pragma warning(disable : 4996)


int main()
{
	int capacity;
	scanf("%d", &capacity);
	if (capacity < 0)
	{
		printf("Invalid input");
		exit(0);
	}
	unsigned int *ages = (unsigned int *)malloc(sizeof(unsigned int) * capacity);
	for (size_t i = 0; i < capacity; i++)
	{
		scanf("%u", &ages[i]);
	}
	unsigned int *_ages_categorized = (unsigned int *)malloc(sizeof(unsigned int) * capacity);
	size_t count = 0;
	size_t temp;
	for (size_t i = 0; i < capacity; i++)
	{
		for (temp = 0; temp < count; temp++)
		{
			if (ages[i] == _ages_categorized[temp])
			{
				break;
			}
		}
		if (temp == count)
		{
			_ages_categorized[count] = ages[i];
			count++;
		}
	}
	size_t *numbers = (size_t *)malloc(sizeof(size_t) * count);
	for (size_t i = 0; i < count; i++)
	{
		numbers[i] = 0;
	}
	for (size_t i = 0; i < count; i++)
	{
		for (size_t j = 0; j < capacity; j++)
		{
			if (ages[j] == _ages_categorized[i])
			{
				numbers[i]++;
			}
		}
	}
	for (size_t i = 0; i < count; i++)
	{
		printf("%d %zu", _ages_categorized[i], numbers[i]);
		if (i < count - 1)
		{
			printf("\n");
		}
	}
	free(numbers);
	free(_ages_categorized);
	free(ages);
    return 0;
}

