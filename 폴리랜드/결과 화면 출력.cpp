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
		
	while(fscanf(fp, "%d,%d,%d,%d,%d,%d,%d,%d,%d", &year[count], &month[count], &day[count], &ArrticketSelect_voucher[count],
	&ArrticketSelect_voucher_kind[count], &ArrageCase[count], &Arrcount[count], &ArrpriceResult[count], &ArrdiscountRate[count]) != -1)
		{
				count++;
		}
	fclose(fp);
	
	printf("============================ report.csv =============================\n\n");
	printf("  ��¥       �̿��   ����     ���ɱ���  ����      ����      ������\n");
	
	for(int i = 0; i < count; i++)
	{
		printf("%d%02d%02d\t%d\t%d\t  %d\t  %d\t%8d\t%d\n", year[i], month[i], day[i], ArrticketSelect_voucher[i], ArrticketSelect_voucher_kind[i],
				ArrageCase[i], Arrcount[i], ArrpriceResult[i], ArrdiscountRate[i]);
	}

	printf("\n---------------------------------------------------------------------\n\n\n");
	printf("======================== �̿�� �� �Ǹ���Ȳ ========================\n\n");
	
	for(int index = 0; index < count; index++)
	{
		if(ArrticketSelect_voucher[index] == 1)
		{
			amount_ticketselect_comp ++;
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
			amount_ticketselect_park ++;
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
	
	printf("�����̿�� �� %d��\n", amount_ticketselect_comp);
	printf("���� %d��, ��� %d��, û�ҳ� %d��, � %d��, ���� %d��\n", baby_comp, child_comp, teen_comp, adult_comp, old_comp);
	printf("�����̿�� ���� : %d��\n\n", sales_comp);
	
	printf("��ũ�̿�� �� %d��\n", amount_ticketselect_park);
	printf("���� %d��, ��� %d��, û�ҳ� %d��, � %d��, ���� %d��\n", baby_park, child_park, teen_park, adult_park, old_park);
	printf("�����̿�� ���� : %d��\n\n", sales_park);	
	
	printf("--------------------------------------------------------------------\n\n\n");
	
	return 0;
}
