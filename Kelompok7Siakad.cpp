#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;
string nama;
char npm[20];

void refresh(){
    system("cls");
}

void newline(){
    cout << "\n";
}

void heading(){
    system("mode con:cols=72 lines=30");
    system("color 09");
    newline();

    cout << "<======================================================================>\n";
    cout << "|                      SISTEM INFORMASI AKADEMIK                       |\n";
    cout << "|                            INFORMATIKA 1C                            |\n";
    cout << "|                UNIVERSITAS SINGAPERBANGSA KARAWANG                   |\n";
    cout << "<======================================================================>\n";
}

int page1(){
    heading();
    newline();
    cout << "Masukkan Nama Lengkap    : ";
    getline(cin, nama);
    cout << "Masukkan NPM             : ";
    cin >> npm;
}

int page2(){
    refresh();
    heading();
    cout << "\n";
    cout << " _________________________" << endl;
    cout << "|                         |" << endl;
    cout << "| 1. Rekap Nilai          |" << endl;
    cout << "| 2. Absensi              |" << endl;
    cout << "| 3. EXIT                 |" << endl;
    cout << "|_________________________|" << endl;
}

int pagengulang(){
    refresh();
    heading();
    page2();
    system("color 04");

    cout << "\n";
    cout << "Kode yang anda masukkan tidak tersedia ! " << endl;
}

struct data{
    string prodi;
    string kelas;
    string matakuliah;
    int bobotsks;
};

struct nilai{
    int nTUGAS;
    int nQUIZ;
    int nUTS;
    int nUAS;
};

int main(){
    int pilihan;
    char absen;
    string pengulangan;
    data mhs;
    nilai matkul;

    do{
        page1();

        awal :
        page2();
        cout << "\nSilakan pilih : ";
        cin >> pilihan;
        refresh();
        if(pilihan == 1){
            pilihan = 1;
        }else if(pilihan == 2){
            pilihan = 2;
        }else if(pilihan == 3){
            system("exit");
        }else{
            pagengulang();
        }
        switch(pilihan){
            case 1:
                float nilaitotal, rata_rata;

                heading();

                cout << "kelas          : ";
                cin >> mhs.kelas;
                cout << "Program Studi  : ";
                cin >> mhs.prodi;
                cout << "Mata Kuliah    : ";
                cin >> mhs.matakuliah;
                cout << "Bobot SKS      : ";
                cin >> mhs.bobotsks;
                newline();

                cout << "\nMasukkan data - data nilai dibawah ini : " << endl;
                cout << "Nilai Tugas    :";
                cin >> matkul.nTUGAS;
                cout << "Nilai Quiz     :";
                cin >> matkul.nQUIZ;
                cout << "Nilai UTS      :";
                cin >> matkul.nUTS;
                cout << "Nilai UAS      :";
                cin >> matkul.nUAS;
                newline();

                cout << "Klik apa saja untuk lanjut !" << endl;
                system("pause");
                system("color 1a");

                refresh();
                heading();
                cout << "\n<========================== DATA MAHASISWA ============================>\n";
                cout << "Nama Mahasiswa : " << nama << endl;
                cout << "NPM            : " << npm << endl;
                cout << "Prodi          : " << mhs.prodi << endl;
                cout << "Kelas          : " << mhs.kelas << endl;
                newline();
                newline();

                cout << "<======================== REKAPITULASI NILAI ==========================>\n";
                cout << "Mata Kuliah	: " << mhs.matakuliah << endl;
                cout << "Bobot SKS	: " << mhs.bobotsks << endl;
                cout << "Nilai Tugas     : " << matkul.nTUGAS << endl;
                cout << "Nilai Quiz      : " << matkul.nQUIZ << endl;
                cout << "Nilai UTS       : " << matkul.nUTS << endl;
                cout << "Nilai UAS       : " << matkul.nUAS << endl;

                nilaitotal = matkul.nTUGAS + matkul.nQUIZ + matkul.nUTS + matkul.nUAS;
                cout << "Nilai Total     : " << nilaitotal << endl;
                rata_rata = nilaitotal / 4;
                cout << "Rata - rata     : " << rata_rata << endl;
                if(rata_rata >= 80){
                    cout << "Grade : A" << endl;
                    system("color 27");
                }else if(rata_rata >= 70 && rata_rata <= 79){
                    cout << "Grade : B" << endl;
                    system("color a7");
                }else if(rata_rata >= 55 && rata_rata <= 69){
                    cout << "Grade : C" << endl;
                    system("color 67");
                }else if(rata_rata >= 35 && rata_rata <= 54){
                    cout << "Grade : D" << endl;
                    system("color 67");
                }else if (rata_rata >= 0 && rata_rata <= 34){
                    cout << "Grade : E" << endl;
                    system("color 47");
                }else{
                    cout << "Grade : F" << endl;
                    system("color 47");
                }
                newline();

                cout << "Ingin kembali ke menu awal (Y / N)? ";
                cin >> pengulangan;

                if(pengulangan == "Y" || pengulangan == "y"){
                    goto awal;
                } else{
                    system("exit");
                }
                break;
            case 2:
                int H = 0, I = 0, A = 0;
                heading();
                cout << "			Absensi Kehadiran\n";
                cout << "\nMata Kuliah : ";
                cin >> mhs.matakuliah;
                for(int b=1;b<17;b++){
                    cout << "Absensi Pertemuan Ke-" << b << " (H/I/A) : ";
                    cin >> absen;
                    switch(absen){
                        case 'H':
                            H++;
                            break;
                        case 'I':
                            I++;
                            break;
                        case 'A':
                            A++;
                            break;
                    }
                }
                system("cls");
                heading();
                cout << "			REKAPITULASI ABSENSI\n";
                cout << "\nNama Lengkap : " << nama << endl;
                cout << "NPM          : " << npm << endl;
                cout << "Mata Kuliah  : " << mhs.matakuliah << endl;
                newline();
                cout << "Jumlah Hadir : " << H << endl;
                cout << "Jumlah Izin  : " << I << endl;
                cout << "Jumlah Alpa  : " << A << endl;

                newline();

                cout << "Ingin kembali ke menu awal (Y / N)? ";
                cin >> pengulangan;

                string *var2 = &pengulangan;

                if(*var2 == "Y" || *var2 == "y"){
                    goto awal;
                } else{
                    system("exit");
                }
                break;
        }
       break;
      }while(page1);
return 0;
}
