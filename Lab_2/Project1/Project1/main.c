#include<stdio.h>

struct clientData {
	int an;
	char ln[15];
	char fn[10];
	double bal;
};

int main(void) {
	FILE *pR, *pW;
	FILE *cP;
	int cnt = 0;
	struct clientData client = { 0, "", "", 0.0 };

	pR = fopen("C:/Users/USER/Desktop/credit.txt", "r");
	if (pR == NULL) return 0;
	pW = fopen("C:/Users/USER/Desktop/credit_bin.txt", "wb");
	if (pW == NULL) {
		fclose(pR); 
		return 0;
	}
	
	while (!feof(pR)) {
		fscanf(pR, "%d%s%s%lf", &client.an, client.ln, client.fn,
			&client.bal);
		fwrite(&client, sizeof(struct clientData), 1, pW);
		
		printf("%-6d%-16s%-11s%10.2f\n", client.an, client.ln,
			client.fn, client.bal);
	}
	fclose(pR);
	fclose(pW);
	printf("已讀取文字檔的ASCI資料，並轉存成二進位資料檔案\n\n");
	system("pause");

	printf("\n讀取二進位資料檔案，並格式輸出如下：\n");
	if ((cP = fopen("C:/Users/USER/Desktop/credit_bin.txt", "rb")) == NULL) {
		printf("File could not be open.\n");
	}
	else {
		printf("%-6s%-16s%-11s%10s\n", "Acct", "Last name", "First Name", "Balance");

		cnt = fread(&client, sizeof(struct clientData), 1, cP);
		while (cnt > 0) {
			printf("%-6d%-16s%-11s%10.2f\n", client.an, client.ln,
				client.fn, client.bal);
			cnt = fread(&client, sizeof(struct clientData), 1, cP);
		}
		fclose(cP);
	}
	return 0;
}