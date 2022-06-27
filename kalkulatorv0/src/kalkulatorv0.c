/*
 ================================================================================================================================================================================================
 Name/Имя              :  Kalkulator/Калькулятор
 Author/Автор          :  Volodin Ilya/Володин Илья
 Copyright/Лицензия    :  All rights reserved/Все права защищены
 Description/Описание  :  The program performs 6 mathematical operations: Addition, Subtraction, Multiplication, Division, Factorial, Raising to a non-negative degree.
                          And also works with vectors, namely, knows how to add, subtract and multiply them.
                          Программа выполняет 6 математических действий: Сложение, Вычитание, Умножение, Деление, Факториал, Возведение в неотрицательную степень
                          А также работет с векторами, а именно умеет их складывать, вычитать и умножать.
                          Язык интерфейса: Русский
 ================================================================================================================================================================================================
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	double a,b;//два числа, которые фигурируют в операциях
	float *x,*y;//два вектора, которые фигурируют в операциях
	int size;//размер векторов
	char p,c,v;//p-переменная, с которой работает while, с-переменная, которая хранит знак операции
	double fact = 1;//переменная, которая хранит значение факториала
    FILE *input, *output;//для ввода-вывода из файла
    input = fopen("input.txt", "r");
    output = fopen("output.txt", "w");
	do//начало цикла while
    {
		fscanf(input, " %c", &v);
		switch(v)//switch для выбора работы числового или векторного калькулятора
		{
		case 's'://если выбор за числовым калькулятором
			fscanf(input, " %c", &c);
			switch (c)//для начала принимает знак
			{
			case '+'://алгоритм сложения
				fscanf(input, "%lf",&a);
				fscanf(input, "%lf",&b);
				fprintf(output, "%lf+%lf=%lf", a, b, a+b);
			break;
			case '-'://алгоритм вычитания
				fscanf(input, "%lf",&a);
				fscanf(input, "%lf",&b);
				fprintf(output, "%lf-%lf=%lf", a, b, a-b);
			break;
			case '*'://алгоритм умножения
				fscanf(input, "%lf",&a);
				fscanf(input, "%lf",&b);
				fprintf(output, "%lf*%lf=%lf", a, b, a*b);
			break;
			case '/'://алгоритм деления, с учетом того, что на ноль делить нельзя
				fscanf(input, "%lf",&a);
				fscanf(input, "%lf",&b);
				fprintf(output, "%lf/%lf=%lf", a, b, a/b);
			break;
			case '!'://алгоритм факториала первого введенного числа, с учетом того что отрицательного факториала не существует
				fscanf(input, "%lf",&a);
				if (a>0)//для числа>1
					{
						for(int i=1; i<=a; i++)
						{
							fact=fact*i;
					    }
					    fprintf(output, "%.0lf!", fact);
					}
				else fprintf(output, "1");//для 0
			break;
			case '^'://алгоритм возведения числа в степень, с учетом того, что любое число в нулевой степени = 1
				fscanf(input, "%lf",&a);
				fscanf(input, "%lf",&b);
				for(int i=1; i<=b; i++)//цикл для умножения
				{
					b = b - 1;
					a = a*a;
				}
				fprintf(output, "%lf", a);
			break;
			}
		break;
		case 'v'://если выбор зя векторным калькулятором
		    fscanf(input, "%i", &size);
			x=malloc(size*sizeof(double));//выделям место
			y=malloc(size*sizeof(double));
			for (int i = 0; i < size; i++) fscanf(input, "%f", &x[i]);
			for (int i = 0; i < size; i++) fscanf(input, "%f", &y[i]);
			fscanf(input, " %c", &c);
			switch(c){//как и с числоывм калькулятором, спрашиваем знак
			case '+'://алгоритм для сложения
				fprintf(output, "Addition of vectors: ");
				fprintf(output, "( ");
				for (int i = 0; i < size; i++) fprintf(output, "%f ", x[i]);
				fprintf(output, ") ");
				fprintf(output, "+ ( ");
				for (int i = 0; i < size; i++) fprintf(output, "%f ", y[i]);
				fprintf(output, ")");
				fprintf(output, " = ");
				fprintf(output, "( ");
				for (int i = 0; i < size; i++) fprintf(output, "%f ", x[i] + y[i]);
				fprintf(output, ")");
			break;
			case '-'://алгоритм для вычитания
				fprintf(output, "Subtracting vectors: ");
				fprintf(output, "( ");
				for (int i = 0; i < size; i++) fprintf(output, "%f ", x[i]);
				fprintf(output, ") ");
				fprintf(output, "+ ( ");
				for (int i = 0; i < size; i++) fprintf(output, "%f ", y[i]);
				fprintf(output, ")");
				fprintf(output, " = ");
				fprintf(output, "( ");
				for (int i = 0; i < size; i++) fprintf(output, "%f ", x[i] - y[i]);
				fprintf(output, ")");
			break;
			case '*'://алгоритм для скалярного произведения
				fprintf(output, "Multiplication of vectors: ");
				fprintf(output, "( ");
				for (int i = 0; i < size; i++) fprintf(output, "%f ", x[i]);
				fprintf(output, ") ");
				fprintf(output, "+ ( ");
				for (int i = 0; i < size; i++) fprintf(output, "%f ", y[i]);
				fprintf(output, ")");
				fprintf(output, " = ");
				fprintf(output, "( ");
				for (int i = 0; i < size; i++) fprintf(output, "%f ", x[i] * y[i]);
				fprintf(output, ")");
			break;
			}
			free(x);//освобождаем выделенную память
			free(y);
		}
	fscanf(input, " %c", &p);
    }while (p == 'y');//конец цикла. Здесь он предлогает продолжить
	fclose(input);
	fclose(output);
	return 0;
}
