#define MAX_NODE 10000

struct Node {
	int data;
	Node* next;
};

Node node[MAX_NODE];
int nodeCnt;
Node* head;
int totCnt;

Node* getNode(int data) {
	node[nodeCnt].data = data;
	node[nodeCnt].next = nullptr;
	return &node[nodeCnt++];
}

void init()
{
	head = nullptr;
	nodeCnt = 0;
	totCnt = 0;
}

void addNode2Head(int data)
{
	if (head == nullptr) {
		head = getNode(data);
	}
	else {
		Node* temp = getNode(data);
		temp->next = head;
		head = temp;
	}
	totCnt++;
}

void addNode2Tail(int data)
{
	if (head == nullptr) {
		addNode2Head(data);
	}
	else
	{
		Node* current;
		for (current = head; current->next != nullptr; current = current->next);
		current->next = getNode(data);
		totCnt++;
	}
}

void addNode2Num(int data, int num)
{
	if (num == 1) {
		addNode2Head(data);
	}
	else if (num == (totCnt + 1)) {
		addNode2Tail(data);
	}
	else {
		Node* current = head;
		for (int i = 1; i < (num - 1); i++, current = current->next);
		Node* newNode = getNode(data);
		newNode->next = current->next;
		current->next = newNode;
		totCnt++;
	}
}

void removeNode(int data)
{
	Node* prev = nullptr;
	for (Node* current = head; current != nullptr;current = current->next) {
		if (current->data = data) {
			if (current == head) {
				head = current->next;
			}
			else {
				prev->next = current->next;
			}
			totCnt--;
		}
		else {
			prev = current;
		}
	}
}

int getList(int output[MAX_NODE])
{
	int i = 0;
	for (Node* current = head; current != nullptr; current = current->next)
	{
		output[i++] = current->data;
	}

	return totCnt;
}