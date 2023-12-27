#include<stdio.h>
#include<string.h>

int main()
{
  char s1[4] = "hdz";//字符数组
  char *s2 = "hello";//字符指针
  char s3[4] = {'H','D','Z','\0'};//字符数组初始化  
  char *s4 = {'H','D','Z'};//字符指针初始化
  strcp(s1,s2);//复制字符串
  strncp(s1,s2);//复制指定长度的字符串
  strcat(s1,s2);//追加字符串
  strncat(s1,s2,n);//追加指定长度字符串
  strlen(s1);//长度
  strcmp(s1,s2);//比较字符串内容
  strcasecmp(s1
