#include "array_pointer.h"

//�迭�� ũ��� �������� ũ�� ��
void f07_extra1(void) {
	int arr[5] = { 10,20,30,40,50 };
	printf("sizeof(arr) = %d\n", sizeof(arr)); // �迭 ��ü�� ũ�� ��ȯ 20
	printf("sizeof(&arr) = %d\n", sizeof(&arr));// �迭�� ����Ű�� �ּ��� ũ�⸦ ��ȯ 4
	printf("sizeof(arr+1) = %d\n", sizeof(arr + 1));// arr�� �迭������, ������ ����� ����Ǵ� ���� �����ͷ� decay��.

}

//�迭������� �� ����Ű�� �迭 �� �������� ũ�� �ǽ�
void f07_extra2(void) {
	int arr[3][5] = { 0 };
	int (*p)[5] = arr; // �迭�� ����Ű�� ������ (ũ��: 4)

	printf("sizeof(arr) = %d\n", sizeof(arr)); // 60 -> int[3][5] �迭�� ũ��
	printf("sizeof(arr[0]) = %d\n", sizeof(arr[0]));// 20 -> int[5] �迭�� ũ��
	printf("sizeof(arr[0][0]) = %d\n", sizeof(arr[0][0]));// 4 -> �迭�� ù��° ���
	printf("sizeof(*arr) = %d\n", sizeof(*arr)); // 20 -> �����ͷν� arr�� ����Ű�� ��
	printf("sizeof(**arr) = %d\n", sizeof(**arr)); // 4 -> �����Ͱ� �������� ����Ű�� ��: �迭�� ù��° ���
	printf("sizeof(p) = %d\n", sizeof(p)); // 4 -> p ��ü�� �ּ��� �׷��� 4
	printf("sizeof(*p) = %d\n", sizeof(*p)); // 20 -> ��ü �迭�� � �����Ͱ� ù��°�� ����Ű�� ���(int[5] �迭 ����)
}

//arr�� �����͸� �������� ��Ƴ��� ������� ����
void f07_extra_3(void) {
	int arr[3] = { 10,20,30 };
	int a = 100;
	int (*p)[3] = &arr;

	printf("sizeof(p) = %d\n", sizeof(p));
	printf("sizeof(*p) = %d\n", sizeof(*p));
	//p�� ����Ͽ� 10 20 30 ���

	int* p2 = (int*)p; //�����͵� ����ȯ ����

	for (int i = 0; i < size(arr); i++) {
		printf("%d ", *(*p + i));
	}
	printf("\n");
	for (int i = 0; i < size(arr); i++) {
		printf("%d ", p2[i]);
	}
}

void f_arr_point_exercise(void) {
	int ary[3] = { 1,2,3 };

	printf("%p\n", ary);
	printf("%p\n", &ary);
	printf("%p\n", ary + 1);
	printf("%p\n", &ary[1]);
	printf("%p\n", &ary + 1);
}