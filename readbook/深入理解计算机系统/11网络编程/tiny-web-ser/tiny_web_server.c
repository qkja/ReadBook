/**
 * User: Qkj
 * Description: 一个简单的基于HTTP/1.0web服务器,处理静态的和动态的内容
 * Date: 2023-08-14
 * Time: 13:39
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
#include "../open_fd/open_listenfd.h"

#define LINE "\r\n"
#define SPACE " "
#define MAXLINE 1204
#define MINLINE 100

void doit(int fd);
void read_requesthdr(char *buf);
int parse_uri(char *uri, char *filename, char *cgiagrs);
void serve_static(int fd, char *filename, int fileszie);
// void get_filetype(char *filename, char *filetype);
void serve_dynamic(int fd, char *filename, char *cgiagrs);
void clienterror(int fd, char *cause, char *errnum, char *shortmsg, char *longmsg);

int main(int argc, char **argv)
{
  int listenfd = -1;
  // int connfd = -1;
  int port = 0;
  socklen_t clientlen = 0;
  struct sockaddr_in clientaddr;

  if (argc != 2)
  {
    fprintf(stderr, "Usage:\n\t %s <port>\n", argv[0]);
    exit(1);
  }
  port = atoi(argv[1]);

  listenfd = open_listenfd(port);
  // printf("=========================\n");
  while (1)
  {
    clientlen = sizeof(clientaddr);
    // printf("--------------\n");
    int connfd = accept(listenfd, (struct sockaddr *)&clientlen, &clientlen);
    // if(connfd == -1)
    // continue;
    printf("已经被打开%d\n", connfd);
    sleep(10);
    // doit(connfd);

    // while (1)
    // {
    //   /* code */
    //   printf("--------------\n");
    //   sleep(3);
    // }

    // doit(connfd); // 处理
    // while (1)
    // {
    //   printf("--------------\n");
    //   sleep(2);
    // }
    // sleep(2);
    // printf("--------------\n");
    close(connfd);
    printf("已经被被关闭%d\n", connfd);
    // printf("--------------\n");
  }
  return 0;
}

// 读取并解析请求行
void doit(int fd)
{

  int is_static = 0;
  char buf[MAXLINE] = {0};

  char m_u_v[MINLINE] = {0};
  char filename[MINLINE] = {0};
  char cgiargs[MINLINE] = {0};

  struct stat sbuf;

  char *method = NULL;
  char *uri = NULL;
  char *version = NULL;
  while (1)
  {
    // 读取请求
    ssize_t s = read(fd, buf, sizeof(buf) - 1);
    if (s == 0)
    {
      printf("hello\n");
      return;
    }
    else if (s > 0)
    {
      buf[s] = '\0';

      // 拿到请求行

      char *pch = strstr(buf, LINE);  // 寻找第一行
      strncpy(m_u_v, buf, pch - buf); // 拷贝
      method = strtok(m_u_v, SPACE);
      uri = strtok(NULL, SPACE);
      version = strtok(NULL, SPACE);
      printf("%s %s %s %d\n", method, uri, version, __LINE__);

      if (strcasecmp(method, "GET"))
      {
        // 此时出现请求错误
        clienterror(fd, method, "501", "Not Implemented", "该服务器不支持");
        return;
      }
      // read_requesthdr(buf);

      // parse uri from get request
      is_static = parse_uri(uri, filename, cgiargs);

      if (stat(filename, &sbuf) < 0)
      {
        clienterror(fd, filename, "404", "Not found", "没有这个文件");
        return;
      }
      // printf("%s %d %d %d\n", filename, is_static, sbuf.st_size, __LINE__);

      // printf("--------------\n");
      serve_static(fd, filename, sbuf.st_size);
      // printf("--------------\n");

      // if (is_static == 1)
      // {
      //   // 是静态的
      //   // 这里也要判断一下
      //   // serve_static(fd, filename, sbuf.st_size);
      // }
      // else
      // {
      //   // 动态的
      //   serve_dynamic(fd, filename, cgiargs);
      // }
    }
    else
    {
    }
  }
}

void read_requesthdr(char *buf)
{
  return;
}

int parse_uri(char *uri, char *filename, char *cgiagrs)
{
#define root "/home/bit/read/readbook/深入理解计算机系统/11网络编程/tiny-web-ser/wwwroot"

  int falg = 1;
  // 静态的 1
  if (strstr(uri, "cgi-bin") == NULL)
  {

    // 静态的
    sprintf(filename, "%s", root);
    if (*uri == '/' && strlen(uri) == 1)
      sprintf(filename, "%s/index.html", filename);
    else
      sprintf(filename, "%s%s", filename, uri);
  }
  else
  {
    falg = 0;
  }
  return falg;
}
// 处理我们的文件
void serve_static(int fd, char *filename, int fileszie)
{
  char buf[MAXLINE] = {0};
  sprintf(buf, "HTTP/1.0 200 OK\r\n");
  sprintf(buf, "%sServer: Tiny Web Server\r\n", buf);
  sprintf(buf, "%sContent-length: %d\r\n", buf, fileszie);
  sprintf(buf, "%sContent-type: TXT\r\n", buf);
  sprintf(buf, "%s%s", buf, LINE);

  // printf("%s\n", buf);

  write(fd, buf, (size_t)strlen(buf));

  // 填写正文
  umask(0);
  char body[MAXLINE] = {0};
  int read_fd = open(filename, O_RDWR, 0666);
  ssize_t s = read(read_fd, body, sizeof(body) - 1);
  body[s] = '\0';
  // printf("%s\n", body);

  write(fd, body, (size_t)strlen(body));
}

// void get_filetype(char *filename, char *filetype)
// {
// }
void serve_dynamic(int fd, char *filename, char *cgiagrs)
{
}
// 客户端请求出现错误
void clienterror(int fd, char *cause, char *errnum, char *shortmsg, char *longmsg)
{
  char buf[MAXLINE] = {0};
  char body[MAXLINE] = {0};

  // 编辑响应主题
  sprintf(body, "<html><title>Tiny Error</title>");
  sprintf(body, "%s<body bgcolor="
                "ffffff"
                ">\r\n",
          body);
  sprintf(body, "%s%s: %s\r\n", body, errnum, shortmsg);
  sprintf(body, "%s<p>%s: %s\r\n", body, longmsg, cause);
  sprintf(body, "%s<hr><em>The Tiny Web server</em>\r\n", body);

  // 编辑响应行和响应报头
  sprintf(buf, "HTTP/1.0 %s %s\r\n", errnum, shortmsg);
  write(fd, buf, (size_t)strlen(buf));
  sprintf(buf, "Content-type: text/html\r\n");
  write(fd, buf, (size_t)strlen(buf));
  sprintf(buf, "Content-length: %d\r\n", (int)strlen(body));
  write(fd, buf, (size_t)strlen(buf));
  sprintf(buf, "%s", LINE);
  write(fd, buf, (size_t)strlen(buf));

  // 填写正文
  write(fd, body, strlen(body));
}