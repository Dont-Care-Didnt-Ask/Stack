#include <stdlib.h>
#include "stack.h"
#include <string.h>

struct Stack{
	size_t size;
	int top;
	size_t one_elem_sz;
	void * arr;
};

void * xrealloc(void * ptr, size_t size) {
	void * tmp = ptr;
	tmp = realloc(ptr, size);
	if (!tmp) {
		free(ptr);
        abort();
	}
	return tmp;
}

void * xmalloc(size_t size) {
	void * tmp = malloc(size);
	if (tmp) return tmp;
	abort();
}

int isempty(Stack * st) {
	if (st->top == -1) return 1;
	return 0;
}

void * pop(Stack * st) {
	if (isempty(st)) return NULL;

	char * tmp = (char *) st->arr;
	tmp += (st->top) * (st->one_elem_sz);
	void * ptr = tmp;
	
	(st->top)--;
	return ptr;
	/*
	Takes the adress of the beginning of the array and adds the offset.
	Offset is calculated as a product of amount of the elements and the size of one element.
	Top is decremented, as we pop the last element.
	*/
}


/*
	Returns the element on the top of the stack
	but doesn't remove it
*/
void *current(Stack * st) {
	if (isempty(st)) return NULL;

	char * tmp = (char *) st->arr;
	tmp += (st->top) * (st->one_elem_sz);
	void * ptr = tmp;

	return ptr;
}

void push(Stack * st, void * elem){
	if (st->top + 1 == st->size) {     // array is full
		st->size <<= 1;
		st->arr = xrealloc(st->arr, st->size);
	}

	char * tmp = (char *) st->arr;
	tmp += (st->top) * (st->one_elem_sz);
	void * ptr = tmp;
	
	(st->top)++;
	memcpy(ptr, elem, st->one_elem_sz);
	/*
	We calculate destination just like in pop().
	*/
}

Stack * new_stack(size_t one_elem_sz, size_t desired_sz) {
	Stack * st = (Stack *)xmalloc(sizeof(Stack));
	st->arr = xmalloc(one_elem_sz * desired_sz);
	st->size = desired_sz;
	st->top = -1;
	st->one_elem_sz = one_elem_sz;
	return st;
}

void free_stack(Stack* st) {
	free(st->arr);
}