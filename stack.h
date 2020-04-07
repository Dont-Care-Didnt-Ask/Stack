#pragma once

typedef struct Stack Stack;
struct Stack;

void *xrealloc(void * ptr, size_t size);

void *xmalloc(size_t size);

int isempty(Stack * st);

void *pop(Stack * st);

void * look(Stack * st);

void push(Stack * st, void * elem);

Stack *new_stack(size_t one_elem_sz, size_t desired_sz);

void free_stack(Stack* st);
