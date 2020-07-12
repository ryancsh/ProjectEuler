#include "stdio.h"

int test1(){
  if(problem1(49) == 543 && problem1(1000) == 233168 && problem1(8456) == 16687353 && problem1(19564) == 89301183) return 1;
  return 0;
}

int test2(){
  if(problem2(10) == 10 && problem2(60) == 44 && problem2(1000) == 798 && problem2(100000) == 60696 && problem2(4000000) == 4613732) return 1;
  return 0;
}

int test(){
  printf("--------\n");
  int result = test1();
  if(result) printf("Test 1 Success\n");
  else printf("Test1 Failed\n");

  result = result && test2();
  if(result) printf("Test 2 Success\n");
  else printf("Test 2 Failed\n");
  
  printf("--------\n");
  return result;
}

int main(){
  test();
  printf("%d\n",test2());
  return 0;
}