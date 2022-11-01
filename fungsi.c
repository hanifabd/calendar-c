#include "header.h"
/// Pembukaan aplikasi
void open()
{
    puts("");
    puts("");
    puts("");
    puts("");
    puts("\t0000000 00000000 00      0000    000 0000000000 000000000 000000");
    puts("\t0000000 00000000 00      00000   000 0000000000 000000000 00    ");
    puts("\t00      00    00 00      000000  000 000    000    000    00    ");
    puts("\t00      00000000 00      000 000 000 000    000    000    000000");
    puts("\t00      00000000 00      000  000000 000    000    000    00    ");
    puts("\t0000000 000   00 0000000 000   00000 0000000000    000    00    ");
    puts("\t0000000 000   00 0000000 000    0000 0000000000    000    000000");
    puts("");
    puts("\t\t\t                    ~ NOTE EVERYTHING YOU WANT ~");
}

/// Menu utama yang akan muncul setelah void open ()
void menu()
{
    kalender kal[20]; /// banyak data yang akan ditampung
    int n=0; /// variabel untuk menghitung banyak data/array yang terisi
    char pilih; /// untuk menampung data pilihan pada menu dibawah
    balik:system("cls");
    printf("\n\n");
    printf("\t\t\t    _______________________  \n");
    printf("\t\t\t   |       MAIN MENU :     |  \n");
    printf("\t\t\t   |-----------------------|  \n");
    printf("\t\t\t   |  1.Tambah Kegiatan    |  \n");
    printf("\t\t\t   |  2.Tampil Kegiatan    |  \n");
    printf("\t\t\t   |  3.Hapus Kegiatan     |  \n");
    printf("\t\t\t   |  4.Cari Kegiatan      |  \n");
    printf("\t\t\t   |  5.Urutkan Kegiatan   |  \n");
    printf("\t\t\t   |  6.Keluar             |  \n");
    printf("\t\t\t   |_______________________|");
    printf("\n\n\t\t  ==> Pilih: "); scanf("%c",&pilih); /// untuk memilih program apa yang ingin dijalankan
    puts("");
    if(pilih=='1') /// pilih 1 untuk menambahkan data
    {
        system("cls"); /// untuk membersihkan layar cmd
        printf("* TAMBAH KEGIATAN \n");
        tambah(kal,n);
        n++; /// untuk menambah data
        fflush(stdin);
        printf("==> Lanjut ? ");scanf("%c",&pilih);
        goto balik;
    }
    else if(pilih=='2') /// pilih 2 untuk menampilkan data
    {
        tampil(kal,0,n); /// memanggil fungsi tampil
        fflush(stdin);
        printf("==> Kembali? ");scanf("%c",&pilih);
        goto balik;
    }
    else if(pilih =='3') /// pilih 3 untuk menghapus data
    {
        int ires; /// untuk menampung data yang digunakan untuk mengisi data array ke -x untuk dihapus
        int batal; /// untuk meyakinkan apakah lanjut menghapus atau tidak jadi
        tampil(kal, 0, n);
        printf("1.Ya \n0.Tidak \nYakin Hapus ? ");scanf("%i", &batal); /// menentukan pilihan apakah benar akan menghapus atau tidak
        if(batal == 0)
        {
            printf(" ");scanf("%c",&pilih);
            goto balik; /// jika tidak maka akan kembali pada menu awal
        }
        else if(batal == 1)
        {
            printf("Hapus Kegiatan Ke ? ");scanf("%i", &ires); /// berfungsi untuk menghapus data array ke - ires
            hapus(kal, n, ires); /// fungsi mengahapus
            n=n-1; /// data dikurangi karena telah terhapus
            system("cls");
            tampil(kal, 0, n);
            fflush(stdin);
            printf("==> Kembali? ");scanf("%c",&pilih);
            goto balik;
        }
    }
    else if(pilih=='4') /// pilih 4 untuk mencari data
    {
        kalender cari; /// struct untuk menampung data yang akan dicari
        puts("!!Pisahkan Tanggal,Bulan dan Tahun masing-masing dengan 1 Spasi");
        puts("                          D M Y");
        printf("Masukkan tanggal\t: "); scanf("%d %d %d",&cari.tang.tgl,&cari.tang.bln,&cari.tang.thn); /// input data kegiatan yang akan dicari
        searching(kal,n,cari,0);
        fflush(stdin);
        printf("==> Kembali? ");scanf("%c",&pilih);
        goto balik;
    }
    else if(pilih=='5') /// pilih 5 untuk mengurutkan data

    {
        sorting(kal,n);
        tampil(kal,0,n);
        fflush(stdin);
        printf("==> Kembali? ");scanf("%c",&pilih);
        goto balik;
    }
    else if(pilih=='6') /// pilih 6 untuk keluar dari aplikasi
    {

    }
}

void tambah(kalender kal[],int n)
{
    puts("_______________________________________________________________________________");

    puts("!!Pisahkan Tanggal,Bulan dan Tahun masing-masing dengan 1 Spasi");
    puts("                          D M Y");
    printf("Masukkan tanggal\t: "); scanf("%d %d %d",&kal[n].tang.tgl,&kal[n].tang.bln,&kal[n].tang.thn); /// untuk menginputkan tanggal

    puts("-------------------------------------------------------------------------------");

    puts("!!Pisahkan Jam dan Menit dengan 1 Spasi");
    puts("    Menggunakan format 24 jam, ex: 14 30");
    puts("\n                          H M");
    printf("Masukkan Jam\t\t: "); scanf("%d %d",&kal[n].wkt.jam,&kal[n].wkt.menit);fflush(stdin); /// untuk menginputkan waktu

    puts("-------------------------------------------------------------------------------");

    puts("!!Mau Ngapain? ");
    printf("Masukkan Kegiatan\t: "); gets(kal[n].kegiatan); /// untuk mendeskripsikan kegiatan

    puts("-------------------------------------------------------------------------------");

    puts("!!Siapa Orang Orang yang Terkait? ");
    printf("Masukkan Nama\t\t: "); gets(kal[n].nama);fflush(stdin); /// untuk menginputkan orang yang bersangkutan dengan kegiatan

    puts("_______________________________________________________________________________");
}

