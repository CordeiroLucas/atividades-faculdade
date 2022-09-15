#include <stdio.h>

void main(){
	int burst[] = {5,7,2};
	int burst_cp[] = {5,7,2};
	int init[] = {0,2,5};

	int time = 0;
	int i = 0;
	int count = 3;
	int NOP = count;
	int q = 2;

	printf("\nProcess No \t\t Burst \t\t Turn Around\n");
	while(count != 0)
	{
		if(burst_cp[i] > 0 && init[i] <= time){
			if(burst_cp[i] <= q)
			{
				count--;
				time += burst_cp[i];
				burst_cp[i] = 0;

				printf("Process[%d] \t\t %d \t\t %d", i, burst[i], time - init[i]);
			}
			else
			{
				burst_cp[i] -= q;
				time += q;
			}
		}
		i = (i+1)%NOP;
	}
}