/*
Assignment 2
Name : Niraj Satish Karande
Roll no : 21335
Batch : F3 [SE-3]
Develop an object oriented program in C++ to create a database of student information
system containing the following information: Name, Roll number, Class, division, Date of
Birth, Blood group, Contact address, telephone number, driving license no. and other.
Construct the database with suitable member functions for initializing and destroying the
data viz constructor, default constructor, Copy constructor, destructor, static member
functions, friend class, this pointer, inline code and dynamic memory allocation
operators-new and delete.*/

#include<iostream>
using namespace std;
// class show;
class student{
    int roll_number=21200;
    string f_name,surname;
    string contact_no,division,DOB,blood_group,driving_no;
    string address[3];
    string question[3]={"Flat number ","society name ","city "};
    static int count;
    static string classes;

    public:
    static string college;
    inline static void class_display(){ //static function and inline
        cout<<classes;
    }

    // friend class show(); static member function,inline function
    student(){  //constuctor
        count++;
        cout << "Enter name and surname of student : " << endl;
        cin >>  f_name >> surname;
        cout << "Enter DOB : dd/mm/yyyy" << endl;
        cin >> DOB;
        // classes = "SE";
        division = 2;
        roll_number += count;    
        cout<<endl;
    }

    student(student &stu){
        f_name= stu.f_name;
        surname=stu.surname;
        division=stu.division;
        surname=stu.surname ; 
        contact_no=stu.contact_no;
        DOB=stu.DOB;
        driving_no=stu.driving_no;
        address[0]=stu.address[0];
        address[1]=stu.address[1];
        address[2]=stu.address[2];

    }

    ~student(){                            //destructor
        cout<<"students left "<<count<<endl;
        count--;
    }

    void getinfo();
    void display_data();
};


string student::classes="SE";              //static variable

void student ::getinfo(){
    cout<<"enter contact number "<<endl;
    cin >> contact_no;
           
    cout << "Driving liscence number " << endl;
    cin >> driving_no;     
    for(int i =0; i<3; i++ )
    {
    cout << question[i] << flush;
    cin >> address[i];
    }
}

int student::count=0;
string student::college ="pict";
void student::display_data(){
    cout<<"\n";
    cout << "******************************************************" << endl;
    cout <<"Roll number " << roll_number<< "'s details are as follows : " << endl;
    cout << "Name of the student = " << f_name << " " << surname << endl;
    cout<<"DOB of the student    = "<<DOB<< endl;
    cout<<"Class of student      = ";
    student::class_display();
    cout << endl;                         //display of inline function
    cout<<"Name of the college   = "<<college<<endl;
    cout<<"Name of rollnumber    = "<<roll_number<<endl;
    // cout<<"Blood group           = "<<blood_group<<endl;
    cout<<"Contact number        = "<<contact_no<<endl;
    cout<<"Adress                = ";
    for(int j = 0; j < 3; j++)
    {
    cout << address[j] << " ";
    }
    cout << endl;
    cout << "******************************************************" << endl;
}


int main(){
    cout<<"enter the number of students "<<endl;
    int n;cin>>n;
    student *stu = new student[n];
    for(int i=0;i<n;i++){
        
        cout<<"student "<< i+1<<" "<<endl;
        (*(stu+i)).getinfo();
        cout<<"\n";
    }
    
    int k;
    int p=1;

    while(p==1){
    cout<<"1)check data of 1 student\n2)check data of all\n3)copy data";
    cout<<"enter choice "<<endl;
    cin >> k ;
        if(k==1){
            cout<<"enyter number of student "<<endl;
            int j;cin>>j;
            (stu+j-1)->display_data();
        }
        else if(k==2){
            for(int i=0;i<n;i++){
                (stu+i)->display_data();
            }
        }
        else if(k==3){
            cout<<"copy deatils of "<<endl;
            int m;cin>>m;
            student s(*(stu+m-1));
            s.display_data();
        }
        cout<<"to cointinuer enter 1";
        cin>>p;
    };
    delete []stu;
return 0;
}