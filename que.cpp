#include <iostream>
#include <iomanip>
#define n 10
using namespace std;

string matkul[5] = {"Sistem Operasi", "Fotografi", "Pemrograman", "Struktur Data", "Komunikasi Data"};

struct mahasiswa{
    string nama;
    int nim;
    int nilai[5];
    float jumlahnilai;
    float Ipk;
    
}Mhs[n];

struct queue{
    int awal, akhir;
}Queue;

void deQueue();
void menu();
void inQueue();
void tampil();

void init(){
    Queue.awal = -1;
    Queue.akhir = -1;
    cout << "Data berhasil di reset" << endl << endl;
    menu();
}

bool isFull(){
    if(Queue.akhir == n - 1){
        return true;
    } else {
        return false;
    }
}

bool isEmpty(){
    if(Queue.akhir == -1){
        return true;
    }else {
        return false;
    }
}

void inQueue(){
    if(!isFull()){
        string nama;
        int nim;
        int ipk;
        cout << "\n";
        cout << "==Tambah Data Mahasiswa=="<<endl;
        cout << "Masukkan Nama :";
        cin >> nama;
        cout << "Masukkan NIM :";
        cin >> nim;
        
        Mhs[Queue.akhir].nama = nama;
        Mhs[Queue.akhir].nim = nim;
        Mhs[Queue.akhir].jumlahnilai = 0;

        for (int i = 0; i < 5; i++)
        {
            cout << i+1 <<". Nilai Matkul "<< matkul[i]<< " :";
            cin >> Mhs[Queue.akhir].nilai[i];
            Mhs[Queue.akhir].jumlahnilai +=  Mhs[Queue.akhir].nilai[i];
        }
        
        ipk = Mhs[Queue.akhir].jumlahnilai / 5;
        Mhs[Queue.akhir].Ipk = ipk;
    

        ++Queue.akhir;
        cout << endl;
        menu();
    }else {
        cout << "Data penuh";
        menu();
    }
}
void Ascbubble(){
    int h, x, temp;
    for ( h = 0; h < Queue.akhir; h++)
    {
        for ( x = 0; x < Queue.akhir; x++)
        {
            if (Mhs[x].Ipk < Mhs[x+1].Ipk)
            {
                temp = Mhs[x].Ipk;
                Mhs[x].Ipk = Mhs[x+1].Ipk;
                Mhs[x+1].Ipk = temp;
            } 
        }  
    }
}

void tampilipksort(){
    if (!isEmpty()){
        Ascbubble();
        cout << "\n";
        cout << "==Hasil Sorting=="<<endl;
        for (int i = 0; i < Queue.akhir; i++)
        {
            cout << i+1 <<" . IPK : "<< Mhs[i].Ipk <<endl; 
        }
    } else{
        cout << "IPK Kosong !!!"<<endl;
    }
    menu();
}

void cari(){
          string cari;
        int ketemu, posisi;
        cout << "Masukan Nama Matakuliah yang dicari (besar/kecil perlu huruf diperhatikan): ";
        cin >> cari;
       
        ketemu = 0;
        for (int i = 0; i < Queue.akhir; i++)
        {
          if (Mhs[i].nama == cari)
          {
            ketemu = 1;
            posisi = i;
            i = 5;
          }  
        }
        if (ketemu == 0)
        {
          cout << "Data tidak ditemukan!!!!"<<endl;
        }else{
          cout << "Data ditemukan pada indek : " << posisi <<endl;
         
        }
    menu();
}
void menu(){
    int pilih;
    cout << "========Menu=======\n";
    cout << "1. Tambah Data\n";
    cout << "2. Hapus Satu Data(Queue)\n";
    cout << "3. Reset Data\n";
    cout << "4. Tampil Data\n";
    cout << "5. Sort Berdasar Ipk\n";
    cout << "6. Cari Data Mhs\n";
    cout << "====================\n";
    cout << "Masukkan pilihan anda: ";
    cin >> pilih;
    cout << endl;
    if(pilih == 1){
        inQueue();
    }else if(pilih == 2){
        deQueue();
    } else if(pilih == 3){
        init();
    }else if(pilih == 4){
        tampil();
    }else if(pilih == 5){
        tampilipksort();
    }else if(pilih == 6){
        cari();
    }else {
        menu();
    }
}

void deQueue(){
    if(!isEmpty()){
        for(int i = Queue.awal; i < Queue.akhir; i++){
            Mhs[i].nama = Mhs[i+1].nama;
            Mhs[i].nim = Mhs[i+1].nim;
            Mhs[i].jumlahnilai = Mhs[i+1].jumlahnilai;
            Mhs[i].Ipk = Mhs[i+1].Ipk;
            for (int j = 0; j < 5; j++)
            {
                Mhs[i].nilai[j] = Mhs[i+1].nilai[j];
            }
        }Queue.akhir--;
        cout << "Data berhasil dihapus" << endl;
        cout << endl;
        menu();
    }else{
        cout << "antrian kosong" << endl;
    }
}

void tampil(){
    if(!isEmpty()){
        cout << "\n";
        cout << "==Data Mahasiswa=="<<endl;
        for(int i = 0; i < Queue.akhir; i++){
        cout << "Nama Mahasiswa: " << Mhs[i].nama << endl;
        cout << "NIM : " << Mhs[i].nim << endl;
        cout << "jumlah nilai = " << Mhs[i].jumlahnilai<<endl; 
        cout << "Nilai IPK = " << setprecision(3) << Mhs[i].Ipk <<endl;
        for (int j = 0; j < 5; j++)
        {
          cout <<j+1 << " || "<<"nilai "<<matkul[j]<<" == "<<Mhs[i].nilai[j]<<endl; 
        }
        }
    }else {
        cout << "data kosong!!!";
        cout << endl << endl;
    }
    menu();
}

int main(){
    menu();

    return 0;
}