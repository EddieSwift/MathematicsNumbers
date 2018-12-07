/*
 * loops.c
 *
 *  Created on: Sep 26, 2018
 *      Author: eddie
 */

#include <stdio.h>

int powXY(int x, int pow);
void printOdd(int number);
void fibonacci(int number);
int countDigits(int number);
int reverseNumber(int number);
void luckyNumber(int number);
int sum(int number);
void luckyNumber1(int number);
void luckyNumber2(int number);
int factorial(int number);

int main() {

	int i = 012; // octal
	i = 0X12; //hexadecimal
	printf("i = %d\n", i);

	int count = 0;

	while (count <= 10) {

		printf("count = %d\n", count);
		count++;
	}

	printf("------------------------\n");

	int res = powXY(2, 3);

	printf("res = %d\n", res);

	printf("------------------------\n");

	//printOdd(10);

	fibonacci(10);

	printf("\nAmount digits: %d\n", countDigits(0));

	printf("Number: %d\n", reverseNumber(-123));

	luckyNumber2(12211221);

	printf("factorial: %d\n", factorial(4));

	return 0;
}

int factorial(int number) {

	int res = 1;

	while (number) {
		res *= number;
		number--;
	}

	return res;
}

void luckyNumber2(int number) {

	int sum = 0;

	while (number) {

		sum = number % 10 - sum;
		number /= 10;
	}

	if (!sum) {
		printf("Lucky!\n");
	} else {
		printf("Unlucky!\n");
	}

}

void luckyNumber1(int number) {

	int rank1 = 0;
	int rank2 = 0;

	while (number) {

		rank1 += number % 10;
		number /= 10;

		rank2 += number % 10;
		number /= 10;

	}

	printf("rank1 = %d\n", rank1);
	printf("rank2 = %d\n", rank2);

	int test = countDigits(number);

	if (test % 2 == 0) {
		printf("Chetnoe!\n");
	} else {
		printf("Ne Chetnoe!\n");
	}

	if (rank1 == rank2) {
		printf("You're lucky!\n");
	} else {
		printf("You're unlucky!\n");
	}
}

int sum(int number) {

	int res = 0;

	while (number) {
		res += number % 10;
		number /= 10;
	}

	return res;
}

void luckyNumber(int number) {

	int count = countDigits(number); /// 123123
	int n2 = count / 2;
	int tmp = powXY(10, n2); // Amount digits in rank
	int left = number / tmp;
	int right = number % tmp;

	if (count % 2 != 0) {
		left /= 10;
	}

	if (sum(left) == sum(right)) {
		printf("You're lucky!\n");
	} else {
		printf("You're unlucky!\n");
	}
}

void luckyNumber3(int number) {

	int tempNum = number;
	int half = 0;
	int first = 0;
	int second = 0;

	int amountOfDigits = countDigits(number);

	printf("amountOfDigits %d\n", amountOfDigits);
	half = amountOfDigits / 2;
	printf("half %d\n", half);

	while (half) {
		second = second + number % 10;
		half--;
		tempNum /= 10;
	}

	int reverse = reverseNumber(number);
	printf("reverse %d\n", reverse);

	half = amountOfDigits / 2;

	while (half) {
		first = first + reverse % 10;
		half--;
		reverse /= 10;
	}

	if (first == second) {
		printf("You're lucky!\n");
	} else {
		printf("Sum of first and second digits of number not equals!\n");
	}
	printf("first %d\n", first);
	printf("second %d\n", second);
}

int reverseNumber(int number) {

	int reverse = 0;

	while (number) { // number != 0

		reverse = 10 * reverse + number % 10;
		number /= 10;
	}

	return reverse;
}

int countDigits(int number) {

	int res = 0;

	while (number) {
		res += number % 10;
		number /= 10;
	}

	int count = 0;

	do {

		number /= 10;
		count++;

	} while (number != 0);

	return count;
}

void fibonacci(int number) {

	printf("------------------------\n");

	int prev = 0;
	int next = 1;

	if (number < 0) {
		number = -number;
	}

	if (number < 2) {
		printf("Fibonacci not possible if number less then 2\n");
	} else {

		printf("[%d][%d]", prev, next);

		while (number > 2) {

			int current = prev + next;

			printf("[%d]", current);
			prev = next;
			next = current;
			number--;
		}

	}
}

void printOdd(int number) {

	int count = 0;

	//printf("[%d]", count);

	while (count <= number) {

		if ((count % 2) == 0) {
			printf("[%d]", count);

		}

		count++;
	}

	printf("\n");
}

int powXY(int x, int pow) {

	int res = x;

	if (pow <= 0) {
		return 1;
	}

	while (pow > 1) {

		res = res * x;
		pow--;
	}

	return res;
}
