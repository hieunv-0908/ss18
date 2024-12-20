#include<stdio.h>
#include<string.h>
int main(){
	struct studen{
		int arge;
		char fullname[100];
		char phoneNumber[100];
	};
	struct studen hieu;
	hieu.arge=18;
	strcpy(hieu.fullname,"NGUYEN VAN HIEU");
	strcpy(hieu.phoneNumber,"0328441049");
	printf("%d\n",hieu.arge);
	printf("%s\n",hieu.fullname);
	printf("%s\n",hieu.phoneNumber);
	return 0;
}
