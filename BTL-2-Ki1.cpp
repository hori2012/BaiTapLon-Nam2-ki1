#include<iostream>
#include<string>
#include<cmath>
#include<fstream>
using namespace std;

class Profile{
	private:
		string  fullname, mssv, province, Class;
		float gpa;
	public:
		friend istream& operator >> (istream& is, Profile &pf1);
		friend ostream& operator << (ostream& os, Profile &pf1);
		float getGpa(); 		//lay diem trung binh
		string getName();		//lay ten sinh vien
		void set_Gpa() ;		//dat lai diem trung binh
};

istream& operator >> (istream& is, Profile &pf1){    //nhap thong tin sinh vien
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
ostream& operator << (ostream& os, Profile &pf1){		//xuat thong tin sinh vien
	os<<"MSSV: "<<pf1.mssv<<endl;
	os<<"Ho va ten: "<<pf1.fullname<<endl;
	os<<"Lop: "<<pf1.Class<<endl;
	os<<"Que: "<<pf1.province<<endl;
	os<<"Diem trung binh: "<<pf1.gpa<<endl;
	return os;
}
float Profile::getGpa(){
	return this->gpa;
}
string Profile::getName(){
	return this->fullname;
}
void Profile::set_Gpa(){
	float temp;
	cout<<"Nhap diem trung binh thay the: ";
	cin>>temp;
	cout<<endl;
	this->gpa=temp;
}
//thêm code ở trên dòng này
class Practise:public Profile {
	private:
		int lesson, allow, n_allow;
		float practise;
		int s_lesson;
	public:
		friend istream& operator >> (istream& is , Practise &pt1);
		friend ostream& operator << (ostream& os, Practise &pt1);
		float point();				//tinh diem ren luyen
		void setPractise(float x);	//dat laij diem ren luyen
		float getPractise();		//lay diem ren luyen
		int get_n_Allow();			//lay so buoi nghi khong phep
		int get_Allow();			//lay so buoi nghi co phep
		void set_s_lesson();		//sua tong so buoi hoc (1 ki)
		void set_All();				//sua lai tat ca thong tin
};
int Practise::getallow(){
	return this->allow; 
} 
int Practise::getn_allow(){
	return this->n_allow; 
} 

istream& operator >> (istream& is, Practise &pt1){ //ham nhap 
	cout<<"Nhap tong so buoi hoc (1 ki): ";
	is>>pt1.s_lesson;
	cout<<endl;
	cout<<"Nhap so buoi da hoc: ";
	is>>pt1.lesson;
	cout<<endl;
	cout<<"Nhap so buoi nghi co phep: ";
	is>>pt1.allow;
	cout<<endl;
	cout<<"Nhap so buoi nghi khong phep: ";
	is>>pt1.n_allow;
	cout<<endl;
	return is;
}
ostream& operator << (ostream& os, Practise &pt1){
	os<<"Tong so buoi (1 ky): "<<pt1.s_lesson<<endl;
	os<<"So buoi hoc: "<<pt1.lesson<<endl;
	os<<"Nghi co phep: "<<pt1.allow<<endl;
	os<<"Nghi khong phep: "<<pt1.n_allow<<endl;
	os<<"Diem ren luyen: "<<pt1.getPractise()<<endl;
	return os;
}
float Practise::point(){
	int cur;   
	int pre;
	float temp;
	cur= allow + n_allow;
	if(cur > (float)(s_lesson * 0.15)){   //so buoi duoc nghi khong qua 15% tong so buoi hoc
		temp=0;							
	}
	else{
		pre=lesson*5 + allow*3 - n_allow*3;  //moi buoi hoc duoc 5d , co phep duoc 3d, khong phep -3d
		temp=(float)(pre*1.0/s_lesson);   //diem ren luyen = tong diem dat duoc / tong so buoi hoc
	}
	return temp;
} 

struct Node{
	Student data;
	Node *next;
};

class Student_Management{
	private:
		long size;
		Node *head;
		Node *tail;
	public:
		Student_Management();
		Student_Management(long size, Node *head, Node *tail);
		Student_Management(const Student_Management &slist);
		~Student_Management();
		Node* createNode(Student st);
		void addLast(Student st);
		Node* previous(Node *p);
		void removeFirst();
		void removeLast();
		void remove(Node *p);
		void traverse();
		void list_student(int &n);
		void list_sholarship();
		void searchName();
		void Delete();
		void add_student();
		void fix_infor();
			
};

Student_Management::Student_Management(){
	head=NULL;
	tail=NULL;
	size=0;
}
Student_Management::Student_Management(long size, Node* head, Node* tail){
	this->size=size;
	this->head=head;
	this->tail=tail;
}
Student_Management::Student_Management(const Student_Management &slist){
	this->size=slist.size;
	this->head=slist.head;
	this->tail=slist.tail;
}
Student_Management::~Student_Management(){
	delete head;
	delete tail;
	size=0;
}
Node* Student_Management::previous(Node *p) {
	Node *t = head;
	while (t->next != p)
		t = t->next;
	return t;
}
void Student_Management::traverse(){
	Node *p=head;
	fstream File;
	File.open("List_student.txt", ios::out);
	File<<"=====DANH SACH THONG TIN SINH VIEN======"<<endl;
	while(p!=NULL){
		cout<<p->data;
		File<<p->data;
		p=p->next;
	}
	File.close();
	delete p;
}
void Student_Management::list_sholarship(){
	fstream File;
	File.open("list_scholarship.txt", ios::out);
	File<<"======DANH SACH HOC BONG====== "<<endl;
	cout<<"======DANH SACH HOC BONG====== "<<endl;
	Node *p=head;
	while(p!=NULL){
		if(p->data.check()){
			cout<<p->data;
			File<<p->data;
		}
		else
			cout<<"Don't student confirm scholarship !!"<<endl;
		p=p->next;
	}
	File.close();
	delete p;
}
// hoàn thành các hàm cua class Student_Management ở đây
int main(){
	
	return 0;
}
