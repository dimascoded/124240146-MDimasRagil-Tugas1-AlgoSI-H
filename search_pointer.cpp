#include <iostream>
#include <stdlib.h>
using namespace std;

struct batalyon
{
    int id, jumlah;
    string nama_general, tipe;
};

bool namaSudahAda(batalyon bt[], int jml_indeks, string nama)
{
    for (int i = 0; i < jml_indeks; i++)
    {
        if (bt[i].nama_general == nama)
        {
            return true;
        }
    }
    return false;
}

void tambah(batalyon bt[100], string tipe_pasukan[3], int &jml_indeks)
{
    string *type = tipe_pasukan;
    bool found = false;
    int i = 0;
    string nama;

    cin.ignore();
    do
    {
        cout << "Input General Name : ";
        getline(cin, nama);

        if (namaSudahAda(bt, jml_indeks, nama))
        {
            cout << "Error: Nama General sudah ada! Silakan masukkan nama lain.\n";
        }
    } while (namaSudahAda(bt, jml_indeks, nama));

    bt[jml_indeks].nama_general = nama;

    while (!found)
    {
        cout << "Input Soldier Type (Infantry/Kavaleri/Archer): ";
        cin >> bt[jml_indeks].tipe;

        for (i = 0; i < 3; i++)
        {
            if (bt[jml_indeks].tipe == *(type + i))
            {
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "Tipe pasukan tidak valid! Silakan masukkan lagi.\n";
        }
    }
    cout << "Input Soldier Quantity: ";
    while (!(cin >> bt[jml_indeks].jumlah) || bt[jml_indeks].jumlah <= 0)
    {
        cout << "Error: Masukkan jumlah yang valid (harus angka positif).\n";
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Input Soldier Quantity: ";
    }

    jml_indeks++;
}

void cari(batalyon bt[100], int &jml_indeks)
{
    int awal = 0, akhir = jml_indeks - 1, tengah;
    string find;
    bool found = false;

    cin.ignore();
    cout << "Masukkan Nama General yang ingin dicari : ";
    getline(cin, find);

    while (!found && awal <= akhir)
    {
        tengah = (awal + akhir) / 2;

        if (bt[tengah].nama_general == find)
        {
            found = true;
        }
        else if (bt[tengah].nama_general > find)
        {
            akhir = tengah - 1;
        }
        else
        {
            awal = tengah + 1;
        }
    }

    if (found)
    {
        cout << "ID = " << tengah + 1 << endl;
        cout << "Soldier Type = " << bt[tengah].tipe << endl;
        cout << "Soldier Quantity = " << bt[tengah].jumlah;
    }
    else
    {
        cout << "Tidak ada general bernama " << find << " dalam Array." << endl;
    }
}

int main()
{
    string lanjut;
    int jml_indeks = 0;
    batalyon bt[100];
    string tipe_pasukan[3] = {"Infantry", "Kavaleri", "Archer"};
    int pilih;

    do
    {
        system("cls");
        cout << "\n===== Daftar Menu =====" << endl;
        cout << "1. Tambah Batalyon" << endl;
        cout << "2. Cari Batalyon" << endl;
        cout << "Pilih Menu : ";
        cin >> pilih;

        switch (pilih)
        {
        case 1:
            tambah(bt, tipe_pasukan, jml_indeks);
            break;
        case 2:
            cari(bt, jml_indeks);
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
        }

        cout << "\nApakah anda ingin melanjutkan? (ya/tidak) = ";
        cin >> lanjut;
    } while (lanjut == "ya");
    system("cls");

    return 0;
}
