#include <stdio.h>
#include <time.h>
#include <stdbool.h>

int main ()
{	
	//배열 선언
	int
	ArrticketSelect_voucher[10] = {0}, ArrticketSelect_voucher_kind[10] = {0},
	Arrage[10] = {0}, Arrcount[10] = {0},
	ArrpriceResult[10] = {0}, ArrdiscountRate[10] = {0}, Arrtotalprice[10] = {0};
	
	int
	index = 0;
	 
	//티켓 가격 
	const int
	//종합이용권 권종별 가격 
	COMP_ADULT_1DAY_PRICE = 59000, COMP_ADULT_AFTER4_PRICE = 48000,
	COMP_TEEN_1DAY_PRICE = 52000, COMP_TEEN_AFTER4_PRICE = 42000,
	COMP_CHILD_1DAY_PRICE = 47000, COMP_CHILD_AFTER4_PRICE = 36000,
	COMP_BABY_1DAY_PRICE = 15000, COMP_BABY_AFTER4_PRICE = 15000,
	COMP_OLD_1DAY_PRICE = 47000, COMP_OLD_AFTER4_PRICE = 36000,
	
	//파크이용권 권종별 가격 
	PARK_ADULT_1DAY_PRICE = 56000, PARK_ADULT_AFTER4_PRICE = 45000,
	PARK_TEEN_1DAY_PRICE = 50000, PARK_TEEN_AFTER4_PRICE = 40000,
	PARK_CHILD_1DAY_PRICE = 46000, PARK_CHILD_AFTER4_PRICE = 35000,
	PARK_BABY_1DAY_PRICE = 15000, PARK_BABY_AFTER4_PRICE = 15000,
	PARK_OLD_1DAY_PRICE = 46000, PARK_OLD_AFTER4_PRICE = 35000;
	
	int ticketSelect = 0, ticketSelect_voucher = 0, ticketSelect_voucher_kind = 0,
		calcPrice = 0, priceResult = 0, totalprice = 0;
	
	//주민등록번호 분석
	long long int IDNumber = 0;
	
	const long long int
	FULL_DIGIT = 10000000000000,
	FULL_DIGIT_MIN = 10000000000,
	SEVEN_DIGIT = 1000000;
	
	int calcIDNumber = 0; //생년월일
	int customerYear = 0, customerMonth = 0, customerDay = 0; // 구매자 생년월일
	int type = 0; //2000년생 구분
	int koreanAge = 0, age = 0; //만나이 계산 
	
	const int
	TWO_DIGIT = 100, ONE_DIGIT = 10,
	OLD_GENERATION = 1900, NEW_GENERATION = 2000,
	MALE_OLD = 1, FEMALE_OLD = 2, MALE_NEW = 3, FEMAIL_NEW = 4;

	//최대 주문량
	int count = 0;
	const int
	MAX_COUNT = 10, MIN_COUNT = 1;	
	
	//종합이용권 할인율 	
	int discountRate = 0;
	
	const float
	DISABLE_DISCOUNT_RATE = 0.5, MERIT_DISCOUNT_RATE = 0.5, COMP_ARMY_DISCOUNT_RATE = 0.51,
	COMP_PREGNANT_DISCOUNT_RATE = 0.5, COMP_MULTICHILD_DISCOUNT_RATE = 0.7;
	
	//이어서 주문
	int continueSelect = 0, countinueSelect2 = 0;
	
	while(true)
	{
		//변수 초기화 
		index = 0,
		totalprice = 0;
	
		while(true)
		{
			//변수 초기화 
			ticketSelect_voucher = 0, ticketSelect_voucher_kind = 0,
			age = 0, count = 0,
			priceResult = 0, discountRate = 0;
			
			printf("이용권을 선택하세요.\n1. 종합이용권\n2. 파크이용권\n");
				while(true){
					scanf("%d", &ticketSelect_voucher);
						if(ticketSelect_voucher == 1 || ticketSelect_voucher == 2){
							break;
						}
						else{
							printf("다시 입력해주세요.\n");	
						}
				}
			printf("권종을 선택하세요.\n1. 주간권\n2. 야간권\n");
				while(true){
					scanf("%d", &ticketSelect_voucher_kind);
						if(ticketSelect_voucher_kind == 1 || ticketSelect_voucher_kind == 2){
							break;
						}
						else{
							printf("다시 입력해주세요.\n");
						}
				}
			printf("주민번호를 입력하세요.\n");
				while(true){
					scanf("%lld", &IDNumber);
						if(IDNumber >= FULL_DIGIT_MIN && IDNumber < FULL_DIGIT){
							break;
						}
						else{
							printf("다시 입력해주세요.\n");
						}
				}
			printf("몇개를 주문하시겠습니까? (최대 10개)\n");
				while(true){
					scanf("%d", &count);
						if(count <= MAX_COUNT || count >= MIN_COUNT){
							break;
						}	
						else{
							printf("다시 입력해주세요.\n");
						}
				}
			printf("우대사항을 선택하세요.\n1. 없음 (나이 우대는 자동처리)\n2. 장애인\n3. 국가유공자\n4. 휴가장병\n5. 임산부\n6. 다둥이 행복카드\n");
				while(true){
					scanf("%d", &discountRate);
						if(discountRate >=1 || discountRate <=6){
							break;
						}
						else{
							printf("다시 입력해주세요.\n");
						}
				}
			
			
			//이용권 선택 
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
			
			//주민번호 분석
			IDNumber += FULL_DIGIT;
			calcIDNumber = IDNumber / SEVEN_DIGIT;
			type = calcIDNumber % 10; //뒷자리 첫 번호
			calcIDNumber /= ONE_DIGIT;
			customerDay = calcIDNumber % TWO_DIGIT; //일
			calcIDNumber /= TWO_DIGIT;
			customerMonth = calcIDNumber % TWO_DIGIT; //월
			calcIDNumber /= TWO_DIGIT;
			customerYear = calcIDNumber % TWO_DIGIT; //년도
			
			if(type == MALE_OLD || type == FEMALE_OLD){
				customerYear += OLD_GENERATION;		
			}
			else{
				customerYear += NEW_GENERATION;
			}
			
			//오늘 날짜 구하기
			int todayYear = 0, todayMonth = 0, todayDay = 0;
			
			time_t current;
			time(&current);
			struct tm* structTime;
			structTime = localtime(&current);
			
			todayYear = structTime->tm_year + OLD_GENERATION;
			todayMonth = structTime->tm_mon + 1;
			todayDay = structTime->tm_mday;
			
			koreanAge = todayYear - customerYear + 1;
			
			//만나이 계산 
			if(customerMonth < todayMonth || customerMonth == todayMonth && customerDay <= todayDay){
				age = koreanAge - 1;
			}
			else{
				age = koreanAge - 2;
			}
			
			//티켓과 나이에 따른 금액 계산
			int calcPrice = 0;
			
			if(age < 3){
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
			if(age >= 3 && age <= 12){
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
			if(age >= 13 && age <= 18){
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
			if(age >= 19 && age <= 64){
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
			if(age > 64){
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
			
			//우대사항 할인	
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
			
			printf("가격은 %d 원 입니다.\n감사합니다.\n\n", priceResult);
			printf("계속 발권 하시겠습니까?\n1. 티켓 발권\n2. 종료\n");
			scanf("%d", &continueSelect); 
			
			totalprice += priceResult;
			
			ArrticketSelect_voucher[index] = ticketSelect_voucher;
			ArrticketSelect_voucher_kind[index] = ticketSelect_voucher_kind;
			Arrage[index] = age;
			Arrcount[index] = count;
			ArrpriceResult[index] = priceResult;
			ArrdiscountRate[index] = discountRate;
				
			index++;		
			
			if(continueSelect == 2){
				printf("티켓 발권을 종료합니다. 감사합니다. \n\n");
				break; 
			}	
		}
		FILE *filePointer = fopen("report.csv", "a");
		
		//영수증 출력 
		printf("========================== 폴리랜드 ==========================\n");
		
		for(int i = 0; i < index; i++)
		{
			fprintf(filePointer, "%d,%d,%d,%d,%d\n", ArrticketSelect_voucher[i], ArrticketSelect_voucher_kind[i], Arrage[i],
														Arrcount[i], ArrpriceResult[i]);
			switch(ArrticketSelect_voucher[i])
			{
				case 1:
					printf("종합이용권 ");
					break;
				case 2:
					printf("파크이용권 ");
					break;
			}
			switch(ArrticketSelect_voucher_kind[i])
			{
				case 1:
					printf("주간권 ");
					break;
				case 2:
					printf("야간권 ");
					break;
			}		
			
			if(Arrage[i] < 3)
			{
				printf("유아 ");
			}
			else if(Arrage[i] >= 3 && Arrage[i] <= 12)
			{
				printf("어린이 ");
			}
			else if(Arrage[i] >= 13 && Arrage[i] <= 18)
			{
				printf("청소년 ");
			}
			else if(Arrage[i] >= 19 && Arrage[i] <= 64)
			{
				printf("어른 ");
			}
			else
			{
				printf("노인 ");
			}
			
			printf("X %d ", Arrcount[i]);
			printf("%d원 ", ArrpriceResult[i]);
			
			switch(ArrdiscountRate[i])
			{
				case 1:
					printf("*우대적용 없음\n");
					break;
				case 2:
					printf("*장애인 우대적용\n");
					break;
				case 3:
					printf("*국가유공자 우대적용\n");
					break;
				case 4:
					printf("*휴가장병 우대적용\n");
					break;
				case 5:
					printf("*임산부 우대적용\n");
					break;
				case 6:
					printf("*다둥이 행복카드 우대적용\n");
					break;																
			}
		}
		fclose(filePointer);
		printf("\n"); 
		printf("입장료 총액은 %d원 입니다.\n", totalprice);
		printf("==============================================================\n\n");
			
		printf("계속 진행(1: 새로운 주문, 2: 프로그램 종료) : ");
		scanf("%d", &countinueSelect2);
		
		if(countinueSelect2 == 2)
		{
			break;
		}
	}
	return 0;
}

