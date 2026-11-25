#include <stdio.h>
#include <stdlib.h>

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	bubble_sort(int *arr, int n)
{
	int	i;
	int	j;
	int	swaped;

	i = 1;
	while (i < n)
	{
		swaped = 1;
		j = 0;
		while (j < n - i)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr + j, arr + j + 1);
				swaped = 0;
			}
			j++;
		}
		if (swaped)
			break ;
		i++;
	}
}

void	insertion_sort(int *arr, int n)
{
	int	i;
	int	j;
	int	key;

	i = 1;
	while (i < n)
	{
		key = arr[i];
		j = i;
		while (j && arr[j - 1] > key)
		{
			arr[j] = arr[j - 1];
			j--;
		}
		arr[j] = key;
		i++;
	}
}

void	selection_sort(int *arr, int n)
{
	int	i;
	int	j;
	int	min;

	i = 0;
	while (i < n - 1)
	{
		j = i + 1;
		min = i;
		while (j < n)
		{
			if (arr[min] > arr[j])
				min = j;
			j++;
		}
		swap(arr + min, arr + i);
		i++;
	}
}

void	merge(int *arr, int n)
{
	
}

void	merge_sort(int *arr, int n)
{
	int mid = n / 2;

	if (n < 2)
		return ;
	merge_sort(arr, mid);
	merge_sort(arr + mid + 1, n - mid);
	merge(arr, n);
}

int	main(void)
{
	int	arr[] = {1, -2, -4, 15, 10, 4, 2, 0, 9, -10, 20, -3, 5};
	int	size = sizeof(arr)/sizeof(*arr);
	int	i = 0;

	//bubble_sort(arr, size);
	//insertion_sort(arr, size);
	selection_sort(arr, size);
	printf("[");
	while (i < size - 1)
		printf("%d, ", arr[i++]);
	printf("%d]\n", arr[i]);
}
