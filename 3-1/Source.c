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

	return;
}

int main(void) {

	int i;
	int n = 6;

	int travel_time[6][6] =
	{ { 0, 7, 3, 0, 0, 0 },
	{ 7, 0, 5, 7, 0, 0 },
	{ 3, 5, 0, 6, 4, 0 },
	{ 0, 7, 6, 0, 3, 9 },
	{ 0, 0, 4, 3, 0, 8 },
	{ 0, 0, 0, 9, 8, 0 } };

	/*�֐��Ăяo���p�_�u���|�C���^��������*/
	int **p_travel_time[6];
	for (i = 0; i < n; i++) {
		p_travel_time[i] = (int **)&travel_time[i];
	}
	/*�֐��Ăяo���p�_�u���|�C���^�����܂�*/

	/*���[�g�i�[�̈�m�ۂ�������*/
	int *route;
	route = (int *)malloc(sizeof(int) * n);
	if (route == NULL) //�������m�ۃG���[
		exit(0);
	for (i = 0; i < n; i++)
		route[i] = -1;
	route[0] = 0;
	/*���[�g�i�[�̈�m�ۂ����܂�*/

	RouteNavigate(p_travel_time, route, n, 0, 0);

	free(route);

	return 0;
}
