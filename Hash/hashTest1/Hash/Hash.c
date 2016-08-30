#include "Hash.h"

/* Create a new hashtable. */
hashtable_t *ht_create( int size ) {

	hashtable_t *hashtable = NULL;
	int i;

	if( size < 1 ) return NULL;

	/* Allocate the table itself. */
	if( ( hashtable = malloc( sizeof( hashtable_t ) ) ) == NULL ) {
		return NULL;
	}

	/* Allocate pointers to the head nodes. */
	if( ( hashtable->table = malloc( sizeof( entry_t * ) * size ) ) == NULL ) {
		return NULL;
	}
	for( i = 0; i < size; i++ ) {
		hashtable->table[i] = NULL;
	}

	hashtable->size = size;

	return hashtable;	
}

#if 1
/* Hash a string for a particular hash table. */ 
int ht_hash( hashtable_t *hashtable, char *key ) { // key to hashing

	unsigned long int hashval;
	int i = 0;

	/* Convert our string to an integer */ //hash function
	while( hashval < ULONG_MAX && i < strlen( key ) ) {
		
		hashval = hashval << 8;
		hashval += key[ i ];
			
		i++;
	}

	//return hashval % hashtable->size;
	return hashval % hashtable->size;
}

#else


/* Hash a string for a particular hash table. */ 
int ht_hash( hashtable_t *hashtable, char *key ) { // key to hashing

	unsigned long int a;
	int i = 0;

	/* Convert our string to an integer */ //hash function
	while( a < ULONG_MAX && i < strlen( key ) ) {
			
		a += ~(a<<15);
		a ^=  (a>>10);
		a +=  (a<<3);
		a ^=  (a>>6);
		a += ~(a<<11);
		a ^=  (a>>16);
		
		a += key[ i ];

		i++;
	}

	//return hashval % hashtable->size;
	return a % hashtable->size;
}
#endif


/* Create a key-value pair. */
entry_t *ht_newpair( char *key, char *value ) {
	entry_t *newpair;

	if( ( newpair = malloc( sizeof( entry_t ) ) ) == NULL ) {
		return NULL;
	}

	if( ( newpair->key = strdup( key ) ) == NULL ) {
		return NULL;
	}

	if( ( newpair->value = strdup( value ) ) == NULL ) {
		return NULL;
	}

	newpair->next = NULL;

	return newpair;
}

/* Insert a key-value pair into a hash table. */
void ht_set( hashtable_t *hashtable, char *key, char *value ) {
	int bin = 0;
	entry_t *newpair = NULL;
	entry_t *next = NULL;
	entry_t *last = NULL;

	bin = ht_hash( hashtable, key );

	printf("bin = %d \n",bin);

	next = hashtable->table[ bin ];

	while( next != NULL && next->key != NULL && strcmp( key, next->key ) > 0 ) {
		last = next;
		next = next->next;
	}

	/* There's already a pair.  Let's replace that string. */
	if( next != NULL && next->key != NULL && strcmp( key, next->key ) == 0 ) {
		printf(" in if ht_set");
		free( next->value );
		next->value = strdup( value );

	/* Nope, could't find it.  Time to grow a pair. */
	} else {
		printf(" else if ht_set \n");
		newpair = ht_newpair( key, value );

		/* We're at the start of the linked list in this bin. */
		if( next == hashtable->table[ bin ] ) {
			newpair->next = next;
			hashtable->table[ bin ] = newpair;
	
		/* We're at the end of the linked list in this bin. */
		} else if ( next == NULL ) {
			last->next = newpair;
	
		/* We're in the middle of the list. */
		} else  {
			newpair->next = next;
			last->next = newpair;
		}
	}
}

/* Retrieve a key-value pair from a hash table. */
char *ht_get( hashtable_t *hashtable, char *key ) {
	//printf("test0\n");
	int bin = 0;
	entry_t *pair;

	//printf("test1\n");
	bin = ht_hash( hashtable, key );
	//printf("test2\n");
	/* Step through the bin, looking for our value. */
	pair = hashtable->table[ bin ];
	//printf("test3\n");
	while( pair != NULL && pair->key != NULL && strcmp( key, pair->key ) > 0 ) {
		//printf("test5\n");
		pair = pair->next;
	}
	//printf("test5\n");
	/* Did we actually find anything? */
	if( pair == NULL || pair->key == NULL || strcmp( key, pair->key ) != 0 ) {
		printf("the key is not valid! \n");
		return "";

	} else {
		//printf("test7\n");
		return pair->value;
	}
	
}


int main( int argc, char **argv ) {

	hashtable_t *hashtable = ht_create( 65536 );

	ht_set( hashtable, "192.168.0.188", "12:34:56:78:90:AB" );
	// String compare 하는 수 밖에 없나... "." 단위로 나누어서 하려면... 그리고 key 값의 길이가 정해져 있지 않음.
	// ex) 192.168.0.188 / 192.168.0.5 ... String Compare가 최선...?	
	// But, Mac Address는 길이가 정해져 있으니... 가능.
	ht_set( hashtable, "key2", "pinky" );
	ht_set( hashtable, "k3", "blinky" );
	ht_set( hashtable, "key4", "floyd" );

	printf( "%s\n", ht_get( hashtable, "192.168.0.188" ) );
	//if(ht_get( hashtable, "key" )!=NULL)
	{
		printf( "%s\n", ht_get( hashtable, "key" ) );
	}
	printf( "%s\n", ht_get( hashtable, "k3" ) );
	printf( "%s\n", ht_get( hashtable, "key4" ) );

	return 0;
}