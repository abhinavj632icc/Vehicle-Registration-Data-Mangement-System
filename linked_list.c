#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node Structure
struct Vehicle {
    char regNo[20];
    char ownerName[50];
    char vehicleType[20];
    struct Vehicle* next;
};

struct Vehicle* head = NULL;

// Add Vehicle (at beginning)
void addVehicle() {
    struct Vehicle* newNode = (struct Vehicle*)malloc(sizeof(struct Vehicle));

    printf("Enter Reg No: ");
    scanf("%s", newNode->regNo);

    printf("Enter Owner Name: ");
    scanf("%s", newNode->ownerName);

    printf("Enter Vehicle Type: ");
    scanf("%s", newNode->vehicleType);

    newNode->next = head;
    head = newNode;

    printf("Vehicle Added Successfully!\n");
}

// Search Vehicle
void searchVehicle() {
    char regNo[20];
    int found = 0;

    printf("Enter Reg No to Search: ");
    scanf("%s", regNo);

    struct Vehicle* temp = head;

    while (temp != NULL) {
        if (strcmp(temp->regNo, regNo) == 0) {
            printf("\nVehicle Found:\n");
            printf("RegNo: %s\nOwner: %s\nType: %s\n",
                   temp->regNo, temp->ownerName, temp->vehicleType);
            found = 1;
            return;
        }
        temp = temp->next;
    }

    if (!found) {
        printf("Vehicle Not Found!\n");
    }
}

// Delete Vehicle
void deleteVehicle() {
    char regNo[20];
    printf("Enter Reg No to Delete: ");
    scanf("%s", regNo);

    struct Vehicle *temp = head, *prev = NULL;

    while (temp != NULL) {
        if (strcmp(temp->regNo, regNo) == 0) {
            if (prev == NULL) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            printf("Vehicle Deleted Successfully!\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    printf("Vehicle Not Found!\n");
}

// Display All Vehicles
void displayVehicles() {
    struct Vehicle* temp = head;

    if (temp == NULL) {
        printf("No Records Found!\n");
        return;
    }

    printf("\nAll Vehicles:\n");
    while (temp != NULL) {
        printf("RegNo: %s | Owner: %s | Type: %s\n",
               temp->regNo, temp->ownerName, temp->vehicleType);
        temp = temp->next;
    }
}

// Main Function
int main() {
    int choice;

    while (1) {
        printf("\n--- Vehicle Registration (Linked List) ---\n");
        printf("1. Add Vehicle\n");
        printf("2. Search Vehicle\n");
        printf("3. Delete Vehicle\n");
        printf("4. Display All\n");
        printf("5. Exit\n");

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
                deleteVehicle();
                break;
            case 4:
                displayVehicles();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid Choice!\n");
        }
    }
}