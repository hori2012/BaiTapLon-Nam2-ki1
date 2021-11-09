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
float Profile::getGpa(){
	return this->gpa;
}
string Profile::getName(){
	return this->fullname;
}

//thêm code ở trên dòng này

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
int main(){
	
}
