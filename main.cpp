#include <iostream>
#include <cstdlib>
#include <ctime>
#define N 1000
using namespace std;

//mas ievads
void mas_ievads(int mas[],int n) {
    int i;
    for (i=0;i<n;i++) {
        cout << "mas[" << i << "]= ";
        cin >> mas[i];
    }
}

//mas izvads
void mas_izvads(int mas[],int n) {
    int i;
    cout<<"\n";
    for (i = 0;i < n;i++) {
        cout << mas[i] << " ";
    }
    cout<<endl;
}

//masiva generesana
void arrayInputGen(int n, int mas[]) {
    for (int i = 0; i < n; i++) {
        mas[i] = rand() % 30 + 1;
    }
}


//=======================================MAIN================================================
int main(){
    srand(time(NULL));
    int mas[N];
    int n,choice;
    cout << "\nn = ";
    cin >> n;
    if (n <= 0 || n > N) {
	    cout << "Wrong array size!";
	    return 1;
    }
    arrayInputGen(n, mas);
    //mas_ievads(mas, n);
    mas_izvads(mas, n);
    
    do {
        system("cls"); //clear
        //saraksts
        cout<<"\n\t\tSorting Algorithms";
        
        cout<<"\n 0. Exit";
        cout<<"\nInput number: ";
        cin>>choice;
        //alg.izvele
        switch(choice){
            
            
            case 0: cout<<"\nExit"; break;
            
            default: cout<<"\nWrong choice";
        }
    }
    while (choice!=0);
    
    
    system("pause>>nul");
    return 0;
}
