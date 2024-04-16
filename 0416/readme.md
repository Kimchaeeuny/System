# 240416 시스템프로그래밍


## 컴퓨터 시스템 구조

### 유닉스 커널(kernel)
- 하드웨어를 운영 관리하여 다음과 같은 서비스를 제공
- 파일 관리(File management)
- 프로세스 관리(Process management)
- 메모리 관리(Memory management)
- 통신 관리(Communication management)
- 주변장치 관리(Device management)

## 시스템 호출
- 시스템 호출은 커널에 서비스 요청을 위한 프로그래밍 인터페이스
- 응용 프로그램은 시스템 호출을 통해서 커널에 서비스를 요청한다.


## 유닉스에서 파일
- 연속된 바이트의 나열
- 특별한 다른 포맷을 정하지 않음
- 디스크 파일뿐만 아니라 외부 장치에 대한 인터페이스


## System call & Library

### System call
- 응용 프로그램 실행 시 커널의 함수를 이용하기 위해 유저 모드에서 커널 모드로 전환하여 커널에 접근할 수 있도록 하는 인터페이스
![image](https://github.com/Kimchaeeuny/System/assets/120534069/53669524-06cb-43e8-a169-a2c8dce72849)

### Library
- 프로그래밍 시 재사용 가능한 코드들을 정리한 파일

### 실습
![image](https://github.com/Kimchaeeuny/System/assets/120534069/dd858daf-56d2-4097-a037-780b8040f823)
![image](https://github.com/Kimchaeeuny/System/assets/120534069/72745abf-5c30-41ad-8954-7e1195ebbae9)
