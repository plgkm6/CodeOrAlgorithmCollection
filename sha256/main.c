#include "sha256.h"

/**
 * 验证：http://tool.oschina.net/encrypt?type=2
 * 代码来源：http://blog.csdn.net/c_duoduo/article/details/43889759
 * 根据代码来源页下面的评论，Linux下使用需要将long类型改为int类型
 * 以下测试代码为我自己所写，仅在Windows下可用
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