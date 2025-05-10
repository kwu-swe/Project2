#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

struct stat stat1, stat2;
struct tm *time1, *time2;

void filestat1();
void filestat2();
void filetime1();
void filetime2();
void sizecmp();
void blockcmp();
void datecmp();
void timecmp();

int main() {
  filestat1();
  filestat2();
  filetime1();
  filetime2();
  sizecmp();
  blockcmp();
  datecmp();
  timecmp();
}

// 파일 1의 정보를 가져오는 함수 작성
void filestat1() {}

// 파일 2의 정보를 가져오는 함수 작성
void filestat2() {}

// 파일 1의 시간 정보를 가져오는 함수 작성
void filetime1() {}

// 파일 2의 시간 정보를 가져오는 함수 작성
void filetime2() {}

// 두 개의 파일 크기를 비교하는 함수 작성
void sizecmp() {
  struct stat stat1, stat2;

    if (stat("text1", &stat1) == -1) {
        perror("stat text1");
        return;
    }
    if (stat("text2", &stat2) == -1) {
        perror("stat text2");
        return;
    }


    if (stat1.st_size > stat2.st_size) {
        printf("text1 is bigger\n");
    } else if (stat1.st_size < stat2.st_size) {
        printf("text2 is bigger\n");
    } else {
        printf("sizes are equal\n");
    }
}

// 두 개의 파일 블락 수를 비교하는 함수 작성
void blockcmp() {}

// 두 개의 파일 수정 날짜를 비교하는 함수 작성
void datecmp() {}

// 두 개의 파일 수정 시간을 비교하는 함수 작성
void timecmp() {}