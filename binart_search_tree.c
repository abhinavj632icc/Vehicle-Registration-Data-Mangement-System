#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure of BST Node
struct Vehicle {
    char regNo[20];
    char ownerName[50];
    char vehicleType[20];
    struct Vehicle* left;
    struct Vehicle* right;
};

// Create new node
struct Vehicle* createNode(char* regNo, char* ownerName, char* vehicleType) {
    struct Vehicle* newNode = (struct Vehicle*)malloc(sizeof(struct Vehicle));
    strcpy(newNode->regNo, regNo);
    strcpy(newNode->ownerName, ownerName);
    strcpy(newNode->vehicleType, vehicleType);
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert into BST
struct Vehicle* insert(struct Vehicle* root, char* regNo, char* ownerName, char* vehicleType) {
    if (root == NULL) {
        return createNode(regNo, ownerName, vehicleType);
    }

    if (strcmp(regNo, root->regNo) < 0) {
        root->left = insert(root->left, regNo, ownerName, vehicleType);
    } else if (strcmp(regNo, root->regNo) > 0) {
        root->right = insert(root->right, regNo, ownerName, vehicleType);
    }

    return root;
}

// Search in BST
struct Vehicle* search(struct Vehicle* root, char* regNo) {
    if (root == NULL || strcmp(root->regNo, regNo) == 0) {
        return root;
    }

    if (strcmp(regNo, root->regNo) < 0) {
        return search(root->left, regNo);
    }

    return search(root->right, regNo);
}

// Inorder Traversal (Sorted Output)
void inorder(struct Vehicle* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("RegNo: %s | Owner: %s | Type: %s\n",
               root->regNo, root->ownerName, root->vehicleType);
        inorder(root->right);
    }
}

// Main Function
int main() {
    struct Vehicle* root = NULL;
    int choice;
    char regNo[20], ownerName[50], vehicleType[20];

    while (1) {
        printf("\n--- Vehicle Registration BST ---\n");
        printf("1. Register Vehicle\n");
        printf("2. Search Vehicle\n");
        printf("3. Display All (Sorted)\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Reg No: ");
                scanf("%s", regNo);
                printf("Enter Owner Name: ");
                scanf("%s", ownerName);
                printf("Enter Vehicle Type: ");
                scanf("%s", vehicleType);

                root = insert(root, regNo, ownerName, vehicleType);
                printf("Vehicle Registered Successfully!\n");
                break;

            case 2: {
                printf("Enter Reg No to Search: ");
                scanf("%s", regNo);

                struct Vehicle* result = search(root, regNo);
                if (result != NULL) {
                    printf("\nVehicle Found:\n");
                    printf("RegNo: %s\nOwner: %s\nType: %s\n",
                           result->regNo, result->ownerName, result->vehicleType);
                } else {
                    printf("Vehicle Not Found!\n");
                }
                break;
            }

            case 3:
                printf("\nAll Vehicles (Sorted):\n");
                inorder(root);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}