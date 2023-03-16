#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int value = 5;

int main()
{
    // Array de dois inteiros para armazenar os descritores do pipe
    int fd[2];
    pid_t pid;
    
    // Criando o pipe
    if (pipe(fd) == -1) {
        perror("pipe failed");
        return 1;
    }

    pid = fork();

    if (pid == 0) { /* child process */
        printf("Entrei no filho!\n");
        value += 15;
        printf ("CHILD: value = %d\n",value); /* LINE A */
        
        // Escrevendo o valor atualizado de value no pipe
        write(fd[1], &value, sizeof(value));
        return 0;
    }
    else if (pid > 0) { /* parent process */
        wait(NULL);
        
        // Lendo o valor atualizado de value do pipe
        read(fd[0], &value, sizeof(value));
        printf ("PARENT: value = %d\n",value); /* LINE A */
        return 0;
    }
}
