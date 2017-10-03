#include "sha256.h"

/**
 * ��֤��http://tool.oschina.net/encrypt?type=2
 * ������Դ��http://blog.csdn.net/c_duoduo/article/details/43889759
 * ���ݴ�����Դҳ��������ۣ�Linux��ʹ����Ҫ��long���͸�Ϊint����
 * ���²��Դ���Ϊ���Լ���д������Windows�¿���
 */

#include <stdio.h>
#include <string.h>
#include <io.h>

#define BUF_SIZE 1024

int main()
{
	char input[BUF_SIZE];
	char output[65];
	char stopFlag[] = "#";
	while(1)
	{
		memset(input, 0, sizeof(char) * BUF_SIZE);
		memset(output, 0, sizeof(char) * 65);
		//delete-gets(input);
		fgets(input, sizeof(input), stdin);
		input[strlen(input) - 1] = '\0';
		printf("Length: %d\nString: \"%s\"\n", strlen(input), input);
		if (strncmp(input, stopFlag, 1) == 0)
			break;
		if(access(input, 0) == 0)
		{
			puts("The SHA-256 of the file is: ");
			FileSHA256(input, output);
		}
		else
		{
			puts("The SHA-256 of the string is: ");
			StrSHA256(input, strlen(input), output);
		}
		puts(output);
	}
	return 0;
}