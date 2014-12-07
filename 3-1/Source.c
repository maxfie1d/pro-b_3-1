#include <stdio.h>
#include <stdlib.h>

void RouteNavigate(int **array, int n){
	int *route = (int *)malloc(sizeof(int) * n);
	if (route == NULL)
		exit(0);
	int i;

	for (i = 0; i < n; i++){

	}




}

int main(void){

	int travel_time[6][6] =
	{ { 0, 7, 3, 0, 0, 0 },
	{ 7, 0, 5, 7, 0, 0 },
	{ 3, 5, 0, 6, 4, 0 },
	{ 0, 7, 6, 0, 3, 9 },
	{ 0, 0, 4, 3, 0, 8 },
	{ 0, 0, 0, 9, 8, 0 } };

	int n = 6;
	int i;
	int **p[6];

	for (i = 0; i < n; i++){
		p[i] = travel_time[i];
	}

	RouteNavigate(p, n);

	printf("hogeeeeeeee\n");

	printf("Hey, survivors...\n");



	return 0;
}
