#include <stdio.h>

int main()
{
	int score[21][10] = {0};
	int sum[21] = {0};
	int ave[21] = {0};
	int subjectSum[10] = {0};
	float subjectAve[10] = {0};
	
	int student_count = 0;
	int subject_count = 0;
	
	printf("�л� �� �Է� : ");
	scanf("%d", &student_count);
	printf("���� �� �Է� : ");
	scanf("%d", &subject_count);
	
	for(int i = 0; i < student_count; i++)
	{
		printf("koposw%d �л��� ���� %d���� ���ʴ�� �Է��ϼ���. : ", i+1, subject_count);
		for(int j = 0; j < subject_count; j++)
		{
		scanf("%d", &score[i][j]);
		}
		
	}
	
	for(int i= 0; i < student_count; i++)
	{
		int sum = 0;
		float ave = 0;
		for(int j = 0; j < subject_count; j++)
		{
			sum += score[i][j];
			subjectSum[j] += score[i][j];
		}
		ave = sum / (float)subject_count;
		printf("koposw%d �л��� ���� ������ %d��, ����� %.2f�� �Դϴ�.\n", i+1, sum, ave);
	}
	
	for(int i = 0; i < subject_count; i++)
	{
		subjectAve[i] = subjectSum[i] / (float)student_count;
		printf("����%d ��ü ��� : %.2f��\n", i+1, subjectAve[i]);
	}
	
	return 0;
} 
