#include <stdio.h>
#include <stdlib.h>
struct node{ // düðüm oluþtururken kullanýlacak struct yapýsý
	int data;
	struct node *next;
};
//yeni düðüm oluþturup düðümdeki sayýlarý tek veya çift olma durumuna göre listenin baþ ve sonuna ekleyen fonksiyon
void insertNode(struct node **head,int value){
 // burda head de ** pointer kullandýk çünkü main de kullandýðýmýz ve parametre olarak aldýðýmýz head in adresi.
	
	struct node *newNode = malloc(sizeof(struct node)); //gelen yeni deðer için düðüm oluþturma ve bellekten yer alma iþlemi
	newNode->data = value; // deðeri düðümün datasýna koyduk
	newNode->next = NULL;
	if(*head==NULL){ // listede daha önceden elaman yoksa bu koþul uygulanýr
		*head=newNode;	
	}
	else if(newNode->data%2==0){ //bu sayý Çifttir ve baþa eklememiz gerekiyor
		struct node *temp = newNode; // newNod u iþaret eden bir pointer oluþturduk
		temp->data = value; 
		temp->next = *head; // yeni düðümü listenin baþýna koyduk ve eski baþý bir sonraki gösterilecek deðer olarak güncelledik
		*head = temp;
		
	}
	else{ // bu sayý tektir ve listenin sonuna eklenir.
		struct node *temp = *head;
		//son sýrayý bulmak için listeyi dolaþýp son düðümün nexti null ý gösterdiðinde durmalýdýr
		while(temp->next!=NULL){
			temp=temp->next; // traverse iþlemi ile listenin sonuna geldik
		}
		temp->next = newNode; 
	}
}
//listedeki elemanlarý yazdýran fonksiyon.
void printList(struct node *head){
	int counter =1;
	if(head==NULL){
		printf("List is Empty");
	}
	else{
		while(head->next!=NULL){
			printf("%d - %d\n",counter,head->data);
			head =head->next;
			counter++;
		}
	}
	
}
int main(){
	struct node *head=NULL;
	int n;
	while(1){
		printf("Enter a number:"); 
		scanf("%d",&n);
		if(n==-1){
			break;
		}
		else{
			insertNode(&head,n);
		}
	}
	printList(head);
}

