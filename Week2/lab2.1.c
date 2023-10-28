#include <stdio.h>
#include <stdlib.h>
struct node{ // d���m olu�tururken kullan�lacak struct yap�s�
	int data;
	struct node *next;
};
//yeni d���m olu�turup d���mdeki say�lar� tek veya �ift olma durumuna g�re listenin ba� ve sonuna ekleyen fonksiyon
void insertNode(struct node **head,int value){
 // burda head de ** pointer kulland�k ��nk� main de kulland���m�z ve parametre olarak ald���m�z head in adresi.
	
	struct node *newNode = malloc(sizeof(struct node)); //gelen yeni de�er i�in d���m olu�turma ve bellekten yer alma i�lemi
	newNode->data = value; // de�eri d���m�n datas�na koyduk
	newNode->next = NULL;
	if(*head==NULL){ // listede daha �nceden elaman yoksa bu ko�ul uygulan�r
		*head=newNode;	
	}
	else if(newNode->data%2==0){ //bu say� �ifttir ve ba�a eklememiz gerekiyor
		struct node *temp = newNode; // newNod u i�aret eden bir pointer olu�turduk
		temp->data = value; 
		temp->next = *head; // yeni d���m� listenin ba��na koyduk ve eski ba�� bir sonraki g�sterilecek de�er olarak g�ncelledik
		*head = temp;
		
	}
	else{ // bu say� tektir ve listenin sonuna eklenir.
		struct node *temp = *head;
		//son s�ray� bulmak i�in listeyi dola��p son d���m�n nexti null � g�sterdi�inde durmal�d�r
		while(temp->next!=NULL){
			temp=temp->next; // traverse i�lemi ile listenin sonuna geldik
		}
		temp->next = newNode; 
	}
}
//listedeki elemanlar� yazd�ran fonksiyon.
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

