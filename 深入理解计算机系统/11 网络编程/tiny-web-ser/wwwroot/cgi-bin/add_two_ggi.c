/**
 * User: Qkj
 * Description:
 * Date: 2023-08-14
 * Time: 13:18
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
  char *buf = NULL;
  char *p = NULL;
#define MAXLINE 1024
  char arg1[MAXLINE] = {0};
  char arg2[MAXLINE] = {0};
  char content[MAXLINE] = {0};
  int n1 = 0;
  int n2 = 0;
  if ((buf = getenv("QUERY_STRING")) != NULL)
  {
    p = strchr(buf, '&');
    *p = '\0';
    strcpy(arg1, buf);
    strcpy(arg2, p + 1);
    n1 = atoi(arg1);
    n2 = atoi(arg2);
  }
  sprintf(content, "Welcome to add.com: ");
  sprintf(content, "%sTHE Internet addition portal.\r\n<p>", content);
  sprintf(content, "%sThe answer is: %d + %d =  %d\r\n<p>", content, n1, n2, n1 + n2);
  sprintf(content, "%sThanks for visting!\r\n", content);

  printf("Content-length: %d\r\n", (int)strlen(content));
  printf("Content-type: test/html\r\n\r\n");

  printf("%s", content);
  fflush(stdout);
  exit(0);
}
