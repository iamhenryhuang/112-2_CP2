struct Node {
    int value;
    struct Node *nextPtr;
};

typedef struct Node Node;

void create2DArray(Node **arr, int m, int n) {
  *arr = (Node *)malloc(m * sizeof(Node));
  for(int i = 0; i < m; i++) {
    Node *tmp = *arr + i;
    for(int j = 0; j < m; j++) {
      tmp->value = n;
      tmp->nextPtr = (Node *)malloc(sizeof(Node)); //接node到下一個位置
      tmp = tmp ->nextPtr; // 把tmp移到原本tmp下一個
    }
    tmp->nextPtr = NULL; // tmp最後接一個null
  }
}

void free2DArray(struct Node *arr, int m) {
  for(int i = 0; i < m; i++) {
    Node *tmp = arr[i].nextPtr;
    while(tmp != NULL) {
      Node *freePtr = tmp;
      tmp = tmp->nextPtr;
      free(freePtr);
    }
  }
  free(arr);
}
