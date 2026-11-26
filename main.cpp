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
    cout << "\nIndex: ";
    for (int i = 0; i < n; i++) {
        cout << i << " ";
    }
    
	cout << "\nArray: ";
    for (int i = 0; i < n; i++) {
        cout << mas[i] << " ";
    }
    cout << "\n--------------------------";
    cout << endl;
}

//bubblesort
void bubblesort(int mas[], int n) {
    int i, j, x;
    int sal = 0;
    int apm = 0;
    bool swapped;
    int passes = 0;

    mas_izvads(mas, n);

    for (j = 0; j < n - 1; j++) {
    	passes++;
		swapped = false;
    	
        for (i = 0; i < n - 1 - j; i++) {
        	sal++;
        	
            if (mas[i] > mas[i + 1]) {
                x = mas[i];
                mas[i] = mas[i + 1];
                mas[i + 1] = x;
                apm++;
                swapped = true;
            }
        }
        if (!swapped) {
            break;
    	}
		
    }

    cout << "\nSorted array:";
    mas_izvads(mas, n);
    
    cout << "\nComparisons: " << sal;
    cout << "\nSwaps: " << apm;
    cout << "\nPasses: " << passes;
}

//masiva generesana
void arrayInputGen(int n, int mas[]) {
    for (int i = 0; i < n; i++) {
        mas[i] = rand() % 30 + 1;
    }
}

//shakersort
void shakersort (int mas[],int n){ //no kreisas uz labo
    int L = 0;
    int R = n - 1;
    int x, i, st = 0;
    int apm;
    
   mas_izvads(mas,n);
    
    while (L<R){
        apm = 0;
        
        //no kr uz labo
        for(i = L; i < R; i++) {
            
            if (mas[i] > mas[i+1]){
                if (apm == 0) {
                    cout << "\nStep = " << st + 1;
                }
            x = mas[i];
            mas[i] = mas[i+1];
            mas[i+1] = x;
            
            apm++;
            //mas_izvads(mas,n);
            }
            mas_izvads(mas,n);
        }
        R--;
         //no labas uz kr
        for (i = R; i > L; i--) {

            if (mas[i] < mas[i-1]) {
                x = mas[i];
                mas[i] = mas[i-1];
                mas[i-1] = x;

                apm++;
                //mas_izvads(mas, n);
            }
            mas_izvads(mas,n);
        }
        L++; 
        
        if (apm == 0){
            return;
        }
        st++; 
    }
}

void shakersort2 (int mas[],int n){ //no labas uz kreiso
    int L = 0;
    int R = n - 1;
    int x, i, st = 0;
    int apm;
    
    mas_izvads(mas,n);
    
    while (L<R){
        apm = 0;
        
        //no labas uz kr
        for(i = R; i > L; i--) {

            if (mas[i] < mas[i-1]) {
                if (apm == 0) {
                    cout << "\nStep = " << st + 1;
                }
                x = mas[i];
                mas[i] = mas[i-1];
                mas[i-1] = x;

                apm++;
                mas_izvads(mas, n);
            }
        }
        L++;
         //no kr uz labo
        for (i = L; i < R; i++) {

            if (mas[i] > mas[i+1]){
            x = mas[i];
            mas[i] = mas[i+1];
            mas[i+1] = x;
            
            apm++;
            mas_izvads(mas,n);
            }
        }
        R--; 
        
        if (apm == 0){
            return;
        }
        st++; 
    }
}


//=======================================MAIN================================================
int main(){
    srand(time(NULL));
    int mas[N];
    int n,choice;
    cout << "\nn = ";
    cin >> n;
    arrayInputGen(n, mas);
    //mas_ievads(mas, n);
    mas_izvads(mas, n);
    
    do {
        system("cls"); //clear
        //saraksts
        cout<<"\n\t\tSorting Algorithms";
        cout<<"\n 1. Bubble Sort";
        cout << "\n 2. ShakerSort (left to right)";
        cout << "\n 3. ShakerSort (no labas uz kreiso)";
        cout<<"\n 0. Exit";
        cout<<"\nInput number: ";
        cin>>choice;
        //alg.izvele
        switch(choice){
            case 1: bubblesort(mas, n);
				    system("pause>>nul");
				    break;
			case 2: shakersort(mas, n);
				    system("pause>>nul");
				    break;
			case 4: shakersort2(mas, n);
				    system("pause>>nul");
				    break;
            
            case 0: cout<<"\nExit"; break;
            
            default: cout<<"\nWrong choice";
        }
    }
    while (choice!=0);
    
    
    system("pause>>nul");
    return 0;
}
