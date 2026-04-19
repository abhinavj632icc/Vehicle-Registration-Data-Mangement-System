#include <stdio.h>
#include <string.h>

#define MAX 100

// Structure
struct Vehicle {
    char regNo[20];
    char ownerName[50];
    char vehicleType[20];
};

// Array of vehicles
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

// Search Vehicle (Linear Search)
void searchVehicle() {
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

// Display All
void displayVehicles() {
    if (count == 0) {
        printf("No Records Found!\n");
        return;
    }

    printf("\nAll Vehicles:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. RegNo: %s | Owner: %s | Type: %s\n",
               i + 1,
               vehicles[i].regNo,
               vehicles[i].ownerName,
               vehicles[i].vehicleType);
    }
}

// Main
int main() {
    int choice;

    while (1) {
        printf("\n--- Vehicle Registration (Array) ---\n");
        printf("1. Add Vehicle\n");
        printf("2. Search Vehicle\n");
        printf("3. Display All\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addVehicle();
                break;
            case 2:
                searchVehicle();
                break;
            case 3:
                displayVehicles();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid Choice!\n");
        }
    }
}