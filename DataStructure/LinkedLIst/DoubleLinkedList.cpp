#define MAX_NODE 10000

struct Node {
	int data;
	Node* prev;
	Node* next;
};

Node node[MAX_NODE+2];
int nodeCnt;
Node* head;
Node* tail;

int totCnt;

Node* getNode(int data) {
	node[nodeCnt].data = data;
	node[nodeCnt].prev = nullptr;
	node[nodeCnt].next = nullptr;
	return &node[nodeCnt++];
}

void init()
{
	nodeCnt = 0;
	totCnt = 0;
	tail = getNode(0);
	head = getNode(0);

	head->next = tail;
	tail->prev = head;
}

void addNode2Head(int data)
{
	Node* newNode = getNode(data);

	head->next->prev = newNode;
	newNode->next = head->next;
	head->next = newNode;
	newNode->prev = head;
	totCnt++;
}

void addNode2Tail(int data)
{
	Node* newNode = getNode(data);
	newNode->prev = tail->prev;
	tail->prev->next = newNode;
	newNode->next = tail;
	tail->prev = newNode;

	totCnt++;
}

void addNode2Num(int data, int num)
{
	Node* newNode = getNode(data);
	Node* current = head->next;

	for (int i = 1;i < num;i++, current = current->next;);
	newNode->prev = current->next;
	current->prev->next = newNode;
	current->prev = newNode;
	newNode->next = current;

	totCnt++;
}


int findNode(int data)
{
	int i = 1;
	for (Node* current = head->next; current->data != data; i++, current = current->next);
	return i;
}
void removeNode(int data)
{
	Node* current;
	for (current = head->next; current != tail; current = current->next) {
		if (current->data == data) {
			current->next->prev = current->prev;
			current->prev->next = current->next;
			totCnt++;

			return;
		}
	}
}

int getList(int output[MAX_NODE])
{
	int i = 0;
	for (Node* current = head->next; current != tail; current = current->next)
	{
		output[i++] = current->data;
	}

	return totCnt;
}

int getReversedList(int output[MAX_NODE])
{
	int i = 0;
	for (Node* current = tail->prev; current != head; current = current->prev)
	{
		output[i++] = current->data;
	}
	return totCnt;
}