#include <stdlib.h>
#include <stdio.h>
//#include <limits.h>
//#include <string.h>


typedef void (*funcPtr)(int);
funcPtr m_pCallback;
int m_Index;

void dq_error(int cam_id){	printf("%d dq_error", cam_id);}

/*
struct entry_s {
	char *key;
	char *value;
	struct entry_s *next;
};

typedef struct entry_s entry_t;

struct hashtable_s {
	int size;
	struct entry_s **table;	
};

typedef struct hashtable_s hashtable_t;
*/
