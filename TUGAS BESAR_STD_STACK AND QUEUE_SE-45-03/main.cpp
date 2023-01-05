#include "gudang.cpp"
int main()
{
    int pil;
    do{
        cout<<"1. Tambah Rak\n"
            <<"2. Ambil Rak\n"
            <<"3. Lihat Rak\n"
            <<"0. Keluar\n"
            <<"Pilih: ";
        cin>>pil;
        switch(pil){
            case 1:
                insertRak(rakBaru());
                break;
            case 2:
                cout<<"\n\n";
                menuRak(ambilRak());
                break;
            case 3:
                lihatRak();
                break;
            case 0:
                cout<<"Terima kasih\n";
                break;
            default:
                cout<<"Menu tidak diketahui\n";
                break;
        }
        cout<<"\n\n";
    }while(pil!=0);

    return 0;
}
