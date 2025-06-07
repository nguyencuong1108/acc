#include<iostream>
#include<fstream>

using namespace std;

// Khai bao cau truc nut cua danh sach lien ket don
struct Nut
{
    int so;         // So nguyen chua trong nut
    Nut *tiep;      // Con tro den nut tiep theo
};

// Khai bao lop doi tuong DanhSach
class DanhSach
{
    private:
        Nut *dau;   // Con tro den nut dau danh sach

    public:
        DanhSach();         // Khoi tao danh sach
        ~DanhSach();        // Huy danh sach
        void them(int x);   // Them mot so vao cuoi danh sach
        void hien();        // Hien thi cac so trong danh sach
        int tim(int x);     // Tim phan tu co gia tri x
        void xoa(int x);    // Xoa mot phan tu co gia tri x
};

// Chuong trinh chinh
int main()
{
    // Tao doi tuong tep doc vao
    ifstream fin("daysonguyen-bai32.txt");

    // Khai bao bien
    int x;
    DanhSach ds; // Doi tuong danh sach lien ket don

    // Dua ra tieu de chuong trinh
    cout<<"Chuong trinh doc day so nguyen tu tep, tim va xoa phan tu\n";

    // Doc day so nguyen tu tep vao danh sach
    while(fin>>x)
    {
        ds.them(x); // Them so vao danh sach
    }

    // Dua ra danh sach so
    cout<<"Danh sach so doc tu tep: ";
    ds.hien();

    // Nhap gia tri x can tim va xoa
    cout<<"\nNhap gia tri x can tim va xoa: ";
    cin>>x;

    // Tim gia tri x
    if(ds.tim(x))
        cout<<"Tim thay gia tri "<<x<<" trong danh sach.\n";
    else
        cout<<"Khong tim thay gia tri "<<x<<" trong danh sach.\n";

    // Xoa mot phan tu co gia tri x
    ds.xoa(x);

    // Dua ra danh sach sau khi xoa
    cout<<"Danh sach sau khi xoa gia tri "<<x<<": ";
    ds.hien();

    cout<<endl;
    return 0;
}

// Dinh nghia ham
DanhSach::DanhSach()
{
    dau = NULL;
}

DanhSach::~DanhSach()
{
    Nut *p = dau;
    while(p != NULL)
    {
        Nut *tam = p;
        p = p->tiep;
        delete tam;
    }
}

void DanhSach::them(int x)
{
    Nut *p = new Nut;
    p->so = x;
    p->tiep = NULL;

    if(dau == NULL)
    {
        dau = p;
    }
    else
    {
        Nut *q = dau;
        while(q->tiep != NULL)
            q = q->tiep;
        q->tiep = p;
    }
}

void DanhSach::hien()
{
    Nut *p = dau;
    while(p != NULL)
    {
        cout<<p->so<<" ";
        p = p->tiep;
    }
}

int DanhSach::tim(int x)
{
    Nut *p = dau;
    while(p != NULL)
    {
        if(p->so == x)
            return 1; // Tim thay
        p = p->tiep;
    }
    return 0; // Khong tim thay
}

void DanhSach::xoa(int x)
{
    Nut *p = dau, *truoc = NULL;
    while(p != NULL && p->so != x)
    {
        truoc = p;
        p = p->tiep;
    }

    if(p != NULL) // Tim thay nut co gia tri x
    {
        if(truoc == NULL) // Xoa nut dau
            dau = p->tiep;
        else // Xoa nut o giua hoac cuoi
            truoc->tiep = p->tiep;
        delete p;
    }
}
