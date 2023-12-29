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
  strcasecmp(s1,s2);//忽略大小的比较字符串
  strncmp(s1,s2);//比较指定长度的字符串
  strchr(s1,s);//在字符串中查找指定字符
  strrchr(s1,s);//在字符串中反向查找
  strstr(s1,s2);//查找字符串
  strpbrk(s1,s2);//以目标字符串的所有字符作为集合，在当前字符串查找该集合的任一元素
  strspn(s1,s2);//以目标字符串的所有字符作为集合，在当前字符串查找不属于该集合的任一元素的偏移
  strcspn(s1,s2);//以目标字符串的所有字符作为集合，在当前字符串查找属于该集合的任一元素的偏移

  strtod(s1,ppend);//从字符串 s1 中转换 double 类型数值，并将后续的字符串指针存储到 ppend 指向的 char* 类型存储。
  strtol(p, ppend, base);//从字符串 p 中转换 long 类型整型数值，base 显式设置转换的整型进制，设置为 0 以根据特定格式判断所用进制，0x, 0X 前缀以解释为十六进制格式整型，0 前缀以解释为八进制格式整型
  atoi(p);//字符串转换到 int 整型
  atof(p);//字符串转换到 double 符点数
  atol(p);//字符串转换到 long 整型

  isalpha();// 检查是否为字母字符
  isupper();// 检查是否为大写字母字符
  islower();// 检查是否为小写字母字符
  isdigit();// 检查是否为数字
  isxdigit();// 检查是否为十六进制数字表示的有效字符
  isspace();// 检查是否为空格类型字符
  iscntrl();// 检查是否为控制字符
  ispunct();// 检查是否为标点符号
  isalnum();// 检查是否为字母和数字
  isprint();// 检查是否是可打印字符
  isgraph();// 检查是否是图形字符，等效于 isalnum() | ispunct()
}
