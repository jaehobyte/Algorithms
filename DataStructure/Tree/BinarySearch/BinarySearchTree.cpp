#define MAX_NUM 30000

struct Node {
	int data;
	int cnt;
	int leftCnt;
	Node* left;
	Node* right;
}node[MAX_NUM];

int count;
Node* root;

Node* getNode(int data) {
	node[count].data = data;
	node[count].cnt = 1;
	node[count].leftCnt = 0;
	node[count].left = nullptr;
	node[count].right = nullptr;
	return &node[count++];
}

void init() {
	count = 0;
	root = nullptr;
}

void insert(int data) {
	if (root == nullptr) {
		root = getNode(data);
	}
	else {
		Node* cur = root;
		while (true) {
			if (data < cur->data) {
				if (cur->left == nullptr) {
					cur->left = getNode(data);
					break;
				}
				cur = cur->left;
			}
			else if (data > cur->data) {
				if (cur->right == nullptr) {
					cur->right = getNode(data);
					break;
				}
				cur = cur->right;
			}
			else {
				cur->cnt += 1;
				break;
			}
		}
	}
}

int remove(int index) {
	Node* cur = root;
	while (true) {
		if (index < cur->leftCnt) {
			cur->leftCnt -= 1;
			cur = cur->left;
		}
		else if (index >= cur->leftCnt + cur->cnt) {
			index = index - (cur->leftCnt + cur->cnt);
			cur = cur->right;
		}
		else {
			cur->cnt -= 1;
			return cur->data;
		}
	}
}

int searchByIndex(int index) {
	Node* cur = root;
	while (true) {
		if (index < cur->leftCnt) cur = cur->left;
		else if (index >= cur->leftCnt + cur->cnt) {
			index = index - (cur->leftCnt + cur->cnt);
			cur = cur->right;
		}
		else return cur->data;
	}
}