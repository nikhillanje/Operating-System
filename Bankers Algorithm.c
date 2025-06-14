#include<stdio.h>
int allocated[20][20], max[20][20], need[20][20], done[20], available[10], cVector[10], np, nr, sequence[20], sp=0;
void input(){
	printf("\n Enter no. of Processes: ");
	scanf("%d", &np);
	printf("\n Enter no. of Resources: ");
	scanf("%d", &nr);
	printf("\n Enter claim vector: ");
	for(int i=0; i<nr; i++){
		scanf("%d", &cVector[i]);
	}
	printf("\n Enter Allocated resource table: \n");
	for(int i=0; i<np; i++){
		for(int j=0; j<nr; j++){
			scanf("%d", &allocated[i][j]);
		}
	}
	printf("\n Enter maximum claim table: \n");
	for(int i=0; i<np; i++){
		for(int j=0; j<nr; j++){
			scanf("%d", &max[i][j]);
		}
	}
	printf("\n Enter available resources: ");
	for(int i=0; i<nr; i++){
		scanf("%d", &available[i]);
	}
	for(int i=0; i<np; i++){
		done[i] = 0;
	}
}
void calculateNeed(){
	for(int i=0; i<np; i++){
		for(int j=0; j<nr; j++){
			need[i][j] = max[i][j] - allocated[i][j];
		}
	}
}
void printNeed(){
	printf("\n Need Table is : \n");
	for(int i=0; i<np; i++){
		for(int j=0; j<nr; j++){
			printf("%d \t", need[i][j]);
		}
		printf("\n");
	}
}
void printSequence(){
	printf("\n Safe state sequence is :");
	for(int i=0; i<sp; i++){
		printf("P%d\t", sequence[i]);
	}
}
void printAvailable(){
	printf("\n Available vector: ");
	for(int i=0; i<nr; i++){
		printf("%d\t", available[i]);
	}
}
void bankersAlgo(){
	for(int i=0; i<np; i++){
		int temp=0;
		for(int j=0; j<nr; j++){
			if(need[i][j] > available[j]){
				break;					
			}else if(need[i][j] <= available[j] && !done[i]){
				temp++;
				if(temp == nr){
					done[i] = 1;
					printAvailable();
					printf("\n Process %d is executing \n Process is in safe state", i);
					
					sequence[sp]=i;
					sp++;
					printSequence();
					for(int k=0; k<nr; k++){
						available[k] +=  allocated[i][k];
					}
				}
			}
		}
		
	}
	for(int i=0; i<np; i++){
		if(done[i] == 0){
			bankersAlgo();
		}
	}
}
void main(){
	input();
	calculateNeed();
	printNeed();	
	bankersAlgo();
	printAvailable();
}

/*
PS C:\Users\nikhi\OneDrive\Desktop\os> cd 

 Enter no. of Processes: 3

 Enter no. of Resources: 3

 Enter claim vector: 3
4
5

 Enter Allocated resource table: 
2
3
4
5
4
3
2
3
4

 Enter maximum claim table:
5
4
3
2
1
2
3
4
5

 Enter available resources: 3
4
5

 Need Table is :
3       1       -1
-3      -3      -1
1       1       1

 Available vector: 3    4       5
 Process 0 is executing
 Process is in safe state
 Safe state sequence is :P0
 Available vector: 5    7       9
 Process 1 is executing
 Process is in safe state
 Safe state sequence is :P0     P1
 Available vector: 10   11      12
 Process 2 is executing
 Process is in safe state
 Safe state sequence is :P0     P1      P2
 Available vector: 12   14      16
PS C:\Users\nikhi\OneDrive\Desktop\os>  */