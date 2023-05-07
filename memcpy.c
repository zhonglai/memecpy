#include <stdlib.h>
#include <stdio.h>

char a[] = "hello";
char b[] = "world";


void* memcpy(void* dst, const void* src, size_t count)
{
    // 检查指针是否为NULL
    if (dst == NULL || src == NULL) {
        printf("null pointer\n");
        return NULL;
    }

    // 判断 dst 拷贝 count 字节后是否会超越最大内存，从而反转到小内存
    if （(dst > src) && (dst + count < src + count)）
    {
        printf("dst exist memory reversal");
        return NULL;
    }

    // 强制转换指针为字节类型
    char* pDst = (char*)dst;
    const char* pSrc = (const char*)src;

    if (pSrc < pDst)
    {
        // 内存可能会存在重叠，进行反向拷贝
        pDst += count;
        pSrc += count;
        while (count--)
        {
            *--pDst = *--pSrc;
            // *--p  等价于 --p; *p
            // --*p  等价于 *p;(*p)--
            // *p--  和 *(p--) 等价于 *p;p-- 由于后置--是先作为整体参与前级运算，然后再进行指针--操作
        }
    }
    else
    {
        while (count--)
        {
            *pDst++ = *pSrc++;
        }

    }

    return dst;
}

int main()
{
    memcpy(a, b, 5);
}