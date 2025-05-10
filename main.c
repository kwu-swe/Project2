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
void filetime1() {
   struct stat fileStat;
    if (stat("text1", &fileStat) == -1) {
        perror("stat");
        return;
    }

    struct tm *modTime = localtime(&fileStat.st_mtime);
    printf("File: text1\n");
    printf("Last modification date: %02d/%02d\n", modTime->tm_mon + 1, modTime->tm_mday); // 월/일
    printf("Last modification time: %02d:%02d\n", modTime->tm_hour, modTime->tm_min);     // 시:분
}

// 파일 2의 시간 정보를 가져오는 함수 작성
void filetime2() {
   struct stat fileStat;
    if (stat("text2", &fileStat) == -1) {
        perror("stat");
        return;
    }

    struct tm *modTime = localtime(&fileStat.st_mtime);
    printf("File: text2\n");
    printf("Last modification date: %02d/%02d\n", modTime->tm_mon + 1, modTime->tm_mday); // 월/일
    printf("Last modification time: %02d:%02d\n", modTime->tm_hour, modTime->tm_min);     // 시:분
}

// 두 개의 파일 크기를 비교하는 함수 작성
void sizecmp() {}

// 두 개의 파일 블락 수를 비교하는 함수 작성
void blockcmp() {}

// 두 개의 파일 수정 날짜를 비교하는 함수 작성
void datecmp() {}

// 두 개의 파일 수정 시간을 비교하는 함수 작성
void timecmp() {}