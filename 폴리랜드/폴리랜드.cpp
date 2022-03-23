#include <stdio.h>
#include <time.h>
#include <stdbool.h>

int main ()
{	
	//�迭 ����
	int
	ArrticketSelect_voucher[10] = {0}, ArrticketSelect_voucher_kind[10] = {0},
	Arrage[10] = {0}, ArrageCase[10] = {0},
	Arrcount[10] = {0}, ArrpriceResult[10] = {0}, ArrdiscountRate[10] = {0}, Arrtotalprice[10] = {0};
	
	int
	index = 0;
	 
	const int
	//�����̿�� ������ ���� 
	COMP_ADULT_1DAY_PRICE = 59000, COMP_ADULT_AFTER4_PRICE = 48000,
	COMP_TEEN_1DAY_PRICE = 52000, COMP_TEEN_AFTER4_PRICE = 42000,
	COMP_CHILD_1DAY_PRICE = 47000, COMP_CHILD_AFTER4_PRICE = 36000,
	COMP_BABY_1DAY_PRICE = 15000, COMP_BABY_AFTER4_PRICE = 15000,
	COMP_OLD_1DAY_PRICE = 47000, COMP_OLD_AFTER4_PRICE = 36000,
	
	//��ũ�̿�� ������ ���� 
	PARK_ADULT_1DAY_PRICE = 56000, PARK_ADULT_AFTER4_PRICE = 45000,
	PARK_TEEN_1DAY_PRICE = 50000, PARK_TEEN_AFTER4_PRICE = 40000,
	PARK_CHILD_1DAY_PRICE = 46000, PARK_CHILD_AFTER4_PRICE = 35000,
	PARK_BABY_1DAY_PRICE = 15000, PARK_BABY_AFTER4_PRICE = 15000,
	PARK_OLD_1DAY_PRICE = 46000, PARK_OLD_AFTER4_PRICE = 35000;
	
	int ticketSelect = 0;
	int ticketSelect_voucher = 0;
	int ticketSelect_voucher_kind = 0;
	
	int priceResult = 0;
	int totalprice = 0;
	
	//�ֹε�Ϲ�ȣ �м�
	long long int IDNumber = 0;
	
	const long long int
	FULL_DIGIT = 10000000000000,
	FULL_DIGIT_MIN = 10000000000,
	SEVEN_DIGIT = 1000000;
	
	int calcIDNumber = 0; //�������
	int customerYear = 0, customerMonth = 0, customerDay = 0; // ������ �������
	int type = 0; //2000��� ����
	int koreanAge = 0, age = 0; //������ ��� 
	int ageCase = 0;
	
	const int
	TWO_DIGIT = 100, ONE_DIGIT = 10,
	OLD_GENERATION = 1900, NEW_GENERATION = 2000,
	MALE_OLD = 1, FEMALE_OLD = 2, MALE_NEW = 3, FEMAIL_NEW = 4,
	
	MIN_BABY = 1, MIN_CHILD = 3, MIN_TEEN = 13, MIN_ADULT = 19,
				  MAX_CHILD = 12, MAX_TEEN = 18, MAX_ADULT = 64;
				  
	//���� ��¥ ���ϱ�
	int todayYear = 0, todayMonth = 0, todayDay = 0;
			
	time_t timer;
	struct tm* t;
	timer = time(NULL);
	t = localtime(&timer);
			
	todayYear = t->tm_year + OLD_GENERATION;
	todayMonth = t->tm_mon + 1;
	todayDay = t->tm_mday; 

	//�ִ� �ֹ���
	int count = 0;
	const int
	MAX_COUNT = 10, MIN_COUNT = 1;	
	
	//�����̿�� ������ 	
	int discountRate = 0;
	
	const float
	DISABLE_DISCOUNT_RATE = 0.5, MERIT_DISCOUNT_RATE = 0.5, COMP_ARMY_DISCOUNT_RATE = 0.51,
	COMP_PREGNANT_DISCOUNT_RATE = 0.5, COMP_MULTICHILD_DISCOUNT_RATE = 0.7;
	
	//�̾ �ֹ�
	int continueSelect = 0, countinueSelect2 = 0;
	
	while(true)
	{
		//���� �ʱ�ȭ 
		index = 0,
		totalprice = 0;
	
		while(true){
			//���� �ʱ�ȭ 
			ticketSelect_voucher = 0, ticketSelect_voucher_kind = 0,
			age = 0, count = 0,
			priceResult = 0, discountRate = 0;
			
			printf("�̿���� �����ϼ���.\n1. �����̿��\n2. ��ũ�̿��\n");
				while(true){
					scanf("%d", &ticketSelect_voucher);
						if(ticketSelect_voucher == 1 || ticketSelect_voucher == 2){
							break;
						}
						else{
							printf("�ٽ� �Է����ּ���.\n");	
						}
				}
			printf("������ �����ϼ���.\n1. �ְ���\n2. �߰���\n");
				while(true){
					scanf("%d", &ticketSelect_voucher_kind);
						if(ticketSelect_voucher_kind == 1 || ticketSelect_voucher_kind == 2){
							break;
						}
						else{
							printf("�ٽ� �Է����ּ���.\n");
						}
				}
			printf("�ֹι�ȣ�� �Է��ϼ���.\n");
				while(true){
					scanf("%lld", &IDNumber);
						if(IDNumber >= FULL_DIGIT_MIN && IDNumber < FULL_DIGIT){
							break;
						}
						else{
							printf("�ٽ� �Է����ּ���.\n");
						}
				}
			printf("��� �ֹ��Ͻðڽ��ϱ�? (�ִ� 10��)\n");
				while(true){
					scanf("%d", &count);
						if(count <= MAX_COUNT || count >= MIN_COUNT){
							break;
						}	
						else{
							printf("�ٽ� �Է����ּ���.\n");
						}
				}
			printf("�������� �����ϼ���.\n1. ���� (���� ���� �ڵ�ó��)\n2. �����\n3. ����������\n4. �ް��庴\n5. �ӻ��\n6. �ٵ��� �ູī��\n");
				while(true){
					scanf("%d", &discountRate);
						if(discountRate >=1 || discountRate <=6){
							break;
						}
						else{
							printf("�ٽ� �Է����ּ���.\n");
						}
				}
			
			
			//�̿�� ���� 
			if(ticketSelect_voucher == 1){
				if(ticketSelect_voucher_kind == 1)
				{
					ticketSelect = 1;
				}
				else if( ticketSelect_voucher_kind == 2)
				{
					ticketSelect = 2;
				}
			}
			if(ticketSelect_voucher == 2){
				if(ticketSelect_voucher_kind == 1){
					ticketSelect = 3;
				}
				else if(ticketSelect_voucher_kind == 2){
					ticketSelect = 4;
				}	
			} 
			
			//�ֹι�ȣ �м�
			
			IDNumber += FULL_DIGIT;
			calcIDNumber = IDNumber / SEVEN_DIGIT;
			type = calcIDNumber % 10; //���ڸ� ù ��ȣ
			calcIDNumber /= ONE_DIGIT;
			customerDay = calcIDNumber % TWO_DIGIT; //��
			calcIDNumber /= TWO_DIGIT;
			customerMonth = calcIDNumber % TWO_DIGIT; //��
			calcIDNumber /= TWO_DIGIT;
			customerYear = calcIDNumber % TWO_DIGIT; //�⵵
			
			if(type == MALE_OLD || type == FEMALE_OLD){
				customerYear += OLD_GENERATION;		
			}
			else{
				customerYear += NEW_GENERATION;
			}
			
			koreanAge = todayYear - customerYear + 1;
			
			//������ ��� 
			if(customerMonth < todayMonth || customerMonth == todayMonth && customerDay <= todayDay){
				age = koreanAge - 1;
			}
			else{
				age = koreanAge - 2;
			}
			//���� ���̽�
			if(age < MIN_CHILD && age >= MIN_BABY)//���� 
			{
				ageCase = 1;
			}
			else if(age < MAX_CHILD && age >= MIN_CHILD)//��� 
			{
				ageCase = 2;
			}
			else if(age < MAX_TEEN && age >= MIN_TEEN)//û�ҳ� 
			{
				ageCase = 3;
			}
			else if(age < MAX_ADULT && age >= MIN_ADULT)//� 
			{
				ageCase = 4;
			}
			else if(age > 64)//���� 
			{
				ageCase = 5;
			}
			else{//(age < MIN_BABY) ���� 
				ageCase = 6;
			}
			//Ƽ�ϰ� ���̿� ���� �ݾ� ���
			int calcPrice = 0;
			
			if(ageCase == 1){
				if(ticketSelect == 1){
					calcPrice = COMP_BABY_1DAY_PRICE;
				}
				else if(ticketSelect == 2){
					calcPrice = COMP_BABY_AFTER4_PRICE;
				}
				else if(ticketSelect == 3){
					calcPrice = PARK_BABY_1DAY_PRICE;
				}
				else{//(ticketSelect == 4)
					calcPrice = PARK_BABY_AFTER4_PRICE;
				}
			}
			if(ageCase == 2){
				if(ticketSelect == 1){
					calcPrice = COMP_CHILD_1DAY_PRICE;
				}
				else if(ticketSelect == 2){
					calcPrice = COMP_CHILD_AFTER4_PRICE;		
				}
				else if(ticketSelect == 3){
					calcPrice = PARK_CHILD_1DAY_PRICE;
				}
				else{//(ticketSelect == 4)
					calcPrice = PARK_CHILD_AFTER4_PRICE;
				}
			}
			if(ageCase == 3){
				if(ticketSelect == 1){
					calcPrice = COMP_TEEN_1DAY_PRICE;
				}
				else if(ticketSelect == 2){
					calcPrice = COMP_TEEN_AFTER4_PRICE;		
				}
				else if(ticketSelect == 3){
					calcPrice = PARK_TEEN_1DAY_PRICE;
				}
				else{//(ticketSelect == 4)
					calcPrice = PARK_TEEN_AFTER4_PRICE;
				}
			}
			if(ageCase == 4){
				if(ticketSelect == 1){
					calcPrice = COMP_ADULT_1DAY_PRICE;
				}
				else if(ticketSelect == 2){
					calcPrice = COMP_ADULT_AFTER4_PRICE;		
				}
				else if(ticketSelect == 3){
					calcPrice = PARK_ADULT_1DAY_PRICE;
				}
				else{//(ticketSelect == 4)
					calcPrice = PARK_ADULT_AFTER4_PRICE;
				}
			}
			if(ageCase == 5){
				if(ticketSelect == 1){
					calcPrice = COMP_OLD_1DAY_PRICE;
				}
				else if(ticketSelect == 2){
					calcPrice = COMP_OLD_AFTER4_PRICE;		
				}
				else if(ticketSelect == 3){
					calcPrice = PARK_OLD_1DAY_PRICE;
				}
				else{//(ticketSelect == 4)
					calcPrice = PARK_OLD_AFTER4_PRICE;
				}
			}
			
			//������ ����	
			if(discountRate == 2){
				calcPrice *= DISABLE_DISCOUNT_RATE;
			}
			if(discountRate == 3){
				calcPrice *= MERIT_DISCOUNT_RATE;
			}
			if(ticketSelect == 1 || ticketSelect == 2){
				if(discountRate == 4){
					calcPrice *= COMP_ARMY_DISCOUNT_RATE;
				}
				else if(discountRate == 5){
					calcPrice *= COMP_PREGNANT_DISCOUNT_RATE;
				}
				else if(discountRate == 6){
					calcPrice *= COMP_MULTICHILD_DISCOUNT_RATE;
				}
			}
			priceResult = calcPrice * count;
			
			printf("������ %d �� �Դϴ�.\n�����մϴ�.\n\n", priceResult);
			printf("��� �߱� �Ͻðڽ��ϱ�?\n1. Ƽ�� �߱�\n2. ����\n");
			scanf("%d", &continueSelect); 
			
			totalprice += priceResult;
			
			ArrticketSelect_voucher[index] = ticketSelect_voucher;
			ArrticketSelect_voucher_kind[index] = ticketSelect_voucher_kind;
			ArrageCase[index] = ageCase;
			Arrcount[index] = count;
			ArrpriceResult[index] = priceResult;
			ArrdiscountRate[index] = discountRate;
				
			index++;		
			
			if(continueSelect == 2){
				printf("Ƽ�� �߱��� �����մϴ�. �����մϴ�. \n\n");
				break; 
			}	
		}
		FILE *filePointer = fopen("report.csv", "a");
		 
		//��� 
		printf("========================== �������� ==========================\n");
		
		for(int i = 0; i < index; i++)
		{
			fprintf(filePointer, "%d,%02d,%02d,%d,%d,%d,%d,%d,%d\n", t->tm_year+1900, t->tm_mon+1, t->tm_mday, ArrticketSelect_voucher[i],
			ArrticketSelect_voucher_kind[i], ArrageCase[i], Arrcount[i], ArrpriceResult[i],ArrdiscountRate[i]);
			switch(ArrticketSelect_voucher[i])
			{
				case 1:
					printf("�����̿�� ");
					break;
				case 2:
					printf("��ũ�̿�� ");
					break;
			}
			switch(ArrticketSelect_voucher_kind[i])
			{
				case 1:
					printf("�ְ��� ");
					break;
				case 2:
					printf("�߰��� ");
					break;
			}		
			
			if(ArrageCase[i] == 1)
			{
				printf("���� ");
			}
			else if(ArrageCase[i] == 2)
			{
				printf("��� ");
			}
			else if(Arrage[i] == 3)
			{
				printf("û�ҳ� ");
			}
			else if(Arrage[i] == 4)
			{
				printf("� ");
			}
			else if(Arrage[i] == 5)
			{
				printf("���� ");
			}
			else//(Arrage[i] == 6)
			{
				printf("���� ");
			}
			
			printf("X %d ", Arrcount[i]);
			printf("%d�� ", ArrpriceResult[i]);
			
			switch(ArrdiscountRate[i])
			{
				case 1:
					printf("*������� ����\n");
					break;
				case 2:
					printf("*����� �������\n");
					break;
				case 3:
					printf("*���������� �������\n");
					break;
				case 4:
					printf("*�ް��庴 �������\n");
					break;
				case 5:
					printf("*�ӻ�� �������\n");
					break;
				case 6:
					printf("*�ٵ��� �ູī�� �������\n");
					break;																
			}
		}
		fclose(filePointer);
		printf("\n"); 
		printf("����� �Ѿ��� %d�� �Դϴ�.\n", totalprice);
		printf("==============================================================\n\n");
			
		printf("��� ����(1: ���ο� �ֹ�, 2: ���α׷� ����) : ");
		scanf("%d", &countinueSelect2);
		
		if(countinueSelect2 == 2)
		{
			break;
		}
	}
	return 0;
}

