#define MAXNODE 500001
#define BUCKET_SIZE 100
#define BUCKET_NUM ((100000 / BUCKET_SIZE) + 1)
#define INF 1000010

struct Node {
	int data;
	Node* next;
};

int nodeCnt = 0;
Node node[MAXNODE];
Node* getNode() { return &node[nodeCnt]; }

Node* getNode(int data) {
	node[nodeCnt].data = data;
	return &node[nodeCnt++];
}

struct List {
	Node* head = 0;
	Node* tail = 0;
	int sz;

	void init() {
		head = getNode();
		tail = getNode();
		tail->data = INF;

		head->next = tail;
		sz = 0;
	}

	Node* searchByIdx(int idx) {
		Node* cur = head->next;

		while (idx--) {
			cur = cur->next;
		}
		return cur;
	}

	void append(int val) {
		Node* cur = head;
		while (cur->next->data < val) {
			cur = cur->next;
		}

		Node* tmp = getNode(val);
		tmp->next = cur->next;
		cur->next = tmp;

		sz++;
	}

	Node* remove(int idx) {
		Node* cur = head;
		Node* erased = 0;

		while (idx--) {
			cur = cur->next;
		}
		erased = cur->next;
		cur->next = cur->next->next;

		sz--;
		return erased;
	}
};

/* 
Bucket의 개수만큼 List 생성
Bucket의 개수는 Bucket의 사이즈에 의존하고 이를 조정해서 성능 개선 가능 (범위형)
*/
List lst[BUCKET_NUM];

// BUCKET 초기화
void init() {
	nodeCnt = 0;
	for (int i = 0; i < BUCKET_NUM; i++) {
		lst[i].init();
	}
}

void insert(int data) {
	int bucket_id = data / BUCKET_SIZE;
	lst[bucket_id].append(data);
}

int remove(int index) {
	Node* erased = 0;
	for (int i = 0; i < BUCKET_NUM; i++) {
		if (index < lst[i].sz) {
			erased = lst[i].remove(index);
			break;
		}
		index -= lst[i].sz;
	}
	return erased->data;
}

int searchByIndex(int index) {
	Node* cur = 0;
	for (int i = 0;i < BUCKET_NUM;i++) {
		if (index < lst[i].sz) {
			cur = lst[i].searchByIdx(index);
			break;
		}
		index -= lst[i].sz;
	}
	return cur->data;
}