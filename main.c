#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

struct stat stat1, stat2;
struct tm *time1, *time2;

// 파일 크기 비교를 위한 변수
off_t size1, size2;

// 블록 수 비교를 위한 변수
blkcnt_t blocks1, blocks2;

// 날짜 비교를 위한 변수
int month1, month2;
int day1, day2;

// 시간 비교를 위한 변수
int hour1, hour2;
int min1, min2;

void filestat1();
void filestat2();
void filetime1();
void filetime2();
void sizecmp();
void blockcmp();
void datecmp();
void timecmp();

int main()
{
	filestat1();
	filestat2();
	filetime1();
	filetime2();
	sizecmp();
	blockcmp();
	datecmp();
	timecmp();
}

// Function to get information for file 1
void filestat1()
{
	// 파일 정보 가져오기 (전역 변수 stat1에 저장됨)
	if (stat("text1", &stat1) == -1)
	{
		perror("Failed to get information for text1");
		return;
	}

	// 시간 정보 가져오기 (전역 변수 time1에 저장됨)
	time1 = localtime(&stat1.st_mtime);

	// 사용할 파일 크기 및 블록 수를 변수에 저장
	size1 = stat1.st_size;
	blocks1 = stat1.st_blocks;

	// 사용할 수정 시간 정보를 변수에 저장
	if (time1 != NULL)
	{
		month1 = time1->tm_mon + 1;
		day1 = time1->tm_mday;
		hour1 = time1->tm_hour;
		min1 = time1->tm_min;
	}

	// ** 저장된 변수 값 테스트 출력
	// printf("\n=== text1 저장된 변수 값 ===\n");
	// printf("size1: %lld\n", size1);
	// printf("blocks1: %lld\n", blocks1);
	// printf("month1: %d\n", month1);
	// printf("day1: %d\n", day1);
	// printf("hour1: %d\n", hour1);
	// printf("min1: %d\n", min1);
}

// Function to get information for file 2
void filestat2()
{
	// 파일 정보 가져오기 (전역 변수 stat2에 저장됨)
	if (stat("text2", &stat2) == -1)
	{
		perror("Failed to get information for text2");
		return;
	}

	// 시간 정보 가져오기 (전역 변수 time2에 저장됨)
	time2 = localtime(&stat2.st_mtime);

	// 사용할 파일 크기 및 블록 수를 변수에 저장
	size2 = stat2.st_size;
	blocks2 = stat2.st_blocks;

	// 사용할 수정 시간 정보를 변수에 저장
	if (time2 != NULL)
	{
		month2 = time2->tm_mon + 1;
		day2 = time2->tm_mday;
		hour2 = time2->tm_hour;
		min2 = time2->tm_min;
	}

	// ** 저장된 변수 값 테스트 출력
	// printf("\n=== text2 저장된 변수 값 ===\n");
	// printf("size2: %lld\n", size2);
	// printf("blocks2: %lld\n", blocks2);
	// printf("month2: %d\n", month2);
	// printf("day2: %d\n", day2);
	// printf("hour2: %d\n", hour2);
	// printf("min2: %d\n", min2);
}

// 파일 1의 시간 정보를 가져오는 함수 작성
void filetime1() {}

// 파일 2의 시간 정보를 가져오는 함수 작성
void filetime2() {}

// 두 개의 파일 크기를 비교하는 함수 작성
void sizecmp() {}

// 두 개의 파일 블락 수를 비교하는 함수 작성
void blockcmp() {}

// 두 개의 파일 수정 날짜를 비교하는 함수 작성
void datecmp() {}

// 두 개의 파일 수정 시간을 비교하는 함수 작성
void timecmp() {}