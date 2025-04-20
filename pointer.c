#include <stdio.h>

typedef struct {
  int x;
  int y;
} Point;

int main() {
  Point p1 = {10, 20};
  Point *pPtr = &p1;

  // Two ways to access structure members via pointer
  printf("Using arrow notation: (%d, %d)\n", pPtr->x, pPtr->y);
  printf("Using dereference: (%d, %d)\n", (*pPtr).x, (*pPtr).y);
  printf("Using struct: (%d, %d)\n", p1.x, p1.y);

  return 0;
}

/*
int main() {
  int arr[5] = {1, 2, 3, 4, 5};
  int *ptr = arr;  // No & needed - array name is a pointer to first element

  // These are equivalent:
  printf("%d\n", arr[2]);  // Prints 3
  printf("%d\n", *(ptr+2));  // Also prints 3
}
*/

/*
int y = 1;

// Pass by value - original variable is not modified
void incrementByValue(int num) {
  num++;  // Only modifies the local copy
  y += num;
}

// Pass by reference - original variable is modified
void incrementByReference(int *num) {
  (*num)++;  // Modifies the value at the address
}

int main() {
  int x = 10;

  incrementByValue(x);
  printf("After pass by value: %d\n", x);  // Still 10
  printf("Y: %d\n", y);  // Still 10

  incrementByReference(&x);
  printf("After pass by reference: %d\n", x);  // Now 11

  return 0;
}
*/

/*
int main() {
    int number = 10;
    int *ptr;  // Declare a pointer to int
    
    ptr = &number;  // Store the address of number in ptr
    
    printf("Value of number: %d\n", number);
    printf("Address of number: %p\n", &number);
    printf("Value of ptr (the address it stores): %p\n", ptr);
    printf("Value ptr points to (dereferenced): %d\n", *ptr);
    
    // Modify the value through the pointer
    *ptr = 20;
    printf("New value of number: %d\n", number);
    
    return 0;
}
*/
