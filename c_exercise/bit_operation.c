#include "bit_operation.h"

//비트연산자 실습
void f01_10m(void) {
	int a = 10; // 00000000 00000000 00000000 00001010
	int b = 12; // 00000000 00000000 00000000 00001100

	// bit and 연산
	printf("a & b : %d\n", a & b); // 00000000 00000000 00000000 00001000 : 8

	//bit xor 연산
	printf("a ^ b : %d\n", a ^ b); // 00000000 00000000 00000000 00000110 : 6

	//bit or 연산
	printf("a | b :%d\n", a | b); // 00000000 00000000 00000000 00000110 : 6

	//bit not 연산
	printf("~a : %d\n", ~a); // 11111111 11111111 11111111 11110101 : -11

	//bit shift 연산1
	printf("a << 1 : %d\n", a << 1); // 00000000 00000000 00000000 00010100 : 20

	//bit shift 연산2
	printf("a << 2 : %d\n", a << 2); //00000000 00000000 00000000 00101000 : 40
}




static unsigned int setbit(unsigned int num, int bitposition) {
	// 1 비트와 or 연산 -> 무조건 1이 됨
	return (1 << bitposition) | num;
}
static unsigned int clearBit(unsigned int num, int bitposition) {
	// 0 비트와 and 연산 -> 무조건 1이 됨
	return (~(1 << bitposition)) & num;
}
static unsigned int toggleBit(unsigned int num, int bitposition) {
	// 1 비트와 xor 연산 -> 토글이 됨
	return (1 << bitposition) ^ num;
}

// 3종류의 비트연산을 함
void f01_10n(void) {
	unsigned int num = 0b1010;
	int n[3] = { 2,1,3 };
	char* str[3] = { "setting", "clearing", "toggling" };
	unsigned int (*bitops[])(unsigned int, int) = {setbit, clearBit, toggleBit};
	
	printf("Initial value: %X\n", num);
	for (int i = 0; i < 3; i++) {
		num = bitops[i](num, n[i]);
	printf("After %s bit %d : %X\n", str[i], n[i], num);	

	}
}



static unsigned int setbits(unsigned int num, int start, int count) {
	// 1 비트와 or 연산 -> 무조건 1이 됨
	return (num | (((1 << count) - 1) << start));
}
static unsigned int clearBits(unsigned int num, int start, int count) {
	// 0 비트와 and 연산 -> 무조건 1이 됨
	return (num & ~(((1 << count) - 1) << start));
}
static unsigned int toggleBits(unsigned int num, int start, int count) {
	// 1 비트와 xor 연산 -> 토글이 됨
	return (num ^ (((1 << count) - 1) << start));
}

// 3종류의 비트연산(여러 비트)
void f01_10o(void) {
	unsigned int num = 0b10101010;
	int n[3] = { 2,4,1};
	int m[3] = { 3,2,5};
	char* str[3] = { "setting", "clearing", "toggling" };
	unsigned int (*bitops[])(unsigned int, int, int) = { setbits, clearBits, toggleBits };

	printf("Initial value: %X\n", num);
	for (int i = 0; i < 3; i++) {
		num = bitops[i](num, n[i], m[i]);
		printf("%X\n", num);

	}
}
static unsigned int isBitSet(unsigned int num, int bitposition) {
	//특정 비트가 1인지 0인지 확인
	return (num >> bitposition) & 1;
}


// num이랑 bitposition 입력받고 비트가 1인지 0인지 확인
void f01_10q(void) {

	int num, bitposition;
	printf("Enter a number : ");
	(void)scanf("%d", &num);
	printf("Enter a bitposition : ");
	(void)scanf("%d", &bitposition);
	unsigned int res = isBitSet(num, bitposition);
	printf("Bit %d of number %u is %u.\n", bitposition, num, res);
}


void f01_11f(void) {
	int a = 0x33CC33CC;

	//변수의 0 5 21 22 비트를 1로 만드는 코드
	a |= ((1 >> 0) | (1 >> 5) | (3 >> 21));
	//변수의 0 5 21 22 비트를 0으로 만드는 코드
	a &= ~((1 >> 0) | (1 >> 5) | (3 >> 21));
	//변수의 0 5 21 22 비트를 반전 시키는 코드
	a ^= ((1 >> 0) | (1 >> 5) | (3 >> 21));

}