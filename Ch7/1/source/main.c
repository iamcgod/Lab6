#include <stdlib.h>
#include <stdio.h>
#pragma warning(disable : 4996)

typedef struct _student
{
	char name[5];
	int chinese, english, math, sum;
	float avg;
}student;


int main(void)
{
	student data[5];
	FILE *s1 = fopen("D://gd.txt", "r");
	FILE *s2 = fopen("D://go.txt", "w");
	int i = 0;
	
	if (s1 == NULL || s2 == NULL)
		printf("�}�ҥ���\n");
	else
	{
		fprintf(s2, "�m�W\t���\t�^��\t�ƾ�\t�`�M\t����\n");
		for (i = 0; i < 5; i++)
		{
			fscanf(s1, "%s", data[i].name);
			fscanf(s1, "%d", &data[i].chinese);
			fscanf(s1, "%d", &data[i].english);
			fscanf(s1, "%d", &data[i].math);

			data[i].sum = data[i].chinese + data[i].english + data[i].math;
			data[i].avg = data[i].sum / 3.0;
			fprintf(s2, "%s\t%d\t%d\t%d\t%d\t%.2f\n", data[i].name, data[i].chinese, data[i].english, data[i].math, data[i].avg);
		}
		fclose(s1);
		fclose(s2);
	}
	system("pause");
	return 0;
}