#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int tgl;
    int bln;
    int thn;
}tanggal; /// typedef untuk menampung tanggal

typedef struct
{
    int jam;
    int menit;
}waktu; /// typedef untuk menampung waktu

typedef struct
{
    tanggal tang;
    waktu wkt;
    char kegiatan[200];
    char nama[100];
}kalender; /// typedef untuk membungkus data yang diperlukan pada kalender

void open(); /// untuk menampilkan UI pembukaan aplikasi
void menu(); /// untuk menampilkan menu utama
void tambah(kalender kal[],int n); /// fungsi untuk menambahkan data
void tampil(kalender kal[],int cur,int n); /// fungsi untuk menampilkan data
void searching(kalender kal[], int n, kalender cari,int flag); /// fungsi untuk mencari data
void sorting(kalender kal[],int n); /// fungsi untuk mengurutkan data
void insort(kalender kal[],int key,int a,int n); /// berfungsi untuk mengidentifikasi data yang lebih kecil
void swap(kalender *a, kalender *b); /// berfungsi untuk menukar data
void hapus(kalender kal[],int n, int ires); /// berfungsi untuk menghapus data
#endif // HEADER_H_INCLUDED
