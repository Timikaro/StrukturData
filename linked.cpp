#include <iostream>
#include <stdlib.h>
using namespace std;

string matkul[5] = {"Sistem Operasi", "Fotografi", "Pemrograman", "Struktur Data", "Komunikasi Data"};

struct Node
{
    string nama;
    int nim;
    int nilai[5];
    int jumlahnilai;
    float ipk;
    Node *next;
};

Node *headNode = NULL;
Node *currentNode = NULL;
void search();
void sortBubble();
bool isEmpty();
void insertNode(string nama, int nim, int nilaia, int nilaib, int nilaic, int nilaid, int nilaie);
void deleteFromFront();
void deleteFromEnd();
void deleteAll();
void printNode();

int main()
{    
    int pilihanMenu;
    string nama;
    int nim;
    int nilaiSO,nilaiFG,nilaiPG,nilaiSD,nilaiKD; 
    do 
    {
        cout << ">>> Menu Linked List <<<" << endl << endl;
        cout << "1. Menambahkan Data" << endl;
        cout << "2. Menghapus Data dari Depan" << endl;
        cout << "3. Menghapus Data dari Belakang" << endl;
        cout << "4. Mengosongkan Data" << endl;
        cout << "5. Menampilkan Data" << endl;
        cout << "6. SortingNim" << endl;
        cout << "7. SearchNim" << endl ;
        cout << "Masukkan pilihan Anda : "; cin >> pilihanMenu;
        cout << endl;
        switch (pilihanMenu)
        {
            case 1: 
                cout << "Masukkan nama : ";
                cin >> nama;
                cout << "Masukan nim : ";
                cin >> nim;
                cout << "1. Nilai Matkul Sistem Operasi = "; cin >> nilaiSO;
                cout << "2. Nilai Matkul Fotografi = "; cin >> nilaiFG;
                cout << "3. Nilai Matkul Pemrograman = "; cin >> nilaiPG;
                cout << "4. Nilai Matkul Struktur Data = "; cin >> nilaiSD;
                cout << "5. Nilai Matkul Komunikasi Data = "; cin >> nilaiKD;
                
                insertNode(nama, nim, nilaiSO ,nilaiFG, nilaiPG, nilaiSD, nilaiKD);
                break;
                
            case 2: 
                if (isEmpty())
                {
                    cout << "List masih kosong !!!" << endl << endl;
                }
                else
                {
                    deleteFromFront();
                }
                break;
                
            case 3: 
                if (isEmpty())
                {
                    cout << "List masih kosong !!!" << endl << endl;
                }
                else
                {
                    deleteFromEnd();
                }
                break;
                
            case 4:
                if (isEmpty())
                {
                    cout << "List masih kosong !!!" << endl << endl;
                }
                else
                {
                    deleteAll();
                }
                break;
                
            case 5: 
                if (isEmpty())
                {
                    cout << "List masih kosong !!!" << endl << endl;
                }
                else
                {
                    printNode();
                }
                break;
                
            case 6:
              if (isEmpty())
                {
                    cout << "List masih kosong !!!" << endl << endl;
                }
                else
                {
                    sortBubble();
                }
                break;

             case 7:
              if (isEmpty())
                {
                    cout << "List masih kosong !!!" << endl << endl;
                }
                else
                {
                    search();
                }
                break;
                 
            
            default:
                cout << "Menu yang Anda pilih tidak terdaftar" << endl << endl;
                break;
        }
        
    } while (pilihanMenu != 6);
        
    cout << endl;    
                           
    system("pause");
    return 0;
}

bool isEmpty()
{
    return (headNode == NULL);
}

void insertNode(string  nama, int nim, int nilaia, int nilaib, int nilaic, int nilaid, int nilaie)
{
    // deklarasi pointer newNode;
    Node *newNode = NULL;
    
    // mengalokasikan memory untuk pointer newNode
    newNode = new Node;

    int arrnilai[5] = {nilaia,nilaib,nilaic,nilaid,nilaie};        
    // isikan data ke node yang baru
    newNode->nama = nama;
    newNode->nim = nim;
    newNode->jumlahnilai = 0;
    for (int i = 0; i < 5; i++)
    {
        newNode->nilai[i] = arrnilai[i];
        newNode->jumlahnilai += arrnilai[i];
    }
    
    newNode->ipk = newNode->jumlahnilai / 5;

    if (isEmpty()) // node masih kosong
    {
        // node baru otomatis menjadi head node                  
        headNode = newNode;                                    
    }
    else // sudah ada node
    {
        // hubungkan pointer next node aktif (current node)
        // ke node yg baru
        currentNode->next = newNode;                    
    }

    // set node baru sebagai node aktif         
    currentNode = newNode;    
    
    // set pointer next node terakhir menjadi NULL
    currentNode->next = NULL;    
    
    cout << "Node berhasil ditambahkan" << endl << endl;
}

