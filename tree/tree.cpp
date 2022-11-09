////#undef UNICODE
////#undef _UNICODE
//
//#include <stdio.h>
////#include <iostream>
//#include <string.h>
////#include <graphics.h>
////#include <conio.h>
//#include "cJSON.h"
//#include "cJSON.c"
////#include "def_c.h"
//
///// <summary>
///// 一次性读取全部内容并返回文件内容地址
///// </summary>
///// <param name="path">文件路径</param>
///// <param name="length">储存文件大小的变量地址</param>
///// <returns>文件全部内容字符串地址</returns>
//char* ReadFile(char* path, int* length);
///// <summary>
///// 获取对象成员数
///// </summary>
///// <param name="JSON">对象</param>
///// <returns>对象的成员数</returns>
//int getNumObjects(cJSON* JSON);
//
////using namespace std;
//
//
//
//int main() {
//	int fileSize;
//	char* FILE = ReadFile("./data.json", &fileSize);
//	cJSON* JSON = cJSON_Parse(FILE);
//	if (JSON == NULL)
//	{
//		printf("解析失败\n");
//		return -1;
//	}
//	printf("%s", cJSON_Print(JSON));
//	printf("\n\n%d", getNumObjects(JSON));
//	return 0;
//}
//
//char* ReadFile(char* path, int* length)
//{
//	FILE* pfile;
//	char* data;
//
//	pfile = fopen(path, "rb");   //rb - 必须存在，只读
//	if (pfile == NULL)
//	{
//		return NULL;
//	}
//	fseek(pfile, 0, SEEK_END); //指针到文件尾
//	*length = ftell(pfile);    //取指针相对于文件首的偏移字节数
//	data = (char*)malloc((*length + 1) * sizeof(char));
//	rewind(pfile);             //指针移动到开头
//	*length = fread(data, 1, *length, pfile);
//	data[*length] = '\0';
//	fclose(pfile);
//	return data;
//}
//
//int getNumObjects(cJSON* JSON) {
//	int count = 0;
//	cJSON* tmp = JSON->child;
//	while (1) {
//		if (tmp == NULL) {
//			break;
//		}
//		else {
//			++count;
//			tmp = tmp->next;
//		}
//	}
//	return count;
//}