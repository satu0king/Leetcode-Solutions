

bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize){
    int n = pushedSize;
    int *s = malloc(n * sizeof(int));
    
    int top = 0;
    int j = 0;
    
    for(int i = 0; i <n; i++) {
        s[top++] = pushed[i];
        while( top!= 0 && j < n && s[top-1] == popped[j]) {
            j++;
            top--;
        }
    }
    free(s);
    return top == 0 && j == n;
}


