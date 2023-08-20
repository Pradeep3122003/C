#include <stdio.h>

#define MAX_SIZE 1000000

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap the elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    FILE *file;
    int array[MAX_SIZE];
    int i = 0;

    // Open the file in read mode
    file = fopen("data.txt", "r");

    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    // Read data from the file and store it into the array
    while (fscanf(file, "%d", &array[i]) != EOF) {
        i++;
        if (i >= MAX_SIZE) {
            printf("Array size exceeded maximum limit.\n");
            break;
        }
    }

    // Close the file
    fclose(file);
        bubbleSort(array, MAX_SIZE);
    // Print the data stored in the array
    printf("Data read from the file:\n");
    for (int j = 0; j < i; j++) {
        printf("%d ", array[j]);
    }
    printf("\n");

    return 0;
}
