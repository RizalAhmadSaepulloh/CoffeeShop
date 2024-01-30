#include <stdio.h>
#include <string.h>

// Struktur data untuk menyimpan informasi minuman
typedef struct
{
    char nama[50];
    float harga;
    int total;
} Minuman;

typedef struct
{
    char username[20];
    char password[20];
} DATAUSER;

void register_user(DATAUSER user[]);
void login_user(DATAUSER user[]);
void ceklogin(DATAUSER user[]);
void register_user(DATAUSER user[]);
void menucofeeshop();
void login_user(DATAUSER user[]);
void optional(int pilihanTambah, int n);
void order();
void cetakStruk(Minuman namaMinuman[], int jumlah, Minuman hargaMinuman[], float totalA[], int n);
void searchMinuman(Minuman menuMinuman[], int n);
void bubbleSort(Minuman menuMinuman[], int n);

void pilihan_menu_utama()
{
    int choice;
    DATAUSER user[2];
    do
    {
        printf("======== SELAMAT DATANG DI MENU COFFEE SHOP =========\n[1] REGISTER\n[2] LOGIN\n[3] EXIT\n");
        printf("MASUKKAN PILIHAN : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            register_user(user);
            break;
        case 2:
            login_user(user);
            break;
        case 3:
            printf("Apakah Anda yakin ingin keluar? (y/n): ");
            char confirm;
            scanf(" %c", &confirm);
            if (confirm == 'y' || confirm == 'Y')
            {
                printf("ANDA BERHASIL KELUAR\n");
                return; // Keluar dari program
            }
            break;
        default:
            printf("Pilihan tidak valid.\n");
            break;
        }
    } while (1);
}

void register_user(DATAUSER user[])
{
    int i = 0;
    do
    {
        printf("=== REGISTER ===\n");
        printf("Masukkan username : ");
        scanf("%s", user[i].username);
        printf("Masukkan password : ");
        scanf("%s", user[i].password);
        printf("=== Registrasi berhasil ===\nsilahkan login\n");

        char choice;
        printf("Lanjutkan registrasi? (y/n): ");
        scanf(" %c", &choice);
        if (choice == 'n' || choice == 'N')
        {
            break;
        }

        i++;
    } while (1);
}

void login_user(DATAUSER user[])
{
    int i = 0;
    do
    {
        printf("=== LOGIN ===\n");
        printf("Masukkan username : ");
        scanf("%s", user[i].username);
        printf("Masukkan password : ");
        scanf("%s", user[i].password);
        ceklogin(user);

        char choice;
        printf("Coba login lagi? (y/n): ");
        scanf(" %c", &choice);
        if (choice == 'n' || choice == 'N')
        {
            break;
        }

        i++;
    } while (1);
}

void ceklogin(DATAUSER user[])
{
    int i = 0, j = 0, found = 0;
    for (i = 0; i <= 10; i++)
    {

        if (strcmp(user[i].username, user[j].username) == 0 && strcmp(user[i].password, user[j].password) == 0)
        {
            found = 1;
        }
    }
    if (found != 0)
    {

        printf("=== Berhasil Login ===\n");
        menucofeeshop();
    }
    else
    {
        printf("=== Login gagal ===");
    }
}

// Fungsi untuk memesan minuman
float pesanMinuman(int jumlah, Minuman harga[], int i)
{
    return jumlah * harga[i].harga;
}

// Fungsi untuk mencetak struk pembayaran
void cetakStruk(Minuman namaMinuman[], int jumlah, Minuman hargaMinuman[], float total[], int pilihan)
{
    printf("==== COFFEE SHOP ====\n");
    printf("Nama Minuman: %s\n", namaMinuman[pilihan].nama);
    printf("Jumlah: %d\n", jumlah);
    printf("Harga: Rp. %.2f\n", hargaMinuman[pilihan].harga);
    printf("Total: Rp. %.2f\n", total[pilihan]);
    printf("=====================\n");
}

void bubbleSort(Minuman menuMinuman[], int n)
{
    int i, j;
    Minuman temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (menuMinuman[j].harga > menuMinuman[j + 1].harga)
            {
                temp = menuMinuman[j];
                menuMinuman[j] = menuMinuman[j + 1];
                menuMinuman[j + 1] = temp;
            }
        }
    }
}

void searchMinuman(Minuman menuMinuman[], int n)
{
    char namaMinuman[50];
    getchar();
    printf("Masukkan nama minuman yang ingin dicari : ");
    fgets(namaMinuman, sizeof(namaMinuman), stdin);

    // Menghapus karakter newline dari namaMinuman
    int len = strlen(namaMinuman);
    if (namaMinuman[len - 1] == '\n')
    {
        namaMinuman[len - 1] = '\0';
    }

    int found = 0;
    for (int i = 0; i < n; i++)
    {
        if (strstr(menuMinuman[i].nama, namaMinuman) != NULL)
        {
            printf("%d. %s - Rp.%.2f\n", i + 1, menuMinuman[i].nama, menuMinuman[i].harga);
            found = 1;
        }
    }

    if (found == 0)
    {
        printf("Minuman '%s' tidak ditemukan.\n", namaMinuman);
    }
}

void menucofeeshop()
{
    char namaMinuman[50];
    int jumlah;
    float total = 0.0;
    float pajak = 0.1; // Pajak sebesar 10%
    int pilihan, n;
    int pilihanTambah;
    float hargaTambahan;
    printf("Selamat datang di Coffee Shop!\n");
    printf("Masukkan Jumlah Minuman Yang dipesan : \n");
    scanf("%d", &n);
    Minuman menuMinuman[n];
    float totalA[n];
    // Inisialisasi menu minuman
    for (int i = 0; i < n; i++)
    {
        getchar();
        printf("Masukkan Nama Minuman yang dipesan : \n");
        fgets(menuMinuman[i].nama, sizeof(menuMinuman[i].nama), stdin);
        int len = strlen(menuMinuman[i].nama);
        if (namaMinuman[len - 1] == '\n')
        {
            namaMinuman[len - 1] = '\0';
        }

        printf("Masukkan Harga Minuman yang dipesan : \n");
        scanf("%f", &menuMinuman[i].harga);
    }

    // Menampilkan menu minuman
    printf("Menu Minuman:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d. %s - Rp.%.2f\n", i + 1, menuMinuman[i].nama, menuMinuman[i].harga);
    }

    // Sorting menu minuman berdasarkan harga
    bubbleSort(menuMinuman, n);

    // Menampilkan menu minuman setelah diurutkan berdasarkan harga
    printf("Menu minuman setelah diurutkan berdasarkan harga : \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d. %s - Rp.%.2f\n", i + 1, menuMinuman[i].nama, menuMinuman[i].harga);
    }
    // Mencari minuman berdasarkan nama
    searchMinuman(menuMinuman, n);

    // Memilih minuman
    printf("Masukkan nomor minuman yang ingin dipesan: ");
    scanf("%d", &pilihan);
    pilihan--; // Mengubah pilihan ke indeks array

    // Meminta input jumlah
    printf("Masukkan jumlah: ");
    scanf("%d", &jumlah);

    // Memesan minuman
    for (int i = 0; i < n; i++)
    {
        totalA[i] += pesanMinuman(jumlah, menuMinuman, pilihan);
    }

    // cetakStruk(menuMinuman, jumlah, total,hargaTambahan);
    cetakStruk(menuMinuman, jumlah, menuMinuman, totalA, pilihan);
}


int main()
{
    pilihan_menu_utama();
    return 0;
}