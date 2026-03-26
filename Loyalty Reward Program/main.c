#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct employeeDetails {
    char firstName[16];
    int monthHire;
    int yearHire;
} employee, *employeeRecords;

employee *getLoyalList(employeeRecords loyalListvar, int *size, int currentDate){
    employeeRecords ptr;
    ptr = malloc(*size * (sizeof(employee)));
    int j = 0;
    for (int i = 0; i < *size; i++){
        if (currentDate - loyalListvar[i].yearHire >= 5){
            ptr[j++] = loyalListvar[i];
        }
    }
    *size = j;
    ptr = realloc(ptr, j * sizeof(employee)); 
    return ptr;
}

void display(employee* properList, int loyalListCount){
    printf("\n");
    printf("List of Loyal Employees\n");
    if (loyalListCount != 0){
        for (int i = 0; i < loyalListCount; i++){
            printf("Name: %s -- Hire Date: %d - %d\n", properList[i].firstName, properList[i].monthHire, properList[i].yearHire);
        }
    } else {
        printf("There are currently no Employees who are eligible for the reward.");
    }
}


int main(){
    int currentSize;
    employee *loyalList;
    printf("Input Number of Employees: ");
    scanf("%d", &currentSize);
    printf("Input Details for Employees:\n");
    employee currentList[currentSize];
    for (int i = 0; i < currentSize; i++){
        printf("===Employee %d===\n", i + 1);
        printf("\n");
        printf("Input First Name: ");
            getchar();
            fgets(currentList[i].firstName, sizeof(currentList[i].firstName), stdin);
            currentList[i].firstName[strcspn(currentList[i].firstName, "\n")] = '\0';
        printf("Input Month of Hire: ");
        scanf("%d", &currentList[i].monthHire);
        printf("Input Year of Hire: ");
        scanf("%d", &currentList[i].yearHire);
        printf("\n");
    }
    
    loyalList = getLoyalList(currentList, &currentSize, 2026);
    display(loyalList, currentSize);
    free(loyalList);
}