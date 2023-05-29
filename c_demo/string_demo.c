#include <stdio.h>
#include <string.h>
#include "./include/io_utils.h"

/**
 * 从本质而言，C语言把字符串字面量作为字符数组来处理。
 * 当C语言编译器在程序中遇到长度为n的字符串字面量时，它会为字符串字面量分配长度为n+1的内存空间。
 * 这块内存空间将用来存储字符串字面量中的字符，以及一个用来标志字符串末尾的额外字符（空字符）。
 * 空字符是一个所有位都为0的字节，因此用转义序列\0来表示。
 * 只要保证字符串是以空字符结尾的，任何一维的字符数组都可以用来存储字符串
 *
 * 只包含一个字符的字符串字面量不同于字符常量。字符串字面量"a"是用指针来表示的，这个指针指向存放字
 * 符"a"（后面紧跟空字符）的内存单元。字符常量'a'是用整数（字符集的数值码）来表示的。
 *
 **/

size_t strlen1(const char *s)
{
    size_t n;
    for (n = 0; *s != '\0'; s++)
        n++;
    return n;
}

// 简化版本
size_t strlen(const char *s)
{
    size_t n = 0;
    while (*s++)
        n++;
    return n;
}

int main(void)
{
    char *p;
    // 这个赋值操作不是复制"abc"中的字符，而是使p指向字符串的第一个字符,始终要知道,P是一个指针
    p = "abc";
    char ch = p[1]; // 对指针下标取值
    PRINT_CHAR(ch);

    // 在声明为数组时，就像任意数组元素一样，可以修改存储在date中的字符。在声明为指针时，date指向字符串字面量，字符串字面量是不可以修改的。
    // 在声明为数组时，date是数组名。在声明为指针时，date是变量,这个变量可以在程序执行期间指向其他字符串。
    // 如果希望可以修改字符串，那么就要建立字符数组来存储字符串，声明指针变量就不够的.
    // 当使用char*来表示时,区分字符串还是字符,一个重要的判断就是最后有没有加"\0"
    char date[] = "June 14";
    char *date1 = "June 14";

    // strcpy函数把字符串s2复制给字符串s1
    strcpy(date, "aaa");

    PRINT_STRING(date);

    // 求字符串长度
    PRINT_INT(strlen(date));

    // 字符串拼接
    strcat(date, "bbb");
    PRINT_STRING(date);

    // 字符串的比较
    PRINT_INT(strcmp("abc", "acd"));

    // 以下的这两种赋值都是不可以的
    // 在C语言中，字符串常量是存储在静态区域（静态存储区）中的，它们的地址在编译时就已经确定，并且在程序运行期间不会改变。因此，当你将q指针
    // 重新赋值为指向另一个字符串常量"123"的首地址时，q指向的地址确实已经发生了变化，但实际上它仍然指向同一个静态区域中的内存地址。因此，打印出来的地址是一样的。
    // 需要注意的是，虽然字符串常量的地址不可改变，但是通过指针可以修改字符串常量的内容是一种未定义的行为，可能会导致程序崩溃或产生其他异常行为。
    // 因此，在使用字符串常量时应该遵循只读的原则，不要试图修改它们的内容。
    char *q = "111";
    PRINT_HEX(&q);
    q = "123";
    PRINT_HEX(&q);
    // *q = "333";
    PRINT_STRING(q);

    return 0;
}