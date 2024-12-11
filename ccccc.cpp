#include <iostream>
#include <iomanip>     
#include <conio.h>     
#include <windows.h>
#include <string> 
using namespace std;

const int Max_buku = 5;
string namapeminjam[100], nimpeminjam[100], kodebuku[100 * Max_buku];
string judulbuku[100 * Max_buku];
int lamabuku[100 * Max_buku], jumlahbuku[100];
int jumlahpeminjam = 0;

void loading(){                            
    cout << "\n\nLoading";
    for(double a = 1;a < 8; a++){   
        Sleep(150);                         
	cout << ".";}
    cout << "\033c";
}

void inputdata() {
    int peminjam;

    cout << setfill('=') << setw(30) << "=" << endl;
    cout << "|" << setfill(' ') << setw(18) << "INPUT DATA" << setw(12) << "|\n";
    cout << setfill('=') << setw(30) << "=" << endl;
    cout << "\t\nINPUT DATA PEMINJAM" << endl;
    cout << "\nInput jumlah peminjam : "; 
    cin >> peminjam;

    for (int i = 0; i < peminjam; i++){
        cout << "\n\tInput Nama peminjam ke-" << (jumlahpeminjam + 1) << " : "; cin.ignore();
        getline(cin, namapeminjam[jumlahpeminjam]);
        cout << "\tInput NIM peminjam ke-" << (jumlahpeminjam + 1) << " : "; getline(cin, nimpeminjam[jumlahpeminjam]);
        cout << "\tJumlah buku yang dipinjam peminjam ke-" << (jumlahpeminjam + 1) << " : "; cin >> jumlahbuku[jumlahpeminjam];

        while (jumlahbuku[jumlahpeminjam] > Max_buku){
            cout << "\tTidak boleh meminjam buku lebih dari 5. Silahkan input kembali!!!" << endl;
            cout << "\tJumlah buku yang dipinjam peminjam ke-" << (jumlahpeminjam + 1) << " : "; cin >> jumlahbuku[jumlahpeminjam];
        }

        cout << "\n\t\tINPUT DATA BUKU" << endl;
        for (int j = 0; j < jumlahbuku[jumlahpeminjam]; j++){
            cout << "\n\t\tInput judul buku ke-" << (j + 1) << " : "; cin.ignore();
            getline(cin, judulbuku[jumlahpeminjam * Max_buku + j]);
            cout << "\t\tInput kode buku ke-" << (j + 1) << " : "; getline(cin, kodebuku[jumlahpeminjam * Max_buku + j]);
            cout << "\t\tInput lama meminjam buku ke-" << (j + 1) << " (dalam hari) : "; cin >> lamabuku[jumlahpeminjam * Max_buku + j];
        }
        jumlahpeminjam++; // jumlah peminjam setelah data baru ditambahkan
    }

    cout << "\npress any key to continue...." << endl;
    getch();
    loading();
}

void showdata(){
    if (jumlahpeminjam == 0){
        cout << "Tidak ada data peminjam!!!" << endl;
    } else {
        cout << setfill('=') << setw(30) << "=" << endl;
        cout << "|" << setfill(' ') << setw(18) << "SHOW DATA" << setw(12) << "|\n";
        cout << setfill('=') << setw(30) << "=" << endl;
        cout << "\nDaftar Peminjam dan Buku yang Dipinjam:\n";
        for (int i = 0; i < jumlahpeminjam; i++){
            cout << "\nNama Peminjam ke-" << (i + 1) << " : " << namapeminjam[i] << endl;
            cout << "NIM Peminjam ke-" << (i + 1) << " : " << nimpeminjam[i] << endl;
            cout << "Buku yang dipinjam Peminjam ke-" << (i + 1) << " : " << jumlahbuku[i] << endl;
            cout << "\n\tDATA BUKU :" << endl;

            for (int j = 0; j < jumlahbuku[i]; j++){
                cout << "\n\tJudul Buku ke-" << (j + 1) << " : " << judulbuku[i * Max_buku + j] << endl;
                cout << "\tKode Buku ke-" << (j + 1) << " : " << kodebuku[i * Max_buku + j] << endl;
                cout << "\tLama meminjam buku ke-" << (j + 1) << " (dalam hari) : " << lamabuku[i * Max_buku + j] << " hari" << endl;
            }

        }
    }
    cout << "\npress any key to continue...." << endl;
    getch();
    loading();
}

int main() {
    int pilih;
    do {
        system("CLS");
        cout << setfill('=') << setw(30) << "=" << endl;
        cout << "|" << setfill(' ') << setw(18) << "MAIN MENU" << setw(12) << "|\n";
        cout << setfill('=') << setw(30) << "=" << endl;
        cout << "|" << setfill(' ') << setw(2) << " 1. INPUT DATA"<< setw(16) << "|\n";
        cout << "|" << setfill(' ') << setw(2) << " 2. SHOW DATA"<< setw(17) << "|\n";
        cout << "|" << setfill(' ') << setw(2) << " 3. EXIT"<< setw(22) << "|\n";
        cout << setfill('=') << setw(30) << "=" << endl;
        cout << "Pilih : ";cin >> pilih;
        loading();
        switch (pilih){
            case 1:
                inputdata();
                break;
            case 2:
                showdata();
                break;
            case 3:
                cout << "\nTerima kasih!!" << endl;
                break;
            default :
            cout << "Pilihan tidak tersedia!! Silahkan pilih antara 1, 2, dan 3\n\n";
        }
    } while (pilih != 3);
    return 0;
}