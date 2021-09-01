#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5
typedef int element;
typedef struct { // 큐 타입
	element  data[MAX_SIZE];
	int  front, rear;
} DequeType;

// 오류 함수
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// 초기화 
void init_deque(DequeType* q)
{
	q->front = q->rear = 0;
}

// 공백 상태 검출 함수
int is_empty(DequeType* q)
{
	return (q->front == q->rear);
}

// 포화 상태 검출 함수
int is_full(DequeType * q)
{
	return ((q->rear + 1) % MAX_SIZE == q->front);
}

// 원형큐 출력 함수
void deque_print(DequeType * q)
{
	printf("DEQUE(front=%d rear=%d) = ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % (MAX_SIZE);
			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}

// 삽입 함수
void add_front(DequeType * q, element val)
{
	if (is_full(q))
		error("큐가 포화상태입니다");
	q->data[q->front] = val;
	q->front = (q->front - 1 + MAX_SIZE) % MAX_SIZE;
}


// 삭제 함수
element delete_front(DequeType * q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->front = (q->front + 1) % MAX_SIZE;
	return q->data[q->front];
}

//확인함수
element get_front(DequeType * q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	return q->data[(q->front + 1) % MAX_SIZE];
}


// 삽입 함수
void add_rear(DequeType * q, element item)
{
	if (is_full(q))
		error("큐가 포화상태입니다");
	q->rear = (q->rear + 1) % MAX_SIZE;
	q->data[q->rear] = item;
}

// 삭제 함수
element delete_rear(DequeType * q)
{
	int prev = q->rear;
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->rear = (q->rear - 1 + MAX_SIZE) % MAX_SIZE;
	return q->data[prev];
}

//확인함수
element get_rear(DequeType * q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	return q->data[q->rear];
}

int main() {
	DequeType a;
	DequeType b;
	init_deque(&a);
	init_deque(&b);
	int choice = 0, num = 0;;

	printf("원하는 작업을 선택하세요.\n \n");
	while(1){
		printf("1 : 입력\t 2 : 삭제\t 3 : 데이터 확인\t 4 : 종료\n \n");
		scanf_s("%d", &choice);
		switch (choice) {
		case(1): {
			int i = 0;
			if (is_empty(&a)) {
				for (i = 0; i < MAX_SIZE - 1; i++)
					add_front(&a, i);
			}
			printf("입력완료.\n");
			break;
		}
		case(2): {
			int i = 0;
			if (is_empty(&b) == 1) {
				for (i = 0; i < MAX_SIZE - 1; i++) {
					add_front(&b,(delete_front(&a)));
				}
			}
			delete_front(&b);
			printf("삭제완료.\n");
			break;
		}
		case(3): {
			int i = 0;
			if (is_empty(&b) == 1) {
				for (i = 0; i < MAX_SIZE - 1; i++) {
					add_front(&b,(delete_front(&a)));
				}
			}
				printf("%d \n \n", get_front(&b));
			break;
		}
		case(4): {
			printf("종료합니다.\n");
			exit(1);
			break;
		}
		}
	}
	
}