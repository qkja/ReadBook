/**
* User: Qkj
* Description: 
* Date: 2023-08-13
* Time: 23:18
*/
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main()
{
  char arr[10] = {0};
  while(1)
  {
    ssize_t s = read(0, arr, sizeof(arr));
    if(s == 0)
      break;
    arr[s-1] = 0;
      printf("%s %d\n",arr,(int)s);
      //puts(arr);
  }
 // while(fgets(arr, 9, stdin))
 // {
 //   arr[strlen(arr)] = '\0';
 //   puts(arr);
 // }
    puts("aaaaaaaaaaa");
  return 0;
}
