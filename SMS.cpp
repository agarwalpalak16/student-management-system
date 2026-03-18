#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
using namespace std;
class student{
    private:
    int rollno, age;
    string name;
    public:
    student(int stdrollno , string stdname , int stdage  ){
        rollno=stdrollno;
        name=stdname;
        age=stdage;
    }

    void setrollno(int stdrollno){
    rollno=stdrollno;}
    int getrollno(){
    return rollno;}

    void setname(string stdname){
    name=stdname;}
    string getname(){
    return name;}

    void setage(int stdage){
    age=stdage;}
    int getage (){
    return age;}

    void displayStudent(){
        cout<<"rollno:"<<rollno<<endl;
        cout<<"name:"<<name<<endl;
        cout<<"age:"<<age<<endl;
    }
};

//create function to add new student 
void addNewStudent(vector<student> &students ){
    int rollno,age;
    string name;
    cout<<"enter rollno:";
    cin>>rollno;
    //check if student already exists
    for(int i=0;i<students.size();i++){
        if(students[i].getrollno()==rollno){
            cout<<"student already exits...."<<endl;
            return;
        }
    }
    cout<<"enter name:";
    cin>>name;
    cout<<"enter age:";
    cin>>age;

    student newStudent(rollno , name , age);
    students.push_back(newStudent);
    cout<<"student add succcessfully..."<<endl;



}
//create function to display students
void displayAllStudent(vector<student> &students){
    if(students.empty()){
        cout<<"No student found"<<endl;
        return;
    }
    for(int i=0;i<students.size();i++){
        students[i].displayStudent();
        cout<<endl;
    }



}
//create funtion for search the students
void searchStudent(vector<student> &students){
    int rollno;
    cout<<"enter a rollno:";
    cin>>rollno;

    for(int i=0;i<students.size();i++){
        if(students[i].getrollno()==rollno){
            cout<<"\t\t------ student Found------ "<<endl;
            students[i].displayStudent();
            return;
        }
        else{
            cout<<"student not found"<<endl;
        }

    }


}
//create funtion for update student
void updateStudent(vector<student> &students){
    string sname;
    bool found=false;
    int choice;

    cout<<"enter name to update record : ";
    cin.ignore();
    getline(cin,sname);

    for(int i=0;i<students.size();i++){
        if(students[i].getname()==sname){
            found=true;
            cout<<"\t\t---student found----"<<endl;
            cout<<"\t\t 1.update rollno"<<endl;
            cout<<"\t\t 2.update name"<<endl;
            cout<<"\t\t 3.updare age"<<endl;
            cout<<"enter your choice"<<endl;
            cin>>choice;

            switch(choice){
                case 1:{
                  int rno;
                  cout<<"enter new rollno:"<<endl;
                  cin>>rno;
                  students[i].setrollno(rno);
                  break;}

                  case 2:{
                  string name;
                  cout<<"enter new name:"<<endl;
                  cin.ignore();
                  getline(cin , name);
                  students[i].setname(name);
                  break;}

                  case 3:{
                  int newage;
                  cout<<"enter new age:"<<endl;
                  cin>>newage;
                  students[i].setage(newage);
                  break;}

                  default:
                  cout<<"invalid number"<<endl;
             } 
        }
        if(!found){
            cout<<"record not found here"<<endl;
            return;

        }
        
    }


}
//create funtion to delete the student in list
void deleteStudent(vector<student> &students){
    string name;
    cout<<"enter name to delete:";
    cin.ignore();
    getline(cin,name);

    for(int i=0;i<students.size();i++){
        if(students[i].getname()==name){
            students.erase(students.begin()+i);
            cout<<"student remove successfully"<<endl;
        }

    }



}

main(){
    vector<student> students;
    students.push_back(student(1 , "palak" , 20));
    char choice;
    do{

        system("cls");

    int op;
    cout<<"\t\t--------------------------"<<endl;
    cout<<"\t\tSTUDENT MANAGEMENT SYSTEM"<<endl;
    cout<<"\t\t--------------------------"<<endl;
    cout<<"\t\t1. add student"<<endl;
    cout<<"\t\t2. display all student"<<endl;
    cout<<"\t\t3.search student "<<endl;
    cout<<"\t\t4. update student"<<endl;
    cout<< "\t\t5. delete student"<<endl;
    cout<<"\t\t6. exit"<<endl;
    cout<<"\t\tenter your choice:";
    cin>>op;
    switch(op){
        case 1:
          addNewStudent(students);
          break;
        case 2:
          displayAllStudent(students); 
          break;
        case 3:
          searchStudent(students);
          break;
        case 4:
          updateStudent(students);
          break;
        case 5:
          deleteStudent(students);
          break;        
        case 6:
          exit(1);
        default:
          cout<<"invalid number..."<<endl;  


    }
    cout<<"\t\tDo you want to continue[y/n]?: ";
    cin>>choice;

   }
   while(choice=='y'||choice=='Y');
   
}
    
