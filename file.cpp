#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
using namespace std;

int n;
//lets add file functionality to add , display and search and edit from the file
string name;
int age, id;
char sex;
float mark[3];
struct Student{
    string name;
    int age, id;
    char sex;
    float mark[3];
};

vector <Student> container;

void getFileData(){
    fstream file {"file.txt",ios::in};
    Student stud;
    while(file>>name>>age>>id>>sex>>mark[0]>>mark[1]>>mark[2]){
        stud.name = name;
        stud.age = age;
        stud.id = id;
        stud.sex = sex;
        for(int i = 0; i<3; ++i){
            stud.mark[i] = mark[i];
        }
        container.push_back(stud);
    }
    file.close();
}
void add(Student s[]){
    int id_check;
    fstream file {"file.txt",ios::app};
    for(int i = 0; i<n; ++i){
        cout<<"name for student "<< i+1<<" : ";
        cin>>s[i].name;
        file<<s[i].name<<" ";
        cout<<"age: ";
        cin>>s[i].age;
        file<<s[i].age<<" ";
        p:
        cout<<"Id (**Notice that id must be unique and you can't edit it**): ";
        cin>>id_check;
        for(Student stud : container){
            if(stud.id == id_check){
                cout<<"**id already taken! please enter new id**"<<endl;
                goto p;
            }
        }
        s[i].id = id_check;
        file<<s[i].id<<" ";
        cout<<"sex(m/f): ";
        cin>>s[i].sex;
        file<<s[i].sex<<" ";
        cout<<"enter three marks respectively: ";
        for(int j = 0; j<3; ++j){
            cin>>s[i].mark[j];
            file<<s[i].mark[j]<<" ";
        };
        file<<endl;
        container.push_back(s[i]);
    }; 
    file.close();
}
void display(){
    if(container.empty()){
        cout<<"**No records found!(empty file)**\n\n"<<endl;
        return;
    }else{
        cout<<"---------------------------------------------------------------------------------------------------------\n";
        cout<<"|id\t|\tname\t|\tage\t|\tsex\t|\tm1\t|\tm2\t|\tm3\t|\n";
        cout<<"---------------------------------------------------------------------------------------------------------\n";
        fstream file {"file.txt", ios::in};
        while(file>>name>>age>>id>>sex>>mark[0]>>mark[1]>>mark[2]){
            cout<<"|"<<id<<"\t|\t"<<name<<"\t|\t"<<age<<"\t|\t"<<sex<<"\t|\t";
            for(int j=0; j<3; ++j){
                cout<<mark[j]<<"\t|\t";
            }
            cout<<endl;
        }
        file.close();
        cout<<"---------------------------------------------------------------------------------------------------------\n";
    }
}
    
