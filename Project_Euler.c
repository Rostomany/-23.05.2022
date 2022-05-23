#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


void Ex1()
{
	int sum = 0;

	for (int i = 3; i < 1000; i++)
	{
		if (i % 5 == 0 || i % 3 == 0)
			sum += i;
	}

	printf("Ex1: %i\n", sum);
}


void Ex2()
{
	int sum = 0;
	int* arr = malloc(400000);

	if (!arr)
	{
		exit(EXIT_FAILURE);
	}

	arr[0] = 0;
	arr[1] = 1;

	for (int i = 2; arr[i - 1] < 4000000; ++i)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
		if (arr[i] % 2 == 0)
			sum += arr[i];
	}

	printf("Ex2: %i\n", sum);
}



void Ex3()
{
	long long int prime_divisor = 0;
	long long int count = 600851475143;
	int check = 1;

	for (int i = 2; i <= sqrt(count); ++i)
	{
		if (count % i == 0)
		{
			for (int j = 2; j <= sqrt(i); ++j)
			{
				if (i % j == 0)
				{
					check = 0;
					j = sqrt(i);
				}
			}

			if (check == 1)
				prime_divisor = i;
			check = 1;
		}
	}

	printf("Ex3: %lli\n", prime_divisor);
}


void Ex4()
{
	int count = 0;
	int max_answer = 0;


	for (int i = 999; i >= 100; --i)
	{
		for (int j = 999; j >= 100; --j)
		{
			count = i * j;

			if (((count <= 99999 && count % 10 == count / 10000 && (count % 100) / 10 == (count / 1000) % 10)\
				|| (count <= 999999 && count % 10 == count / 100000 && (count % 100) / 10 == (count / 10000) % 10) && (count % 1000) / 100 == (count / 1000) % 10) && count > max_answer)
				max_answer = count;
		}
	}

	printf("Ex4: %i\n", max_answer);
}


void Ex5()
{
	int count = 20;
	int i = 2;

	while (i <= 20)
	{
		if (count % i != 0)
		{
			++count;
			i = 2;
		}
		else
			i++;
	}

	printf("Ex5: %i\n", count);
}


void Ex6()
{
	int sum_of_squares = 0;
	int sum_square = 0;

	for (int i = 1; i <= 100; i++)
	{
		sum_of_squares += pow(i,2);
		sum_square += i;
	}

	int answer = sum_of_squares - pow(sum_square, 2);
	printf("Ex6: %i\n", answer);
}


void Ex7()
{
	int check = 1;
	int counter = 2;
	int count = 4;

	while (counter != 10001)
	{
		check = 1;
		++count;
		for (int i = 2; i <= sqrt(count); ++i)
		{
			if (count % i == 0)
			{
				check = 0;
				i = sqrt(count);
			}
		}
		if (check == 1)
			++counter;
	}

	printf("Ex7: %i\n", count);
}


void Ex8()
{
	unsigned long long answer = 0;
	char count[1000] = { "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450" };
	unsigned long long buf = 1;

	for (int i = 0; i < 987; i++)
	{
		for (int j = 0; j <= 12; ++j)
			buf *= ((unsigned long long)count[i+j] - '0');
		if (buf > answer)
			answer = buf;
		buf = 1;
	}

	printf("Ex8: %llu\n", answer);
}


void Ex9()
{
	for (int a = 1; a <= 995; ++a)
		for (int b = a + 1; b <= 996; ++b)
			for (int c = b + 1; c <= 997; ++c)
				if ((pow(a,2) + pow(b,2) == pow(c,2)) && (a + b + c == 1000))
					printf("Ex9: %i\n", a * b * c);
}


void Ex10()
{
	long long sum = 5;
	int check = 1;

	for (int i = 4; i < 2000000; i++)
	{
		check = 1;
		for (int j = 2; j <= sqrt(i); ++j)
		{
			if (i % j == 0)
			{
				check = 0;
				j = sqrt(i);
			}

		}
		if (check == 1)
			sum+=i;
	}
	printf("Ex10: %lli\n", sum);
}


