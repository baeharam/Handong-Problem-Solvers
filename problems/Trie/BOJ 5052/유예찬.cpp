#include <cstdio>
#include <algorithm>
using namespace std;

const int CHILD_SIZE = 10;

struct Tree{
	Tree *child[CHILD_SIZE];
	int hasChild, suffix;

	Tree() {
		fill(child, child+CHILD_SIZE, nullptr);
		hasChild = suffix = false;
	}

	~Tree() {
		for (int i=0; i<CHILD_SIZE; i++)
			if (child[i]) delete child[i];
	}

	bool update(const char *str) {
		if (suffix) return true;
		if (*str == '\0') {
			suffix = true;
			return hasChild;
		}
		int curr = *str-'0';
		if (!child[curr]) child[curr] = new Tree;
		hasChild = true;
		return child[curr]->update(str+1);
	}
};

int main() {
	int T, N;
	char data[CHILD_SIZE+1];
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		Tree *root = new Tree;
		bool check = false;
		while (N--) {
			scanf("%s", data);
			if (!check && root->update(data)) check=true;
		}

		if (check) puts("NO");
		else puts("YES");

		delete root;
	}
	return 0;
}