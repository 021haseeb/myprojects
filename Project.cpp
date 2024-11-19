#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>
#include<conio.h>
using namespace std;

struct node {
    string comment, task, importance;
    int time;
    node* next;
};

class Admin {
public:
    node* head;
    node* tail;
    int count;

    Admin() {
        head = NULL;
        tail = NULL;
        count = 0;
    }

    void insertion() {
        node* nn = new node;
        cout << "Enter time that you want to work on the task (0000-2400): \n";
        cin >> nn->time;

        if (nn->time < 0 || nn->time > 2400) {
            cout << "Time is out of range \n" << endl;
            delete nn;
            return;
        }

        cout << "Enter task:  \n";
        cin.ignore();
        getline(cin, nn->task);

        cout << "Enter any comment with this task:  \n";
        getline(cin, nn->comment);

        cout << "Enter importance for this task: \n ";
        getline(cin, nn->importance);

        nn->next = NULL;

        if (head == NULL) {
            head = nn;
            tail = nn;
        } else {
            if (nn->time < head->time) {
                nn->next = head;
                head = nn;
            } else if (nn->time > tail->time) {
                tail->next = nn;
                tail = nn;
            } else {
                node* temp = head;
                while (temp->next != NULL && nn->time > temp->next->time)
                    temp = temp->next;

                nn->next = temp->next;
                temp->next = nn;
            }
        }

        cout << "Added" << endl;
        count++;
    }

    void display() {
        if (head == NULL) {
            cout << "No tasks to display" << endl;
            return;
        }

        cout << "Tasks in ascending order of time:" << endl;
        node* temp = head;
        while (temp != NULL) {
            cout << "Time: " << temp->time << endl;
            cout << "Task: " << temp->task << endl;
            cout << "Comment: " << temp->comment << endl;
            cout << "Importance: " << temp->importance << endl;
            cout << endl;
            temp = temp->next;
        }
    }

    void search() {
        if (head == NULL) {
            cout << "No tasks to search" << endl;
            return;
        }

        int searchTime;
        cout << "Enter the time of the task to search: ";
        cin >> searchTime;

        node* temp = head;
        bool found = false;
        while (temp != NULL) {
            if (temp->time == searchTime) {
                cout << "Task found at time: " << temp->time << endl;
                cout << "Task: " << temp->task << endl;
                cout << "Comment: " << temp->comment << endl;
                cout << "Importance: " << temp->importance << endl;
                found = true;
                break;
            }
            temp = temp->next;
        }

        if (!found) {
            cout << "Task not found at the specified time" << endl;
        }
    }

    void updation() {
        if (head == NULL) {
            cout << "No tasks to update" << endl;
            return;
        }

        int updateTime;
        cout << "Enter the time of the task to update: ";
        cin >> updateTime;

        node* temp = head;
        bool found = false;
        while (temp != NULL) {
            if (temp->time == updateTime) {
                cout << "Enter new task: ";
                cin.ignore();
                getline(cin, temp->task);

                cout << "Enter new comment: ";
                getline(cin, temp->comment);

                cout << "Enter new importance: ";
                getline(cin, temp->importance);

                cout << "Task updated successfully" << endl;
                found = true;
                break;
            }
            temp = temp->next;
        }

        if (!found) {
            cout << "Task not found at the specified time" << endl;
        }
    }

    void deletion() {
        if (head == NULL) {
            cout << "No tasks to delete" << endl;
            return;
        }

        int deleteTime;
        cout << "Enter the time of the task to delete: ";
        cin >> deleteTime;

        node* temp = head;
        node* prev = NULL;
        bool found = false;
        while (temp != NULL) {
            if (temp->time == deleteTime) {
                if (prev == NULL) {
                    head = temp->next;
                    delete temp;
                } else {
                    prev->next = temp->next;
                    if (temp == tail) {
                        tail = prev;
                    }
                    delete temp;
                }

                cout << "Task deleted successfully" << endl;
                found = true;
                count--;
                break;
            }

            prev = temp;
            temp = temp->next;
        }

        if (!found) {
            cout << "Task not found at the specified time" << endl;
        }
    }
    	void loadingBar(){
    system("color 0A");
    char a = 177, b = 219;
    printf("\n\n\n\n");
    printf("\n\n\n\n\t\t\t\t\t" "Loading...\n\n");
    printf("\t\t\t\t\t");
  
    for (int i = 0; i < 26; i++)
        printf("%c", a);
    printf("\r");
    printf("\t\t\t\t\t");
    for (int i = 0; i < 26; i++) {
        printf("%c", b);
  

        Sleep(100);
    }
    system("CLS");
      system("Color 07");
}
}l1;

int main() {
		cout<<"\nStarting the program please wait.....\n";
			sleep(1);	
		cout<<"\nLoading up files.....\n";
		sleep(1);
			system("CLS"); 
   // Admin admin;
   	st:
	int enter;
	again:
	cout<<setw(200)<<"\t\t\t\t\t//////////////////////--TASK  MANAGEMENT SYSTEM--//////////////////////\n";
	cout<<setw(190)<<"1.User login : \n";
	cout<<setw(185)<<"2.Exit :  \n";
	cout<<setw(200)<<"/////////////////////////////////////\n";
	cin>>enter;
	system("CLS");
	if(enter==1){
		  
	  int login();
	  login();
		  l1.loadingBar();
		int a;
    int choice;

    while (true) {
   	cout<<"\n\n\n";
    cout << "\t\t\t\t\t\t1)Insert Task\n";
	cout<<"\t\t\t\t\t\t2)Display\n";
	cout<<"\t\t\t\t\t\t3)Search\n";
	cout<<"\t\t\t\t\t\t4)Updation\n";
	cout <<"\t\t\t\t\t\t5)Delete at Specific Point\n";
	cout<<"\t\t\t\t\t\t6)Back to Main Menu\n";
        cin >> choice;
    
        switch (choice) {
            case 1:
                l1.insertion();
                break;
            case 2:
                l1.display();
                break;
            case 3:
                l1.search();
                break;
            case 4:
                l1.updation();
                break;
            case 5:
                l1.deletion();
                break;
            case 6:
             system("CLS");
            goto st;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
         system("PAUSE");
    system("CLS");
        cout << endl;
    }
    
}
if(enter==2){
		return 0;
	}
	else{
		cout<<"Invlid operation...\n";
		cout<<"Enter again: \n";
		sleep(1);
		system("CLS");
		goto again;
	}
    return 0;
}
int login(){
	string pass="";
	char ch;
	cout<<"\n\n\n\n\n\n\t\t\t\t\t             TASK MANAGEMENT SYSTEM\n\n";
	cout<<"\t\t\t\t\t----------------------------------------------";
	cout<<"\t\t\t\t\t                                            	          LOGIN\n";
	cout<<"\t\t\t\t\t----------------------------------------------\n\n";
	cout<<"\t\t\t\t\t             Enter Password: ";
	ch=_getch();
	while(ch!=13){
		pass.push_back(ch);
		cout<<'*';
		ch=_getch();
	}
	if(pass == "faizi"){
		cout<<"\n\n\n\t\t\t\t\tAccess Granted! \n";
		system("CLS");
	}
	else{
		cout<<"\n\n\t\t\t\t\t\t\t\tAccess Aborted...\n\t\t\t\t\t\t\tPlease Try again\n\n";
		system("PAUSE");
		system("CLS");
		login();
		}
}