void Ex11()
{

	int matrix[20][20] = { 8, 2, 22, 97, 38, 15, 0, 40, 0, 75, 4, 5, 7, 78, 52, 12, 50, 77, 91, 8,
		 49, 49, 99, 40, 17, 81, 18, 57, 60, 87, 17, 40, 98, 43, 69, 48, 4, 56, 62, 0,
		 81, 49, 31, 73, 55, 79, 14, 29, 93, 71, 40, 67, 53, 88, 30, 3, 49, 13, 36, 65,
		 52, 70, 95, 23, 4, 60, 11, 42, 69, 24, 68, 56, 1, 32, 56, 71, 37, 2, 36, 91,
		 22, 31, 16, 71, 51, 67, 63, 89, 41, 92, 36, 54, 22, 40, 40, 28, 66, 33, 13, 80,
		 24, 47, 32, 60, 99, 3, 45, 2, 44, 75, 33, 53, 78, 36, 84, 20, 35, 17, 12, 50,
		 32, 98, 81, 28, 64, 23, 67, 10, 26, 38, 40, 67, 59, 54, 70, 66, 18, 38, 64, 70,
		 67, 26, 20, 68, 2, 62, 12, 20, 95, 63, 94, 39, 63, 8, 40, 91, 66, 49, 94, 21,
		 24, 55, 58, 5, 66, 73, 99, 26, 97, 17, 78, 78, 96, 83, 14, 88, 34, 89, 63, 72,
		 21, 36, 23, 9, 75, 0, 76, 44, 20, 45, 35, 14, 0, 61, 33, 97, 34, 31, 33, 95,
		 78, 17, 53, 28, 22, 75, 31, 67, 15, 94, 3, 80, 4, 62, 16, 14, 9, 53, 56, 92,
		 16, 39, 5, 42, 96, 35, 31, 47, 55, 58, 88, 24, 0, 17, 54, 24, 36, 29, 85, 57,
		 86, 56, 0, 48, 35, 71, 89, 7, 5, 44, 44, 37, 44, 60, 21, 58, 51, 54, 17, 58,
		 19, 80, 81, 68, 5, 94, 47, 69, 28, 73, 92, 13, 86, 52, 17, 77, 4, 89, 55, 40,
		 4, 52, 8, 83, 97, 35, 99, 16, 7, 97, 57, 32, 16, 26, 26, 79, 33, 27, 98, 66,
		 88, 36, 68, 87, 57, 62, 20, 72, 3, 46, 33, 67, 46, 55, 12, 32, 63, 93, 53, 69,
		 4, 42, 16, 73, 38, 25, 39, 11, 24, 94, 72, 18, 8, 46, 29, 32, 40, 62, 76, 36,
		 20, 69, 36, 41, 72, 30, 23, 88, 34, 62, 99, 69, 82, 67, 59, 85, 74, 4, 36, 16,
		 20, 73, 35, 29, 78, 31, 90, 1, 74, 31, 49, 71, 48, 86, 81, 16, 23, 57, 5, 54,
		 1, 70, 54, 71, 83, 51, 54, 69, 16, 92, 33, 48, 61, 43, 52, 01, 89, 19, 67, 48};

	int answer = 0;
	int buf = 1;

	for(int i = 0; i <= 19; ++i)
		for (int j = 0; j <= 19; ++j)
		{
			if (j <= 16)
				buf = matrix[i][j] * matrix[i][j + 1] * matrix[i][j + 2] * matrix[i][j + 3];
			if (buf > answer)
				answer = buf;

			if (i <= 16)
				buf = matrix[i][j] * matrix[i + 1][j] * matrix[i + 2][j] * matrix[i + 3][j];
			if (buf > answer)
				answer = buf;

			if (i <= 16 && j <= 16)
				buf = matrix[i][j] * matrix[i + 1][j + 1] * matrix[i + 2][j + 2] * matrix[i + 3][j + 3];
			if (buf > answer)
				answer = buf;

			if (i <= 16 && j >= 3)
				buf = matrix[i][j] * matrix[i + 1][j - 1] * matrix[i + 2][j - 2] * matrix[i + 3][j - 3];
			if (buf > answer)
				answer = buf;
		}

	printf("Ex11: %i\n", answer);
}


void Ex12()
{
	unsigned int triunglar_count = 0;
	int counter = 1;

	for (int i = 1; counter <= 500; ++i)
	{
		counter = 2;
		triunglar_count += i;
		for (int j = 1; j <= sqrt(triunglar_count); ++j)
		{
			if (triunglar_count % j == 0)
				counter += 2;
			if (j == sqrt(triunglar_count))
				--counter;
		}
	}

	printf("Ex12: %i\n", triunglar_count);
}

void Ex14()
{
	int answer = 0;
	for (int i = 1; i < 1000000; ++i)
	{
		int counter = 1;
		long long buf = i;
		while (buf != 1)
		{
			counter += 1;
			if (buf % 2 == 0)
				buf = buf / 2;
			else
				buf = buf * 3 + 1;
		}
		if (counter > answer)
			answer = counter;
	}

	printf("Ex14: %i\n", answer);
}


void Ex15()
{
	long long int arr[21][21] = { 0 };
	for (int i = 0; i < 21; i++)
		for (int j = 0; j < 21; j++)
		{
			if (i == 0 && j == 0)
				arr[i][j] = 0;
			else if (i == 0 || j == 0)
				arr[i][j] = 1;
			else
				arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
		}
	printf("Ex15: %lli\n", arr[20][20]);
}

//Задание на проверку скобок в строке. Строка считывается с файла Ex2_string.txt
void Ex2_string()
{
	FILE* F = fopen("Ex2_string.txt", "r");
	if (!F)
		return;

	char symbol = '0';
	int counter = 0;
	int first_error = -2;

	for (int i = 0; symbol != EOF; i++)
	{
		symbol = getc(F);

		if (symbol == '(')
			++counter;
		if (symbol == ')')
			--counter;
		if (counter == -1)
		{
			first_error = i;
			symbol = EOF;
		}

	}

	if (counter == 0)
		printf("0");
	if (counter > 0)
		printf("-1");
	if (first_error>=0)
		printf("%i", first_error);

	fclose(F);

	printf("\n");
}


/*
void Ex3_date()
{
	FILE* F = fopen("Date1.txt", "r");
	FILE* F2 = fopen("Date2.txt", "w");

	struct Date
	{
		int day;
		int month;
		int year;
	};

	struct Date* arr = malloc(5 * sizeof(int));

	char c = 0;

	for (int i = 0; c != EOF; i++)
	{
		c = getc(F);
		fgets(F, "%d", arr->day);
		fgets(F, "%d", arr->month);
		fgets(F, "%d", arr->year);
		printf("%d/%d/%d", arr->day, arr->month, arr->year);
	}
}
*/

int main()
{
	Ex1();
	Ex2();
	Ex3();
	Ex4();
	Ex5();
	Ex6();
	Ex7();
	Ex8();
	Ex9();
	Ex10();
	Ex11();
	Ex12();
	Ex14();
	Ex15();


	Ex2_string();

	return 0;
}