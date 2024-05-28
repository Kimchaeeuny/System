# 240528 시스템프로그래밍

## 프로세스 생성
### fork() 시스템 호출
- 부모 프로세스를 똑같이 복제하여 새로운 자식 프로세스를 생성
- 자기복제
![image](https://github.com/Kimchaeeuny/System/assets/120534069/e4cda36d-3c5c-43ed-9ccf-157826d59f76)

### fork()는 한 번 호출되면 두 번 리턴한다
- 자식 프로세스에게는 0리턴
- 부모 프로세스에게는 자식 프로세스 ID를 리턴
- 부모 프로세스와 자식 프로세스는 병행적으로 각각 실행을 계속함

## 부모 프로세스와 자식 프로세스 구분

### fork() 호출 후 리턴값이 다르므로 이 리턴값 이용
### 부모 프로세스와 자식 프로세스 구별
### 서로 다른 일 하도록 할 수 있음

## 프로세스 기다리기: wait()

### 자식 프로세스 중의 하나가 끝날 때까지 기다린다
- 끝난 자식 프로세스의 종료 코드가 status에 저장
- 끝난 자식 프로세스의 번호 리턴
- ![image](https://github.com/Kimchaeeuny/System/assets/120534069/4a70e98d-e136-477a-b028-b6bc346a0261)

## fork() 후에 파일 공유

### 자식은 부모의 fd 테이블을 복사
- 부모와 자식이 같은 파일 디스크립터를 공유
- 같은 파일 오프셋을 공유
- 부모와 자식으로부터 출력이 서로 섞이게 됨

### 자식에게 상속되지 않는 성질
- fork()의 반환값
- 프로세스 ID
- 파일 잠금
- 설정된 알람과 시그널
- ![image](https://github.com/Kimchaeeuny/System/assets/120534069/476bd4e7-30ba-4981-a66d-8454678540f4)

## 프로그램 실행

### fork() 후
- 자식 프로세스는 부모 프로세스와 똑같은 코드 실행

### 자식 프로세스에게 새 프로그램 실행
- exec() 시스템 호출 사용
- 프로세스 내의 프로그램을 새 프로그램으로 대치

### 보통 fork()후에 exec()
![image](https://github.com/Kimchaeeuny/System/assets/120534069/996fbb04-56a8-4956-853d-41919b8c7f72)


## fork / exec

### 보통 fork() 호출 후에 exec() 호출
- 새로 실행할 프로그램에 대한 정보를 arguments로 전달
  
### exec() 호출 성공시
- 자식 프로세스는 새로운 프로그램 실행
- 부모는 계속해서 다음 코드 실행
- ![image](https://github.com/Kimchaeeuny/System/assets/120534069/fb2eba99-b9db-4490-95f2-0eb7f621085e)

## system()
### /bin/sh -c cmdstring를 호출하여 cmdstring에 지정된 명령어 실행, 명령어가 끝난 후 명령어의 종료코드 반환

- 자식 프로세스 생성, /bin/sh로 하여금 지정된 명령어 실행
- system() 함수 구현
- 반환값
