// stack.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <locale.h>

#define MAX 100

int *p;   /* ��������� �� ������� ��������� ������ */
int *tos; /* ��������� �� ������� ����� */
int *bos; /* ��������� �� ��� ����� */

void push(int i);
int pop(void);

 


int _tmain(int argc, _TCHAR* argv[])
{

	setlocale( LC_CTYPE, ".1251" );
	
  char s[80];

  p = (int *) malloc(MAX*sizeof(int)); /* �������� ������ ��� ����� */
  if(!p) {
    printf("������ ��� ��������� ������\n");
    exit(1);
  }
  tos = p;
  bos = p + MAX-1;


  do {
    printf("1 - push, 2- pop");
    gets(s);
    switch(*s) {
       case '1':
		int a;
		printf(": ");
		scanf("%d", a);
		push(a);
		break;
      case '2':{
        int b = pop();
        printf("%d", b);
        break;
	  default:
		  {
			  break;
		  }
		}
	     
    }
  }
  while(*s != 'q');
	
  return 0;
}

/* ��������� �������� � ����. */
void push(int i)
{
  if(p > bos) {
    printf("���� �����\n");
    return;
  }
  *p = i;
   p++;
}

/* ��������� �������� �������� �� �����. */
int pop(void)
{
  p--;
  if(p < tos) {
    printf("���� ����\n");
    return 0;
  }
  return *p;
}

