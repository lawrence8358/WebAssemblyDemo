// EM_PORT_API 是為了告訴編譯器需保留我們自定義的 Methods
// https://www.cntofu.com/book/150/zh/ch2-c-js/ch2-01-js-call-c.md
#ifndef EM_PORT_API
#	if defined(__EMSCRIPTEN__)
#		include <emscripten.h>
#		if defined(__cplusplus)
#			define EM_PORT_API(rettype) extern "C" rettype EMSCRIPTEN_KEEPALIVE
#		else
#			define EM_PORT_API(rettype) rettype EMSCRIPTEN_KEEPALIVE
#		endif
#	else
#		if defined(__cplusplus)
#			define EM_PORT_API(rettype) extern "C" rettype
#		else
#			define EM_PORT_API(rettype) rettype
#		endif
#	endif
#endif

#include <stdio.h>

// 測試是否可以使用 ncnn
#include "net.h" 

// 測試是否可以使用 OpenCV
#include "opencv2/opencv.hpp" 

int main()
{
    printf("預設的 main Method\n");
    return 0;
}

// 故意寫一個 add Method 來測試是否可以被編譯器保留
EM_PORT_API(int) add(int a, int b) 
{
    int sum = a + b;
    printf("The sum of %d and %d is: %d\n", a, b, sum);
    return sum;
}

// 故意寫一個不會被編譯器保留的 helloWorld Method
void helloWorld() 
{
    printf("Hello World\n");
}