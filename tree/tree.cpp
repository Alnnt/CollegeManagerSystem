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
///// һ���Զ�ȡȫ�����ݲ������ļ����ݵ�ַ
///// </summary>
///// <param name="path">�ļ�·��</param>
///// <param name="length">�����ļ���С�ı�����ַ</param>
///// <returns>�ļ�ȫ�������ַ�����ַ</returns>
//char* ReadFile(char* path, int* length);
///// <summary>
///// ��ȡ�����Ա��
///// </summary>
///// <param name="JSON">����</param>
///// <returns>����ĳ�Ա��</returns>
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
//		printf("����ʧ��\n");
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
//	pfile = fopen(path, "rb");   //rb - ������ڣ�ֻ��
//	if (pfile == NULL)
//	{
//		return NULL;
//	}
//	fseek(pfile, 0, SEEK_END); //ָ�뵽�ļ�β
//	*length = ftell(pfile);    //ȡָ��������ļ��׵�ƫ���ֽ���
//	data = (char*)malloc((*length + 1) * sizeof(char));
//	rewind(pfile);             //ָ���ƶ�����ͷ
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