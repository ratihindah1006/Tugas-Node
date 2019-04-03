/*
Nama Kelompok:
1. Ratih Indah Wardani	1817051006
2. Intania Rahmadhilla	1817051025
3. Rahmadila Nurjannah	1817051038
4. Dewi Lestari		1817051041
*/
#include <iostream>
using namespace std;
struct Sllc{
	int nilai;
	Sllc *next;
};
Sllc *head;
void init(){
	head=NULL;
}
int isEmpty(){
	if(head==NULL) 
		return 1;
	else 
		return 0;
}
//1. Menambahkan node di depan
void tambahdepan(int nilaibaru){
	Sllc *baru,*bantu;
	baru= new Sllc;
	
	baru->nilai=nilaibaru;
	baru->next=baru;
	
	if(isEmpty()==1){
		head=baru;
		head->next=head;
	}else{
		bantu=head;
		while(bantu->next!=head){
			bantu=bantu->next;
		}
		baru->next=head;
		head=baru;
		bantu->next=head;
	}
}
//2. Menambahkan node di belakang
void tambahbelakang(int nilaibaru){
	Sllc *baru,*bantu;
	baru= new Sllc;
	baru->nilai=nilaibaru;
	
//	cout<<"masukkan nilai ";
//	cin>>nilaibaru;
	baru->next=baru;
	
	if(isEmpty()==1){
		head=baru;
		head->next=head;
	}else{
		bantu=head;
		while(bantu->next!=head){
			bantu=bantu->next;
		}
		bantu->next=baru;
		baru->next=head;
	} 
}

//3.hapus node depan
void hapusdepan(){
	Sllc *hapus,*bantu;
	if(isEmpty()==0){
		int a;
		hapus=head;
		a=head->nilai;
		if(head->next!=head){
			bantu=head;
			while(bantu->next!=head){
			bantu=bantu->next;
		}
		head=head->next;
		delete hapus;
		bantu->next=head;
	}else{
		head=NULL;
	}
	cout<<"nilai terhapus\n";
	
}else cout<<"nilai kosong\n";
}
//4.hapus node belakang
void hapusbelakang(){
	Sllc *hapus,*bantu;
	if(isEmpty()==0){
		int a;
		hapus=head;
		if(head->next==head){
			head=NULL;
		}else{
			bantu=head;
			while(bantu->next->next!=head){
				bantu=bantu->next;
			}
			hapus=bantu->next;
			a=bantu->nilai;
			bantu->next=head;
			delete hapus;
		}
		cout<<"nilai terhapus\n";
	}else cout<<"nilai kosong\n";
	
}

int main ()
{

}
