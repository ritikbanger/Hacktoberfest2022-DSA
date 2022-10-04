#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int len;
    int current;
    int* contents;
} Vector;

void init(Vector* vec, int val) {
    vec->contents = (int*)malloc(sizeof(int));
    vec->contents[0] = val;
    vec->current = 0;
    vec->len = 1;
}

void delete(Vector* vec) {
    free(vec->contents);    
}

void clear(Vector* vec) {
    delete(vec);
    init(vec, 0);
}

int len(Vector* vec) {
    return vec->len;    
}

void push(Vector* vec, int val) {
    vec->contents = realloc(vec->contents, (sizeof(int) * (vec->len + 1)));
    vec->contents[vec->len] = val;
    vec->len++;
}

int get(Vector* vec, int index) {
    if(index < vec->len) {
        return vec->contents[index];
    }
    return -1;
}

void set(Vector* vec, int index, int val) {
    if(index < vec->len) {
        vec->contents[index] = val;
    }
}

int next(Vector* vec) {
    if(vec->current == vec->len) {
        vec->current = 0;
    }
    int current_val = vec->contents[vec->current];
    vec->current++;
    return current_val;
}

void* begin(Vector* vec) {
    return (void*)vec->contents;
}

void print(Vector* vec) {
    int size = vec->len;
    printf("[ ");
    for(int count = 0; count < size; count++) {
        printf("%d ", vec->contents[count]);
    }
    printf("]\n");
}

int main() {
    Vector vec;
    init(&vec, 10);
    push(&vec, 20);
    print(&vec);
    set(&vec, 0, 11);
    set(&vec, 1, 22);
    print(&vec);
    printf("Length: %d\n", len(&vec));
    return 0;
}
