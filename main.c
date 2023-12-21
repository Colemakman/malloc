#include <stdio.h>
#include <pthread.h>


typedef char ALIGN[16];

union header {
	struct {
		size_t size;
		unsigned is_free;
		union header * next;
	} s;
	ALIGN stub;
};
typedef union header header_t;

pthread_mutex_t global_malloc_lock;
header_t *head, *tail;

void *malloc(size_t size) { 
	size_t total_size;
	void *block;
	header_t *header;

	if (!size) {
		return NULL;
	}

	pthread_mutex_lock(&global_malloc_lock);
	header = get_free_block(size);
}

int main() {
	return 0;
}
