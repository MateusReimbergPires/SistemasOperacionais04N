#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex;
double sum = 0.0;
long long n = 1000000000;
int num_threads = 4;

void* Thread_sum_mutex(void* rank){
    long my_rank = (long) rank;
    double factor;
    long long i;
    long long my_n = n / num_threads;
    long long my_first_i = my_n * my_rank;
    long long my_last_i = my_first_i + my_n;

    double my_sum = 0.0;
    if (my_first_i % 2 == 0)
        factor = 1.0;
    else
        factor = -1.0;

    for (i = my_first_i; i < my_last_i; i++, factor = -factor) {
        my_sum += factor / (2*i+1);
    }

    pthread_mutex_lock(&mutex);
    sum += my_sum;
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main(){
  long thread;
  pthread_t* id_threads;
  id_threads = (pthread_t*) malloc(num_threads*sizeof(pthread_t));
  
  //Mutex
  pthread_mutex_init(&mutex, NULL);
  printf("\nQuantidade de Threads: %d\n", num_threads);

  for (thread = 0; thread < num_threads; thread++) {
      pthread_create(&id_threads[thread], NULL, Thread_sum_mutex, (void*) thread);
  }

  for (thread = 0; thread < num_threads; thread++) {
      pthread_join(id_threads[thread], NULL);
  }

  sum *= 4.0;
  printf("Valor de PI (MUTEX): %.20f\n", sum);
  pthread_mutex_destroy(&mutex);
  //Fim Mutex

  free(id_threads);

  return 0;
}

