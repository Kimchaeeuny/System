#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* 세 개의 자식 프로세스를 생성하여 각각 다른 명령어를 실행한다. */
int main() {
    printf("부모 프로세스 시작\n");

    for (int i = 0; i < 3; ++i) {
        if (fork() == 0) {
            switch (i) {
                case 0:
                    execl("/bin/echo", "echo", "hello", NULL);
                    fprintf(stderr, "첫 번째 실패");
                    break;
                case 1:
                    execl("/bin/date", "date", NULL);
                    fprintf(stderr, "두 번째 실패");
                    break;
                case 2:
                    execl("/bin/ls", "ls", "-l", NULL);
                    fprintf(stderr, "세 번째 실패");
                    break;
            }
            exit(i + 1); // 프로세스 종료
        }
    }

    printf("부모 프로세스 끝\n");

}
