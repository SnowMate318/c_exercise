#include "bit_operation.h"

//��Ʈ������ �ǽ�
void f01_10m(void) {
	int a = 10; // 00000000 00000000 00000000 00001010
	int b = 12; // 00000000 00000000 00000000 00001100

	// bit and ����
	printf("a & b : %d\n", a & b); // 00000000 00000000 00000000 00001000 : 8

	//bit xor ����
	printf("a ^ b : %d\n", a ^ b); // 00000000 00000000 00000000 00000110 : 6

	//bit or ����
	printf("a | b :%d\n", a | b); // 00000000 00000000 00000000 00000110 : 6

	//bit not ����
	printf("~a : %d\n", ~a); // 11111111 11111111 11111111 11110101 : -11

	//bit shift ����1
	printf("a << 1 : %d\n", a << 1); // 00000000 00000000 00000000 00010100 : 20

	//bit shift ����2
	printf("a << 2 : %d\n", a << 2); //00000000 00000000 00000000 00101000 : 40
}




static unsigned int setbit(unsigned int num, int bitposition) {
	// 1 ��Ʈ�� or ���� -> ������ 1�� ��
	return (1 << bitposition) | num;
}
static unsigned int clearBit(unsigned int num, int bitposition) {
	// 0 ��Ʈ�� and ���� -> ������ 1�� ��
	return (~(1 << bitposition)) & num;
}
static unsigned int toggleBit(unsigned int num, int bitposition) {
	// 1 ��Ʈ�� xor ���� -> ����� ��
	return (1 << bitposition) ^ num;
}

// 3������ ��Ʈ������ ��
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
	// 1 ��Ʈ�� or ���� -> ������ 1�� ��
	return (num | (((1 << count) - 1) << start));
}
static unsigned int clearBits(unsigned int num, int start, int count) {
	// 0 ��Ʈ�� and ���� -> ������ 1�� ��
	return (num & ~(((1 << count) - 1) << start));
}
static unsigned int toggleBits(unsigned int num, int start, int count) {
	// 1 ��Ʈ�� xor ���� -> ����� ��
	return (num ^ (((1 << count) - 1) << start));
}

// 3������ ��Ʈ����(���� ��Ʈ)
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
	//Ư�� ��Ʈ�� 1���� 0���� Ȯ��
	return (num >> bitposition) & 1;
}


// num�̶� bitposition �Է¹ް� ��Ʈ�� 1���� 0���� Ȯ��
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

	//������ 0 5 21 22 ��Ʈ�� 1�� ����� �ڵ�
	a |= ((1 >> 0) | (1 >> 5) | (3 >> 21));
	//������ 0 5 21 22 ��Ʈ�� 0���� ����� �ڵ�
	a &= ~((1 >> 0) | (1 >> 5) | (3 >> 21));
	//������ 0 5 21 22 ��Ʈ�� ���� ��Ű�� �ڵ�
	a ^= ((1 >> 0) | (1 >> 5) | (3 >> 21));

}