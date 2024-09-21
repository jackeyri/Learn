#include <stdio.h>  // strlen 和 malloc 函数没有被包含在这个头文件中
#include <stdlib.h>
#include <string.h>

void display1(char* string);  // 没有返回任何值。这可能会导致未定义的行为。我们应该改变这些函数的返回类型为 void，因为它们不需要返回任何值。
char* reverse(char* string);  // reverse 函数没有返回任何值，但在 main 函数中，我们试图将其返回值赋给 ptr。我们应该修改 reverse 函数以返回 string2。

int main() {
    char string[] = "Embeded Linux in ZhongShan Institute";
    char* ptr = NULL;
    display1(string);
    ptr = reverse(string);
    printf("the string len is %ld\n", strlen(ptr));
}

void display1(char* string) {
    printf("The original string is %s\n", string);
}

char* reverse(char* string1) {
    char* string2;
    int size = 0;
    int i = 0;
    size = strlen(string1);
    string2 = (char*)malloc(size + 1);
    for (i = 0; i < size; i++) {
        string2[size - i - 1] = string1[i];  // 在 reverse 函数中，我们在为 string2 分配内存后，试图访问 string2[size - i]，这是一个越界访问，因为 i 从 0 开始，所以 size - i 从 size 开始，这超出了我们为 string2 分配的内存。我们应该改为 string2[size - i - 1]。
    }
    string2[size] = '\0';  // 我们试图在 string2[size + 1] 位置设置一个空格，这也是一个越界访问。我们应该在 string2[size] 位置设置一个空字符（'\0'），以标记字符串的结束。
    printf("The string afterward is %s\n", string2);
	return string2;
}
