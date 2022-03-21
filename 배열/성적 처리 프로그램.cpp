//과목수 픽스, 학생수 먼저
#include <stdio.h>

int main()
{
	int score[21][10] = {0};
	int sum[21] = {0};
	float ave[21] = {0};
	int subjectSum[10] = {0};
	float subjectAve[10] = {0};
	
	int student_count = 0;
	printf("학생 수 입력 : ");
	scanf("%d", &student_count);
	
	for(int i = 0; i < student_count; i++)
	{
		printf("koposw%d 학생의 점수 3개를 차례대로 입력하세요. : ", i+1);
		scanf("%d %d %d", &score[i][0], &score[i][1], &score[i][2]);
	}
	
	for(int i= 0; i < student_count; i++)
	{
		sum = score[i][1] + score[i][2] + score[i][3];
		ave = sum/3;
		
		printf("koposw%d 학생의 과목 총점은 %d점, 평균은 %.2f점 입니다.\n", i+1, sum, ave);
	}
	
	for(int i = 0; i < 3 ; i++)
	{
		subjectsum[0] += score[i][0];
		subjectsum[1] += score[i][1];
		subjectsum[2] += score[i][2];
	
		subjectAve[i] = subjectsum[i]/(float)student_count;
		printf("과목%d 전체 평균 : %.2f점\n", i+1, subjectAve[i]);
	}
	
	return 0;
} 