void deleteFromFront()
{
    if (!isEmpty())
    {
        // deklarasi var bantu untuk menampung headNode                   
        Node *hapusNode = headNode;                        
        
        // pindahkan headNode ke node berikutnya
        headNode = headNode->next;        
        
        // hapus headNode yang lama
        delete hapusNode;  
                
        cout << "Node berhasil dihapus" << endl << endl;
    }
}

void deleteFromEnd()
{
    // jika node tinggal satu
    if (headNode == currentNode)
    {
        headNode = NULL;
        currentNode = NULL;
        return;
    }  
    // deklarasi pointer bantu untuk menampung head node
    Node *bantu = headNode;
    
    // deklarasi pointer hapus untuk menampung current node
    Node *hapusNode = currentNode;
    // lakukan perulangan sebelum mencapai akhir node
    while (bantu->next != currentNode)
    {
        bantu = bantu->next;
    }  
    currentNode = bantu;
    currentNode->next = NULL;  
    delete hapusNode; 
    cout << "Node berhasil dihapus" << endl << endl;
}

void deleteAll()
{
    Node *bantu, *hapusNode;
    bantu = headNode; 
    // lakukan perulangan sebelum mencapai akhir node
    while (bantu->next != currentNode)
    {
        hapusNode = bantu;
        bantu = bantu->next; 
        delete hapusNode;
    }
    headNode = NULL;
    currentNode = NULL;
    cout << "Node berhasil dikosongkan" << endl << endl;
}

void printNode()
{
    // deklarasi pointer awal node untuk menampung head node
    Node *awalNode = headNode;
    int i = 1;
    while (awalNode != NULL)
    {
        // cout << "Data pada node #" << i << " = " << awalNode->data << endl;
        // awalNode = awalNode->next;         
            
        cout << "data ke-"<<i<<endl;
        cout << "nama = "<< awalNode->nama <<endl;
        cout << "nim  = "<< awalNode->nim <<endl;
        cout << "Jumlah nilai = "<<awalNode->jumlahnilai<<endl;
        cout << "Nilai IPK = "<<awalNode->ipk<<endl;
        for (int i = 0; i < 5; i++)
        {
            cout <<i+1<< ". nilai Matkul "<< matkul[i] <<" = "<< awalNode->nilai[i]<<endl;
        }
        
        
        awalNode = awalNode->next;
        i++;
    }  
    cout << endl;      
}

void sortBubble(){
    Node *awalNode = headNode;
    int i = 1;
    int arr[20];
    int x,j,tmp;
    while (awalNode != NULL)
    {
        arr[i] = awalNode->nim ;
        awalNode = awalNode->next;
        i++;
    }

    for ( x = 0; x < 5; x++)
    {
       for ( j = 0; j < 5; j++)
       {
            if (arr[j]> arr[j+1])
            {
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }   
       }
    }

    for (int s = 0; s < 3; s++)
    {
        cout << arr[s]<<endl;
    }
}
void search(){
    Node *awalNode = headNode;
    int i = 1;
    int arr[20];
    while (awalNode != NULL)
    {
        arr[i] = awalNode->nim ;
        awalNode = awalNode->next;
        i++;
    }
        int cari;
        int ketemu, posisi;
        cout << "Masukan Nim yang dicari : ";
        cin >> cari;
       
        ketemu = 0;
        for (int a = 0; a < 20; a++)
        {
          if (arr[a] == cari)
          {
            ketemu = 1;
            posisi = a;
            a = 5;
          }  
        }
        if (ketemu == 0)
        {
          cout << "Data tidak ditemukan!!!!"<<endl;
        }else{
          cout << "Data ditemukan pada indek : " << posisi <<endl;
        }

}