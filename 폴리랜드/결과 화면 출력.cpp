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
	printf("  ��¥       �̿��   ����     ���ɱ���  ����      ����      ������\n");
	
	for(int i = 0; i < count; i++)
	{
		printf("%d%02d%02d\t%d\t%d\t  %d\t  %d\t%8d\t%d\n", year[i], month[i], day[i], ArrticketSelect_voucher[i], ArrticketSelect_voucher_kind[i],
				ArrageCase[i], Arrcount[i], ArrpriceResult[i], ArrdiscountRate[i]);
	}

	printf("\n---------------------------------------------------------------------\n\n\n");
	printf("======================== �̿�� �� �Ǹ���Ȳ ========================\n\n");
	
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
	
	printf("�����̿�� �� %d��\n", amount_ticketselect_comp);
	printf("���� %d��, ���� %d��, ��� %d��, û�ҳ� %d��, � %d��, ���� %d��\n",
		  ticketselect_comp[5], ticketselect_comp[0], ticketselect_comp[1], ticketselect_comp[2], ticketselect_comp[3], ticketselect_comp[4]);
	printf("�����̿�� ���� : %d��\n\n", sales_comp);
	
	printf("��ũ�̿�� �� %d��\n", amount_ticketselect_park);
	printf("���� %d��, ���� %d��, ��� %d��, û�ҳ� %d��, � %d��, ���� %d��\n",
		  ticketselect_park[5], ticketselect_park[0], ticketselect_park[1], ticketselect_park[2], ticketselect_park[3], ticketselect_park[4]);
	printf("�����̿�� ���� : %d��\n\n", sales_park);	
	printf("--------------------------------------------------------------------\n\n\n");
	
	//���
	FILE *fp1 = fopen("�̿�Ǻ� �Ǹ� ����.csv", "a"); 
	fprintf(fp1, "����, �����̿��, ��ũ�̿��\n");
	fprintf(fp1, "%s,%d,%d\n", "����", ticketselect_comp[5], ticketselect_park[5]);
	fprintf(fp1, "%s,%d,%d\n", "����", ticketselect_comp[0], ticketselect_park[0]);
	fprintf(fp1, "%s,%d,%d\n", "���", ticketselect_comp[1], ticketselect_park[1]);
	fprintf(fp1, "%s,%d,%d\n", "û�ҳ�", ticketselect_comp[2], ticketselect_park[2]);
	fprintf(fp1, "%s,%d,%d\n", "�", ticketselect_comp[3], ticketselect_park[3]);
	fprintf(fp1, "%s,%d,%d\n", "����", ticketselect_comp[4], ticketselect_park[4]);
	fprintf(fp1, "%s,%d,%d\n", "�հ�", amount_ticketselect_comp, amount_ticketselect_park);
	fprintf(fp1, "%s,%d,%d\n", "����", sales_comp, sales_park);
	fclose(fp1);
	
	printf("===== ���� �Ǹ� ��Ȳ =====\n\n");
	
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
	
	printf("�� �Ǹ� Ƽ�ϼ�     :   %d��\n", totalSales);
	printf("��� ����          :   %d��\n", discount[0]);
	printf("�����             :   %d��\n", discount[1]);
	printf("����������         :   %d��\n", discount[2]);
	printf("�ް��庴           :   %d��\n", discount[3]);
	printf("�ӻ��             :   %d��\n", discount[4]);
	printf("�ٵ��� �ູī��    :   %d��\n\n", discount[5]);
	printf("----------------------------\n\n");	
	
	//���
	FILE *fp2 = fopen("���� �Ǹ� ����.csv", "a"); 
	fprintf(fp2, "%s,%d\n", "�� �Ǹ�Ƽ�ϼ�", totalSales);
	fprintf(fp2, "%s,%d\n", "��� ����", discount[0]);
	fprintf(fp2, "%s,%d\n", "�����", discount[1]);
	fprintf(fp2, "%s,%d\n", "����������", discount[2]);
	fprintf(fp2, "%s,%d\n", "�ް��庴", discount[3]);
	fprintf(fp1, "%s,%d\n", "�ӻ��", discount[4]);
	fprintf(fp1, "%s,%d\n", "�ٵ��� �ູī��", discount[5]);
	fclose(fp2);		
	
	return 0;
}
