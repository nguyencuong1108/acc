#include<iostream>
#include<fstream>

using namespace std;

// Khai bao cau truc nut cua hang doi
struct Nut
{
    int so;         // So nguyen chua trong nut
    Nut *tiep;      // Con tro den nut tiep theo
};

// Khai bao lop doi tuong HangDoi
class HangDoi
{
    private:
        Nut *dau;   // Con tro den nut dau hang doi
        Nut *cuoi;  // Con tro den nut cuoi hang doi

    public:
        HangDoi();         // Khoi tao hang doi
        ~HangDoi();        // Huy hang doi
        void them(int x);   // Them mot so vao cuoi hang doi
        void hien();        // Hien thi cac so trong hang doi
};

// Chuong trinh chinh
int main()
{
    // Tao doi tuong tep doc vao
    ifstream fin("daysonguyen-bai30.txt");

    // Khai bao bien
    int x;
    HangDoi soDuong, soAm; // Hai hang doi cho so duong va so am

    // Dua ra tieu de chuong trinh
    cout<<"Chương trình tách dãy số nguyên từ tệp thành dãy số dương và số âm\n";

    // Doc day so nguyen tu tep vao hai hang doi
    while(fin>>x)
    {
        if(x>=0)
            soDuong.them(x); // Them so duong vao hang doi soDuong
        else
            soAm.them(x);    // Them so am vao hang doi soAm
    }

    // Dua ra danh sach so duong va so am
    cout<<"Danh sách số dương: ";
    soDuong.hien();
    cout<<"\nDanh sách số âm: ";
    soAm.hien();

    cout<<endl;
    return 0;
}

// Dinh nghia ham
HangDoi::HangDoi()
{
    dau = NULL;
    cuoi = NULL;
}

HangDoi::~HangDoi()
{
    Nut *p = dau;
    while(p != NULL)
    {
        Nut *tam = p;
        p = p->tiep;
        delete tam;
    }
}

void HangDoi::them(int x)
{
    Nut *p = new Nut;
    p->so = x;
    p->tiep = NULL;

    if(dau == NULL)
    {
        dau = p;
        cuoi = p;
    }
    else
    {
        cuoi->tiep = p;
        cuoi = p;
    }
}

void HangDoi::hien()
{
    Nut *p = dau;
    while(p != NULL)
    {
        cout<<p->so<<" ";
        p = p->tiep;
    }
}
