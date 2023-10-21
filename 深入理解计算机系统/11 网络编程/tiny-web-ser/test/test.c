/**
 * User: Qkj
 * Description:
 * Date: 2023-08-14
 * Time: 16:49
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <unistd.h>

#define LINE "\r\n"
#define SPACE " "
#define MAXLINE 1204
#define MINLINE 100

void serve_static(int fd, char *filename, int fileszie)
{
  char buf[MAXLINE] = {0};
  sprintf(buf, "HTTP/1.0 200 OK\n");
  sprintf(buf, "%sServer: Tiny Web Server\n", buf);
  sprintf(buf, "%sContent-length: %d\n", buf, fileszie);
  // sprintf(buf, "%sContent-type: TXT\r\n", buf);
  sprintf(buf, "%s", LINE);

  printf("%s\n", buf);
  printf("==============================\n");

  write(fd, buf, (size_t)strlen(buf));

  // 填写正文
  umask(0);

  char body[MAXLINE] = {0};
  int read_fd = open(filename, O_RDWR, 0666);
  ssize_t s = read(read_fd, body, sizeof(body) - 1);
  body[s] = '\0';
  printf("%s\n", body);

  write(fd, body, (size_t)strlen(body));
}
// int main()
// {
//   // char *filename = "/home/bit/read/readbook/深入理解计算机系统/11网络编程/tiny-web-ser/wwwroot/index.html";
//   // int fd = 1;
//   // serve_static(fd, filename, 10000);
//   printf("%s\n", strerror(139));
//   return 0;
// }

#include <string.h>  
  
int main()  
{  
  int n = 500;  
  for(int i=0; i<n; i++)  
  {  
    printf("%d %s\n",i,strerror(i));               
  }  
  return 1;  
}