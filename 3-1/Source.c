﻿#include <stdio.h>
#include <stdlib.h>

/*すでに通ったポイントか判定*/
int AlreadyPassed(int *route, int count, int area){
	int i;
	for (i = 0; i < count; i++)
		if (area == route[i])
			return 1;

	return 0;
}

/*全ルートを割り出す*/
void RouteNavigate(int **p_travel_time, int *route, int n, int start, int count) {
	int i;
	int area; //行き先

	/*目標地点に到達した時*/
	if (start == n - 1){
		for (i = 0; i <= count; i++)
			printf("%d - ", route[i] + 1);
		printf("\b\b\b  \b\b\n");

		return;
	}
	else{
		for (area = 0; area < n; area++) {
			if (p_travel_time[start][area] > 0 && !AlreadyPassed(route, count, area)){
				count++;
				route[count] = area;
				start = area;
				RouteNavigate(p_travel_time, route, n, start, count);
				//移動取り消し
				start = route[count - 1];
				count--;
			}

		}
	}

	return;
}

int main(void) {

	int i;
	int n = 6; //目的地

	//各道の移動時間
	int travel_time[6][6] = {
		{ 0, 7, 3, 0, 0, 0 },
		{ 7, 0, 5, 7, 0, 0 },
		{ 3, 5, 0, 6, 4, 0 },
		{ 0, 7, 6, 0, 3, 9 },
		{ 0, 0, 4, 3, 0, 8 },
		{ 0, 0, 0, 9, 8, 0 }
	};

	/*配列を指すダブルポインタ*/
	int **p_travel_time;
	p_travel_time = (int **)malloc(sizeof(int *)*n);
	if (p_travel_time == NULL) //メモリ確保エラー
		exit(0);
	for (i = 0; i < n; i++)
		p_travel_time[i] = travel_time[i];

	/*ルート格納領域確保*/
	int *route;
	route = (int *)malloc(sizeof(int) * n);
	if (route == NULL) //メモリ確保エラー
		exit(0);
	for (i = 0; i < n; i++)
		route[i] = -1;
	route[0] = 0;

	/*全ルート探索*/
	RouteNavigate(p_travel_time, route, n, 0, 0);

	/*メモリ解放*/
	free(p_travel_time);
	free(route);

	return 0;
}
