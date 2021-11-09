#include<iostream>
#include<string>
using namespace std;

class Profile{
	private:
		string  fullname, mssv, province, Class;
		float gpa;
	public:
		friend istream& operator >> (istream& is, Profile &pf1);
		friend ostream& operator << (ostream& os, Profile &pf1);
		float getGpa();
		string getName();
		void set_Gpa() ;
};

istream& operator >> (istream& is, Profile &pf1){
	cout<<"Nhap ho ten sinh vien: ";
	fflush(stdin);
	getline(is, pf1.fullname);
	cout<<endl;
	cout<<"Nhap ma so sinh vien: ";
	fflush(stdin);
	getline(is, pf1.mssv);
	cout<<endl;
	cout<<"Nhap lop: ";
	fflush(stdin);
	getline(is, pf1.Class);
	cout<<endl;
	cout<<"Nhap que cua sinh vien: ";
	fflush(stdin);
	getline(is, pf1.province);
	cout<<endl;
	cout<<"Nhap diem trung binh: ";
	is>>pf1.gpa;
	cout<<endl;
	return is;
}
ostream& operator << (ostream& os, Profile &pf1){
	os<<"Ho va ten: "<<pf1.fullname<<endl;
	os<<"MSSV: "<<pf1.mssv<<endl;
	os<<"Lop: "<<pf1.Class<<endl;
	os<<"Que: "<<pf1.province<<endl;
	os<<"Diem trung binh: "<<pf1.gpa<<endl;
	return os;
}
int main(){
	
	
