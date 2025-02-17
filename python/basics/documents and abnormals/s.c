#define _CRT_SECURE_NO_WARNINGS//定义一个宏，使编译器不发出警告
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;
int main() {
 
	unsigned int width = 1024;//定义一个非负（无符号）整数，表示图像宽度1024
	unsigned int height = 1024;//定义一个非负整数，表示图像高度1024
	size_t pixelCount = width * height;//定义一个无符号整数类型像素数目，大小为宽乘高
	void* pData = malloc(pixelCount * sizeof(short));//将像素所占用的大小动态分配到内存，定义一个无类型指针将空间起始地址存在pData
	FILE* pFile = fopen("D:/OneDrive/sliced.img", "rb+");//定义一个文件指针pFile，fopen用于打开名为sliced.img的文件，以读写二进制方式打开
	if (pFile == NULL) {
		cout << "打开失败" << endl;
		free(pData);
		return 0;
	} //如果文件打开失败，则要释放malloc分配的动态内存空间，并返回0
 
 
	size_t rBite = fread(pData, sizeof(short), pixelCount, pFile);//fread用于从文件中读取数据，rBite是一个sie_t类型的变量，用于存储实际成功读取的数据项目
	//pData是malloc分配的内存空间起始地址，用于储存读取的数据，每个数据项的大小是sizeof(short)字节
   // 从文件中读取pixelCount数目个 short 类型的数据项，pFile指向要从中读取数据的文件。
	fclose(pFile);  //读取成功后关闭文件
	
 
	FILE* pnewFile = fopen("newsliced.img", "wb+");
	if (pnewFile == NULL) {
		cout << "打开失败" << endl;
		free(pData);
		return 0;
	}
	size_t wBite = fwrite(pData, sizeof(short), pixelCount, pnewFile);
	if (wBite != pixelCount) {
		cout << "写入未完成" << endl;
	}
 
	fclose(pnewFile);
	free(pData);//释放malloc分配的动态内存空间
 
	cout << "完成" << endl;
}