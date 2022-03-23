#include <stdio.h>

int main()
{
	FILE *fp = fopen("report.csv", "r");
	
	const int MAX = 100;
	int count = 0;
	int year[MAX], month[MAX], day[MAX], ArrticketSelect_voucher[MAX], ArrticketSelect_voucher_kind[MAX],
		ArrageCase[MAX], Arrcount[MAX], ArrpriceResult[MAX], ArrdiscountRate[MAX];
		
	int amount_ticketselect_comp = 0, amount_ticketselect_park = 0;
	int baby_comp = 0, child_comp = 0, teen_comp = 0, adult_comp = 0, old_comp = 0, newborn_comp = 0,
		baby_park = 0, child_park = 0, teen_park = 0, adult_park = 0, old_park = 0, newborn_park = 0;	
	int sales_comp = 0, sales_park = 0;
	
	int totalSales = 0,
		discount_no = 0, discount_disable = 0, discount_merit = 0, discount_army = 0, discount_pregnant = 0, discount_multichild = 0;
	
		
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
				baby_comp ++;
			}
			else if(ArrageCase[index] == 2)
			{
				child_comp ++;
			}
			else if(ArrageCase[index] == 3)
			{
				teen_comp ++;
			}
			else if(ArrageCase[index] == 4)
			{
				adult_comp ++;
			}
			else if(ArrageCase[index] == 5)
			{
				old_comp ++;
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
				baby_park ++;
			}
			else if(ArrageCase[index] == 2)
			{
				child_park ++;
			}
			else if(ArrageCase[index] == 3)
			{
				teen_park ++;
			}
			else if(ArrageCase[index] == 4)
			{
				adult_park ++;
			}
			else if(ArrageCase[index] == 5)
			{
				old_park ++;
			}
			else
			{
				amount_ticketselect_park --;
			}
		}		
	}
	
	printf("종합이용권 총 %d매\n", amount_ticketselect_comp);
	printf("유아 %d매, 어린이 %d매, 청소년 %d매, 어른 %d매, 노인 %d매\n", baby_comp, child_comp, teen_comp, adult_comp, old_comp);
	printf("종합이용권 매출 : %d원\n\n", sales_comp);
	
	printf("파크이용권 총 %d매\n", amount_ticketselect_park);
	printf("유아 %d매, 어린이 %d매, 청소년 %d매, 어른 %d매, 노인 %d매\n", baby_park, child_park, teen_park, adult_park, old_park);
	printf("종합이용권 매출 : %d원\n\n", sales_park);	
	printf("--------------------------------------------------------------------\n\n\n");
	
	printf("===== 우대권 판매 현황 =====\n\n");
	
	for(int index = 0; index < count; index++)
	{
		totalSales += Arrcount[index];
		
		if(ArrdiscountRate[index] == 1)
		{
			discount_no += Arrcount[index];
		}
		else if(ArrdiscountRate[index] == 2)
		{
			discount_disable += Arrcount[index];
		}
		else if(ArrdiscountRate[index] == 3)
		{
			discount_merit += Arrcount[index];
		}
		else if(ArrdiscountRate[index] == 4)
		{
			discount_army += Arrcount[index];
		}
		else if(ArrdiscountRate[index] == 5)
		{
			discount_pregnant += Arrcount[index];
		}
		else
		{
			discount_multichild += Arrcount[index];
		}
	}
	
	printf("총 판매 티켓수     :   %d매\n", totalSales);
	printf("우대 없음          :   %d매\n", discount_no);
	printf("장애인             :   %d매\n", discount_disable);
	printf("국가유공자         :   %d매\n", discount_merit);
	printf("휴가장병           :   %d매\n", discount_army);
	printf("임산부             :   %d매\n", discount_pregnant);
	printf("다둥이 행복카드    :   %d매\n\n", discount_multichild);
	printf("----------------------------\n\n");			
	
	return 0;
}
