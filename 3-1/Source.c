#include <stdio.h>
#include <stdlib.h>

void RouteNavigate(int **p_travel_time, int **p_passed, int *route, int n, int start, int count) {

	int i, j;
	if (start == n - 1) {
		for (i = 0; i < 6; i++)
			printf("%d-",route[i]);
		count--;
		for (j = 0; j < 6; j++) {
			p_passed[j][start] = 1;
		}
		p_passed[route[count - 1]][route[count]] = 0;
		RouteNavigate(p_travel_time, p_passed, route, n, start, count);
	}
	else {
		for (i = 0; i < n; i++) {
			if (p_travel_time[start][i] > 0 && p_passed[start][i] != 0) {
				route[++count] = i;
				for (j = 0; j < n; j++)
					p_passed[j][start] = 0;
				printf("%d-", i + 1);
				start = i;
				RouteNavigate(p_travel_time, p_passed, route, n, start, count);
			}

		}
		count--;
		for (j = 0; j < 6;j++)

		RouteNavigate(p_travel_time, p_passed, route, n, start, count);
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

	int *route; //“¹‹Ø‚ğŠi”[
	route = (int *)malloc(sizeof(int) * n);
	if (route == NULL) //ƒƒ‚ƒŠŠm•ÛƒGƒ‰[
		exit(0);

	route[0] = 0;

	int **p_travel_time[6];

	for (i = 0; i < n; i++) {
		p_travel_time[i] = travel_time[i];
	}

	int **p_passed[6];

	for (i = 0; i < n; i++)
		p_passed[i] = passed[i];

	RouteNavigate(p_travel_time, p_passed, route, n, 0,0);

	return 0;
}
