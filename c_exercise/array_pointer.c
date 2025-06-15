#include "array_pointer.h"

//배열의 크기와 포인터의 크기 비교
void f07_extra1(void) {
	int arr[5] = { 10,20,30,40,50 };
	printf("sizeof(arr) = %d\n", sizeof(arr)); // 배열 전체의 크기 반환 20
	printf("sizeof(&arr) = %d\n", sizeof(&arr));// 배열을 가리키는 주소의 크기를 반환 4
	printf("sizeof(arr+1) = %d\n", sizeof(arr + 1));// arr은 배열이지만, 포인터 산술이 적용되는 순간 포인터로 decay됨.

}

//배열등가포인터 및 가리키는 배열 및 포인터의 크기 실습
void f07_extra2(void) {
	int arr[3][5] = { 0 };
	int (*p)[5] = arr; // 배열을 가리키는 포인터 (크기: 4)

	printf("sizeof(arr) = %d\n", sizeof(arr)); // 60 -> int[3][5] 배열의 크기
	printf("sizeof(arr[0]) = %d\n", sizeof(arr[0]));// 20 -> int[5] 배열의 크기
	printf("sizeof(arr[0][0]) = %d\n", sizeof(arr[0][0]));// 4 -> 배열의 첫번째 요소
	printf("sizeof(*arr) = %d\n", sizeof(*arr)); // 20 -> 포인터로써 arr이 가리키는 곳
	printf("sizeof(**arr) = %d\n", sizeof(**arr)); // 4 -> 포인터가 이중으로 가리키는 곳: 배열의 첫번째 요소
	printf("sizeof(p) = %d\n", sizeof(p)); // 4 -> p 자체는 주소임 그래서 4
	printf("sizeof(*p) = %d\n", sizeof(*p)); // 20 -> 전체 배열의 등가 포인터가 첫번째로 가리키는 요소(int[5] 배열 형태)
}

//arr의 포인터를 여러곳에 담아놓는 방법으로 복사
void f07_extra_3(void) {
	int arr[3] = { 10,20,30 };
	int a = 100;
	int (*p)[3] = &arr;

	printf("sizeof(p) = %d\n", sizeof(p));
	printf("sizeof(*p) = %d\n", sizeof(*p));
	//p를 사용하여 10 20 30 출력

	int* p2 = (int*)p; //포인터도 형변환 가능

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