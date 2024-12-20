#include<stdio.h>
#include<string.h>
int main(){
	typedef struct{
		int id;
		char name[100];
		int age;
		char phoneNumber[100];
	}Studen;
	Studen studen[50];
	int i;
	for(int i=0;i<5;i++){
		printf("MOI NHAP VAO THONG TIN CUA SINH VIEN THU %d\n",i+1);
		studen[i].id=i+1;
		
		printf("TEN: ");
		fflush(stdin);
		fgets(studen[i].name,sizeof(studen[i].name),stdin);
		studen[i].name[strcspn(studen[i].name,"\n")]='\0';
		
		printf("TUOI: ");
		scanf("%d",&studen[i].age);
		getchar();
		
		
		printf("PhoneNumber: ");
		fgets(studen[i].phoneNumber,sizeof(studen[i].phoneNumber),stdin);
		studen[i].phoneNumber[strcspn(studen[i].phoneNumber,"\n")]='\0';
		
	}
	printf("\n");
	printf("\n");
	printf("\n");
	
	printf("Thong tin cua sinh vien da nhap:\n");
    for (i = 0; i < 5; i++) {
        printf("SV thu %d:\n", i + 1);
        printf("ID: %d\n", studen[i].id);
        printf("TEN: %s\n", studen[i].name);
        printf("TUOI: %d\n", studen[i].age);
        printf("SO DIEN THOAI: %s\n\n", studen[i].phoneNumber);
    }
	return 0;
}
