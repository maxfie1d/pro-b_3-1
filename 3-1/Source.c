#include <stdio.h>
#include <stdlib.h>

/*���łɒʂ����|�C���g������*/
int AlreadyPassed(int *route, int count, int area){
	int i;
	for (i = 0; i < count; i++)
		if (area == route[i])
			return 1;

	return 0;
}

/*�S���[�g������o��*/
void RouteNavigate(int **p_travel_time[], int *route, int n, int start, int count) {
	int i;
	int area; //�s����

	/*�ڕW�n�_�ɓ��B������*/
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
				//�ړ�������
				start = route[count - 1];
				count--;
			}

		}
	}

	return;
}

int main(void) {

	int i;
	int n = 7;

	int travel_time[7][7] = {
		{ 0, 1, 0, 1, 1, 0, 0 },
		{ 1, 0, 1, 1, 0, 0, 0 },
		{ 0, 1, 0, 1, 0, 0, 1 },
		{ 1, 1, 1, 0, 1, 1, 1 },
		{ 1, 0, 0, 1, 0, 1, 0 },
		{ 0, 0, 0, 1, 1, 0, 1 },
		{ 0, 0, 1, 1, 0, 1, 0 }
	};

	/*�z����w���_�u���|�C���^*/
	int **p_travel_time;
	p_travel_time = (int **)malloc(sizeof(int *)*n);
	if (p_travel_time == NULL) //�������m�ۃG���[
		exit(0);
	for (i = 0; i < n; i++)
		p_travel_time[i] = travel_time[i];

	/*���[�g�i�[�̈�m��*/
	int *route;
	route = (int *)malloc(sizeof(int) * n);
	if (route == NULL) //�������m�ۃG���[
		exit(0);
	for (i = 0; i < n; i++)
		route[i] = -1;
	route[0] = 0;

	/*�S���[�g�T��*/
	RouteNavigate(p_travel_time, route, n, 0, 0);

	/*���������*/
	free(p_travel_time);
	free(route);

	return 0;
}
