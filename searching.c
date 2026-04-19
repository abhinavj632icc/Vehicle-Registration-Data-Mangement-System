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

// Linear Search
void linearSearch() {
    char regNo[20];
    int found = 0;

    printf("Enter Reg No to Search: ");
    scanf("%s", regNo);

    for (int i = 0; i < count; i++) {
        if (strcmp(vehicles[i].regNo, regNo) == 0) {
            printf("\nVehicle Found:\n");
            printf("RegNo: %s\nOwner: %s\nType: %s\n",
                   vehicles[i].regNo,
                   vehicles[i].ownerName,
                   vehicles[i].vehicleType);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Vehicle Not Found!\n");
    }
}

// Bubble Sort (for Binary Search)
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
}

// Binary Search
void binarySearch() {
    char regNo[20];
    int low = 0, high = count - 1;

    printf("Enter Reg No to Search: ");
    scanf("%s", regNo);

    while (low <= high) {
        int mid = (low + high) / 2;

        int cmp = strcmp(vehicles[mid].regNo, regNo);

        if (cmp == 0) {
            printf("\nVehicle Found:\n");
            printf("RegNo: %s\nOwner: %s\nType: %s\n",
                   vehicles[mid].regNo,
                   vehicles[mid].ownerName,
                   vehicles[mid].vehicleType);
            return;
        }
        else if (cmp < 0)
            low = mid + 1;
        else
            high = mid - 1;
    }

    printf("Vehicle Not Found!\n");
}

// Main Function
int main() {
    int choice;

    while (1) {
        printf("\n--- Vehicle Registration System (Searching) ---\n");
        printf("1. Add Vehicle\n");
        printf("2. Display Vehicles\n");
        printf("3. Linear Search\n");
        printf("4. Binary Search\n");
        printf("5. Exit\n");

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
                linearSearch();
                break;
            case 4:
                bubbleSort(); // IMPORTANT before binary search
                binarySearch();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid Choice!\n");
        }
    }
}