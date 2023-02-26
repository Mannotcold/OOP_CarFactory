#include <iostream>
#include <string>
#include<vector>
using namespace std;

class MauXe
{
private:
	string PhienBan;
	string MauSac;
	string PhanLoai;
public:
	MauXe()
	{
		PhienBan = "Fadil";
		MauSac = "Do";
		PhanLoai = "Tieu Chuan";
	}

	MauXe(string newPhienBan, string newMauSac, string newPhanLoai)
	{
		PhienBan = newPhienBan;
		MauSac = newMauSac;
		PhanLoai = newPhanLoai;
	}
	~MauXe() {};

	string GetPhienBan()
	{
		return PhienBan;
	}
	string GetMauSac()
	{
		return MauSac;
	}

	string GetPhanLoai()
	{
		return PhanLoai;
	}
	void SetPhienBan(string newPhienBan)
	{
		PhienBan = newPhienBan;
	 }
	void SetMauSac(string newMauSac)
	{
		MauSac = newMauSac;
	}

	void SetPhanLoai(string newPhanLoai)
	{
		PhanLoai=newPhanLoai;
	}

	friend istream& operator>>(istream& is, MauXe& ms)
	{
		
			cout << "Nhap phien ban xe(Fadil, LuxA, LuxSA): ";
			getline(is, ms.PhienBan);
			
			cout << "Nhap mau sac xe(Den, Trang, Cam, Xanh, Xam, do, Bac): ";
			getline(is, ms.MauSac);
			
			cout << "Nhap phan loai xe(Tieu chuan, nang cao, cao cap): ";
			getline(is, ms.PhanLoai);
		
		return is;
	}


	friend ostream& operator<<(ostream& os, const MauXe& ms)
	{
		os << "Phien Ban: " << ms.PhienBan << endl;
		os << "Mau Sac: " << ms.MauSac << endl;
		os << "Phan Loai: " << ms.PhanLoai << endl;
		return os;
	}

};


class XeThuongMai : MauXe
{
private:
	MauXe Mauxe;
	long long GiaBan;
	string BienSo;
public:
	XeThuongMai()
	{
		Mauxe;
		GiaBan = 1000000;
		BienSo = "95236";
	}

	XeThuongMai(MauXe newMauxe, long long newGiaBan)
	{
		Mauxe = newMauxe;
		GiaBan = newGiaBan;
	}

	XeThuongMai(string newPhienBan, string newMauSac, string newPhanLoai, long long newGiaBan,string newBienSo)
	{
		Mauxe.SetPhienBan(newPhienBan);
		Mauxe.SetMauSac(newMauSac);
		Mauxe.SetPhanLoai(newPhanLoai);
		GiaBan = newGiaBan;
		BienSo = newBienSo;
	}


	XeThuongMai(const XeThuongMai& n) {
		Mauxe = n.Mauxe;
		GiaBan = 1000000;
		BienSo = "95236";
	}

	~XeThuongMai() {};
	XeThuongMai operator=(XeThuongMai xtm) {

		if (xtm.Mauxe.GetPhienBan() == Mauxe.GetPhienBan() && xtm.Mauxe.GetMauSac() == Mauxe.GetMauSac()) {
			Mauxe.SetPhanLoai(xtm.Mauxe.GetPhanLoai());
			GiaBan = xtm.GiaBan;
		}
	}


	friend istream& operator>>(istream& is, XeThuongMai& xtm)
	{

		cout << "Nhap mau xe: \n";
		is >>xtm.Mauxe;
		cout << "Nhap gia ban: ";
		is >> xtm.GiaBan;
		cin.ignore();
		cout << "Nhap bien so: ";
		getline(is, xtm.BienSo);
		
		return is;
	}


	friend ostream& operator<<(ostream& os, const XeThuongMai& xtm)
	{
		os << xtm.Mauxe << endl;
		os << "Gia ban: " << xtm.GiaBan << endl;
		os << "Bien so: " << xtm.BienSo << endl;
		return os;
	}


};
class NhaMayOTo
{
private:
	vector<MauXe*> Mauxe;
public:
	NhaMayOTo()
	{
	}
	~NhaMayOTo() {
	}
	NhaMayOTo(const NhaMayOTo& nm)
	{
		
		for (int i = 0;i < nm.Mauxe.size();++i)
		{
			Mauxe.push_back(new MauXe(*nm.Mauxe[i]));
		}
	}

	vector <MauXe*> GetMauXeList()
	{
		return Mauxe;
	}

	void ListMauXe()
	{
		cout << "\nDanh sach skill da hoc:\n ";
		for (MauXe* sk : Mauxe)
		{
			cout << sk->GetPhienBan() << "\n";
			cout << sk->GetMauSac() << "\n";
			cout << sk->GetPhanLoai() << "\n";
		}
	}
};


int main()
{
	MauXe a;
	cin >> a;
	cout << a << endl;
	XeThuongMai xeA("LuxA", "Den", "TieuChuan", 950000000.00, "55A5-55555");
	
	cout << xeA;
}
