#include <stdio.h>
#include <time.h>
#include <stdbool.h>

int main()
{
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
	
	//주민등록번호 분석
	const long long int
	FULL_DIGIT = 10000000000000,
	FULL_DIGIT_MIN = 10000000000,
	SEVEN_DIGIT = 1000000;
	
	const int
	TWO_DIGIT = 100, ONE_DIGIT = 10,
	OLD_GENERATION = 1900, NEW_GENERATION = 2000,
	MALE_OLD = 1, FEMALE_OLD = 2, MALE_NEW = 3, FEMAIL_NEW = 4,
	BEFORE_BIRTH = 2, AFTER_BIRTH = 1;
	
	
	const int
	//나이에 따른 범위
	MIN_BABY = 1, MIN_CHILD = 3, MIN_TEEN = 13, MIN_ADULT = 19,
	MAX_CHILD = 12, MAX_TEEN = 18, MAX_ADULT = 64,
	
	//나이에 따른 그룹
	BABY = 1, CHILD = 2, TEEN = 3, ADULT = 4, OLD = 5;
	
	
	const float
	//종합이용권 할인율 
	COMP_DISABLE_DISCOUNT_RATE = 0.5, COMP_MERIT_DISCOUNT_RATE = 0.5, COMP_ARMY_DISCOUNT_RATE = 0.49,
	COMP_PREGNANT_DISCOUNT_RATE = 0.5, COMP_MULTICHILD_DISCOUNT_RATE = 0.3,
	
	//파크이용권 할인율
	PARK_DISABLE_DISCOUNT_RATE = 0.5, PARK_MERIT_DISCOUNT_RATE = 0.5;
	
	//최대 주문량
	const int
	MAX_COUNT = 10, MIN_COUNT = 1;	 
	
	int inputTicketSelect()
	{
	int ticketSelect = 0;
	int ticketSelect_voucher = 0;
	int ticketSelect_voucher_kind = 0;
	
	
	
	printf("이용권을 선택하세요.\n1. 종합이용권\n2. 파크이용권");
	
	while(true)
	{
		scanf("%d", ticketSelect_voucher);
		if(ticketSelect_voucher == 1)
			{
				printf("권종을 선택하세요.\n1. 주간권\n2. 야간권");
				scanf("%d", ticketSelect_voucher_kind);
				if(ticketSelect_voucher == 1 && ticketSelect_voucher_kind == 1)
				{
					ticketSelect = 1;
					break;
				}
				else if(ticketSelect_voucher == 1 && ticketSelect_voucher_kind == 2)
				{
					ticketSelect = 2;
					break;
				}
			}
		else if(ticketSlecet_voucher == 2)
			{
				printf("권종을 선택하세요.\n1. 주간권\n2. 야간권");
				scanf("%d", ticketSelect_voucher_kind);
			}
				if(ticketSelect_voucher_kind == 2 && ticketSelect_voucher_kind == 1)
				{
					ticketSelect = 3;
					break;
				}
				else if(ticketSelect_voucher ==2 && ticketSelect_voucher_kind == 2)
				{
					ticketSelect = 4;
					break;
				}			
	}
	}
	return 0;
	}
}//951001  2170011
