#include<stdio.h>
#include<string.h>
typedef struct{
	int id;
	char name[100];
	float price;
}Dist;
void PrintfArrStruct(Dist DistChaoMenu[],int *len);
void InsertArrStruct(Dist DistChaoMenu[],int *len);
void EditArrStruct(Dist DistChaoMenu[],int *len);
void DeleteArrStruct(Dist DistChaoMenu[],int *len);
void SortArrStructPrice(Dist DistChaoMenu[],int len);
void SearchArrStructName(Dist DistChaoMenu[],int len);


int main(){

Dist DistChaoMenu[100]={
{1,"Chao luon",45.5},
{2,"Chao tiet",30},
{3,"Chao ga",35},
{4,"Chao thit heo",35.5},
{5,"Chao suon",40},
};

int len =5;
int select;
do{
	printf("\n");
	printf("\n__________MENU_________\n");
	printf("Lua chon 1:In ra menu quan\n");
	printf("Lua chon 2:Them mot phan tu vao vi tri chi dinh\n");
	printf("Lua chon 3:Sua mot phan tu\n");
	printf("Lua chon 4:Xoa mot phan tu o vi tri chi dinh\n");
	printf("Lua chon 5:Sap xep phan tu\n a.Giam dan theo gia\n b. Tang dan theo gia\n");
	printf("Lua chon 6:Tim kiem phan tu theo name\n a.Tim kiem tuyen tinh\n b.Tim kiem nhi phan\n");
	printf("Lua chon 7:Thoat\n");
	printf("Moi ban nhap vao lua chon: ");
	scanf("%d",&select);
	getchar();
	switch(select){
		case 1:
		PrintfArrStruct(DistChaoMenu,&len);	
		break;
		
		case 2:
			InsertArrStruct(DistChaoMenu,&len);
		break;
		
		case 3:
			EditArrStruct(DistChaoMenu,&len);
		break;
		
		case 4:
			DeleteArrStruct(DistChaoMenu,&len);
		break;
		
		case 5:
			SortArrStructPrice(DistChaoMenu,len);
		break;
		
		case 6:
			SearchArrStructName(DistChaoMenu,len);
		break;
		
		case 7:
			return 1;
		break;	
		default :
		printf("Lua chon khong hop le.\nMoi ban nhap lai lua chon\n");	
		break;
	}
}while(select!=7);
return 0;
}

//in ra Menu cac mon chao

void PrintfArrStruct(Dist DistChaoMenu[],int *len){
	printf("\n");
	printf("\n");
	printf("Menu quan\n");
	for(int i=0;i<*len;i++){
		printf("%d.%s:%.3f\n",DistChaoMenu[i].id,DistChaoMenu[i].name,DistChaoMenu[i].price);
	}
}

// chen them mon an vao Menu

void InsertArrStruct(Dist DistChaoMenu[],int *len){
	Dist insertDist;
	printf("Moi ban nhap vao so thu tu cua mon an moi\n");
	scanf("%d",&insertDist.id);
	getchar();
	printf("Moi ban nhap vao ten mon an moi\n");
	fgets(insertDist.name,100,stdin);
	insertDist.name[strcspn(insertDist.name,"\n")]='\0';
	printf("Moi ban nhap vao so gia cua mon an moi\n");
	scanf("%f",&insertDist.price);
	getchar();
	printf("Moi ban nhap vao vi tri muon them\n");
	int indexInsert;
	scanf("%d",&indexInsert);
	getchar();
	if(indexInsert>*len){
		printf("Vi tri muon chen khong hop le\n");
	}else{
		for(int i=*len;i>indexInsert;i--){
			DistChaoMenu[i]=DistChaoMenu[i-1];
		}
		DistChaoMenu[indexInsert]=insertDist;
		(*len)++;
		for(int i =indexInsert;i<*len;i++){
			DistChaoMenu[i].id+=1;
		}
	}
}

