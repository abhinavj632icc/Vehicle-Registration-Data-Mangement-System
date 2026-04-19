#include <stdio.h>
#include <string.h>

#define MAX 100

// Structure
struct Vehicle {
    char regNo[20];
    char ownerName[50];
    char vehicleType[20];
};

struct Vehicle vehicles[MAX];
int count = 0;

// Add Vehicle
void addVehicle() {
    if (count >= MAX) {
        printf("Storage Full!\n");
        return;
    }

    printf("Enter Reg No: ");
    scanf("%s", vehicles[count].regNo);

    printf("Enter Owner Name: ");
    scanf("%s", vehicles[count].ownerName);

    printf("Enter Vehicle Type: ");
    scanf("%s", vehicles[count].vehicleType);

    count++;
    printf("Vehicle Added Successfully!\n");
}

// Display Vehicles
void displayVehicles() {
    if (count == 0) {
        printf("No Records Found!\n");
        return;
    }

    printf("\nVehicle Records:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. RegNo: %s | Owner: %s | Type: %s\n",
               i + 1,
               vehicles[i].regNo,
               vehicles[i].ownerName,
               vehicles[i].vehicleType);
    }
}

// Bubble Sort
void bubbleSort() {
    struct Vehicle temp;

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (strcmp(vehicles[j].regNo, vehicles[j+1].regNo) > 0) {
                temp = vehicles[j];
                vehicles[j] = vehicles[j+1];
                vehicles[j+1] = temp;
            }
        }
    }

    printf("Sorted using Bubble Sort!\n");
}

// Selection Sort
void selectionSort() {
    struct Vehicle temp;

    for (int i = 0; i < count - 1; i++) {
        int min = i;

        for (int j = i + 1; j < count; j++) {
            if (strcmp(vehicles[j].regNo, vehicles[min].regNo) < 0) {
                min = j;
            }
        }

        temp = vehicles[i];
        vehicles[i] = vehicles[min];
        vehicles[min] = temp;
    }

    printf("Sorted using Selection Sort!\n");
}

// Swap function
void swap(struct Vehicle *a, struct Vehicle *b) {
    struct Vehicle temp = *a;
    *a = *b;
    *b = temp;
}

// Quick Sort
int partition(int low, int high) {
    char pivot[20];
    strcpy(pivot, vehicles[high].regNo);

    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (strcmp(vehicles[j].regNo, pivot) < 0) {
            i++;
            swap(&vehicles[i], &vehicles[j]);
        }
    }

    swap(&vehicles[i + 1], &vehicles[high]);
    return i + 1;
}

void quickSort(int low, int high) {
    if (low < high) {
        int pi = partition(low, high);

        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

// Main Function
int main() {
    int choice;

    while (1) {
        printf("\n--- Vehicle Registration System (Sorting) ---\n");
        printf("1. Add Vehicle\n");
        printf("2. Display Vehicles\n");
        printf("3. Bubble Sort\n");
        printf("4. Selection Sort\n");
        printf("5. Quick Sort\n");
        printf("6. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addVehicle();
                break;
            case 2:
                displayVehicles();
                break;
            case 3:
                bubbleSort();
                break;
            case 4:
                selectionSort();
                break;
            case 5:
                quickSort(0, count - 1);
                printf("Sorted using Quick Sort!\n");
                break;
            case 6:
                return 0;
            default:
                printf("Invalid Choice!\n");
        }
    }
}