#include <stdio.h>
#include <ctype.h>

typedef struct {
  int cordx;
  int cordy;
  int position;
} Cord;

void displayPoint(Cord a){
    printf("The point (%d, %d) is in ", a.cordx, a.cordy);
    switch (a.position){
        case 0:
            printf("Origin");
            break;
        case 1:
            printf("Q1");
            break;
        case 2:
            printf("Q2");
            break;
        case 3:
            printf("Q3");
            break;
        case 4:
            printf("Q4");
            break;
        case 5:
            printf("x-axis");
            break;
        case 6:
            printf("y-axis");
            break;
        default:
            printf("not present");
    }
}

Cord createPoint() {
    Cord coordinate;
    int valid;
    
    do {
        printf("Enter x - coordinate: ");
        valid = scanf("%d", &coordinate.cordx);
        if (valid != 1) {
            while (getchar() != '\n'){
                printf("Invalid input. Please enter a number.\n");
            }
                
        }
    } while (valid != 1);
    
    do {
        printf("Enter y - coordinate: ");
        valid = scanf("%d", &coordinate.cordy);
        if (valid != 1) {
            while (getchar() != '\n'){
                printf("Invalid input. Please enter a number.\n");
            }
        }
    } while (valid != 1);
    return coordinate;
}

int identifyPoint(Cord b){
    if (b.cordx == 0 && b.cordy == 0) {
        return 0;
    } 
    else if (b.cordx == 0) {
        return 6; 
    } 
    else if (b.cordy == 0) {
        return 5;
    } 
    else if (b.cordx < 0 && b.cordy > 0) {
        return 1;
    } 
    else if (b.cordx > 0 && b.cordy > 0) {
        return 2;
    } 
    else if (b.cordx < 0 && b.cordy < 0) {
        return 3;
    } 
    else if (b.cordx > 0 && b.cordy < 0) {
        return 4;
    }
}

int main() {
    Cord moe = createPoint();
    moe.position = identifyPoint(moe);
    displayPoint(moe);

    
  return 0;
}

