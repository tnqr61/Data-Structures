#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node{
	char name[20];
	int studentNum;
	int age;
	struct node *next;
	
};
//aranan ogrenciden bir sonraki düðümü silen fonksiyon
void deleteStudent(struct node **head){
	char name[20];
	printf("Aramak istediginiz ogrencinin ismini girin:");
	scanf("%s",name);
	struct node *current = *head;
			while(current!=NULL){
			
			if(strcmp(name,current->name)==0){
				struct node *deleted = current->next;
				current->next = deleted->next;
				free(deleted);
				
			}
			current=current->next;	
			
		}
		printf("Aradiginiz Ogrenciden bir Sonraki Ogrenci hafýzadan silindi\n");
	
	
}
//düðümde aranan öðrenci var mý kontrol eder 
void searchStudent(struct node *head){
	char name[20];
	printf("Aramak istediginiz ogrencinin ismini girin:");
	scanf("%s",name);
		while(head!=NULL){
			if(strcmp(name,head->name)==0){
				printf("Student is existing!!\n");
			}
			head=head->next;
			
		}
		
}
//girilen ögrencileri yazdýrma fonkisyonu
void printList(struct node *head){
	int counter=1;
	if(head==NULL){
		printf("List is Empty");
	}
	else{
		printf("STUDENT LIST\n");
		while(head!=NULL){
			printf("%d- %s stdNUM:%d Age:%d\n",counter,head->name,head->studentNum,head->age);
			head=head->next;
			counter++;
		}
	}
	printf("\n");
}
//dugume yeni ogrenci ekleme fonksyonu
void insertList(struct node **head){
	
	struct node *newNode = malloc(sizeof(struct node));
	char name[20];
	printf("Ogrenci ismini girin:");
	scanf("%s",name);
	strcpy(newNode->name,name);
	printf("Ogrenci Numarasini girin:");
	scanf("%d",&newNode->studentNum);
	printf("Ogrenci yasini girin:");
	scanf("%d",&newNode->age);
	newNode->next = NULL;
	if(*head==NULL){
		*head= newNode;
	}
	else{
		struct node *current=*head;
		while(current->next!=NULL){
			current=current->next;//düðümün sonuna yerleþiyor
		}
		current->next = newNode; // düðümün sonuna yeni düðümü ekliyor
		
	}
	
	
}
//listedeki en uzun ismi bulup yazdýrma
void printLongestName(struct node *head){
	char longestName[20];
	struct node *current = head;
	strcpy(longestName,current->name);
	while(current->next!=NULL){
		if(strlen(current->name)>strlen(longestName)){
			strcpy(longestName,current->name);
		}
		current = current->next;
		
	}
	printf("Listedeki En Uzun isimli Ogrenci: %s\n\n",longestName);
	
}
int main(){
	struct node *head=NULL;
	int choice;// switch koþulunda kullanýlmak üzere oluþturuldu
		while(1){
		printf("1-Ogrencileri kaydet\n2-Ogrenci Arama\n3-Aranan Ogrenciden bir sonraki dugumu silme\n4-En uzun isimli ogrenciyi bulma\n5-Ogrencilerin Bilgilerini yazdirma \n0-Cikis\n");
		scanf("%d",&choice);
			switch(choice){
				case 1: insertList(&head); break;// Ogrenci Kaydetme
				case 2: searchStudent(head); break; // Ogrenci arama
				case 3: deleteStudent(&head);break; // Aranan ogrenciden bir sonraki dugumdeki Ogrenci bilgilerini silme
				case 4: printLongestName(head); break; //listedki en uzun isimli ogrenciyi bulma
				case 5: printList(head); break; // Ogrenci Listeleme
				case 0: goto finish; break;// Çýkýþ	
			}
	}
		finish:
	return 0;
}

