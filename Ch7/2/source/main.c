#include <stdlib.h>
#include <stdio.h>
#pragma warning(disable : 4996)

typedef struct cdata
{
	int acc;
	char ln[15], fn[10];
	double balance;
};


int main(void)
{

	FILE *pread = fopen("D://c.txt", "r");
	FILE *pwrite = fopen("D://c_bin.txt", "wb");
	FILE *cf;
	int cnt = 0;
	struct cdata c = { 0,"","",0.0 };
	
	if (pread == NULL)
		return 0;
	if (pwrite == NULL)
		return 0;
	while (!feof(pread))
	{
		fscanf(pread, "%d%s%s%lf", &c.acc, c.ln, c.fn, &c.balance);
		fwrite(&c, sizeof(struct cdata), 1, pwrite);
		printf("%-6d%-16s%-11s%10.2f\n", c.acc, c.ln, c.fn, c.balance);
	}
	fclose(pread);
	fclose(pwrite);
	printf("已讀ASCII並轉純二進位\n\n");
	system("pause");

	printf("\n讀取二進位，輸出如下:\n");
	if ((cf = fopen("D://c_bin.txt", "rb")) == NULL)
		printf("File could not be opened.\n");
	else
	{
		printf("%-6s%-16s%-11s%10s\n", "Acct", "LastName", "FirstName", "Balance");
		cnt = fread(&c, sizeof(struct cdata), 1, cf);
		while (cnt>0)
		{
			printf("%6d%-16s%-11s%10.2f\n", c.acc, c.ln, c.fn, c.balance);
			cnt = fread(&c, sizeof(struct cdata), 1, cf);
		}

		fclose(cf);
	}

	system("pause");
	return 0;
}