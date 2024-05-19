#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct Jobs {
   char id; // Jobs Id
   int dead; // Deadline of Jobs
   int profit; // Profit if Jobs is over before or on deadline
} Jobs;

// This function is used for sorting all Jobss according to
// profit
int compare(const void* a, const void* b){
   Jobs* temp1 = (Jobs*)a;
   Jobs* temp2 = (Jobs*)b;
   return (temp2->profit - temp1->profit);
}

// Find minimum between two numbers.
int min(int num1, int num2){
   return (num1 > num2) ? num2 : num1;
}
int main(){
   Jobs arr[] = { 
      { 'a', 2, 100 },
      { 'b', 2, 20 },
      { 'c', 1, 40 },
      { 'd', 3, 35 },
      { 'e', 1, 25 }
   };
   int n = sizeof(arr) / sizeof(arr[0]);
	int i, j;
	Jobs temp;  
  	for (i = 0; i < n-1; i++) {  
    	for (j = 0; j < n - i - 1; j++) {  
      	if (arr[j].profit < arr[j + 1].profit) {  
        	temp = arr[j];  
        	arr[j] = arr[j + 1];  
       	 	arr[j + 1] = temp;  
      }  
    }  
  }  

   printf("Following is maximum profit sequence of Jobs: \n");
   for (i = 0; i < n ; i++) {  
   		printf("%c,%d->%d",arr[i].id,arr[i].dead,arr[i].profit);
   	printf("\n");
   }
   int result[n]; // To store result sequence of Jobs
   bool slot[n]; // To keep track of free time slots
	int totalProfit = 0;
   // Initialize all slots to be free
   for (i = 0; i < n; i++)
      slot[i] = false;

   // Iterate through all given Jobs
   for (i = 0; i < n; i++) {

      // Find a free slot for this Job
      for (j = min(n, arr[i].dead) - 1; j >= 0; j--) {
         if (slot[j] == false) {
            result[j] = i;
            slot[j] = true;
            totalProfit = totalProfit +arr[i].profit;
            break;
         }
      }
   }       
    printf("Scheduled jobs:\n");
    for (i = 0; i < n; i++) {
        if (slot[i] != false) {
            printf("Job ID: %c\n", arr[result[i]].id);
        }
    }
    printf("Total Profit: %d\n", totalProfit);
   return 0; 
}

/*
Following is maximum profit sequence of Jobs:
a,2->100
c,1->40
d,3->35
e,1->25
b,2->20
Scheduled jobs:
Job ID: c
Job ID: a
Job ID: d
Total Profit: 175

--------------------------------
Process exited after 0.05442 seconds with return value 0
Press any key to continue . . .
*/
