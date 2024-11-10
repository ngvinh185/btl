#include <iostream>
#include <string>
#include <list>
#include <algorithm>
using namespace std;


class SinhVien {
private:
    int maSV;
    string ten;
    int tuoi;
    float diem;

public:
    SinhVien(int maSV = 0, string ten = "", int tuoi = 0, float diem = 0.0) {
        this->maSV = maSV;
        this->ten = ten;
        this->tuoi = tuoi;
        this->diem = diem;
    }


    friend istream& operator>>(istream& in, SinhVien& sv) {
        cout << "Nhap ma sinh vien: ";
        in >> sv.maSV;
        in.ignore();
        cout << "Nhap ten sinh vien: ";
        getline(in, sv.ten);
        cout << "Nhap tuoi: ";
        in >> sv.tuoi;
        cout << "Nhap diem: ";
        in >> sv.diem;
        return in;
    }


    friend ostream& operator<<(ostream& out,  SinhVien& sv) {
        out << "Ma SV: " << sv.maSV << ", Ten: " << sv.ten << ", Tuoi: " << sv.tuoi << ", Diem: " << sv.diem;
        return out;
    }

    bool operator<( SinhVien& sv)  {
        return diem < sv.diem;
    }

    int getMaSV()  { return maSV; }
    float getDiem()  { return diem; }
};

class DanhSachSinhVien {
private:
    list<SinhVien> danhSach;

public:
    void nhapDanhSach(int n) {
        SinhVien sv;
        for (int i = 0; i < n; i++) {
            cout << "Nhap thong tin sinh vien thu " << i + 1 << ":\n";
            cin >> sv;
            danhSach.push_back(sv);
        }
    }

    void xuatDanhSach() {
        for ( SinhVien& sv : danhSach) {
            cout << sv << endl;
        }
    }

    void sapXepDanhSach() {
        danhSach.sort(); 
    }

    SinhVien timMax() {
        if (danhSach.empty()) {
        cout << "Danh sach rong!" << endl;
        return SinhVien();
      }
      
        auto ma = danhSach.begin();
        for (auto it = danhSach.begin(); it != danhSach.end(); ++it) {
            if (it->getDiem() > ma->getDiem()) {
                ma = it;
            }
        }
        return *ma;
    

    SinhVien timMin() {
        if (danhSach.empty()) {
        cout << "Danh sach rong!" << endl;
        return SinhVien();
    }
    
        auto mi = danhSach.begin();
        for (auto it = danhSach.begin(); it != danhSach.end(); ++it) {
            if (it->getDiem() < mi->getDiem()) {
                mi = it;
            }
        }
        return *m;
    }

    void themSinhVien( SinhVien& sv) {
        danhSach.push_back(sv);
    }

    void xoaSinhVien(int maSV) {
        danhSach.remove_if([maSV]( SinhVien& sv) {
            return sv.getMaSV() == maSV;
        });
    }

    void timKiemSinhVien(int maSV) {
        for ( SinhVien& sv : danhSach) {
            if (sv.getMaSV() == maSV) {
                cout << "Sinh vien tim duoc: " << sv << endl;
                return;
            }
        }
        cout << "Sinh vien khong ton tai!" << endl;
    }
};

class App {
private:
    DanhSachSinhVien dssv;

public:
    void hienThiMenu() {
    int c;
    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Nhap danh sach sinh vien\n";
        cout << "2. Xuat danh sach sinh vien\n";
        cout << "3. Sap xep danh sach\n";
        cout << "4. Tim sinh vien co diem cao nhat\n";
        cout << "5. Tim sinh vien co diem thap nhat\n";
        cout << "6. Them sinh vien\n";
        cout << "7. Xoa sinh vien\n";
        cout << "8. Tim kiem sinh vien\n";
        cout << "9. Thoat\n";
        cout << "Chon thao tac: ";
        cin >> c;

        if (c == 1) {
            int n;
            cout << "Nhap so luong sinh vien: ";
            cin >> n;
            dssv.nhapDanhSach(n);
        }
        else if (c == 2) {
            dssv.xuatDanhSach();
        }
        else if (c == 3) {
            dssv.sapXepDanhSach();
        }
        else if (c == 4) {
            cout << "Sinh vien diem cao nhat: " << dssv.timMax() << endl;
        }
        else if (c == 5) {
            cout << "Sinh vien diem thap nhat: " << dssv.timMin() << endl;
        }
        else if (c == 6) {
            SinhVien sv;
            cin >> sv;
            dssv.themSinhVien(sv);
        }
        else if (c == 7) {
            int maSV;
            cout << "Nhap ma sinh vien can xoa: ";
            cin >> maSV;
            dssv.xoaSinhVien(maSV);
        }
        else if (c == 8) {
            int maSV;
            cout << "Nhap ma sinh vien can tim: ";
            cin >> maSV;
            dssv.timKiemSinhVien(maSV);
        }
        else if (c == 9) {
            cout << "Thoat chuong trinh!" << endl;
        }
        else {
            cout << "Lua chon khong hop le!" << endl;
        }
    } while (c != 9);
}

    
};

int main() {
    App app;
    app.hienThiMenu();
    return 0;
}
