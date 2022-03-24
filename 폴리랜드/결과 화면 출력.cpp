#include <stdio.h>

int main()
{
	FILE *fp = fopen("report.csv", "r");
	
	const int MAX = 100;
	int count = 0;
	int year[MAX], month[MAX], day[MAX], ArrticketSelect_voucher[MAX], ArrticketSelect_voucher_kind[MAX],
		ArrageCase[MAX], Arrcount[MAX], ArrpriceResult[MAX], ArrdiscountRate[MAX];
		
	int amount_ticketselect_comp = 0, amount_ticketselect_park = 0;
	int ticketselect_comp[MAX] = {0}, ticketselect_park[MAX] = {0};	
	int sales_comp = 0, sales_park = 0;
	
	int totalSales = 0;
	int discount[MAX] = {0};
	
	while(fscanf(fp, "%d,%d,%d,%d,%d,%d,%d,%d,%d", &year[count], &month[count], &day[count], &ArrticketSelect_voucher[count],
	&ArrticketSelect_voucher_kind[count], &ArrageCase[count], &Arrcount[count], &ArrpriceResult[count], &ArrdiscountRate[count]) != -1)
		{
				count++;
		}
	fclose(fp);
	
	printf("============================ report.csv =============================\n\n");
	printf("  날짜       이용권   권종     연령구분  수량      가격      우대사항\n");
	
	for(int i = 0; i < count; i++)
	{
		printf("%d%02d%02d\t%d\t%d\t  %d\t  %d\t%8d\t%d\n", year[i], month[i], day[i], ArrticketSelect_voucher[i], ArrticketSelect_voucher_kind[i],
				ArrageCase[i], Arrcount[i], ArrpriceResult[i], ArrdiscountRate[i]);
	}

	printf("\n---------------------------------------------------------------------\n\n\n");
	printf("======================== 이용권 별 판매현황 ========================\n\n");
	
	for(int index1 = 0; index1 < count; index1++)
	{
		if(ArrticketSelect_voucher[index1] == 1)
		{
			amount_ticketselect_comp += Arrcount[index1];
			sales_comp += ArrpriceResult[index1];
			
			if(ArrageCase[index1] == 1)
			{
				ticketselect_comp[0] += Arrcount[index1];
			}
			else if(ArrageCase[index1] == 2)
			{
				ticketselect_comp[1] += Arrcount[index1];
			}
			else if(ArrageCase[index1] == 3)
			{
				ticketselect_comp[2] += Arrcount[index1];
			}
			else if(ArrageCase[index1] == 4)
			{
				ticketselect_comp[3] += Arrcount[index1];
			}
			else if(ArrageCase[index1] == 5)
			{
				ticketselect_comp[4] += Arrcount[index1];
			}
			else
			{
				ticketselect_comp[5] += Arrcount[index1];
			}
		}
		
		if(ArrticketSelect_voucher[index1] == 2)
		{
			amount_ticketselect_park += Arrcount[index1];
			sales_park += ArrpriceResult[index1];
			
			if(ArrageCase[index1] == 1)
			{
				ticketselect_park[0] += Arrcount[index1];
			}
			else if(ArrageCase[index1] == 2)
			{
				ticketselect_park[1] += Arrcount[index1];
			}
			else if(ArrageCase[index1] == 3)
			{
				ticketselect_park[2] += Arrcount[index1];
			}
			else if(ArrageCase[index1] == 4)
			{
				ticketselect_park[3] += Arrcount[index1];
			}
			else if(ArrageCase[index1] == 5)
			{
				ticketselect_park[4] += Arrcount[index1];
			}
			else
			{
				ticketselect_park[5] += Arrcount[index1];
			}
		}		
	}
	
	printf("종합이용권 총 %d매\n", amount_ticketselect_comp);
	printf("영아 %d매, 유아 %d매, 어린이 %d매, 청소년 %d매, 어른 %d매, 노인 %d매\n",
		  ticketselect_comp[5], ticketselect_comp[0], ticketselect_comp[1], ticketselect_comp[2], ticketselect_comp[3], ticketselect_comp[4]);
	printf("종합이용권 매출 : %d원\n\n", sales_comp);
	
	printf("파크이용권 총 %d매\n", amount_ticketselect_park);
	printf("영아 %d매, 유아 %d매, 어린이 %d매, 청소년 %d매, 어른 %d매, 노인 %d매\n",
		  ticketselect_park[5], ticketselect_park[0], ticketselect_park[1], ticketselect_park[2], ticketselect_park[3], ticketselect_park[4]);
	printf("종합이용권 매출 : %d원\n\n", sales_park);	
	printf("--------------------------------------------------------------------\n\n\n");
	
	//출력
	FILE *fp1 = fopen("이용권별 판매 개수.csv", "a"); 
	fprintf(fp1, "구분, 종합이용권, 파크이용권\n");
	fprintf(fp1, "%s,%d,%d\n", "영아", ticketselect_comp[5], ticketselect_park[5]);
	fprintf(fp1, "%s,%d,%d\n", "유아", ticketselect_comp[0], ticketselect_park[0]);
	fprintf(fp1, "%s,%d,%d\n", "어린이", ticketselect_comp[1], ticketselect_park[1]);
	fprintf(fp1, "%s,%d,%d\n", "청소년", ticketselect_comp[2], ticketselect_park[2]);
	fprintf(fp1, "%s,%d,%d\n", "어른", ticketselect_comp[3], ticketselect_park[3]);
	fprintf(fp1, "%s,%d,%d\n", "노인", ticketselect_comp[4], ticketselect_park[4]);
	fprintf(fp1, "%s,%d,%d\n", "합계", amount_ticketselect_comp, amount_ticketselect_park);
	fprintf(fp1, "%s,%d,%d\n", "매출", sales_comp, sales_park);
	fclose(fp1);
	
	printf("===== 우대권 판매 현황 =====\n\n");
	
	for(int index = 0; index < count; index++)
	{
		totalSales += Arrcount[index];
		
		if(ArrdiscountRate[index] == 1)
		{
			discount[0] += Arrcount[index];
		}
		else if(ArrdiscountRate[index] == 2)
		{
			discount[1] += Arrcount[index];
		}
		else if(ArrdiscountRate[index] == 3)
		{
			discount[2] += Arrcount[index];
		}
		else if(ArrdiscountRate[index] == 4)
		{
			discount[3] += Arrcount[index];
		}
		else if(ArrdiscountRate[index] == 5)
		{
			discount[4] += Arrcount[index];
		}
		else
		{
			discount[5] += Arrcount[index];
		}
	}
	
	printf("총 판매 티켓수     :   %d매\n", totalSales);
	printf("우대 없음          :   %d매\n", discount[0]);
	printf("장애인             :   %d매\n", discount[1]);
	printf("국가유공자         :   %d매\n", discount[2]);
	printf("휴가장병           :   %d매\n", discount[3]);
	printf("임산부             :   %d매\n", discount[4]);
	printf("다둥이 행복카드    :   %d매\n\n", discount[5]);
	printf("----------------------------\n\n");	
	
	//출력
	FILE *fp2 = fopen("우대권 판매 개수.csv", "a"); 
	fprintf(fp2, "%s,%d\n", "총 판매티켓수", totalSales);
	fprintf(fp2, "%s,%d\n", "우대 없음", discount[0]);
	fprintf(fp2, "%s,%d\n", "장애인", discount[1]);
	fprintf(fp2, "%s,%d\n", "국가유공자", discount[2]);
	fprintf(fp2, "%s,%d\n", "휴가장병", discount[3]);
	fprintf(fp1, "%s,%d\n", "임산부", discount[4]);
	fprintf(fp1, "%s,%d\n", "다둥이 행복카드", discount[5]);
	fclose(fp2);		
	
	return 0;
}
