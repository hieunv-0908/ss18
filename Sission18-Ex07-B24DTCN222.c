#include<stdio.h>
#include<string.h>
struct student {
	char id[100];
	char name[100];
	char phoneNumber[100];
	int age;
};  
void deletSt(struct student sv[],char nameStDl[],int *lenght){
	for(int i=0;i<*lenght;i++){
		if(strcmp(sv[i].name,nameStDl)==0){
			for(int j=i;j<*lenght;j++){
				sv[j]=sv[j+1];
			}
			(*lenght)--;
			i--;
		}
	}
}


int main(){
	struct student sv[50] = {
	{"B24DTCN222","nguyen van toan","049827422",18},
	{"B24DTCN222","nguyen van hai","0917283651",24},
	{"B24DTCN222","nguyen van chien","0897352751",19},
	{"B24DTCN222","nguyen van long","0893746254",25},
	{"B24DTCN222","nguyen van minh","0893746254",53},
	{"B24DTCN222","nguyen van hoang","0893746254",37},
};
	int lenght =5;
	char nameStDl[100];
	
	printf("Moi ban nhap vao ten sinh vien can xoa");
	fgets(nameStDl,100,stdin);
	nameStDl[strcspn(nameStDl,"\n")]='\0';
		
	deletSt(sv,nameStDl,&lenght);
	
	printf("Danh sach hoc sinh sau khi xoa\n");
	for(int i=0;i<lenght;i++){
		printf("ID= %s\nNAME= %s\nAGE= %d\nPHONENUMBER= %s\n",sv[i].id, sv[i].name,sv[i].age,sv[i].phoneNumber);
		printf("________________________\n");
	}
	
return 0;
}