// Sua thong tin MENU
void EditArrStruct(Dist DistChaoMenu[],int *len){
	printf("Moi ban nhap vao vi tri muon sua:");
	int indexEdit;
	scanf("%d",&indexEdit);
	getchar();
	if(indexEdit<*len&&indexEdit>=0){
		printf("Moi ban chon phan tu muon sua\n");
		printf("1.Id\n"); 	
		printf("2.Name\n");
		printf("3.Price\n");
		int selectEdit;
		scanf("%d",&selectEdit);
		getchar();
		if(selectEdit==1){
			printf("Moi ban tien hanh sua ID cua mon an\n");
			scanf("%d",&DistChaoMenu[indexEdit].id);
			getchar();
		}else if(selectEdit==2){
			printf("Moi ban tien hanh sua Name cua mon an\n");
			fgets(DistChaoMenu[indexEdit].name,100,stdin);
			DistChaoMenu[indexEdit].name[strcspn(DistChaoMenu[indexEdit].name,"\n")]='\0';
		}else if(selectEdit==3){
			printf("Moi ban tien hanh sua Price cua mon an\n");
			scanf("%f",&DistChaoMenu[indexEdit].price);
			getchar();
		}else{
			printf("Lua chon khong hop le!!!\n");
		}
	}
	
}

// xoa mot phan tu trong Menu nha hang
void DeleteArrStruct(Dist DistChaoMenu[],int *len){
	printf("Moi ban nhap vao vi tri muon xoa:");
	int deleteIndex;
	scanf("%d",&deleteIndex);
	getchar();
	if(deleteIndex>0&&deleteIndex<*len){
		for(int i=deleteIndex;i<*len;i++){
			DistChaoMenu[i]=DistChaoMenu[i+1];
		}
		(*len)--;
		for(int i=deleteIndex;i<*len;i++){
			DistChaoMenu[i].id-=1;
		}
	}
}

void SortArrStructPrice(Dist DistChaoMenu[],int len){
	printf("a.Giam dan theo Price\n");
	printf("b.Tang dan theo Price\n");
	printf("Moi ban nhap vao kieu sap xep mong muon(1=a,2=b):");
	int sortSelect;
	scanf("%d",&sortSelect);
	getchar();
	Dist temp;
	switch(sortSelect){
		case 1:
			for(int i=0;i<len;i++){
				for(int j=0;j<len-1;j++){
					if(DistChaoMenu[j].price<DistChaoMenu[j+1].price){
						temp=DistChaoMenu[j];
						DistChaoMenu[j]=DistChaoMenu[j+1];
						DistChaoMenu[j+1]=temp;
					}
				}
			}
			break;
		case 2:
			for(int i=0;i<len;i++){
				for(int j=0;j<len-1;j++){
					if(DistChaoMenu[j].price>DistChaoMenu[j+1].price){
						temp=DistChaoMenu[j];
						DistChaoMenu[j]=DistChaoMenu[j+1];
						DistChaoMenu[j+1]=temp;
					}
				}
			}
			break;	
	}
	
}

void SearchArrStructName(Dist DistChaoMenu[],int len){
	printf("a.Tim kiem tuyen tinh\n");
	printf("b.Tim kiem nhi phan(nen dung khi mang da gan nhu duoc sap xep hoac da sap xep)\n");
	printf("Moi ban nhap vao kieu muon tim kiem:");
	int searchSelect;
	scanf("%d",&searchSelect);
	getchar();
	printf("Moi ban nhap vao Name muon tim kiem:");
	char searchName[100];
	fgets(searchName,100,stdin);
	searchName[strcspn(searchName,"\n")]='\0';
	switch(searchSelect){
		case 1:
			for(int i=0;i<len;i++){
				if(DistChaoMenu[i].name==searchName){
					printf("Da tim thay vi tri cua phan tu %s\n Tai vi tri %d\n",DistChaoMenu[i].name,i);
					break;
				}
			}
			break;
		case 2:
			
			
			break;
	}
}

















