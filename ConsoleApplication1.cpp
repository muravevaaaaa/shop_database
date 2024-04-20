#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <conio.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#define LENGHT 101
#define ROWS 7
#define cell 15


struct list {//главная структура программы
	char type[LENGHT];
	char art;
	int quantity;
	int price;
	char firm[LENGHT];
	int year;

};

int is_alpha(char k[]) {//проверка:состоит ли строка только из букв
	int m = strlen(k);
	int flag = 1;
	for (int i = 0; i < strlen(k); i++) {
		if (not(isalpha(k[i]))) flag = 0;
	}
	return flag;

}
int is_number(char k[]) {//проверка:состоит ли строка только из цифр
	int m = strlen(k);
	int flag = 1;
	for (int i = 0; i < strlen(k); i++) {
		if (not(isdigit(k[i]))) flag = 0;
	}
	return flag;

}



int table_add(int n) {//создание новой таблицы и добавление новой строки в существ. таблицу
	struct list row;
	FILE* table;
	int m;
	table = 0;
	int lenght;//количество строк в таблице
	char l[LENGHT];//количество строк в таблице
	if (n == 0) {//создание новой таблицы
		table = fopen("maintable", "w");
		if (table == NULL) return -1;
		lenght = 0;
	}
	if (n == 1) {//добавление новой строки
		table = fopen("maintable", "r+");
		if (table == NULL) return -1;
		fgets(l, LENGHT, table);
		lenght = atoi(l);
	}
	if (n == 0) {
		printf("Введите количество строк таблицы:\n");
		while (scanf("%d", &m) != 1 or m < 0) {
			fseek(stdin, 0, SEEK_END);
			printf("Длина должна быть натуральным числом!");
		}
		fseek(stdin, 0, SEEK_END);
		lenght = m;

	}
	if (n == 1) {
		m = 1;
		lenght += 1;
	}
	sprintf(l, "%d", lenght);
	fseek(table, 0, SEEK_SET);
	fputs(l, table);
	fputs("\n", table);
	fseek(table, 0, SEEK_END);
	if (n == 1) {
		fclose(table);
		table = fopen("maintable", "a");
	}
	for (int i = 0; i < m; i++) {
		printf("Введите вид обуви: ");
		while (scanf("%s", &row.type) != 1 or is_alpha(row.type) == 0)
		{
			fseek(stdin, 0, SEEK_END);
			printf("Ошибка. Введите вид обуви: ");
		}
		fprintf(table, "%s ", row.type);
		fseek(stdin, 0, SEEK_END);
		printf("Введите артикул(F- женские, M- мужские, C - детские):\n");
		int flag2 = 1;
		while (scanf("%c", &row.art) != 1 or (row.art != 'F' && row.art != 'M' && row.art != 'C'))
		{
			fseek(stdin, 0, SEEK_END);
			printf("Ошибка. Введите артикул обуви: ");
		}
		fprintf(table, "%c ", row.art);
		fseek(stdin, 0, SEEK_END);
		printf("Введите количество пар:\n");
		while (scanf("%d", &row.quantity) != 1 or (row.quantity < 1))
		{
			fseek(stdin, 0, SEEK_END);
			printf("Ошибка. Введите количество пар обуви: ");
		}
		fprintf(table, "%d ", row.quantity);
		fseek(stdin, 0, SEEK_END);
		printf("Введите стоимость пары обуви:\n");
		while (scanf("%d", &row.price) != 1 or (row.price < 1))
		{
			fseek(stdin, 0, SEEK_END);
			printf("Ошибка. Введите стоимость пары обуви: ");
		}
		fprintf(table, "%d ", row.price);
		fseek(stdin, 0, SEEK_END);
		printf("Введите производителя обуви: ");
		while (scanf("%s", &row.firm) != 1)
		{
			fseek(stdin, 0, SEEK_END);
			printf("Ошибка. Введите производителя обуви: ");
		}
		fprintf(table, "%s ", row.firm);
		fseek(stdin, 0, SEEK_END);
		printf("Введите год выпуска обуви: ");
		while (scanf("%d", &row.year) != 1 or (row.year < 0))
		{
			fseek(stdin, 0, SEEK_END);
			printf("Ошибка. Введите год выпуска обуви: ");
		}
		fprintf(table, "%d ", row.year);
		fseek(stdin, 0, SEEK_END);
		fprintf(table, "\n");
	}
	fclose(table);
	return 0;

}

