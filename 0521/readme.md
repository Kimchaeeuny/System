# 240521 시스템프로그래밍

## 포맷 입출력
![image](https://github.com/Kimchaeeuny/System/assets/120534069/24d3e1ba-a837-4b25-82be-ed372bf2fa1b)


## 블록 단위 입출력
![image](https://github.com/Kimchaeeuny/System/assets/120534069/92ac1ddc-6cf9-4f45-bbb9-237f3faf6c0b)

![image](https://github.com/Kimchaeeuny/System/assets/120534069/506d3391-fce0-46bd-b654-1766b68e0a1b)
![image](https://github.com/Kimchaeeuny/System/assets/120534069/abca8afc-1e6d-4d46-94d8-e40c53cb7b82)

## 프로세스(process)
- 실행중인 프로그램을 프로세스(process)라고 부른다.
- 각 프로세스는 유일한 프로세스 번호 PID를 갖는다.
- ps 명령어를 사용하여 나의 프로세스들을 볼 수 있다.

## 프로그램 실행 시작
### exec 시스템 호출
- C 시작 루틴에 명령줄 인수와 환경 변수를 전달
- 프로그램 실행
### C 시작 루틴(start-up routine)
- main 함수를 호출시키면서 명령줄 인수, 환경 변수를 전달
- exix( main ( argc, argv) );
- 실행이 끝나면 반환값을 받아 exit 한다.

## 프로그램 실행 시작
![image](https://github.com/Kimchaeeuny/System/assets/120534069/f10baf59-2dd2-421e-827c-bb5fa035f586)

## 명령줄 인수/환경 변수
![image](https://github.com/Kimchaeeuny/System/assets/120534069/0596ed57-eea5-47c5-92e2-2b36579774d0)

## 프로그램 종료
### 정상 종료(normal termination)
- main() 실행을 마치고 리턴하면 C 시작 루틴은 이 리턴값을 가지고 exit()을 호출
- 프로그램 내에서 직접 exit()을 호출
- 프로그램 내에서 직접 _exit()을 호출

### 비정상 종료(abnormal termination)
- abort(): 프로세스에 SIGABRT 시그널을 보내어 프로세스를 비정상적으로 종료
- 시그널에 의한 종료

![image](https://github.com/Kimchaeeuny/System/assets/120534069/35c9dba0-e5a2-48a4-a58c-f53bb2b3b5be)
![image](https://github.com/Kimchaeeuny/System/assets/120534069/6ed3dab5-d85f-4dab-8b8b-5a1b93953f5d)
