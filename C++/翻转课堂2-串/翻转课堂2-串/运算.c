#include "串.h"
#include <string.h>
char* StrAssign(char* str, char* s)
{
	assert(str && s);
	while (*s != '\0')
	{
		*str = *s;
		*str++, *s++;
	}
	return str;
}
char* StrCopy(char* str, char* t)
{
	const char* start = t;
	while (*t != '\0')
	{
		*str = *t;
		str++;
		t++;
	}
	return start;
}
int StrLength(char* str)
{
	int cnt = 0;
	assert(str);
	while (*str != '\0')
	{
		cnt++; str++;
	}
	return cnt;
}
char* StrInsert(char* str, int pos, char* t)
{
	int len1 = StrLength(str);
	int len2 = StrLength(t);
	for (int i = len1 - 1; i >= pos - 1; i--)
	{
		str[i + len2] = str[i];//先把str往后移动
	}
	for (int i = pos - 1; i < pos - 1 + len2; i++)
	{
		str[i] = t[i - pos + 1];//从t[0]开始赋值 
	}
	return str;
}
char* StrDelete(char* str, int pos, int len)
{
	int i = 0, j = 0;
	int L = StrLength(str);
	char* ret = (char*)malloc(100 * sizeof(char));
	char c;
	for (i = 0; i < pos - 1; i++) 
	{
		ret[i] = str[i];
	}
	j = pos + len - 1;
	while ((c = str[j++]) != '\0') 
	{
		ret[i++] = c;
	}
	ret[i] = '\0';
	return ret;

}
void SteCmp(char* str, char* t)
{
	while (*str == *t)
	{
		if (*str == '\0')
		{
			printf("相等\n");
			return;
		}
		str++; t++;
	}
	printf("不相等\n");
	return;
}
char* StrCat(char* str, char* t)
{
	char* ret = str;
	assert(str && t);
	while (*str != '\0')
		str++;  //先找到目标字符串中的\0
	while (*str = *t)
	{
		str++; t++;
	}
	return ret;
}
char* SubStr(char* t, char* str, int pos, int len)
{
	int cnt = 1;
	char* ret = t;
	while (cnt != pos)
	{
		cnt++, *str++;
	}
	cnt = 0;
	while (cnt != len)
	{
		*t = *str;
		*str++, * t++;
		cnt++;
	}
	return ret;
}
int StrIndex(char* str, int pos, char* t)
{
	int len1 = StrLength(str);
	int len2 = StrLength(t);
	int flag = 0;
	for (int i = pos - 1; i < len1; i++)
	{
		if (str[i] == t[0])
		{
			int k = i;
			for (int j = 0; j < len2; j++)
			{
				if (str[k] == t[j])
				{
					k++;
				}
				if (k - i == len2)
				{
					flag = 1;
				}
			}
		}
		if (flag == 1)
		{
			return i + 1;
		}
	}
	if (!flag)
		return -1;
}
char* StrReplace(char* str, char* t, char* p)
{
	int find_len = StrLength(t);
	int replace_len = StrLength(p);
	int str_len = StrLength(str);
	int i, j, k;
	int new_len = str_len;
	for (i = 0; i < str_len; i++) 
	{
		if (strstr(&str[i], t) == &str[i])
		{
			new_len += replace_len - find_len;
			i += find_len - 1;
		}
	}
	char* new_str = (char*)malloc(sizeof(char) * (new_len + 1));
	i = 0;
	j = 0;
	while (i < str_len) 
	{
		if (strstr(&str[i], t) == &str[i]) 
		{
			for (k = 0; k < replace_len; k++) 
			{
				new_str[j++] = p[k];
			}
			i += find_len;
		}
		else 
		{
			new_str[j++] = str[i++];
		}
	}
	new_str[j] = '\0';
	return StrCopy(str, new_str);
	
}
bool StrEmpty(char* str)
{
	if (str == NULL)
		return true;
	else
		return false;
}
char* StrClear(char* str)
{
	*str = NULL;
	return str;
}

