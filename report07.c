#include <stdio.h>
int get_year(void);
int get_day(void);
void calc_month_day(int year, int day);
int main()
{
	int i;
	int choiceYear;
	int choiceDay;

	for (i = 0; i < 5; i++) {
		choiceYear = get_year();
		while (choiceYear < 2000 || choiceYear > 3000) {	//년도가 2000~2999년 사이가 아니면 다시 호출
			choiceYear = get_year();
		}

		choiceDay = get_day();
		if ((choiceYear % 4 == 0 && choiceYear % 100 != 0) || choiceYear % 400 == 0) {
			while (choiceDay > 366)	//윤년일때 366일보다 크면 다시 호출
				choiceDay = get_day();
		}
		else {
			while (choiceDay > 365)	//윤년아닐때 365일보다 크면 다시 호출
				choiceDay = get_day();
		}

		calc_month_day(choiceYear, choiceDay);	//년도와 일수로 계산한 월,일,요일을 출력할 함수 호출
	}
}

int get_year() {
	int year;
	printf("년도 입력: ");
	scanf("%d", &year);

	while(year < 999 || year > 9999) {	//년도가 4자리 숫자가 아니면 다시 입력
		printf("4자리의 숫자로 다시 입력하시오.\n");
		printf("년도 입력: ");
		scanf("%d", &year);
	}
	return year;
}

int get_day() {
	int day;
	printf("일수 입력: ");
	scanf("%d", &day);

	while(day < 1 || day > 999) {	//일수가 1~3자리 숫자가 아니면 다시입력
		printf("1~3자리의 숫자로 다시 입력하시오.\n");
		printf("일수 입력: ");
		scanf("%d", &day);
	}
	return day;
}

void calc_month_day(int year, int day) {
	int month = 0;	//월
	int monthCnt[12] = {31,28,31,30,31,30,31,31,30,31,30,31};	//1~12월의 일수 배열
	int date = 0;	//일
	char *day_of_week[7] = {"일", "월", "화", "수", "목", "금", "토"};	//요일
	int week_day = 0;	//요일의 배열안에 들어갈 매개변수
	int total_day = 0;	//전체일수 계산 변수
	int i;

	date = day;

	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)	//윤년일때
		monthCnt[1] = 29;	//윤년 2월은 29일까지 있으니 다시 설정

	for (month = 0; monthCnt[month] < date; month++)
		date -= monthCnt[month];	//1~12월까지 일수들이 현재 입력한 일수보다 작으면 빼면서 월을 정해감

	for(i = 1; i < year; i++) { //1년부터 입력한 년도 전년도까지의 전체일수 구함
		if(i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
			total_day += 366; //윤년의 일수 더하기
		else 
			total_day += 365; //윤년 아닌 년의 일수 더하기
	}
	total_day += day;	//위의 전체 일수에 현재 년도의 일수 더함
	week_day = total_day % 7;	//전체 일수를 7개의 요일로 나누면 해당 요일이 나옴

	printf("%d년도의 %d일째 날은 %d년 %d월 %d일 %s요일\n", year, day, year, month + 1, date, day_of_week[week_day]);
}