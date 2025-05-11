#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#include <time.h>

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
void sizecmp() {}

// 두 개의 파일 블락 수를 비교하는 함수 작성
void blockcmp() {}

// 두 개의 파일 수정 날짜를 비교하는 함수 작성
void datecmp() {
    struct stat buf1, buf2;
    struct tm *time1, *time2;
    if (stat("text1", &buf1) == -1) {
        perror("stat text1");
        return;
    }
    if (stat("text2", &buf2) == -1) {
        perror("stat text2");
        return;
    }
    time1 = localtime(&buf1.st_mtime);
    time2 = localtime(&buf2.st_mtime);
    printf("text1 date: %04d-%02d-%02d\n", time1->tm_year+1900, time1->tm_mon+1, time1->tm_mday);
    printf("text2 date: %04d-%02d-%02d\n", time2->tm_year+1900, time2->tm_mon+1, time2->tm_mday);
    if ((time1->tm_year == time2->tm_year) && (time1->tm_mon == time2->tm_mon) && (time1->tm_mday == time2->tm_mday)) {
        printf("날짜가 같습니다.\n");
    } else if ((time1->tm_year < time2->tm_year) ||
               (time1->tm_year == time2->tm_year && time1->tm_mon < time2->tm_mon) ||
               (time1->tm_year == time2->tm_year && time1->tm_mon == time2->tm_mon && time1->tm_mday < time2->tm_mday)) {
        printf("text1가 더 이전에 수정되었습니다.\n");
    } else {
        printf("text2가 더 이전에 수정되었습니다.\n");
    }
}

// 두 개의 파일 수정 시간을 비교하는 함수 작성
void timecmp() {
    struct stat buf1, buf2;
    if (stat("text1", &buf1) == -1) {
        perror("stat text1");
        return;
    }
    if (stat("text2", &buf2) == -1) {
        perror("stat text2");
        return;
    }
    printf("text1 mtime: %ld.%09ld\n", buf1.st_mtim.tv_sec, buf1.st_mtim.tv_nsec);
    printf("text2 mtime: %ld.%09ld\n", buf2.st_mtim.tv_sec, buf2.st_mtim.tv_nsec);

    if (buf1.st_mtim.tv_sec == buf2.st_mtim.tv_sec && buf1.st_mtim.tv_nsec == buf2.st_mtim.tv_nsec) {
        printf("수정 시간이 같습니다.\n");
    } else if (buf1.st_mtim.tv_sec < buf2.st_mtim.tv_sec ||
              (buf1.st_mtim.tv_sec == buf2.st_mtim.tv_sec && buf1.st_mtim.tv_nsec < buf2.st_mtim.tv_nsec)) {
        printf("text1가 더 이전에 수정되었습니다.\n");
    } else {
        printf("text2가 더 이전에 수정되었습니다.\n");
    }
}