

#include<stdio.h>
#include<assert.h>
#include<Windows.h>
//模拟实现memcpy
void * Mymemcpy(void * dst, const void * str, int n)
{
	assert(dst);
	assert(str);
	char*p = (char*)dst;
	const char*q= (const char*)str;
	while (n)
	{
		*p = *q;
		p++;
		q++;
		n--;
	}
	return dst;
}
//模拟实现memmove
void *Mymemmove(void *dst, const void *str, int n)
{
	assert(dst);
	assert(str);

	char *_dst = (char *)dst;
	const char *_str = (const char *)str;

	if (_dst > _str && _dst < _str + n)//right -> left
	{
		_dst = _dst + n - 1;
		_str = _str + n - 1;

		while (n){
			*_dst = *_str;
			_dst--;
			_str--;
			n--;
		}
	}
	else//left -> right
	{
		while (n)
		{
			*_dst = *_str;
			_dst++;
			_str++;
			n--;
		}
	}
	return dst;
}

//模拟实现strstr
void *Mystrstr(char *dst, const char* str)
{
	assert(dst);
	assert(str);
	
	while (*dst)
	{
		char *p = dst;
		const char*q = str;
		while (*p && *q && *p == *q)
		{
			p++;
			q++;
		}
		if (*q == '\0')
			return dst;
		dst++;
	}
	return 0;
}


int main()
{
	char  str[30] = "hello world!hello world!";
	//Mymemcpy(str+1, str, strlen(str)+1);
	//printf("%s\n", str);
	/*Mymemmove(str+1, str , strlen(str) + 1);
	printf("%s\n", str);*/
	char *p = Mystrstr(str, "world");
	Mymemmove(p, "kitty", 5);
	printf("%s\n", str);
	system("pause");
	return 0;
}