int table_style(int n) {//вывод основной таблицы или запроса
	FILE* table;
	table = 0;
	if (n == 0) table = fopen("maintable", "r");//n = 0 вывод основной таблицы
	if (n == 1) table = fopen("req_table", "r");//n = 1 вывод таблицы запроса
	if (table == NULL) return -1;
	printf("+");
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < cell; j++) printf("-");
		printf("+");
	}
	printf("\n");
	printf("|Number         ");
	printf("|1.Name         ");
	printf("|2.Article      ");
	printf("|3.Quantity     ");
	printf("|4.Price        ");
	printf("|5.Firm         ");
	printf("|6.Year         |");
	printf("\n");
	printf("+");
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < cell; j++) printf("-");
		printf("+");

	}
	printf("\n");
	char string1[LENGHT];
	int i = 1;
	if (n == 0)fgets(string1, LENGHT, table);
	while (fgets(string1, LENGHT, table) != 0) {
		printf("|%-*d", cell, i);
		printf("|%-15.15s", strtok(string1, " "));
		printf("|%-*s", cell, strtok(NULL, " "));
		printf("|%-*s", cell, strtok(NULL, " "));
		printf("|%-*s", cell, strtok(NULL, " "));
		printf("|%-15.15s", strtok(NULL, " "));
		printf("|%-*s", cell, strtok(NULL, " "));
		printf("|\n");
		i++;
	}
	printf("+");
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < cell; j++) printf("-");
		printf("+");
	}
	fclose(table);
	if (n == 1) remove("req_table");
	return 0;

}

int table_edit() {//редактирование полей таблицы
	FILE* table;
	table = fopen("maintable", "r+");
	if (table == NULL) return -1;
	int n, m;
	char string1[LENGHT];
	char l[LENGHT];//количество строк в таблице
	fgets(l, LENGHT, table);
	if (atoi(l) > 0) {
		printf("Введите номер строки: ");
		while (scanf("%d", &n) != 1 or (n < 1 or n > atoi(l)))
		{
			fseek(stdin, 0, SEEK_END);
			printf("Ошибка. Введите номер строки: ");
		}
		printf("Введите номер столбца:");
		while (scanf("%d", &m) != 1 or (1 > m or m > 6))
		{
			fseek(stdin, 0, SEEK_END);
			printf("Ошибка. Введите номер столбца: ");
		}
		fseek(stdin, 0, SEEK_END);
		for (int i = 1; i <= n; i++) {
			fgets(string1, LENGHT, table);
		}
		int lenght = strlen(string1);
		char s_type[LENGHT], s_quant[LENGHT], s_art[LENGHT], s_price[LENGHT], s_firm[LENGHT], s_year[LENGHT];//переменные для полей строки
		char* p = strtok(string1, " ");
		strcpy(s_type, p);
		p = strtok(NULL, " ");
		strcpy(s_art, p);
		p = strtok(NULL, " ");
		strcpy(s_quant, p);
		p = strtok(NULL, " ");
		strcpy(s_price, p);
		p = strtok(NULL, " ");
		strcpy(s_firm, p);
		p = strtok(NULL, " ");
		strcpy(s_year, p);
		fseek(table, -1 * lenght - 1, SEEK_CUR);
		switch (m) {
		case 1:
			printf("Введите вид обуви: ");
			while (scanf("%s", &s_type) != 1 or is_alpha(s_type) == 0)
			{
				fseek(stdin, 0, SEEK_END);
				printf("Ошибка. Введите вид обуви: ");
			}
			fseek(stdin, 0, SEEK_END);
			break;
		case 2:
			printf("Введите артикул(F- женские, M- мужские, C - детские):\n");
			while (scanf("%c", &s_art) != 1 or (s_art[0] != 'F' && s_art[0] != 'M' && s_art[0] != 'C'))
			{
				fseek(stdin, 0, SEEK_END);
				printf("Ошибка. Введите артикул обуви: ");
			}
			fseek(stdin, 0, SEEK_END);
			break;
		case 3:
			printf("Введите количество пар:\n");
			while (scanf("%s", &s_quant) != 1 or is_number(s_quant) == 0)
			{
				fseek(stdin, 0, SEEK_END);
				printf("Ошибка. Введите количество пар обуви: ");
			}
			fseek(stdin, 0, SEEK_END);
			break;
		case 4:
			printf("Введите стоимость пары обуви:\n");
			while (scanf("%s", &s_price) != 1 or is_number(s_price) == 0)
			{
				fseek(stdin, 0, SEEK_END);
				printf("Ошибка. Введите стоимость пары обуви: ");
			}
			fseek(stdin, 0, SEEK_END);
			break;
		case 5:
			printf("Введите производителя обуви: ");
			while (scanf("%s", s_firm) != 1)
			{
				fseek(stdin, 0, SEEK_END);
				printf("Ошибка. Введите производителя обуви: ");
			}
			fseek(stdin, 0, SEEK_END);
			break;
		case 6:
			printf("Введите год выпуска обуви: ");
			while (scanf("%s", s_year) != 1 or is_number(s_year) == 0)
			{
				fseek(stdin, 0, SEEK_END);
				printf("Ошибка. Введите год выпуска обуви: ");
			}
			fseek(stdin, 0, SEEK_END);
			break;
		}
		fprintf(table, "%s ", s_type);
		fprintf(table, "%s ", s_art);
		fprintf(table, "%s ", s_quant);
		fprintf(table, "%s ", s_price);
		fprintf(table, "%s ", s_firm);
		fprintf(table, "%s ", s_year);


	}
	else printf("\nТаблица пустая.\n");
	fclose(table);
	return 0;
}

