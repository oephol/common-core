#include <stdio.h>

void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	bubble_sort(int *arr, int n)
{
	int	i;
	int	j;
	int	no_swap;

	i = 0;
	while (i < n)
	{
		j = 0;
		no_swap = 1;
		while (j < n - i)
		{
			if (arr[j] > arr[i + 1])
			{
				swap(arr + j, arr + j + 1);
				no_swap = 0;
			}
			j++;
		}
		if (no_swap)
			break ;
		i++;
	}
}

void selection_sort(int *arr, int n)
{
	int min;
	int i;
	int j;

	min = 0;
	i = 0;
	while (i < n - 1)
	{
		j = i + 1;
		min = i;
		while (j < n)
		{
			if (arr[j] < arr[min])
				min = j;
			j++;
		}
		if (min != i)
			swap(arr + i, arr + min);
		i++;
	}
}

void	merge_sort(int *arr, int *tmp, int left, int right)
{

}

void insertion_sort(int *arr, int n)
{
	int i;
	int j;
	int selected;

	i = 1;
	while (i < n)
	{
		j = i;
		selected = arr[i];
		while (j && selected < arr[j - 1])
		{
			arr[j] = arr[j - 1];
			j--;
		}
		arr[j] = selected;
		i++;
	}
}

int main()
{
	int arr[] = {8, 7, 4, 0, 1, 2, 9, 5, 3, 6};
	int tmp = malloc(10 * sizeof(int));
	int i;
	int n;

	n = sizeof(arr) / sizeof(arr[0]);
	// selection(arr, n);
	//insertion(arr, n);
	bubble_sort(arr, n);
	i = 0;
	printf("[");
	while (i < n - 1)
		printf("%d, ", arr[i++]);
	printf("%d]\n", arr[i]);
	return (0);
}