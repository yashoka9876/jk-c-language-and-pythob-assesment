#include<stdio.h>
#include<stdlib.h>
struct book{
	int id;
	char name[50];
	int prize;
};
void write_f(struct book b1){
	FILE *fpr=fopen("file2.txt","wb");
	if(fpr==NULL){
		printf("file will not open bro");
		exit(3);
	}
	printf("Enter is id,tittle and prize of the book\n");
	scanf("%d",&b1.id);
	fflush(stdin);
	gets(b1.name);
	scanf("%d",&b1.prize);
	fwrite(&b1,sizeof(b1),1,fpr);
	fclose(fpr);
}
void readd2_f(struct book b2){
	FILE *fpr1=fopen("file2.txt","r");
	if(fpr1==NULL){
		printf("file will not open bro");
		exit(3);
	}
	fread(&b2,sizeof(b2),1,fpr1);
	printf("this is the book data which i retrive from the file\n\n\n");
	printf("%d\t",b2.id);
	printf("%s\t",b2.name);
	printf("%d\t",b2.prize);
	fclose(fpr1);
}
int main(){
	struct book b1,b2;
	write_f(b1);
	readd2_f(b2);	
}
