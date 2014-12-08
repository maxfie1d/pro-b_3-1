#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int AlreadyPassed(int route[], int count, int area){
	int i;

	for (i = 0; i < count; i++)
		if (route[i] == area)
			return 1;

	return 0;
}

void RouteNavigate(int **p_travel_time, int *route, int n, int start, int count) {

	int i;
	char num;


	int area;
	int j;

	if (start == n - 1){
		for (i = 0; i <= count; i++)
			printf("%d - ", route[i] + 1);
		printf("\b\b\b  \b\b\n");
		Sleep(100);
		//取り消し
		start = route[count - 1];
		route[count] = -1;
		count--;
		return 0;
	}

	for (area = 0; area < n; area++) {
		if (p_travel_time[start][area] > 0 && !AlreadyPassed(route, count, area)){
			printf("%d -> %d\n", start + 1, area + 1);
			count++;
			route[count] = area;
			start = area;
			RouteNavigate(p_travel_time, route, n, start, count);
			//取り消し
			start = route[count - 1];
			route[count] = -1;
			count--;
		}

	}



	return 0;



}

int main(void) {


	int i, j;
	int n = 6;

	int travel_time[6][6] =
	{ { 0, 7, 3, 0, 0, 0 },
	{ 7, 0, 5, 7, 0, 0 },
	{ 3, 5, 0, 6, 4, 0 },
	{ 0, 7, 6, 0, 3, 9 },
	{ 0, 0, 4, 3, 0, 8 },
	{ 0, 0, 0, 9, 8, 0 } };

	int passed[6][6];

	for (i = 0; i < 6; i++)
		for (j = 0; j < 6; j++)
			passed[i][i] = 1;

	int *route; //道筋を格納
	route = (int *)malloc(sizeof(int) * n);
	if (route == NULL) //メモリ確保エラー
		exit(0);

	for (i = 0; i < n; i++)
		route[i] = -1;

	route[0] = 0;

	int **p_travel_time[6];

	for (i = 0; i < n; i++) {
		p_travel_time[i] = travel_time[i];
	}

	RouteNavigate(p_travel_time, route, n, 0, 0);

	return 0;
}
