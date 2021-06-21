/* 
 * semaphore.c 
 */


#include "csapp.h"
void *thread(void *vargp);

sem_t sping, spong;

void *ping(void *arg)
{
	while(&sping){
		P(&spong);
		printf("ping is here\n");
		V(&sping);
	}
}
void *pong(void *arg)
{
	while(&spong) {
		P(&sping);
		printf("pong is here\n");
		V(&spong);
	}
}

int main() 
{
    Sem_init(&sping, 0, 0);// initialize sping to 0
    Sem_init(&spong, 0, 1);// initialize spong to 1 so spong will start first
    pthread_t pingT, pongT;
    Pthread_create(&pingT, NULL, ping, NULL);//pingT thread will use ping routine
    Pthread_create(&pongT, NULL, pong, NULL);//pongT thread will use ping routine
    Pthread_join(pingT, NULL);//reap pingT
    Pthread_join(pongT, NULL);//reap pongT
    exit(0); 
}
