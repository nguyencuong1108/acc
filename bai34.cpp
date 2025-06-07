#include<iostream>
#include<fstream>

using namespace std;

// Khai bao cau truc nut cua danh sach lien ket kep
struct Nut
{
    int so;         // So nguyen chua trong nut
    Nut *truoc;     // Con tro den nut truoc
    Nut *tiep;      // Con tro den nut tiep theo
};

// Khai bao lop doi tuong DanhSach
class DanhSach
{
    private:
        Nut *dau;   // Con tro den nut dau danh sach
        Nut *cuoi;  // Con tro den nut cuoi danh sach
        int n;      // So luong phan tu trong danh sach

    public:
        DanhSach();         // Khoi tao danh sach
        ~DanhSach();        // Huy danh sach
        void thietLap(int x); // Them mot so vao cuoi danh sach
        void hienTrai();     // Hien thi danh sach tu trai sang phai
        void hienPhai();     // Hien thi danh sach tu phai sang trai
        int laySoPhanTu();   // Lay so luong phan tu trong danh sach
        void chenDau(int x); // Chen mot so vao dau danh sach
        void xoa(int x);     // Xoa mot nut co gia tri x
        int tim(int x);      // Tim nut co gia tri x
};

// Chuong trinh chinh
int main()
{
    // Tao doi tuong tep doc vao
    ifstream fin("daysonguyen-bai34.txt");

    // Khai bao bien
    int x;
    DanhSach ds; // Doi tuong danh sach lien ket kep

    // Dua ra tieu de chuong trinh
    cout<<"Chương trình đọc dãy số nguyên từ tệp, thao tác với danh sách liên kết kép\n";

    // Doc day so nguyen tu tep vao danh sach
    while(fin>>x)
    {
        ds.thietLap(x); // Them so vao danh sach
    }

    // Dua ra danh sach theo hai chieu
    cout<<"Danh sách số đọc từ tệp (từ trái sang phải): ";
    ds.hienTrai();
    cout<<"\nDanh sách số đọc từ tệp (từ phải sang trái): ";
    ds.hienPhai();

    // Dua ra so luong phan tu
    cout<<"\nSố lượng phần tử trong danh sách: "<<ds.laySoPhanTu();

    // Nhap gia tri x de chen, tim va xoa
    cout<<"\nNhập giá trị x để chèn, tìm và xóa: ";
    cin>>x;

    // Chen x vao dau danh sach
    ds.chenDau(x);
    cout<<"Danh sách sau khi chèn "<<x<<" vào đầu (từ trái sang phải): ";
    ds.hienTrai();

    // Tim gia tri x
    if(ds.tim(x))
        cout<<"\nTìm thấy giá trị "<<x<<" trong danh sách.\n";
    else
        cout<<"\nKhông tìm thấy giá trị "<<x<<" trong danh sách.\n";

    // Xoa mot nut co gia tri x
    ds.xoa(x);
    cout<<"Danh sách sau khi xóa giá trị "<<x<<" (từ trái sang phải): ";
    ds.hienTrai();

    cout<<endl;
    return 0;
}

// Dinh nghia ham
DanhSach::DanhSach()
{
    dau = NULL;
    cuoi = NULL;
    n = 0;
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

void DanhSach::thietLap(int x)
{
    Nut *p = new Nut;
    p->so = x;
    p->tiep = NULL;
    p->truoc = cuoi;

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
    n++;
}

void DanhSach::hienTrai()
{
    Nut *p = dau;
    while(p != NULL)
    {
        cout<<p->so<<" ";
        p = p->tiep;
    }
}

void DanhSach::hienPhai()
{
    Nut *p = cuoi;
    while(p != NULL)
    {
        cout<<p->so<<" ";
        p = p->truoc;
    }
}

int DanhSach::laySoPhanTu()
{
    return n;
}

void DanhSach::chenDau(int x)
{
    Nut *p = new Nut;
    p->so = x;
    p->truoc = NULL;
    p->tiep = dau;

    if(dau == NULL)
    {
        dau = p;
        cuoi = p;
    }
    else
    {
        dau->truoc = p;
        dau = p;
    }
    n++;
}

void DanhSach::xoa(int x)
{
    Nut *p = dau;
    while(p != NULL && p->so != x)
        p = p->tiep;

    if(p != NULL) // Tim thay nut co gia tri x
    {
        if(p == dau) // Xoa nut dau
        {
            dau = p->tiep;
            if(dau != NULL)
                dau->truoc = NULL;
            else
                cuoi = NULL;
        }
        else if(p == cuoi) // Xoa nut cuoi
        {
            cuoi = p->truoc;
            cuoi->tiep = NULL;
        }
        else // Xoa nut o giua
        {
            p->truoc->tiep = p->tiep;
            p->tiep->truoc = p->truoc;
        }
        delete p;
        n--;
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
