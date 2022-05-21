/*
 ================================================================================================================================================================================================
 Name/Имя              :  Kalkulator/Калькулятор
 Author/Автор          :  Volodin Ilya/Володин Илья
 Copyright/Лицензия    :  All rights reserved/Все права защищены
 Description/Описание  :  The program performs 6 mathematical operations: Addition, Subtraction, Multiplication, Division, Factorial, Raising to a non-negative degree/
                          Программа выполняет 6 математических действий: Сложение, Вычитание, Умножение, Деление, Факториал, Возведение в неотрицательную степень
                          Язык интерфейса: Русский
 ================================================================================================================================================================================================
 */
#include <stdio.h>
int main(int argc, char *argv[])
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	double a,b;//два числа, которые фигурируют в операциях
	char p,c;//p-переменная, с которой работает while, с-переменная, которая хранит знак операции
	double fact = 1;//переменная, которая хранит значение факториала

	printf("Калькулятор может выполнять следующие операции: \nСумма:'+' \nРазность:'-' \nПроизведение:'*' \nЧастное:'/' \nФакториал числа:'!' \nВозведение в неотрицательную степень:'^'");

	do//начало цикла while
    {
		printf("\nВведите знак:");
		scanf(" %c", &c);
		switch (c)//для начала принимает знак
		{
		case '+'://алгоритм сложения
			printf("\nВведите первое число a:");
			scanf("%lf",&a);
			printf("Введите второе число b:");
			scanf("%lf",&b);
			printf("%lf", a+b);
		break;
		case '-'://алгоритм вычитания
			printf("\nВведите первое число a:");
			scanf("%lf",&a);
			printf("Введите второе число b:");
			scanf("%lf",&b);
			printf("%lf", a-b);
		break;
		case '*'://алгоритм умножения
			printf("\nВведите первое число a:");
			scanf("%lf",&a);
			printf("Введите второе число b:");
			scanf("%lf",&b);
			printf("%lf", a*b);
		break;
		case '/'://алгоритм деления, с учетом того, что на ноль делить нельзя
			printf("\nУчтите, что на 0 делить НЕЛЬЗЯ");
			printf("\nВведите первое число a:");
			scanf("%lf",&a);
			printf("Введите второе число b:");
			scanf("%lf",&b);
			printf("%lf", a/b);
		break;
		case '!'://алгоритм факториала первого введенного числа, с учетом того что отрицательного факториала не существует
			printf("Учтите, что факториала отрицательного числа НЕСУЩЕСТВУЕТ");
			printf("\nВведите число:");
			scanf("%lf",&a);
			if (a>0)//для числа>1
				{

					for(int i=1; i<=a; i++)
					{
						fact=fact*i;
			        }
				    printf("%.0lf", fact);
				}
			else printf("1");//для 0
		break;
		case '^'://алгоритм возведения числа в степень, с учетом того, что любое число в нулевой степени = 1
			printf("Учтите, что при возведении любого числа в 0 степень получится 1");
			printf("\nВведите число a:");
			scanf("%lf",&a);
			printf("Введите неотрицательную степень b:");
			scanf("%lf",&b);
			for(int i=1; i<=b; i++)//цикл для умножения
			{
				b = b - 1;
				a = a*a;
			}
			printf("%lf",a);
		break;
		}

	printf("\nЗапустить заново (y/n)?");
	scanf(" %c",&p);
    }
	while (p == 'y');//конец цикла. Здесь он предлогает продолжить
	return 0;
}