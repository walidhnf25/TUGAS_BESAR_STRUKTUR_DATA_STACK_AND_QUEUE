#include "gudang.h"

/*/
Ketentuan TUBES
Desain struktur data :
Stack dengan Array
Queue dengan list
Fungsionalitas :
Insert data
Delete data
Show data
Pemanfaatan primitif dalam penyelesaian masalah, Contoh: infix to prefix dan kasus lainnya
Main program
/*/

//push
Rak *rakBaru(){
    Rak *rak = (struct Rak*) malloc(sizeof(struct Rak));
    int n;
    rak->id = NO_RAK++;
    cout<<"Masukkan banyak barang yang diisi: ";
    cin>>n;
    for (int i = 1; i <= n; i++) {
        cout<<"Barang ke "<<i<<endl;
        string kode;
        cout<<"Masukkan kode: ";
        cin>>kode;
        rak->barang[rak->n].kode = kode;
        cout<<"Masukkan harga: ";
        cin>>rak->barang[rak->n].harga;
        rak->n+=1;
    }
    return rak;
}

//enqueue
void insertRak(Rak *rak){
    if(lemari.head==NULL){
        lemari.head=rak;
        lemari.tail=rak;
    }else{
        lemari.tail->next = rak;
        lemari.tail = rak;
    }
}

//dequeue
Rak *ambilRak(){
    Rak *temp = lemari.head;
    if(lemari.head!=NULL){
        lemari.head = lemari.head->next;
        cout<<"Lemari diambil: "<<temp->id<<endl;
    }else{
        cout<<"Lemari kosong\n";
    }
    return temp;
}

//pop
void keluarBarang(Rak *rak){
    char konfirmasi;
    if(rak==NULL){
        return;
    }
    Barang barang = rak->barang[--rak->n];
    cout<<"Data Barang:\n"
        <<"Kode: "<<barang.kode<<endl
        <<"Harga: "<<barang.harga<<endl
        <<"Telah dikeluarkan\n";
}

//show rak
void lihatRak(){
    if(lemari.head!=NULL){
        cout<<"Data Rak Terdepan:\n"
            <<"ID: "<<lemari.head->id<<endl
            <<"Jumlah Barang: "<<lemari.head->n<<endl;
    }else{
        cout<<"Lemari kosong\n";
    }
}

//show barang
void lihatBarang(Rak *rak){
    Barang barang = rak->barang[rak->n-1];
    cout<<"Data Barang Teratas:\n"
        <<"Kode: "<<barang.kode<<endl
        <<"Harga: "<<barang.harga<<endl;
}

void menuRak(Rak *rak){
    int pil;
    do{
        if(rak->n==0){
            cout<<"Barang sudah habis\n";
            return;
        }
        cout<<"1. Lihat\n"
            <<"2. Ambil Barang\n"
            <<"0. Keluar\n"
            <<"Pilih: ";
        cin>>pil;
        switch(pil){
            case 1:
                lihatBarang(rak);
                break;
            case 2:
                keluarBarang(rak);
                break;
            case 0:
                char konfirmasi;
                do{
                    cout<<"Yakin ingin membuang seluruh barang? (y/n): ";
                    cin>>konfirmasi;
                    if(konfirmasi=='y'||konfirmasi=='n'){
                        break;
                    }
                    cout<<"Pilihan tidak diketahui\n";
                }while(1);
                if(konfirmasi=='y'){
                    return;
                }
                break;
            default:
                cout<<"Menu tidak diketahui\n";
                break;
        }
        cout<<"\n\n";
    }while(1);
}
