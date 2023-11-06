#include <stdio.h>
#include <stdlib.h>  // Include the standard library for system("pause")
//#include <string.h>

int main() {
    int allocated[20][20], max[20][20], available[20] = {0}, need[20][20], total[20];
    int finish[20] = {0};
    int cntProcess, cntRes, process, res, flag, execFlag, executed;
    
    printf("Enter no. of processes: ");
    scanf("%d", &process);
    
    printf("Enter no. of resources: ");
    scanf("%d", &res);
    
    printf("Enter the maximum instances of each resource:\n");
    for (cntRes = 0; cntRes < res; cntRes++) {
        printf("\nNo. of instances of resource #%d: ", cntRes);
        scanf("%d", &total[cntRes]);
    }
    
    printf("Enter the maximum requirement of each process:\n");
    for (cntProcess = 0; cntProcess < process; cntProcess++) {
        printf("Process #%d:\n", cntProcess);
        for (cntRes = 0; cntRes < res; cntRes++) {
            printf("Requirement for resource #%d: ", cntRes);
            scanf("%d", &max[cntProcess][cntRes]);
        }
    }
    
    printf("Enter the current allocation for each process:\n");
    for (cntProcess = 0; cntProcess < process; cntProcess++) {
        printf("Process #%d:\n", cntProcess);
        for (cntRes = 0; cntRes < res; cntRes++) {
            printf("Allocation for resource #%d: ", cntRes);
            scanf("%d", &allocated[cntProcess][cntRes]);
        }
    }
    
    for (cntRes = 0; cntRes < res; cntRes++) {
        for (cntProcess = 0; cntProcess < process; cntProcess++) {
            available[cntRes] += allocated[cntProcess][cntRes];
        }
        available[cntRes] = total[cntRes] - available[cntRes];
    }
    
    printf("The available instances of each resource are:\n");
    for (cntRes = 0; cntRes < res; cntRes++) {
        printf("Resource #%d: %d\n", cntRes, available[cntRes]);
    }
    
    for (cntProcess = 0; cntProcess < process; cntProcess++) {
        for (cntRes = 0; cntRes < res; cntRes++) {
            need[cntProcess][cntRes] = max[cntProcess][cntRes] - allocated[cntProcess][cntRes];
        }
    }
    
    printf("The NEED matrix is:\n");
    for (cntProcess = 0; cntProcess < process; cntProcess++) {
        for (cntRes = 0; cntRes < res; cntRes++) {
            printf("%d\t", need[cntProcess][cntRes]);
        }
        printf("\n");
    }
    
    printf("The processes are executed in the following sequence:\n");
    executed = 0;
    
    do {
        //this below for loop is for traversing all the proccesses 
        for (cntProcess = 0 ; cntProcess < process; cntProcess++) {
            int execFlag = 0;
            flag = 0;
            // if--> already succesfully executed
            if (finish[cntProcess] != 0)
            {
                continue;
            }    
            else { //else-->if process not executed

            //this below for loop is for traversing resources 
                for (cntRes = 0; cntRes < res; cntRes++) {
                    if (need[cntProcess][cntRes] > available[cntRes]) {
                        printf("process  P%d is not executed",cntProcess);
                        flag = 1;
                        break;
                    }
                }
                
                if (flag == 0) {
                    printf("P%d executed ", cntProcess);
                    finish[cntProcess] = 1;
                    for (cntRes = 0; cntRes < res; cntRes++) {
                        available[cntRes] += allocated[cntProcess][cntRes];
                    }
                    execFlag = 1;
                    executed++;
                }
            }
        }
        
        if (execFlag == 0) {
            printf("\n\nThe system is in an UNSAFE state!\n");
            break;
        }
    } while (executed < process);
    
    printf("\n");
    
    
    // // Pause the program
    // system("pause");
    
    return 0;
}


