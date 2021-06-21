/* 
 * race.c - demonstrates a race condition
 */
/* $begin race */
/* WARNING: This code is buggy! */
#include "csapp.h"
#define N 4

void *thread(void *vargp);

int main() 
{
    pthread_t tid[N];
    int i;
    int* num;
    
    for (i = 0; i < N; i++) {
        num = (int*) malloc(size_of(int));
        *num = i;
        Pthread_create(&tid[i], NULL, thread, num);

    }
        

    for (i = 0; i < N; i++) 
    	Pthread_join(tid[i], NULL);
        
    exit(0);
}

/* Thread routine */
void *thread(void *vargp) 
{
    int myid = *((int *)vargp);  //line:conc:race:derefarg
    free(vargp);
    printf("Hello from thread %d\n", myid);
    return NULL;
}
/* $end race */
