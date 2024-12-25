#include<stdio.h>
#include<string.h>
typedef struct {
	int id;
	char name[100];
	int age;
	char phoneNumber[100];
} Student;  
// chen mot hoc sinh vao mang cau truc hoc sinh co san
void InsertArrStruct (Student students[],int *len);

int main(){
	int len=5;
	Student students[50]={
	{1,"nguyen van hieu",18,"0328441049"},
	{2,"nguyen van minh",18,"0986736563"},
	{3,"nguyen van anh",18,"0786546731"},
	{4,"nguyen tien minh",18,"018218731"},
	{5,"nguyen trong vuong",18,"0123712831"},
	};	
	InsertArrStruct(students,&len);
	
	return 0;
}

void InsertArrStruct(Student students[],int *len){
	int indexInsert;
		for(int i=0;i<*len;i++){
		printf("ID: %d\n Name: %s\n Age: %d\n phoneNumber: %s\n",students[i].id,students[i].name,students[i].age,students[i].phoneNumber);
		printf("_________________________\n");
	}
	
	printf("Moi ban nhap vao vi tri muon chen\n");
	scanf("%d",&indexInsert);
	getchar();
	
	if(indexInsert<0||indexInsert>*len){
		return;
	}
	
	printf("Moi ban nhap thong tin cua hoc sinh muon chen\n");
	Student InsertStudent;
	
	printf("Moi nhap vao so id: ");
	scanf("%d",&InsertStudent.id);
	getchar();
	
	printf("Moi nhap vao Name: ");
	fgets(InsertStudent.name,100,stdin);
	InsertStudent.name[strcspn(InsertStudent.name,"\n")]='\0';
	
	printf("Moi nhap vao so Age: ");
	scanf("%d",&InsertStudent.age);
	getchar();
	
	printf("Moi nhap vao phoneNumber: ");
	fgets(InsertStudent.phoneNumber,100,stdin);
	InsertStudent.phoneNumber[strcspn(InsertStudent.phoneNumber,"\n")]='\0';
	
	for(int i=*len;i>=indexInsert;i--){
		students[i]=students[i-1];
	}
	(*len)++;
	students[indexInsert]=InsertStudent;
	printf("Mang cau truc sau khi chen\n");
	for(int i=0;i<*len;i++){
		printf("ID: %d\n Name: %s\n Age: %d\n phoneNumber: %s\n",students[i].id,students[i].name,students[i].age,students[i].phoneNumber);
		printf("_________________________\n");
	}
}

