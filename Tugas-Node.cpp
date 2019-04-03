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
//5. tambah tengah
void tambahtengah(int letak, int nilai){
	if(isEmpty()==0){
		Sllc *bantu1 = new Sllc;
		Sllc *bantu2= new Sllc;
		Sllc *baru = new Sllc;
		bantu1 = head;
		for(int i=1;i<letak;i++){
			bantu2 = bantu1;
			bantu1 = bantu1->next;
		}
		baru->nilai = nilai;
		bantu2->next = baru;
		baru->next = bantu1;
		
	}	
}
//6. hapus tengah
void hapustengah(int nilai){
    if(isEmpty()==0){
        Sllc *bantu1 = new Sllc;
        Sllc *bantu2 = new Sllc;
        bantu1 = head;
        int i = 1;
        for(bantu1=head;bantu1->nilai!=nilai;bantu1=bantu1->next){
            i++;
        }
        bantu2 = head;
        for(int j=1;j<i;j++){
            bantu2 = bantu2->next;
        }
        bantu2->next = bantu1->next;
        delete bantu1;
        cout << "Hapus Berhasil";
    }else
        cout << "Kosong";
}
void cetaknilai(){
	Sllc *b;
	b=head;
	if(isEmpty()==0){
		do{
		cout<<b->nilai<<endl;
		b=b->next;}
		while (b!=head); 
			cout<<endl;}
					
	else cout<<"masih kosong\n";
	
}
	void tanya(){
	int pilihan,nilaibaru,nilai,letak;
	cout<<"**********************************************\n";
	cout<<" \t\tsilahkan pilih?\n";
	cout<<"**********************************************\n";
	cout<<"1.tambah nilai di depan\n";
	cout<<"2.tambah nilai di belakang\n";
	cout<<"3.hapus nilai depan \n";
	cout<<"4.hapus nilai belakang\n";
	cout<<"5.tambah nilai di posisi tertentu\n";
	cout<<"6.hapus nilai di posisi tertentu\n";
	cout<<"7.tampilkan semua nilai\n";
	cout<<"8.keluar\n";
	cout<<"masukkan pilihan anda \n";
	cin>>pilihan;
	switch(pilihan){
		case 1:
			cout<<"masukkan nilai ";
			cin>>nilaibaru;
			tambahdepan( nilaibaru);
			break;
		case 2:
			cout<<"masukkan nilai ";
			cin>>nilaibaru;
			tambahbelakang( nilaibaru);
			break;
		case 3:
			hapusdepan();
			break;
		case 4:
			hapusbelakang();
			break;
		case 5:
			cout<<"tambah di posisi ke- ?";
			cin>>letak;
			cout<<"masukkan nilai ";
			cin>>nilai;
			tambahtengah(1,3);
			break;
		case 6:
			cout<<"hapus node di posisi ke- ?";
			hapustengah(nilai);
			break;
		case 7 : 
			sysstem("cls")
			cetaknilai();
			break;
		case 8 :
			cin.get();
		default:
			cout<<"kode salah\n";
			system("cls");
	}}
	

int main ()
{
	char lagi='y';
	tanya();
	cout<<"mau edit lagi [y jika ya]?\n";
	cin>>lagi;
	system("cls");
	while (lagi=='y'){
		tanya();
	
	}
;
	return 0;
}