int main(){
    getFileData();
    int choice,id,choice2;
    n:  
    Student s[n];
    goto p;
    m:
    cout<<"\nwhat do you want?\n1. ADD\n2. DISPLAY THE GIVEN DATA\n3. Search\n4. Edit\n5. Clear the data in the file\n6.exit"<<endl;
    cout<<"enter your choice(1/2/3/4/5): ";
    cin>>choice;
    if(choice == 1){
        cout<<"\n\n";
        cout<<"how many students: ";
        cin>>n;
        goto n;
        p:
        add(s);
        goto m;
    }else if(choice == 2){
        cout<<"\n\n";
        display();
        goto m;
    }else if(choice == 3){
        int id3;
        cout<<"\n\n";
        cout<<"enter the id to search: ";
        cin>>id3;
        cout<<"\nSearchig.......\n\n";
        int found{};
        fstream file {"file.txt", ios::in};
        while(file>>name>>age>>id>>sex>>mark[0]>>mark[1]>>mark[2]){
            if(id == id3){
                cout<<"id found!\n\n"<<endl;
                found++;
                cout<<"---------------------------------------------------------------------------------------------------------\n";
                cout<<"|id\t|\tname\t|\tage\t|\tsex\t|\tm1\t|\tm2\t|\tm3\t|\n";
                cout<<"---------------------------------------------------------------------------------------------------------\n";
                cout<<"|"<<id<<"\t|\t"<<name<<"\t|\t"<<age<<"\t|\t"<<sex<<"\t|\t"<<mark[0]<<"\t|\t"<<mark[1]<<"\t|\t"<<mark[2]<<"\t|\n";
                cout<<"---------------------------------------------------------------------------------------------------------\n";
                file.close();
            }
        }
        if(found == 0){
            cout<<"**id not found!**"<<endl;
        }
        file.close();
        goto m;
    }else if(choice == 4){
        int id4;
        cout<<"\n\n";
        cout<<"enter the id of the student to edit: ";
        cin>>id4;
        int found{};
        for(Student &stud : container){
            if(stud.id == id4){
                found++;
                cout<<"\n\n** id found! **\n\n"<<endl;
                cout<<"** The student data with the given id is ... **\n\n";
                fstream file {"file.txt", ios::in};
                while(file>>name>>age>>id>>sex>>mark[0]>>mark[1]>>mark[2]){
                    if(id == id4){
                        cout<<"---------------------------------------------------------------------------------------------------------\n";
                        cout<<"|id\t|\tname\t|\tage\t|\tsex\t|\tm1\t|\tm2\t|\tm3\t|\n";
                        cout<<"---------------------------------------------------------------------------------------------------------\n";
                        cout<<"|"<<id<<"\t|\t"<<name<<"\t|\t"<<age<<"\t|\t"<<sex<<"\t|\t"<<mark[0]<<"\t|\t"<<mark[1]<<"\t|\t"<<mark[2]<<"\t|\n";
                        cout<<"---------------------------------------------------------------------------------------------------------\n";
                    }
                }
                file.close();
                file.open("file.txt",ios::out);
                r:
                cout<<"\n\nwhat do you want to edit?\n1. name\n2. age\n3. sex\n4. m1\n5. m2\n6. m3\n7.Back"<<endl;
                cout<<"enter your choice(1/2/3/4/5/6/7): ";
                cin>>choice2;
                switch (choice2){
                case 1:
                    cout<<"enter name: ";
                    cin>>stud.name;
                    cout<<"\nname updated successfully!"<<endl;
                    goto r;
                case 2:
                    cout<<"age: ";
                    cin>>stud.age;
                    cout<<"\nage updated successfully!"<<endl;
                    goto r;
                case 3:
                    cout<<"sex(m/f): ";
                    cin>>stud.sex;
                    cout<<"\nsex updated successfully!"<<endl;
                    goto r;
                case 4:
                    cout<<"enter mark 1: ";
                    cin>>stud.mark[0];
                    cout<<"\nmark 1 updated successfully!"<<endl;
                    goto r;
                case 5:
                    cout<<"enter mark 2: ";
                    cin>>stud.mark[1];
                    cout<<"\nmark 2 updated successfully!"<<endl;
                    goto r;
                case 6:
                    cout<<"enter mark 3: ";
                    cin>>stud.mark[2];
                    cout<<"\nmark 3 updated successfully!"<<endl;
                    goto r;
                case 7:
                    for(Student stud: container){
                        file<<stud.name<<" "<<stud.age<<" "<<stud.id<<" "<<stud.sex<<" "<<stud.mark[0]<<" "<<stud.mark[1]<<" "<<stud.mark[2]<<endl;
                    }
                    file.close();
                    cout<<"\n** editing finished **\n"<<endl;
                    break;
                default:
                    cout<<"\n** choose only from the given options **";
                    goto r;
                }
            }
        }
        
        if (found == 0){
            cout<<"\n\n**id not found!**"<<endl;
        }
        goto m;
    }else if(choice == 5){
        if(container.empty()){
            cout<<"**\n\nalready the file is empty**\n\n"<<endl;
            goto m; 
        }else{
        fstream file {"file.txt", ios::out};
        file.close();
        container.clear();
        cout<<"\n** file data cleared successfully **"<<endl;
        goto m;
        }
        
          
    }else if(choice == 6){
        cout<<"\n\n**Good bye!**\n\n";
        return 0;
    }else{
        cout<<"choose from the given options"<<endl;
        goto m;
    }
    return 0;
}
