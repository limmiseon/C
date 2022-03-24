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
	
	for(int index = 0; index < count; index++)
	{
		if(ArrticketSelect_voucher[index] == 1)
		{
			amount_ticketselect_comp += Arrcount[index];
			sales_comp += ArrpriceResult[index];
			
			if(ArrageCase[index] == 1)
			{
				ticketselect_comp[0] += Arrcount[index];
			}
			else if(ArrageCase[index] == 2)
			{
				ticketselect_comp[1] += Arrcount[index];
			}
			else if(ArrageCase[index] == 3)
			{
				ticketselect_comp[2] += Arrcount[index];
			}
			else if(ArrageCase[index] == 4)
			{
				ticketselect_comp[3] += Arrcount[index];
			}
			else if(ArrageCase[index] == 5)
			{
				ticketselect_comp[4] += Arrcount[index];
			}
			else
			{
				amount_ticketselect_comp --;
			}
		}
		
		if(ArrticketSelect_voucher[index] == 2)
		{
			amount_ticketselect_park += Arrcount[index];
			sales_park += ArrpriceResult[index];
			
			if(ArrageCase[index] == 1)
			{
				ticketselect_park[0] += Arrcount[index];
			}
			else if(ArrageCase[index] == 2)
			{
				ticketselect_park[1] += Arrcount[index];
			}
			else if(ArrageCase[index] == 3)
			{
				ticketselect_park[2] += Arrcount[index];
			}
			else if(ArrageCase[index] == 4)
			{
				ticketselect_park[3] += Arrcount[index];
			}
			else if(ArrageCase[index] == 5)
			{
				ticketselect_park[4] += Arrcount[index];
			}
			else
			{
				amount_ticketselect_park --;
			}
		}		
	}
	
	printf("종합이용권 총 %d매\n", amount_ticketselect_comp);
	printf("유아 %d매, 어린이 %d매, 청소년 %d매, 어른 %d매, 노인 %d매\n",
		  ticketselect_comp[0], ticketselect_comp[1], ticketselect_comp[2], ticketselect_comp[3], ticketselect_comp[4]);
	printf("종합이용권 매출 : %d원\n\n", sales_comp);
	
	printf("파크이용권 총 %d매\n", amount_ticketselect_park);
	printf("유아 %d매, 어린이 %d매, 청소년 %d매, 어른 %d매, 노인 %d매\n",
		  ticketselect_park[0], ticketselect_park[1], ticketselect_park[2], ticketselect_park[3], ticketselect_park[4]);
	printf("종합이용권 매출 : %d원\n\n", sales_park);	
	printf("--------------------------------------------------------------------\n\n\n");
	
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
	
	return 0;
}
