#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct listNode {
	element data;
	struct listNode* link;
}ListNode;

ListNode* insert_first(ListNode* tail, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (tail == NULL) {
		tail = node;
		node->link = node;
	}
	else {
		node->link = tail->link;
		tail->link = node;
	}
	return tail;
}

ListNode* insert_last(ListNode* tail, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode)); //<1번, 운영체제로 부터 메모리 할당>
	node->data = data; // <2번>
	if (tail == NULL) {
		tail = node;
		node->link = tail;
	}
	else {
		node->link = tail->link; // <3번>
		tail->link = node;  //<4번>
		tail = node; // <5번>
	}
	return tail;  //<5번>
}

ListNode* delete_first(ListNode* tail) {
	if (tail == NULL)
		return NULL;
	ListNode* remove = tail->link;
	if (tail == remove) {
		free(remove);
		return NULL;
	}
	tail->link = remove->link;
	free(remove);

	return tail;
}

ListNode* delete_last(ListNode* tail) {
	if (tail == NULL)
		return NULL;
	ListNode* remove = tail->link;
	ListNode* p = tail;
	if (tail == remove) {
		free(remove);
		return NULL;
	}
	while (remove->link != tail->link) {
		p = remove;
		remove = remove->link;
	}
	p->link = tail->link;
	free(tail);

	return p;
}

void print_list(ListNode* tail) {
	ListNode* p;
	if (tail == NULL)
		return;
	p = tail->link;
	do {
		printf(" %2d -> ", p->data);
		p = p->link;
	} while (p != tail->link);
	printf("(head)");

}

main() {
	ListNode* tail = NULL;

	int choice;
	int num;
	int pos;
	int count;

	while (1) {
		printf("\n메뉴 : \n");
		printf("1. 숫자를 입력받아서 리스트 처음에 추가 \n");
		printf("2. 숫자를 입력받아서 리스트 마지막에 추가 \n");
		printf("3. 리스트 처음 노드 삭제 \n");
		printf("4. 리스트 마지막 노드 삭제 \n");
		printf("5. 리스트 프린트 \n");
		printf("0. 프로그램 종료 \n");
		printf("메뉴를 선택 하세요 : ");
		scanf_s("%d", &choice);

		switch (choice) {
		case 1:
				printf("추가할 숫자를 입력하세요: ");
				scanf_s("%d", &num);
				tail = insert_first(tail, num);
				print_list(tail);
			break;
		case 2:
			printf("추가할 숫자를 입력하세요: ");
			scanf_s("%d", &num);
			tail = insert_last(tail, num);
			print_list(tail);
			break;
		case 3:
			tail = delete_first(tail);
			print_list(tail);
			break;
		case 4:
			tail = delete_last(tail);
			print_list(tail);
			break;
		case 5:
			print_list(tail);
			break;

		case 0:
			printf("프로그램 종료\n");
			return 0;
		default:
			printf("잘못된 선택입니다. 다시 시도하세요\n");

		}

	}
}