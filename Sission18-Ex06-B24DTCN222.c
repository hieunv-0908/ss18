#include<stdio.h>
struct student{
	int age;
	char id[50];
	char name[50];
	char phoneNumber[50];
};
struct student sv[50] = {
	{
	18,"B24DTCN222","nguyen van toan","0328441049"
	},
	{
	18,"B24DTCN222","nguyen van hai","0328441049"	
	},
	{
	18,"B24DTCN222","nguyen van chien","0328441049"
	},
	{
	18,"B24DTCN222","nguyen van long","0328441049"	
	},
	{
	18,"B24DTCN222","nguyen van minh","0328441049"	
	},
	{
	18,"B24DTCN222","nguyen van hoang","0328441049"	
	},
};  
void enterStudent(struct student sv[],int *lenghtSv){
	struct student newstudent;
	fflush(stdin);
	printf("Moi ban nhap tuoi cua hoc sinh moi:");
	scanf("%d",&newstudent.age);
	getchar();
	printf("Moi ban nhap id cua hoc sinh moi:");
	fgets(newstudent.id,50,stdin);
	newstudent.id[strcspn(newstudent.id,"\n")]='\0';
	printf("Moi ban nhap ten cua hoc sinh moi:");
	fgets(newstudent.name,50,stdin);
	newstudent.name[strcspn(newstudent.name,"\n")]='\0';
	printf("Moi ban nhap so dien thoai cua hoc sinh moi:");
	fgets(newstudent.phoneNumber,50,stdin);
	newstudent.phoneNumber[strcspn(newstudent.phoneNumber,"\n")]='\0';
	sv[*lenghtSv]=newstudent;
	(*lenghtSv)++; 
}
int main(){
	int lenghtSv=5; 
	struct student newstudent;  
    enterStudent(&sv,&lenghtSv);
for(int i=0;i<lenghtSv;i++){
	printf("%s ",sv[i].id); 
	printf("%d ",sv[i].age);
	printf("%s ",sv[i].name);
	printf("%s ",sv[i].phoneNumber);
	printf("\n"); 
} 
return 0;
}

