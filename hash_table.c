#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

// Structure for Vehicle
struct Vehicle {
    char regNo[20];
    char ownerName[50];
    char vehicleType[20];
    struct Vehicle* next;
};

// Hash Table
struct Vehicle* hashTable[SIZE];

// Hash Function
int hashFunction(char* key) {
    int sum = 0;
    for(int i = 0; key[i] != '\0'; i++) {
        sum += key[i];
    }
    return sum % SIZE;
}

// Insert Vehicle
void insertVehicle(char* regNo, char* ownerName, char* vehicleType) {
    int index = hashFunction(regNo);

    struct Vehicle* newVehicle = (struct Vehicle*)malloc(sizeof(struct Vehicle));
    strcpy(newVehicle->regNo, regNo);
    strcpy(newVehicle->ownerName, ownerName);
    strcpy(newVehicle->vehicleType, vehicleType);
    newVehicle->next = NULL;

    // Collision handling using chaining
    if(hashTable[index] == NULL) {
        hashTable[index] = newVehicle;
    } else {
        newVehicle->next = hashTable[index];
        hashTable[index] = newVehicle;
    }

    printf("Vehicle Registered Successfully!\n");
}

// Search Vehicle
void searchVehicle(char* regNo) {
    int index = hashFunction(regNo);

    struct Vehicle* temp = hashTable[index];

    while(temp != NULL) {
        if(strcmp(temp->regNo, regNo) == 0) {
            printf("\nVehicle Found:\n");
            printf("Reg No: %s\n", temp->regNo);
            printf("Owner: %s\n", temp->ownerName);
            printf("Type: %s\n", temp->vehicleType);
            return;
        }
        temp = temp->next;
    }

    printf("Vehicle Not Found!\n");
}

// Display All Vehicles
void displayVehicles() {
    for(int i = 0; i < SIZE; i++) {
        struct Vehicle* temp = hashTable[i];

        if(temp != NULL) {
            printf("\nIndex %d:\n", i);
            while(temp != NULL) {
                printf("RegNo: %s | Owner: %s | Type: %s\n",
                       temp->regNo, temp->ownerName, temp->vehicleType);
                temp = temp->next;
            }
        }
    }
}

// Main Function
int main() {
    int choice;
    char regNo[20], ownerName[50], vehicleType[20];

    // Initialize table
    for(int i = 0; i < SIZE; i++) {
        hashTable[i] = NULL;
    }

    while(1) {
        printf("\n--- Vehicle Registration System ---\n");
        printf("1. Register Vehicle\n");
        printf("2. Search Vehicle\n");
        printf("3. Display All\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter Reg No: ");
                scanf("%s", regNo);
                printf("Enter Owner Name: ");
                scanf("%s", ownerName);
                printf("Enter Vehicle Type: ");
                scanf("%s", vehicleType);

                insertVehicle(regNo, ownerName, vehicleType);
                break;

            case 2:
                printf("Enter Reg No to Search: ");
                scanf("%s", regNo);
                searchVehicle(regNo);
                break;

            case 3:
                displayVehicles();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}