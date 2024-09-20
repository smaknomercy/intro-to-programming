#include <stdio.h>

int main() {
  printf("Article title: The fundamental types in C++\n");
  printf("Article URL: https://en.cppreference.com/w/cpp/language/types\n");
  printf("Summary table:\n");
  printf("  |----------------------|--------------|----|-----|-----|----|\n");
  printf("  |\t   Name \t |C++ standard\t|LP32|ILP32|LLP64|LP64|\n");
  printf("  |----------------------|--------------|----|-----|-----|----|\n");
  printf("  | \tsigned char \t | at least 8\t| 8  |  8  |  8  | 8  |\n");
  printf("  |----------------------|--------------|----|-----|-----|----|\n");
  printf("  | \tunsigned char \t | at least 8\t| 8  |  8  |  8  | 8  |\n");
  printf("  |----------------------|--------------|----|-----|-----|----|\n");
  printf("  | \tshort int\t | at least 16\t| 16 |  16 |  16 | 16 |\n");
  printf("  |----------------------|--------------|----|-----|-----|----|\n");
  printf("  |    unsigned short int| at least 16\t| 16 |  16 |  16 | 16 |\n");
  printf("  |----------------------|--------------|----|-----|-----|----|\n");
  printf("  | \tint\t\t | at least 16\t| 16 |  32 |  32 | 32 |\n");
  printf("  |----------------------|--------------|----|-----|-----|----|\n");
  printf("  | \tunsigned int\t | at least 16\t| 16 |  32 |  32 | 32 |\n");
  printf("  |----------------------|--------------|----|-----|-----|----|\n");
  printf("  | \tlong int\t | at least 32\t| 32 |  32 |  32 | 64 |\n");
  printf("  |----------------------|--------------|----|-----|-----|----|\n");
  printf("  | \tunsigned long int| at least 32\t| 32 |  32 |  32 | 64 |\n");
  printf("  |----------------------|--------------|----|-----|-----|----|\n");
  printf("  | \tlong long int\t | at least 64\t| 64 |  64 |  64 | 64 |\n");
  printf("  |----------------------|--------------|----|-----|-----|----|\n");
  printf("  |unsigned long long int| at least 64\t| 64 |  64 |  64 | 64 |\n");
  printf("  |----------------------|--------------|----|-----|-----|----|\n");
  return 0;
} 