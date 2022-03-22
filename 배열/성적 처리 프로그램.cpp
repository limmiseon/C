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
	
	printf("학생 수 입력 : ");
	scanf("%d", &student_count);
	printf("과목 수 입력 : ");
	scanf("%d", &subject_count);
	
	for(int i = 0; i < student_count; i++)
	{
		printf("koposw%d 학생의 점수 %d개를 차례대로 입력하세요. : ", i+1, subject_count);
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
		printf("koposw%d 학생의 과목 총점은 %d점, 평균은 %.2f점 입니다.\n", i+1, sum, ave);
	}
	
	for(int i = 0; i < subject_count; i++)
	{
		subjectAve[i] = subjectSum[i] / (float)student_count;
		printf("과목%d 전체 평균 : %.2f점\n", i+1, subjectAve[i]);
	}
	
	return 0;
} 
