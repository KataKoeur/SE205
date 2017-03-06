//helloworld.c

#include <stdatomic.h>
#include <stdio.h>
#include <pthread.h>

void *printHelloWorld()
{
   printf("Hello World !\n");
   return NULL;
}

int main(void)
{
   printf("Debut du programme\n");

   pthread_t t1, t2;
   pthread_create(&t1, NULL, printHelloWorld, NULL);
   pthread_create(&t2, NULL, printHelloWorld, NULL);

   pthread_join(t1, NULL);
   pthread_join(t2, NULL);

   printf("Fin du programme");

   return 0;
}
