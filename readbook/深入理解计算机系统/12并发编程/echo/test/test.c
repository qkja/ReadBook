/**
 * User: Qkj
 * Description:
 * Date: 2023-08-13
 * Time: 23:18
 */
// #include <stdio.h>
// #include <string.h>
// #include <unistd.h>

// int main()
// {
//   char arr[10] = {0};
//   while(1)
//   {
//     ssize_t s = read(0, arr, sizeof(arr));
//     if(s == 0)
//       break;
//     arr[s-1] = 0;
//       printf("%s %d\n",arr,(int)s);
//       //puts(arr);
//   }
//  // while(fgets(arr, 9, stdin))
//  // {
//  //   arr[strlen(arr)] = '\0';
//  //   puts(arr);
//  // }
//     puts("aaaaaaaaaaa");
//   return 0;
// }
#include <stdio.h>
#include <string.h>

int main()
{

#define SPACE "\r\n"
#define MAXLINE 1204
#define MINLINE 100
  char str[] = "This a sample\r\n";

  char m_u_v[MINLINE] = {0};
  char *method = NULL;
  char *uri = NULL;
  char *version = NULL;

  char *pch = strstr(str, SPACE);
  strncpy(m_u_v, str, pch - str);

  method = strtok(m_u_v, " ");
  uri = strtok(NULL, " ");
  version = strtok(NULL, " ");
  printf("%s\n%s\n%s\n", method, uri, version);
  return 0;
}

// int main()
// {
//   char str[] = "This a sample\r\n string.";
//   // char *pch;
//   // printf("Splitting string \"%s\" into tokens:\n", str);
//   char *pch = strstr(str, "\r\n");
//   char arr[20];
//   strncpy(arr, str, pch-str);
//     printf("%s\n", arr);

//   // getline()
//   // pch = strtok(str, " \r\n");
//   // while (pch != NULL)
//   // {
//   //   printf("%s\n", pch);
//   //   pch = strtok(NULL, " \r\n");
//   // }

//   return 0;
// }