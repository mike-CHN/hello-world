#include <stdio.h>
#include <stdbool.h>
//#define InitSize 100
typedef struct{
	int *data;
	int Maxsize,length;	
}Seqlist;

void Initial_list(Seqlist *L,int InitSize){
	int i=0;
	L->data=(int*)malloc(sizeof(int)*InitSize);	//Allocate list space

	i=0;
	L->Maxsize=InitSize;	//initialize Maxsize 	
	L->length=0;//initialize current length
	
	//initialize part of list
	printf("input sequence list element\n");
	while(i<L->Maxsize){
		scanf("%d",&L->data[i++]);
		L->length++;
	}
}
void show_current_list(Seqlist *L){
	int i=0;
	for(i=0;i<L->length;i++)
		printf("%d",L->data[i]);
	printf("\n");
}
int caculate_length(Seqlist *L){
	return L->length;	
}
void locate_element(Seqlist *L,int value){
	bool return_status=false;
	int i=0;
	for(i=0;i<L->length;i++){
		if(L->data[i]==value){
			printf("query successfully! %d in this list!\n",value);
			return_status=true;
			break;
			return;
		}	
	}
	if(!return_status)
		printf("query failed!\n");
	
}
int get_element(Seqlist *L,int location){
	if(location<1||location>L->length){
		printf("out of bound of the list\n");
		exit(0);
	}
	return L->data[location-1];
}
void judge_empty(Seqlist *L){
	if(L->length==0)
		printf("the list is empty!\n");
	else
		printf("the list is not empty!\n");
	
}
void Insert_list(Seqlist *L,int location,int value){
	if(location<1||location>L->length+1)
		printf("Insert failed!\n");	
	else
		{
			int j=0;
			
			for(j=L->length;j>=location;j--){
				L->data[j]=L->data[j-1];
			}
			L->data[j]=value;
			L->length++;
			printf("Insert successfully!\n");
		}	
}
void delete_element(Seqlist *L,int location){
	 if(location<1||location>L->Maxsize||location>L->length+1)
		printf("Delete failed!\n");	
	 else 
		{
			int j=0;
			
			for(j=location;j<L->length;j++){
				L->data[j-1]=L->data[j];
			}
			L->data[L->length-1]=0;
			L->length--;
			printf("Delete successfully!\n");	
		}
}
int main(int argc, char *argv[])
{
	Seqlist L;
	int InitSize=0;
	
	printf("input InitSize\n");
	scanf("%d",&InitSize);
	Initial_list(&L,InitSize);
		
	locate_element(&L,2);
	printf("%d\n",get_element(&L,5));

	Insert_list(&L,1,9);
	show_current_list(&L);
	
	printf("current length is:%d\n",caculate_length(&L));
	
	delete_element(&L,1);
	show_current_list(&L);
	printf("current length is:%d\n",caculate_length(&L));
	
	judge_empty(&L);
	
	return 0;
}
