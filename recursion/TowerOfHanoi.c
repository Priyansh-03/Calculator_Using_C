#include <stdio.h>

void towerOfHanoi(int n, int poles, int from, int destination, int mid) {
    if (n == 1) {
        printf("Move disk 1 from pole %d to pole %d\n", from, destination);
        return;
    }
    towerOfHanoi(n-1, poles, from, mid, destination);
    printf("Move disk %d from pole %d to pole %d\n", n, from, destination);
    towerOfHanoi(n-1, poles, mid, destination, from);
}

int main() {
    int n, poles;
    printf("Enter the number of poles: ");
    scanf("%d", &poles);
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    
    printf("The steps to solve the Tower of Hanoi problem are:\n");
    towerOfHanoi(n, poles, 1, poles, poles-1);
    return 0;
}
