#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <utime.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    struct stat buf;    // 파일 상태 저장을 위한 변수
    struct utimbuf time;    // 파일의 접근 시간 및 수정 시간을 설정하기 위한 변수
    
    // 프로그램 실행 시 사용법을 출력하고 인자가 충분하지 않을 경우 종료
    if (argc < 3) {
        fprintf(stderr, "사용법: cptime file1 file2\n");
        exit(1);
    }
    
    // 파일의 상태를 가져오는데 실패할 경우 오류 출력 후 종료
    if (stat(argv[1], &buf) < 0) {
        perror("stat()");
        exit(-1);
    }
    
    // 파일의 접근 시간 및 수정 시간을 가져와 설정
    time.actime = buf.st_atime;    // 파일의 마지막 접근 시간 설정
    time.modtime = buf.st_mtime;    // 파일의 마지막 수정 시간 설정
    
    // 파일의 접근 시간과 수정 시간을 변경하는데 실패할 경우 오류 출력
    if (utime(argv[2], &time))
        perror("utime");
    else    // 성공할 경우 종료
        exit(0);
}
