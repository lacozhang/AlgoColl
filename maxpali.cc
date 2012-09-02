#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void foo(char a[100],int cnt[256])
{
		memset(cnt ,0, sizeof(int)*256);
		while (*a!='\0')
		{
				++cnt[*a];
				++a;
		}
		for ( char c='a';c<='z';++c)
		{
				printf("%c:%d\n",c,cnt[c]);
		}
}

int main()
{
		char a[100]="百度abc";
		int cnt[256];
		foo(a,cnt);
		int *c = new int[10];
		int *b = new int[10]();
		for(int i=0; i<10; i++){
				printf("%d:%d\n", c[i], b[i]);
		}
		return 0;
}
