/**
* User: Qkj
* Description: 
* Date: 2023-08-18
* Time: 23:45
*/
//void twiddle1(int* xp, int* yp)
//{
//  *xp += *yp;
//  *xp += *yp;
//}
//void twiddle2(int* xp, int* yp)
//{
//  *xp += 2 * *yp;
//}
//void swap(int *xp, int* yp)
//{
//  *xp = *xp + *yp;
//  *yp = *xp - *yp;
//  *xp = *xp - *yp;
//}
//int f();
//int func1()
//{
//  return f()+f()+f()+f();
//}
//int func2()
//{
//  return 4 * f();
//}
//int count = 0;
//int f()
//{
//  return count++;
//}
//void psum1(float a[], float p[], long int n)
//{
//  long int i = 0;
//  p[0] = a[0];
//  for(i = 1; i < n; i++)
//    p[i] = p[i-1] + a[i];
//}
//void psum2(float a[], float p[], long int n)
//{
//  long int i = 0;
//  p[0] = a[0];
//  for(i = 1; i < n-1; i+=2)
//  {
//    float mid_val = p[i-1] + a[i];
//    p[i] = mid_val;
//    p[i+1] = mid_val + a[i+1];
//  }
//  if(i < n)
//    p[i] = p[i-1] + a[i];
//}
#include <stdio.h>
#include <stdlib.h>

typedef int data_t;
typedef struct 
{
  long int len;
  data_t* data;
} vec_rec, *vec_ptr;

// 申请一篇空间
vec_ptr new_vec(long int len)
{
  vec_ptr result = (vec_ptr)malloc(sizeof(vec_rec));
  if(result == NULL)
    return NULL;
  result->len = len;
  if(len > 0)
  {
    data_t* data = (data_t*)calloc(len, sizeof(data_t));
    if(data == NULL)
    {
      free(result);
      return NULL;
    }
    result->data = data;
  }
  else 
    result->data = NULL;
  return result;
}
int get_vec_element(vec_ptr v, long int index, data_t* dest)
{
  if(index < 0 || index >= v->len)
    return 0;
  *dest = v->data[index];
  return 1;
}

long int vec_length(vec_ptr v)
{
  return v->len;
}
#define IDENT 0 
#define OP +
void combine1(vec_ptr v, data_t *dest)
{
  long int i = 0;
  *dest = IDENT;
  for(i = 0; i < vec_length(v); i++)
  {
    data_t val;
    get_vec_element(v, i, &val);
    *dest = *dest OP val;
  }
}
