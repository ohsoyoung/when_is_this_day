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
		while (choiceYear < 2000 || choiceYear > 3000) {	//�⵵�� 2000~2999�� ���̰� �ƴϸ� �ٽ� ȣ��
			choiceYear = get_year();
		}

		choiceDay = get_day();
		if ((choiceYear % 4 == 0 && choiceYear % 100 != 0) || choiceYear % 400 == 0) {
			while (choiceDay > 366)	//�����϶� 366�Ϻ��� ũ�� �ٽ� ȣ��
				choiceDay = get_day();
		}
		else {
			while (choiceDay > 365)	//����ƴҶ� 365�Ϻ��� ũ�� �ٽ� ȣ��
				choiceDay = get_day();
		}

		calc_month_day(choiceYear, choiceDay);	//�⵵�� �ϼ��� ����� ��,��,������ ����� �Լ� ȣ��
	}
}

int get_year() {
	int year;
	printf("�⵵ �Է�: ");
	scanf("%d", &year);

	while(year < 999 || year > 9999) {	//�⵵�� 4�ڸ� ���ڰ� �ƴϸ� �ٽ� �Է�
		printf("4�ڸ��� ���ڷ� �ٽ� �Է��Ͻÿ�.\n");
		printf("�⵵ �Է�: ");
		scanf("%d", &year);
	}
	return year;
}

int get_day() {
	int day;
	printf("�ϼ� �Է�: ");
	scanf("%d", &day);

	while(day < 1 || day > 999) {	//�ϼ��� 1~3�ڸ� ���ڰ� �ƴϸ� �ٽ��Է�
		printf("1~3�ڸ��� ���ڷ� �ٽ� �Է��Ͻÿ�.\n");
		printf("�ϼ� �Է�: ");
		scanf("%d", &day);
	}
	return day;
}

void calc_month_day(int year, int day) {
	int month = 0;	//��
	int monthCnt[12] = {31,28,31,30,31,30,31,31,30,31,30,31};	//1~12���� �ϼ� �迭
	int date = 0;	//��
	char *day_of_week[7] = {"��", "��", "ȭ", "��", "��", "��", "��"};	//����
	int week_day = 0;	//������ �迭�ȿ� �� �Ű�����
	int total_day = 0;	//��ü�ϼ� ��� ����
	int i;

	date = day;

	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)	//�����϶�
		monthCnt[1] = 29;	//���� 2���� 29�ϱ��� ������ �ٽ� ����

	for (month = 0; monthCnt[month] < date; month++)
		date -= monthCnt[month];	//1~12������ �ϼ����� ���� �Է��� �ϼ����� ������ ���鼭 ���� ���ذ�

	for(i = 1; i < year; i++) { //1����� �Է��� �⵵ ���⵵������ ��ü�ϼ� ����
		if(i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
			total_day += 366; //������ �ϼ� ���ϱ�
		else 
			total_day += 365; //���� �ƴ� ���� �ϼ� ���ϱ�
	}
	total_day += day;	//���� ��ü �ϼ��� ���� �⵵�� �ϼ� ����
	week_day = total_day % 7;	//��ü �ϼ��� 7���� ���Ϸ� ������ �ش� ������ ����

	printf("%d�⵵�� %d��° ���� %d�� %d�� %d�� %s����\n", year, day, year, month + 1, date, day_of_week[week_day]);
}