#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//力扣 27 移除元素
//int removeElement1(int* nums, int numsSize, int val)
//{
//    int size = numsSize;
//    for (int i = 0; i < size; i++)
//    {
//        if (nums[i] == val)
//        {
//            for (int j = i + 1; j < size; j++)
//            {
//                nums[j - 1] = nums[j];
//            }
//            i--;
//            size--;
//        }
//    }
//    return size;
//}
//int removeElement2(int* nums, int numsSize, int val)
//{
//    int src = 0; int dst = 0;
//    while (src < numsSize)
//    {
//        if (nums[src] != val)
//        {
//            nums[dst] = nums[src];
//            src++; dst++;
//        }
//        else
//            src++;
//    }
//    return dst;
//}
//int main()
//{
//    int arr[10] = { 1,2,3,4,5,5,5,6,6,7 };
//    int p = removeElement1(arr, 10, 5);
//    for (int i = 0; i < p; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    return 0;
//}

//26. 删除有序数组中的重复项
//int removeDuplicates(int* nums, int numsSize)
//{
//    if (numsSize == 0)
//        return 0;
//    int i = 0; int j = 1; int dst = 0;
//    while (j < numsSize)
//    {
//        if (nums[i] == nums[j])
//        {
//            j++;
//        }
//        else
//        {
//            nums[dst] = nums[i];
//            dst++;
//            i = j;
//            j++;
//        }
//    }
//    nums[dst] = nums[i];
//    dst++;
//    return dst;
//}
//int main()
//{
//    int arr[3] = { 1,1,2 };
//    printf("%d",removeDuplicates(arr, 3));
//    return 0;
//}

//88. 合并两个有序数组
//void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
//{
//    int end1 = m - 1; int end2 = n - 1;
//    int end = m + n - 1;
//    while (end1 >= 0 && end2 >= 0)
//    {
//        if (nums1[end1] > nums2[end2])
//        {
//            nums1[end--] = nums1[end1--];
//        }
//        else
//        {
//            nums1[end--] = nums2[end2--];
//        }
//    }
//    while (end2 >= 0)
//    {
//        nums1[end--] = nums2[end2--];
//    }
//}
//int main()
//{
//    int arr1[6] = { 1,2,3,0,0,0 }; int arr2[3] = { 2,5,6 };
//    merge(arr1, 6, 3, arr2, 3, 3);
//}