void tampil(kalender kal[],int cur,int n)
{
    if(cur==n) /// BASIS
    {

    }
    else /// REKURENS
    {
        printf("No. %d\n",cur+1);
        if(kal[cur].tang.tgl < 10 && kal[cur].tang.bln < 10)
        {
            printf("  Tanggal\t: 0%d-0%d-%d \n",kal[cur].tang.tgl,kal[cur].tang.bln,kal[cur].tang.thn);
        }
        else if(kal[cur].tang.bln < 10)
        {
            printf("  Tanggal\t: %d-0%d-%d \n",kal[cur].tang.tgl,kal[cur].tang.bln,kal[cur].tang.thn);
        }
        else if(kal[cur].tang.tgl < 10)
        {
            printf("  Tanggal\t: 0%d-%d-%d \n",kal[cur].tang.tgl,kal[cur].tang.bln,kal[cur].tang.thn);
        }
        else
        {
            printf("  Tanggal\t: %d-%d-%d \n",kal[cur].tang.tgl,kal[cur].tang.bln,kal[cur].tang.thn);
        }
        if(kal[cur].wkt.jam < 10 && kal[cur].wkt.menit < 10)
        {
            printf("  Jam\t\t: 0%d:0%d \n",kal[cur].wkt.jam,kal[cur].wkt.menit);
        }
        else if(kal[cur].wkt.menit < 10)
        {
            printf("  Jam\t\t: %d:0%d \n",kal[cur].wkt.jam,kal[cur].wkt.menit);
        }
        else if(kal[cur].wkt.jam < 10)
        {
            printf("  Jam\t\t: 0%d:%d \n",kal[cur].wkt.jam,kal[cur].wkt.menit);
        }
        else
        {
            printf("  Jam\t\t: %d:%d \n",kal[cur].wkt.jam,kal[cur].wkt.menit);
        }
        /// Kondisi diatas berfungsi untuk menampilkan format tanggal dibawah sepuluh dengan format 0x-0x-xxxx
        /// dan membuat format tanggal dan waktu diatas 10
        printf("  Kegiatan\t: %s \n",kal[cur].kegiatan);
        printf("  Orang Terkait\t: %s \n",kal[cur].nama);
        puts("");
        tampil(kal,cur+1,n); /// memanggil fungsi kembali
    }
}

void hapus(kalender kal[],int n, int ires)
{
    int awal;/// variabel yang nantinya digunakan sebagai penentu letak data array ke - x yang akan dihapus
    for(awal=ires-1 ; awal<n-1 ; awal++)
    {
        kal[awal]=kal[awal+1]; /// menghapus dengan cara mereplace data yang dimaksud dengan data sesudahnya
    }
}

void sorting(kalender kal[],int n)
{
    if(n<=1) /// BASIS
    {

    }
    else /// REKURENS
    {
        insort(kal,n-1,n-2,n-1); /// fungsi untuk sorting
        sorting(kal,n-1); /// memanggil fungsi kembali
    }
}
void insort(kalender kal[],int key,int a,int n)
{
    int jml1;
    int jml2;
    //printf("Key awal ==> %d\n",key);
    if(a==-1)
    {
        swap(&kal[key], &kal[n]); /// memanggil fungsi swap menggunakan pointer
//        temp=kal[key];
//        kal[key]=kal[n];
//        kal[n]=temp;
    }
    else
    {
        ///guna untuk membandingkan data
        jml1=kal[key].tang.tgl+(kal[key].tang.bln*31)+(kal[key].tang.thn*12*31); /// menjumlahkan semua data yang ada di variabel tgl bln thn ke - key
        jml2=kal[a].tang.tgl+(kal[a].tang.bln*31)+(kal[a].tang.thn*12*31);/// menjumlahkan data sebelum data ke - key
        //printf("indeks %d= %d dan indeks %d= %d \n",key,jml1,a,jml2);
        if(jml1<jml2)
        {
            key=a; /// untuk mengganti nilai mana data yang paling kecil

        }
        insort(kal,key,a-1,n);
    }
}

void swap(kalender *a, kalender *b)
{
    kalender temp;
    /// proses swapping
    temp=*a;
    *a=*b;
    *b=temp;

}

void searching(kalender kal[], int n, kalender cari,int flag)
{

    if(n==-1) /// BASIS
    {
        if(flag==0)
        {
            printf("Data tidak ditemukan!!!");
        }
    }
    else /// REKURENS
    {
        if((cari.tang.tgl==kal[n-1].tang.tgl) && (cari.tang.bln==kal[n-1].tang.bln )&& (cari.tang.thn==kal[n-1].tang.thn)) /// kondisi mencocokan nilai satu per satu
        {
            tampil(kal,n-1,n); /// apabila cocok maka akan memanggil fungsi tampil untuk menampilkan semua kegiatan yang disimpan
            flag=1; /// untuk memastikan bahwa data telah ditemukan sehingga tidak menampilkan kata kata data tidak ditemukan
        }
        searching(kal,n-1,cari,flag);
    }
}
