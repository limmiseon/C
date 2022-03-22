#include <stdio.h>
#include <time.h>
#include <stdbool.h>

int main ()
{
	int index = 0;
	int index_end = 0;
	
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
	int ticketSelect_voucher[10] = {0};
	int ticketSelect_voucher_kind[10] = {0};
	
	int priceResult[10] = {0};
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
	int koreanAge = 0, age[10] = {0};
	
	const int
	TWO_DIGIT = 100, ONE_DIGIT = 10,
	OLD_GENERATION = 1900, NEW_GENERATION = 2000,
	MALE_OLD = 1, FEMALE_OLD = 2, MALE_NEW = 3, FEMAIL_NEW = 4;

	//�ִ� �ֹ���
	int count[10] = {0};
	const int
	MAX_COUNT = 10, MIN_COUNT = 1;	
	
	//�����̿�� ������ 	
	int discountRate[10] = {0};
	
	const float
	DISABLE_DISCOUNT_RATE = 0.5, MERIT_DISCOUNT_RATE = 0.5, COMP_ARMY_DISCOUNT_RATE = 0.51,
	COMP_PREGNANT_DISCOUNT_RATE = 0.5, COMP_MULTICHILD_DISCOUNT_RATE = 0.7;
	
	//�̾ �ֹ�
	int continueSelect = 0;
	
	while(true){
		
		printf("�̿���� �����ϼ���.\n1. �����̿��\n2. ��ũ�̿��\n");
			while(true){
				scanf("%d", &ticketSelect_voucher[index]);
					if(ticketSelect_voucher[index] == 1 || ticketSelect_voucher[index] == 2){
						break;
					}
					else{
						printf("�ٽ� �Է����ּ���.\n");	
					}
			}
		printf("������ �����ϼ���.\n1. �ְ���\n2. �߰���\n");
			while(true){
				scanf("%d", &ticketSelect_voucher_kind[index]);
					if(ticketSelect_voucher_kind[index] == 1 || ticketSelect_voucher_kind[index] == 2){
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
				scanf("%d", &count[index]);
					if(count[index] <= MAX_COUNT || count[index] >= MIN_COUNT){
						break;
					}	
					else{
						printf("�ٽ� �Է����ּ���.\n");
					}
			}
		printf("�������� �����ϼ���.\n1. ���� (���� ���� �ڵ�ó��)\n2. �����\n3. ����������\n4. �ް��庴\n5. �ӻ��\n6. �ٵ��� �ູī��\n");
			while(true){
				scanf("%d", &discountRate[index]);
					if(discountRate[index] >=1 || discountRate[index] <=6){
						break;
					}
					else{
						printf("�ٽ� �Է����ּ���.\n");
					}
			}
		
		
		//�̿�� ���� 
		if(ticketSelect_voucher[index] == 1){
			if(ticketSelect_voucher_kind[index] == 1)
			{
				ticketSelect = 1;
			}
			else if( ticketSelect_voucher_kind[index] == 2)
			{
				ticketSelect = 2;
			}
		}
		else if(ticketSelect_voucher[index] == 2){
			if(ticketSelect_voucher_kind[index] == 1){
				ticketSelect = 3;
			}
			else if(ticketSelect_voucher_kind[index] == 2){
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
		
		//���� ��¥ ���ϱ�
		int todayYear = 0, todayMonth = 0, todayDay = 0;
		
		time_t current;
		time(&current);
		struct tm* structTime;
		structTime = localtime(&current);
		
		todayYear = structTime->tm_year + OLD_GENERATION;
		todayMonth = structTime->tm_mon + 1;
		todayDay = structTime->tm_mday;
		
		koreanAge = todayYear - customerYear + 1;
		
		//������ ��� 
		if(customerMonth < todayMonth || customerMonth == todayMonth && customerDay <= todayDay){
			age[index] = koreanAge - 1;
		}
		else{
			age[index] = koreanAge - 2;
		}
		
		//Ƽ�ϰ� ���̿� ���� �ݾ� ���
		int calcPrice = 0;
		
		if(age[index] < 3){
			if(ticketSelect == 1){
				calcPrice = COMP_BABY_1DAY_PRICE;
			}
			else if(ticketSelect == 2){
				calcPrice = COMP_BABY_AFTER4_PRICE;
			}
			else if(ticketSelect == 3){
				calcPrice = PARK_BABY_1DAY_PRICE;
			}
			else if(ticketSelect == 4){
				calcPrice = PARK_BABY_AFTER4_PRICE;
			}
		}
		if(age[index] >= 3 && age[index] <= 12){
			if(ticketSelect == 1){
				calcPrice = COMP_CHILD_1DAY_PRICE;
			}
			else if(ticketSelect == 2){
				calcPrice = COMP_CHILD_AFTER4_PRICE;		
			}
			else if(ticketSelect == 3){
				calcPrice = PARK_CHILD_1DAY_PRICE;
			}
			else if(ticketSelect == 4){
				calcPrice = PARK_CHILD_AFTER4_PRICE;
			}
		}
		if(age[index] >= 13 && age[index] <= 18){
			if(ticketSelect == 1){
				calcPrice = COMP_TEEN_1DAY_PRICE;
			}
			else if(ticketSelect == 2){
				calcPrice = COMP_TEEN_AFTER4_PRICE;		
			}
			else if(ticketSelect == 3){
				calcPrice = PARK_TEEN_1DAY_PRICE;
			}
			else if(ticketSelect == 4){
				calcPrice = PARK_TEEN_AFTER4_PRICE;
			}
		}
		if(age[index] >= 19 && age[index] <= 64){
			if(ticketSelect == 1){
				calcPrice = COMP_ADULT_1DAY_PRICE;
			}
			else if(ticketSelect == 2){
				calcPrice = COMP_ADULT_AFTER4_PRICE;		
			}
			else if(ticketSelect == 3){
				calcPrice = PARK_ADULT_1DAY_PRICE;
			}
			else if(ticketSelect == 4){
				calcPrice = PARK_ADULT_AFTER4_PRICE;
			}
		}
		if(age[index] > 64){
			if(ticketSelect == 1){
				calcPrice = COMP_OLD_1DAY_PRICE;
			}
			else if(ticketSelect == 2){
				calcPrice = COMP_OLD_AFTER4_PRICE;		
			}
			else if(ticketSelect == 3){
				calcPrice = PARK_OLD_1DAY_PRICE;
			}
			else if(ticketSelect == 4){
				calcPrice = PARK_OLD_AFTER4_PRICE;
			}
		}
		
		//������ ����	
		if(discountRate[index] == 2){
			calcPrice *= DISABLE_DISCOUNT_RATE;
		}
		else if(discountRate[index] == 3){
			calcPrice *= MERIT_DISCOUNT_RATE;
		}
		if(ticketSelect == 1 || ticketSelect == 2){
			if(discountRate[index] == 4){
				calcPrice *= COMP_ARMY_DISCOUNT_RATE;
			}
			else if(discountRate[index] == 5){
				calcPrice *= COMP_PREGNANT_DISCOUNT_RATE;
			}
			else if(discountRate[index] == 6){
				calcPrice *= COMP_MULTICHILD_DISCOUNT_RATE;
			}
		}
		priceResult[index] = calcPrice * count[index];
		
		printf("������ %d �� �Դϴ�.\n�����մϴ�.\n\n", priceResult[index]);
		printf("��� �߱� �Ͻðڽ��ϱ�?\n1. Ƽ�� �߱�\n2. ����\n");
		scanf("%d", &continueSelect); 
		
		totalprice += priceResult[index];
		
		if(continueSelect == 2){
			printf("Ƽ�� �߱��� �����մϴ�. �����մϴ�. \n\n");
			break; 
		}
		
		index_end++;
		index++;
	}
	// ��� 
	printf("========================== �������� ==========================\n");
	
	for(index = 0; index <= index_end; index++)
	{
		switch(ticketSelect_voucher[index])
		{
			case 1:
				printf("�����̿�� ");
				break;
			case 2:
				printf("��ũ�̿�� ");
				break;
		}
		switch(ticketSelect_voucher_kind[index])
		{
			case 1:
				printf("�ְ��� ");
				break;
			case 2:
				printf("�߰��� ");
				break;
		}		
		
		if(age[index] < 3)
		{
			printf("���� ");
		}
		else if((age[index] >= 3) && (age[index] <= 12))
		{
			printf("��� ");
		}
		else if((age[index] >= 13) && (age[index] <= 18))
		{
			printf("û�ҳ� ");
		}
		else if((age[index] >= 19 && age[index] <= 64))
		{
			printf("� ");
		}
		else
		{
			printf("���� ");
		}
		
		printf("X %d ", count[index]);
		printf("%d�� ", priceResult[index]);
		
		switch(discountRate[index])
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
	printf("\n"); 
	printf("����� �Ѿ��� %d�� �Դϴ�.\n", totalprice);
	printf("==============================================================\n");
	
	return 0;
}


