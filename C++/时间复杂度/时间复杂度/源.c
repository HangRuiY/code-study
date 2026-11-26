#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
//力扣面试题 17.04. 消失的数字
//int missingNumber(int* nums, int numsSize)
//{
//	int i = 0; int sum1 = 0; int sum2 = 0;
//	for (i = 0; i < numsSize; i++)
//	{
//		sum1 += nums[i];
//	}
//	for (i = 0; i <= numsSize; i++)
//	{
//		sum2 += i;
//	}
//	return sum2 - sum1;
//}
//int main()
//{
//	int arr[100] = { 0 };
//	int n = 0;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	printf("%d", missingNumber(arr,n));
//	return 0;
//}

//力扣189  旋转数组
//void reverse(int* nums, int left, int right)
//{
//    while (left < right)
//    {
//        int tmp = 0;
//        tmp = nums[left];
//        nums[left] = nums[right];
//        nums[right] = tmp;
//        left++; right--;
//    }
//}
//void rotate(int* nums, int numsSize, int k)
//{
//    if (k > numsSize)
//    {
//        k %= numsSize;
//    }
//    //前n-k个数字逆序
//    reverse(nums, 0, numsSize - k - 1);
//    //后面k个数字逆序
//    reverse(nums, numsSize - k, numsSize - 1);
//    //整体逆序
//    reverse(nums, 0, numsSize - 1);
//}
//int main()
//{
//    int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };//6 5 4 3 2 1 7 8 9 10
//    rotate(arr, 10, 4);                    //6 5 4 3 2 1 10 9 8 7
//    for (int i = 0; i < 10; i++)           //7 8 9 10 1 2 3 4 5 6
//    {
//        printf("%d ", arr[i]);
//    }
//    return 0;
//}