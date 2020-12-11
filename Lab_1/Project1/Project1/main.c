#include<stdio.h>

typedef struct _student {
	char name[5];
	int chinese, english, math, sum;
	float avg;
}student;

int main() {
	student data[5];
	FILE *s1;
	FILE *s2;

	s1 = fopen("C:/Users/USER/Desktop/gd.txt", "r");
	s2 = fopen("C:/Users/USER/Desktop/go.txt", "w");

	if (s1 == NULL || s2 == NULL) {
		printf("�ɮ׶}�ҥ���\n");
	}
	else {
		fprintf(s2, "�m�W\t���\t�^��\t�ƾ�\t��X\t����\n");
		for (int i = 0; i < 5; i++) {
			fscanf(s1, "%s", data[i].name);
			fscanf(s1, "\t\t%d", &data[i].chinese);

			fscanf(s1, "\t%d", &data[i].english);
			fscanf(s1, "\t%d", &data[i].math);

			data[i].sum = data[i].chinese + data[i].english + data[i].math;
			data[i].avg = data[i].sum / 3.0;
			fprintf(s2, "%s\t%d\t%d\t%d\t%d\t%.2f\n", data[i].name,
				data[i].chinese, data[i].english, data[i].math, data[i].sum,
				data[i].avg);
		}
		fclose(s1);
		fclose(s2);
	}
	return 0;
}