#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* 부모 프로세스가 두 개의 자식 프로세스를 생성한다. */
int main() {
    int pid1, pid2;

    pid1 = fork();
    if (pid1 == 0) { // 첫 번째 자식 프로세스
        printf("[Child 1] : Hello, world! pid=%d\n", getpid());
        exit(0);
    }

    pid2 = fork();
    if (pid2 == 0) { // 두 번째 자식 프로세스
        printf("[Child 2] : Hello, world! pid=%d\n", getpid());
        exit(0);
    }

    // 부모 프로세스는 여기에서 종료되지 않고 계속 실행될 수 있습니다.
    // 자식 프로세스가 종료될 때까지 기다리려면 wait()를 사용할 수 있습니다.
    // 예: waitpid(pid1, NULL, 0); waitpid(pid2, NULL, 0);
    
    // 또는 간단하게 두 자식 프로세스가 종료될 때까지 기다리기 위해 두 번의 wait() 호출을 사용할 수 있습니다.
    wait(NULL);
    wait(NULL);

    return 0;
}