int request_() {//создание запроса
	FILE* table;
	FILE* req_table;
	table = fopen("maintable", "r");
	req_table = fopen("req_table", "w");
	if (table == NULL) return -1;
	if (req_table == NULL) return -2;
	char l[LENGHT];
	fgets(l, LENGHT, table);
	int sign = 0;
	char i[] = "+-";
	if (atoi(l) > 0) {
		struct list request;
		char filter[7];
		printf("\nВведите запрос:\n");
		printf("Запрос по виду обуви? ДА + НЕТ -: ");
		fseek(stdin, 0, SEEK_END);
		while (scanf("%c", &filter[0]) != 1 or strchr(i, filter[0]) == NULL)
		{
			fseek(stdin, 0, SEEK_END);
			printf("Ошибка. Введите + или -: ");
		}
		fseek(stdin, 0, SEEK_END);
		switch (filter[0]) {
		case '+':
			printf("Введите вид обуви: ");
			while (scanf("%s", &request.type) != 1 or is_alpha(request.type) == 0)
			{
				fseek(stdin, 0, SEEK_END);
				printf("Ошибка. Введите вид обуви: ");
			}
			fseek(stdin, 0, SEEK_END);
			break;

		case '-':
			break;
		}
		printf("Запрос по артикулу обуви? ДА + НЕТ -: ");
		fseek(stdin, 0, SEEK_END);
		while (scanf("%c", &filter[1]) != 1 or strchr(i, filter[1]) == NULL)
		{
			fseek(stdin, 0, SEEK_END);
			printf("Ошибка. Введите + или -: ");
		}
		fseek(stdin, 0, SEEK_END);
		switch (filter[1]) {
		case '+':
			printf("Введите артикул обуви: ");
			while (scanf("%c", &request.art) != 1 or (request.art != 'F' && request.art != 'M' && request.art != 'C'))
			{
				fseek(stdin, 0, SEEK_END);
				printf("Ошибка. Введите артикул обуви: ");
			}
			fseek(stdin, 0, SEEK_END);
			break;

		case '-':
			break;
		}
		fseek(stdin, 0, SEEK_END);
		printf("Запрос по количеству пар обуви? ДА + НЕТ -: ");
		while (scanf("%c", &filter[2]) != 1 or strchr(i, filter[2]) == NULL)
		{
			fseek(stdin, 0, SEEK_END);
			printf("Ошибка. Введите + или -: ");
		}
		fseek(stdin, 0, SEEK_END);
		switch (filter[2]) {
		case '+':
			printf("Введите количество пар обуви: ");
			while (scanf("%d", &request.quantity) != 1 or (request.quantity < 1))
			{
				fseek(stdin, 0, SEEK_END);
				printf("Ошибка. Введите количество пар обуви: ");
			}
			break;

		case '-':
			break;
		}
		fseek(stdin, 0, SEEK_END);
		printf("Запрос по цене пары обуви? ДА + НЕТ -: ");
		while (scanf("%c", &filter[3]) != 1 or strchr(i, filter[3]) == NULL)
		{
			fseek(stdin, 0, SEEK_END);
			printf("Ошибка. Введите + или -: ");
		}
		switch (filter[3]) {
		case '+':
			printf("Введите цену обуви:");
			while (scanf("%d", &request.price) != 1 or (request.price < 1))
			{
				fseek(stdin, 0, SEEK_END);
				printf("Ошибка. Введите цену пары обуви: ");
			}
			printf("1 - выше заданной цены, 2 - ниже, 3 - равно: ");
			while (scanf("%d", &sign) != 1 or (sign < 1 or sign > 3))
			{
				fseek(stdin, 0, SEEK_END);
				printf("Ошибка. Выберите вариант(1 - выше заданной цены, 2 - ниже, 3 - равно): ");
			}
			break;

		case '-':
			break;
		}
		fseek(stdin, 0, SEEK_END);
		printf("Запрос по производителю обуви? ДА + НЕТ -: ");
		while (scanf("%c", &filter[4]) != 1 or strchr(i, filter[4]) == NULL)
		{
			fseek(stdin, 0, SEEK_END);
			printf("Ошибка. Введите + или -: ");
		}
		switch (filter[4]) {
		case '+':
			printf("Введите производителя обуви: ");
			while (scanf("%s", &request.firm) != 1)
			{
				fseek(stdin, 0, SEEK_END);
				printf("Ошибка. Введите производителя обуви: ");
			}
			break;

		case '-':
			break;
		}
		fseek(stdin, 0, SEEK_END);
		printf("Запрос по году выпуска обуви? ДА + НЕТ -: ");
		while (scanf("%c", &filter[5]) != 1 or strchr(i, filter[5]) == NULL)
		{
			fseek(stdin, 0, SEEK_END);
			printf("Ошибка. Введите + или -: ");
		}
		switch (filter[5]) {
		case '+':
			printf("Введите год выпуска обуви: ");
			while (scanf("%d", &request.year) != 1 or (request.year < 0 or request.year > 2024))
			{
				fseek(stdin, 0, SEEK_END);
				printf("Ошибка. Введите год выпуска обуви: ");
			}
			break;

		case '-':
			break;
		}
		char string1[LENGHT];
		char s_type[LENGHT], s_quant[LENGHT], s_art[LENGHT], s_price[LENGHT], s_firm[LENGHT], s_year[LENGHT];
		int flag = 1;
		while (fgets(string1, LENGHT, table) != 0) {
			char string_req[LENGHT] = "";
			int lenght = strlen(string1);
			char* p = strtok(string1, " ");
			strcpy(s_type, p);
			p = strtok(NULL, " ");
			strcpy(s_art, p);
			p = strtok(NULL, " ");
			strcpy(s_quant, p);
			p = strtok(NULL, " ");
			strcpy(s_price, p);
			p = strtok(NULL, " ");
			strcpy(s_firm, p);
			p = strtok(NULL, " ");
			strcpy(s_year, p);
			flag = 1;
			for (int j = 0; j < 6; j++) {
				if (filter[j] == '+') {
					switch (j) {
					case 0:
						if (strcmp(request.type, s_type) != 0) flag = 0;
						break;
					case 1:
						if (request.art != s_art[0]) flag = 0;
						break;
					case 2:
						if (request.quantity != atoi(s_quant)) flag = 0;
						break;
					case 3:
						switch (sign) {
						case 1:
							if (atoi(s_price) <= request.price) flag = 0;
							break;
						case 2:
							if (atoi(s_price) >= request.price) flag = 0;
							break;
						case 3:
							if (request.price != atoi(s_price)) flag = 0;
							break;
						}
						break;
					case 4:
						if (strcmp(request.firm, s_firm) != 0) flag = 0;
						break;
					case 5:
						if (request.year != atoi(s_year)) flag = 0;
					}

				}
			}
			if (flag) {
				fprintf(req_table, "%s ", s_type);
				fprintf(req_table, "%s ", s_art);
				fprintf(req_table, "%s ", s_quant);
				fprintf(req_table, "%s ", s_price);
				fprintf(req_table, "%s ", s_firm);
				fprintf(req_table, "%s ", s_year);
				fputc('\n', req_table);
			}

		}
	}
	else printf("\nТаблица пустая.\n");

	fclose(table);
	fclose(req_table);
	return 0;

}

