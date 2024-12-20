#include<stdio.h>
#include<string.h>
int main(){
	struct studen{
		int arge;
		char fullname[100];
		char phoneNumber[100];
	};
	struct studen studen01;
	printf("Please enter your arge:");
	scanf("%d",&studen01.arge);
	fflush(stdin);
	printf("Please enter your fullname:");
	fgets(studen01.fullname,100,stdin);
	studen01.fullname[strcspn(studen01.fullname,"\n")]='\0';
	fflush(stdin);
	printf("Please enter your phoneNumber:");
	fgets(studen01.phoneNumber,100,stdin);
	studen01.phoneNumber[strcspn(studen01.phoneNumber,"\n")]='\0';
	fflush(stdin);
	printf("Your backGround\n");
	printf("arge: %d\n",studen01.arge);
	printf("fullname: %s\n",studen01.fullname);
	printf("phoneNumber: %s\n",studen01.phoneNumber);
	return 0;
}
