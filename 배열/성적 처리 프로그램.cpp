//����� �Ƚ�, �л��� ����
#include <stdio.h>

int main()
{
	int score[21][10] = {0};
	int sum[21] = {0};
	float ave[21] = {0};
	int subjectSum[10] = {0};
	float subjectAve[10] = {0};
	
	int student_count = 0;
	printf("�л� �� �Է� : ");
	scanf("%d", &student_count);
	
	for(int i = 0; i < student_count; i++)
	{
		printf("koposw%d �л��� ���� 3���� ���ʴ�� �Է��ϼ���. : ", i+1);
		scanf("%d %d %d", &score[i][0], &score[i][1], &score[i][2]);
	}
	
	for(int i= 0; i < student_count; i++)
	{
		sum = score[i][1] + score[i][2] + score[i][3];
		ave = sum/3;
		
		printf("koposw%d �л��� ���� ������ %d��, ����� %.2f�� �Դϴ�.\n", i+1, sum, ave);
	}
	
	for(int i = 0; i < 3 ; i++)
	{
		subjectsum[0] += score[i][0];
		subjectsum[1] += score[i][1];
		subjectsum[2] += score[i][2];
	
		subjectAve[i] = subjectsum[i]/(float)student_count;
		printf("����%d ��ü ��� : %.2f��\n", i+1, subjectAve[i]);
	}
	
	return 0;
} 
