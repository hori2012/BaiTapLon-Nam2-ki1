class Practise:public Profile {
	private:
		int lesson, allow, n_allow;
		float practise;
		int s_lesson;
	public:
		friend istream& operator >> (istream& is , Practise &pt1);
		friend ostream& operator << (ostream& os, Practise &pt1);
		float point();
		void setPractise(float x);
		float getPractise();
		int getallow();
		int getn_allow(); 		 
};
int Practise::getallow(){
	return this->allow; 
} 
int Practise::getn_allow(){
	return this->n_allow; 
} 

istream& operator >> (istream& is, Practise &pt1){ //ham nhap 
	cout<<"Enter of the sum lesson: ";
	is>>pt1.s_lesson;
	cout<<endl;
	cout<<"Enter of the lesson: ";
	is>>pt1.lesson;
	cout<<endl;
	cout<<"Enter of the allow: ";
	is>>pt1.allow;
	cout<<endl;
	cout<<"Enter of the not allow: ";
	is>>pt1.n_allow;
	cout<<endl;
	return is;
}
