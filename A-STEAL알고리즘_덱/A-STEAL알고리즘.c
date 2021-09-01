#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5
typedef int element;
typedef struct { // ť Ÿ��
	element  data[MAX_SIZE];
	int  front, rear;
} DequeType;

// ���� �Լ�
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// �ʱ�ȭ 
void init_deque(DequeType* q)
{
	q->front = q->rear = 0;
}

// ���� ���� ���� �Լ�
int is_empty(DequeType* q)
{
	return (q->front == q->rear);
}

// ��ȭ ���� ���� �Լ�
int is_full(DequeType * q)
{
	return ((q->rear + 1) % MAX_SIZE == q->front);
}

// ����ť ��� �Լ�
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

// ���� �Լ�
void add_front(DequeType * q, element val)
{
	if (is_full(q))
		error("ť�� ��ȭ�����Դϴ�");
	q->data[q->front] = val;
	q->front = (q->front - 1 + MAX_SIZE) % MAX_SIZE;
}


// ���� �Լ�
element delete_front(DequeType * q)
{
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	q->front = (q->front + 1) % MAX_SIZE;
	return q->data[q->front];
}

//Ȯ���Լ�
element get_front(DequeType * q)
{
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	return q->data[(q->front + 1) % MAX_SIZE];
}


// ���� �Լ�
void add_rear(DequeType * q, element item)
{
	if (is_full(q))
		error("ť�� ��ȭ�����Դϴ�");
	q->rear = (q->rear + 1) % MAX_SIZE;
	q->data[q->rear] = item;
}

// ���� �Լ�
element delete_rear(DequeType * q)
{
	int prev = q->rear;
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	q->rear = (q->rear - 1 + MAX_SIZE) % MAX_SIZE;
	return q->data[prev];
}

//Ȯ���Լ�
element get_rear(DequeType * q)
{
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	return q->data[q->rear];
}

int main() {
	DequeType a;
	DequeType b;
	init_deque(&a);
	init_deque(&b);
	int choice = 0, num = 0;;

	printf("���ϴ� �۾��� �����ϼ���.\n \n");
	while(1){
		printf("1 : �Է�\t 2 : ����\t 3 : ������ Ȯ��\t 4 : ����\n \n");
		scanf_s("%d", &choice);
		switch (choice) {
		case(1): {
			int i = 0;
			if (is_empty(&a)) {
				for (i = 0; i < MAX_SIZE - 1; i++)
					add_front(&a, i);
			}
			printf("�Է¿Ϸ�.\n");
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
			printf("�����Ϸ�.\n");
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
			printf("�����մϴ�.\n");
			exit(1);
			break;
		}
		}
	}
	
}