int table_delete() {//удаление строки таблицы
	FILE* table;
	FILE* help_table;
	table = fopen("maintable", "r");
	help_table = fopen("help_t", "w");//вспомогательный файл
	if (table == NULL) return -1;
	int n;
	char l[LENGHT];
	fgets(l, LENGHT, table);
	if (atoi(l) > 0) {
		printf("Введите номер строки, которую хотите удалить:");
		while (scanf("%d", &n) != 1 or (n < 1 or n > atoi(l)))
		{
			fseek(stdin, 0, SEEK_END);
			printf("Ошибка. Введите номер строки: ");
		}
		int lenght = atoi(l) - 1;
		sprintf(l, "%d", lenght);
		fprintf(help_table, "%s", l);
		fprintf(help_table, "\n");
		char string1[LENGHT];
		int counter = 0;
		while (fgets(string1, LENGHT, table) != 0) {
			if (counter != n - 1) {
				fputs(string1, help_table);
			}
			counter++;
		}
		//перезапись файла
		fclose(table);
		fclose(help_table);
		remove("maintable");
		rename("help_t", "maintable");
	}
	else printf("Таблица пустая.\n");
	return 0;
}
int main()
{
	setlocale(LC_ALL, "rus");
	system("color F0");
	setlocale(LC_ALL, "rus");
	int system_done = 1;
	do {
		int choice;
		printf("\nВыберите действие с таблицей:\n");
		printf("1 - Выполнить запрос\n");
		printf("2 - Удалить строку таблицы\n");
		printf("3 - Добавить строку таблицы\n");
		printf("4 - Редактировать таблицу\n");
		printf("5 - Вывести таблицу\n");
		printf("6 - Ввести новую таблицу\n");
		printf("7 - Выход из программы\n");
		while (scanf("%d", &choice) != 1 or (choice < 1) or choice > 7)
		{
			fseek(stdin, 0, SEEK_END);
			printf("Ошибка. Выберите действие с таблицей: ");
		}
		fseek(stdin, 0, SEEK_END);
		switch (choice) {
		case 1:
			switch (request_()) {
			case -1:printf("Таблица не создана.\n"); break;
			case -2:exit(EXIT_SUCCESS);
			default:table_style(1);
			}
			break;
		case 2:
			switch (table_delete()) {
			case -1:printf("Таблица не создана.\n"); break;
			default: table_style(0);
			}
			break;
		case 3:
			switch (table_add(1)) {
			case -1:printf("Таблица не создана.\n"); break;
			default:table_style(0);
			}
			break;
		case 4:
			switch (table_edit()) {
			case -1:printf("Таблица не создана.\n"); break;
			default:table_style(0);
			}
			break;
		case 5:
			switch (table_style(0)) {
			case -1:printf("Таблица не создана.\n"); break;
			}
			break;
		case 6:
			switch (table_add(0)) {
			case -1:printf("Таблица не создана.\n"); exit(EXIT_SUCCESS);
			}
			table_style(0);
			break;
		case 7:
			system_done = 0;
			break;
		}
	} while (system_done);
	return 0;
}
