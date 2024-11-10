#include <bits/stdc++.h>
using namespace std;
int loai;
struct MatHang {
    int id, sl;
    string ten, nsx;
};

struct HoaDon {
    int idd, idh, sl, mua, ban;
    string type, ngayMua, ngayBan;
};

class CuaHang {
private:
    vector<MatHang> danhSachMatHang;
    vector<HoaDon> danhSachHoaDon;
public:
    void nhap() {
        int id, idh, sl;
        string ten, nsx, type, ngayMua, ngayBan;
        
        if(loai == 1)
        {
        	cin>>id;
            cin.ignore();
            getline(cin, ten);
            getline(cin, nsx);

            MatHang mh;
            mh.id = id;
            mh.ten = ten;
            mh.nsx = nsx;
            danhSachMatHang.push_back(mh);

		}
        
        else
		{
			cin >> id >> idh >> sl;
            cin.ignore();
            getline(cin, type);
            if(type == "Mua") getline(cin, ngayMua);
            else getline(cin, ngayBan);

            HoaDon hd;
            hd.idd = id;
            hd.idh = idh;
            hd.sl = sl;
            hd.type = type;
            hd.ngayMua = ngayMua;
            hd.ngayBan = ngayBan;
            danhSachHoaDon.push_back(hd);

            for (auto& mh : danhSachMatHang) 
			{
                if (mh.id == hd.idh) {
                    if (hd.type == "Ban") mh.sl -= hd.sl;
                    else mh.sl += hd.sl;
                    break;
                }
        	}
		}
    }
    void hienThiDanhSachMatHang() {
        cout << "**Danh sach mat hang hien co**:\n";
        int ok = 1;
        cout << "------------------------------\n";    
        for (auto& mh : danhSachMatHang) {
            if(mh.sl > 0) ok = 0, cout << "ID: " << mh.id << "\nTen: " << mh.ten <<"\nSo luong: " << mh.sl << "\nNSX: " << mh.nsx << endl << endl;
        }
        if(ok) cout<<"Khong con mat hang nao!\n";
        cout<< "-------------------------------\n";
        cout<< "-------------------------------\n";
    }

    void thongKeSoLuongTon() {
        cout << "\n**Thong ke so luong ton cua moi mat hang**:\n";
        cout<< "-------------------------------\n";
        for (auto& mh : danhSachMatHang) {
            cout << "Mat hang: " << mh.ten << "\nSo luong ton: " << mh.sl << endl;
        }
        cout<< "-------------------------------\n";
        cout<< "-------------------------------\n";
    }
    
    void xuat()
    {
    	cout<<"\n**Tat ca thong tin cac mat hang:**\n";
    	cout<< "-------------------------------\n";
    	cout<<"--Danh sach mat hang:--\n";
    	for (auto& mh : danhSachMatHang) {
            cout << "ID: " << mh.id << "\nTen: " << mh.ten << "\nNSX: " << mh.nsx << endl;
        }
        cout<< "-------------------------------\n";
        cout<< "-------------------------------\n";
        cout<<endl;
	}
};

int main() {
	freopen("code.inp", "r", stdin);
	freopen("code.out", "w", stdout);
    CuaHang a;
    
    while(cin>>loai)
    {
    	a.nhap();
	}
    a.xuat();
    a.hienThiDanhSachMatHang();  
    a.thongKeSoLuongTon();
    
    return 0;
}

