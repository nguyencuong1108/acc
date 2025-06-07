#include<iostream>
#include<fstream>

using namespace std;

// Khai bao lop doi tuong DaySo
class DaySo
{
    private:
        int *a;        // Mang dong chua cac so
        int n;         // So luong phan tu trong mang
        int maxSize;   // Kich thuoc toi da cua mang

    public:
        DaySo();         // Khoi tao mang
        ~DaySo();        // Huy mang
        void them(int x); // Them mot so vao mang
        void hien();      // Hien thi cac so trong mang
};

// Chuong trinh chinh
int main()
{
    // Tao doi tuong tep doc vao
    ifstream fin("daysonguyen-bai30.txt");

    // Khai bao bien
    int x;
    DaySo soDuong, soAm; // Hai doi tuong cho so duong va so am

    // Dua ra tieu de chuong trinh
    cout<<"Chương trình tách dãy số nguyên từ tệp thành dãy số dương và số âm\n";

    // Doc day so nguyen tu tep vao hai mang
    while(fin>>x)
    {
        if(x>=0)
            soDuong.them(x); // Them so duong vao mang soDuong
        else
            soAm.them(x);    // Them so am vao mang soAm
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
DaySo::DaySo()
{
    maxSize = 1000; // Kich thuoc mac dinh
    a = new int[maxSize];
    n = 0;
}

DaySo::~DaySo()
{
    delete[] a;
}

void DaySo::them(int x)
{
    if(n < maxSize)
    {
        a[n] = x;
        n++;
    }
}

void DaySo::hien()
{
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
}
