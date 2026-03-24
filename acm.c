#include <stdio.h>
#include <string.h>

#define NUM_USERS 3
#define NUM_RESOURCES 3

void checkPermission(char permissions[NUM_USERS][NUM_RESOURCES][5], int user, int resource, char op) {
    if (strchr(permissions[user][resource], op) != NULL) {
        printf("Access GRANTED for '%c' operation.\n", op);
    } else {
        printf("Access DENIED for '%c' operation.\n", op);
    }
}

int main() {
    char acm[NUM_USERS][NUM_RESOURCES][5] = {
        {"RW", "R", "X"},
        {"R", "RWX", ""},
        {"", "R", "RW"}
    };

    printf("Access Control Matrix:\n");
    printf("Users\\Resources\tFile1\tFile2\tFile3\n");
    for (int u = 0; u < NUM_USERS; u++) {
        printf("User%d\t\t", u);
        for (int r = 0; r < NUM_RESOURCES; r++) {
            printf("%s\t", acm[u][r]);
        }
        printf("\n");
    }

    int userNum, resourceNum;
    char operation;

    printf("\nEnter user number (0-2): ");
    scanf("%d", &userNum);

    printf("Enter resource number (0-2): ");
    scanf("%d", &resourceNum);

    printf("Enter operation (R/W/X): ");
    scanf(" %c", &operation);

    checkPermission(acm, userNum, resourceNum, operation);

    return 0;
}