#include <stdio.h>
#include <string.h>
#include <assert.h>
//int main()
//{
//	int arr1[20]={1, 2, 3, 4, 5, 6, 7, 8, 9};
//	int arr2[20] = { 0 };
//	memcpy(arr2, arr1, 20);
//
//	return 0;
//}

//模拟实现memcpy
//void* my_memcpy (void* dest, void* src, size_t num)
//{
//	assert(dest && src);
//	void* ret = dest;
//	while (num--)
//	{
//		//*(char*)dest = *(char*)src;//强制类型转换
//		//dest= (char*)dest + 1;
//		//src = (char*)src + 1;
//	}
//	return ret;
//}
//int main()
//{
//	int arr1[20] = { 1,2,3,4,5,6,7,8,9 };
//	int arr2[20] = { 0 };
//	my_memcpy(arr1, arr2, 20);
//}

//实现memmove
//void* my_memmove(void* dest, void* src, size_t num)
//{
//	assert(dest && src);
//	void* ret = dest;
//	while (num--)
//	{
//		*(char*)dest = *(char*)src;
//		dest = (char*)dest + 1;
//		src = (char*)src + 1;
//	}
//	while (num--)
//	{
//		*((char*)dest + num) = *((char*)src + num);
//	}
//	return ret;
//}
//int main()
//{
//	int arr1[20] = { 1,2,3,4,5,6,7,8,9 };
//	int arr2[20] = { 0 };
//	my_memmove(arr1 + 2, arr1, 20); //12345 拷贝到 34567
//}

int main()
{
	int arr[10] = { 0 };
	memset(arr, 1, 30);
}