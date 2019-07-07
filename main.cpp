
#include<stdio.h>
#include<stdlib.h>
//  #include <sys/io.h>  // Linuxϵͳ�������������io.h
#include<io.h>

/*
src�������ļ���Դ��ַ
dst�������ļ���Ŀ�ĵ�ַ
return��0��ʾ�ɹ�����0��ʾ����
*/
int yingbao(const char *src, const char *dst)
{
	if (src == NULL || dst == NULL)
	{
		return -1;
	}
	if (_access(src, 0) != 0)
	{
		return -1;
	}
	// file exist
	int c = EOF;
	FILE *readFileHandler = NULL;
	FILE *writeFileHandler = NULL;

	errno_t rtn = fopen_s(&readFileHandler, src, "r");
	if (rtn != 0)
	{
		return -1;
	}
	rtn = fopen_s(&writeFileHandler, dst, "w");   //create and write to file
	if (rtn != 0)
	{
		fclose(readFileHandler);
		return -1;
	}
	while ((c = fgetc(readFileHandler)) != EOF)
	{
		fputc(c, writeFileHandler);
	}

	fclose(readFileHandler);
	fclose(writeFileHandler);
	return 0;
}


int main()
{
	char* filePath = "./test.log";
	char *dst = "./t.log";
	int res = yingbao(filePath, dst);
	if (res == 0)
	{
		printf("success\n");
	}
	else
	{
		printf("error\n");
	}
	system("pause");
	return 0;
}


