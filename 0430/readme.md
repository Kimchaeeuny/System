# 240430 시스템프로그래밍

## 파일 시스템 구조

### 부트 블록(Boot Block)
-파일 시스템 시작부에 위치하고 보통 첫 번째 섹터를 차지
-부트스트랩 코드가 저장되는 블록

### 슈퍼 블록(Super Block)
-전체 파일 시스템에 대한 정보를 저장
(총 블록 수, 사용 가능한 i-노드 개수, 사용 가능 한 블록 비트 맵, 블록의 크기, 사용 중안 블록 수, 사용 가능한 블록 수 등)

### i-리스트(i-list)
-각 파일을 나타내는 모든 i-노드들의 리스트
-한 블록은 약 40개 정도의 i-노드를 포함

### 데이터 블록(Data Block)
-파일의 내용(데이터)을 저장하기 위한 블록들

## 파일 상태(file status)

### 파일 상태
-파일에 대한 모든 정보
-블록수, 파일 타입, 사용 권한, 링크수, 파일 소유자의 사용자 ID, 그룹 ID, 파일 크기, 최종 수정 시간 등

### stat 구조체
![image](https://github.com/Kimchaeeuny/System/assets/120534069/34b12b91-51f4-418d-8a34-6969bb06d35e)

## 파일 사용 권한

### 각 파일에 대한 권한 관리
- 각 파일마다 사용권한이 있다.
- 소유자(owner)/그룹(qroup)/기타(others)로 구분해서 관리한다.

### 파일에 대한 권한
- 읽기 r
- 쓰기 w
- 실행 x

### ![image](https://github.com/Kimchaeeuny/System/assets/120534069/1fbb1d6f-c84f-4a19-a2b6-fd8529485df8)

## 디렉토리 리스트

### opendir()
- 디렉터리 열기 함수
- DIR 포인터(열린 디렉터리를 가리키는 포인터) 리턴

### readdir()
- 디렉터리 읽기 함수
- ![image](https://github.com/Kimchaeeuny/System/assets/120534069/074906df-3241-4034-bb1d-2bd13f964a95)

## 파일 이름/크기 출력

### 디렉터리 내에 있는 파일 이름과 그 파일의 크기(블록의 수)를 출력하도록 확장

###![image](https://github.com/Kimchaeeuny/System/assets/120534069/9c044d19-fe07-40bf-a1e8-8cc9a5150b6d)

## st_mode

### lsat() 시스템 호출
- 파일 타입과 사용권한 정보는 st-> st_mode 필드에 함께 저장됨

### st_mode 필드
- 4비트: 파일 타입
- 3비트: 특수용도
- 9비트: 사용권한
  - 3비트: 파일 소유자의 사용권한
  - 3비트: 그룹의 사용권한
  - 3비트: 기타 사용자의 사용권한
 
## 디렉토리 만들기

### mkdir() 시스템 호출
- path가 나타내는 새로운 디렉터리를 만든다.
- "."와 ".."파일은 자동적으로 만들어진다.
- ![image](https://github.com/Kimchaeeuny/System/assets/120534069/92cf317d-627e-4a30-933a-f72d5b870e78)


## 디렉토리 삭제

### rmdir() 시스템 호출
- path가 나타내는 디렉토리가 비어 있으면 삭제한다.
- ![image](https://github.com/Kimchaeeuny/System/assets/120534069/b8fa3ba2-a463-4404-859b-5f79c59c141b)

## 디렉토리 구현

### 파일 시스템 구조를 보자
- 디렉토리를 위한 구조는 따로 없다.

### 파일 시스템 내에서 디렉터리를 어떻게 구현할 수 있을까?
- 디렉터리도 일종의 파일로 다른 파일처럼 구현된다.
- 디렉터리도 다른 파일처럼 하나의 i-노드로 표현된다.
- 디렉터리의 내용은 딝터리 엔트리(파일이름, i-노드 번호)
- ![image](https://github.com/Kimchaeeuny/System/assets/120534069/682c8b64-6d7f-4b31-9458-04cf31c9ddcd)

## 링크

### 링크는 기존 파일에 대한 또 다른 이름으로, 하드 링크와 심볼릭(소프트)링크가 있다.

![image](https://github.com/Kimchaeeuny/System/assets/120534069/f530c6cb-59b9-4d0e-963c-f4d0febe9b5b)


## 하드 링크 vs 심볼릭 링크

### 하드 링크
- 지금까지 살펴본 링크
- 파일 시스템 내의 i-노드를 가리키므로 같은 파일 시스템 내에서만 사용될 수 있다

### 심볼릭 링크
- 소프트 링크
- 실제 파일의 경로명을 저장하고 있는 링크
- 파일에 대한 간접적인 포인터 역할을 한다
- 다른 파일 시스템에 있는 파일도 링크 가능
- ![image](https://github.com/Kimchaeeuny/System/assets/120534069/2458fbe5-ec18-4d2e-901b-b7d2ec388043)


