#include <stdio.h>
int main() {
    int n, i, j, p[100], b[100], t[100], w[100];
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter burst time of process %d: ", i + 1);
        scanf("%d", &b[i]);

        printf("Enter priority of process %d: ", i + 1);
        scanf("%d", &p[i]);

        t[i] = 0;
        w[i] = 0;
    }

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (p[i] > p[j]) {
                int temp = p[i];
                p[i] = p[j];
                p[j] = temp;

                temp = b[i];
                b[i] = b[j];
                b[j] = temp;
            }
        }
    }

    for (i = 0; i < n; i++) {
        t[i] = b[i] + w[i];
        w[i] = t[i] - b[i];
    }

    printf("Process ID\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, b[i], p[i], w[i], t[i]);
    }

    return 0;
