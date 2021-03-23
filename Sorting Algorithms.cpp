//Sorting Algorithms
#include <iostream>
using namespace std;

void bubleSort(int *a, int n);
void selectionSort(int *a, int n);
void insertionSort(int *a, int n);
void shellSort(int *a, int n);
void merge(int *a, int l, int m, int r);
void mergeSort(int *a, int l, int r);
void quickSort(int *a, int low, int high);
int partition(int *a, int low, int high);
void display(int *a, int n);

int main()
{
	int ch;
	do
	{
		int arr[] = { 6, 3, 9, 1, 5, 4, 7, 2 };
		int arr_size = sizeof(arr) / sizeof(arr[0]);
		system("cls");
		cout << "Sorting Algorithms" << endl << endl;
		cout << "[1] Bubble Sort" << endl;
		cout << "[2] Selection Sort" << endl;
		cout << "[3] Insertion Sort" << endl;
		cout << "[4] Shell Sort" << endl;
		cout << "[5] Merge Sort" << endl;
		cout << "[6] Quick Sort" << endl;
		cout << "[8] Exit Program" << endl;
		cout << endl << "Enter choice: ";
		cin >> ch;
		system("cls");
		cout << "Unordered List..." << endl;
		display(arr, arr_size);
		switch (ch)
		{
		case 1:  bubleSort(arr, arr_size); break;
		case 2:  selectionSort(arr, arr_size); break;
		case 3:  insertionSort(arr, arr_size); break;
		case 4:  shellSort(arr, arr_size); break;
		case 5:  
		{
			cout << endl << "Merge Sort..." << endl << endl;
			mergeSort(arr, 0, arr_size - 1);
			cout << "Sorted Array..." << endl << endl;
			display(arr, arr_size);
			break;
		}
		case 6:
		{
			cout << endl << "Quick Sort..." << endl << endl;
			quickSort(arr, 0, arr_size - 1);
			cout << "Sorted Array..." << endl << endl;
			display(arr, arr_size);
			break;
		}
		case 8:  exit(0);
		}
		cout << endl;
		system("pause");
	} while (ch >= 1 && ch<= 8);
	cout << endl;
	system("pause");
}

void bubleSort(int *a, int n)
{
	int last = n - 1;
	cout << endl << "Bubble Sort..." << endl << endl;
	for (int i = 0; i < last; i++)
	{
		for (int j = last; j > i; j--)
			if (a[j - 1] > a[j])
		 	 swap(a[j], a[j - 1]);
		cout << "Pass " << i + 1 << "...." << endl;
		display(a, n);
		cout << endl;
		
	}
}

void selectionSort(int *a, int n) 
 {
	cout << endl << "Selection Sort..." << endl << endl;
	for (int i = 0; i < n - 1; i++) 
	 {
		int min = i;
		for (int j = i + 1; j < n; j++)
			if (a[j] < a[min]) 
				min = j;
		swap(a[i], a[min]);
		cout << "Pass " << i + 1 << "...." << endl;
		display(a, n);
		cout << endl;
	}
}

void insertionSort(int *a, int n)
{
	int i, j;
	cout << endl << "Insertion Sort..." << endl << endl;
	for (i = 1; i < n; i++)
	{
		int tmp = a[i];
		for (j = i; j > 0 && tmp < a[j - 1]; j--)
			a[j] = a[j - 1];
		a[j] = tmp;
		cout << "Pass " << i << "...." << endl;
		display(a, n);
		cout << endl;
	}
}

void shellSort(int *a, int n)
{ 
	cout << endl << "Shell Sort..." << endl << endl;
	for (int gap = n / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < n; i += 1)
		{
			int temp = a[i];
			int j;
			for (j = i; j >= gap && a[j - gap] > temp; j -= gap)
				a[j] = a[j - gap]; 
			a[j] = temp;
			cout << "Pass " << i << ", Gap " << gap << "...." << endl;
			display(a, n);
			cout << endl;
		}
		
	}
}

void merge(int *a, int l, int m, int r)
{
	int i, j, k;
	int *L, *R;
	int n1 = (m - l) + 1;
	int n2 = r - m;
	L = new int [n1];
	R = new int [n2];
	for (i = 0; i < n1; i++)
		L[i] = a[l + i];
	for (j = 0; j < n2; j++)
		R[j] = a[m + 1 + j];
	i = 0; 
	j = 0;  
	k = l;  
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			a[k] = L[i];
			i++;
		}
		else
		{
			a[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		a[k] = L[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		a[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int *a, int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2; 
		mergeSort(a, l, m);
		mergeSort(a, m + 1, r);
		merge(a, l, m, r);
	}
}

void quickSort(int *a, int low, int high)
{
	int pi;
	if (low < high)
	{
		pi = partition(a, low, high);
		quickSort(a, low, pi - 1);  
		quickSort(a, pi + 1, high); 
	}
}

int partition(int *a, int low, int high)
{
	int pivot, i, j;
	pivot = a[high];

	i = (low - 1);
	for (j = low; j <= high - 1; j++)
	 {
	   if (a[j] <= pivot)
		{
		   i++;    
		   swap(a[i], a[j]);
		}
	  }
	swap(a[i + 1], a[high]);
	return (i + 1);
}



void display(int *a, int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
