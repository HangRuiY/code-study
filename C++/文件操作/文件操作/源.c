#include <stdio.h>
#include <assert.h>
//打开 关闭 
//int main()
//{
//	//FILE* pf = fopen("自定义类型.exe", "r");
//	FILE* pf = fopen("文件操作.dat", "r"); 
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//写文件
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//写文件
//int main()
//{
//	
//	FILE* pf = fopen("文件操作.dat", "w"); //w-只写
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//写文件
//	/*fputc('a', pf);
//	fputc('b', pf);
//	fputc('c', pf);*/
//	fputc('a', stdout);
//	fputc('b', stdout);
//	fputc('c', stdout);
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//读文件
//int main()
//{
//
//	FILE* pf = fopen("文件操作.dat", "r"); //r-只读
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//读文件
//	int ret = fgetc(pf);
//	printf("%c", ret);
//	ret = fgetc(pf);
//	printf("%c", ret); 
//	ret = fgetc(pf);
//	printf("%c", ret);
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
//int main()
//{
//	int ret = fgetc(stdin);
//	printf("%c", ret);
//	ret = fgetc(stdin);
//	printf("%c", ret);
//	ret = fgetc(stdin);
//	printf("%c", ret);
//}

//fgets读文件
//int main()
//{
//	char arr[10] = { 0 };
//	FILE* pf = fopen("文件操作.dat", "r"); 
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//写文件
//	/*fputc("abcdef\n", pf);
//	fputc("qwedwf", pf);*/
//	//读文件
//	fgets(arr, 4, pf);
//	printf("%s\n", arr);
//	fgets(arr, 4, pf);
//	printf("%s\n", arr);
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//格式化写文件
struct s
{
	char arr[10];
	int a;
};
int main()
{
	struct s a = { 0 };
	FILE* pf = fopen("文件.dat", "r");
	assert(pf != NULL);
	//写文件
	fprintf(pf, "%s %d", a.arr, a.a);
	//读文件
	fscanf(pf, "%s %d\n", a.arr, &a.a);
	//打印
	fprintf(stdout,"%s %d", a.arr, a.a);
	//关闭文件
	fclose(pf);
	pf = NULL;
	return 0;
}