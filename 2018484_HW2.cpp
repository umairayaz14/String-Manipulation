#include<iostream>
#include<cstdio>
using namespace std;
class strings {       
public:
	    char store[];
        char x[100]; 
        strings()
		 {
                int i = 0;
                for (i; i < 100; i++) {
                        store[i] = 0;
                }
        }
        strings(int x) {
                int i = 0;
                for (i; i < x; i++) {
                        store[i] = 0;
                }
        }
        strings(char x[]) {
                char temp[100];
                for (int i= 0; i < 100; i++) {
                temp[i] = 0;
                }
                for (int i = 0; i<100;i++){
                        if ((x[i]>=65 and x[i]<=90)or(x[i]>=97 and x[i]<=122) or x[i]==32){
                                temp[i]=x[i];
                        }
                        else{
                                break;
                        }
                }
                for (int i=0 ; i < 100; i++) {
                        store[i] = temp[i];
                }
        }

        int returnlength() {
                int i = 0;
                int count = 0;
                for (i; i < 100; i++) {
                        if (store[i] != 0) {
                                count++;
                        }
                }
                return count;
        }
        
        void erase() {
                int i = 0;
                for (i; i < 100; i++) {
                        store[i] = 0;
                }
        }      
		  
        void addequal(strings y) {
                int u = 0, k = 0;
                u = returnlength();
                k = y.returnlength();
                for (int i = 0; i < k; i++) {
                        store[u + i] = y.store[i];
                }
        }
        
        void addequal(char o[]) {
                int u = 0, k = 0;
                strings y;
                for (int i = 0; i < 100; i++) {
                y.store[i]=o[i];
                }
                u = returnlength();
                k = y.returnlength();
                for (int i = 0; i < k; i++) {
                        store[u + i] = y.store[i];
                }
        }

        char Getat(int x){
                return store[x];
        }
        
        void Setat(int x , char y){
                store[x]=y;
        }
        
        bool isequal(strings y){
                int i = 0;
                for (i;i<returnlength();i++){
                        if (store[i]==y.store[i] and i != returnlength()-1){
                                continue;
                        }
                        else if (store[i]!=y.store[i]){
                                return 0;
                                break;
                        } 
                        if (store[i]==y.store[i] and i == returnlength()-1){
                                return 1;
                                continue;
                        }
                }
        }
        
        bool isnotequal(strings y){
                int i = 0;
                for (i;i<returnlength();i++){
                        if (store[i]!=y.store[i] and i != returnlength()-1){
                                continue;
                        }
                        else if (store[i]==y.store[i]){
                                return 0;
                                break;
                        } 
                        if (store[i]!=y.store[i] and i == returnlength()-1){
                                return 1;
                                continue;
                        }
                }
        }
        
        bool isGreater(strings y){
                int u=y.returnlength();
                int i=returnlength();
                if(u<i){return 1;
                }
                if(u>i){return 0;
                }
        }
        
        bool isLess(strings y){
                int u=y.returnlength();
                int i=returnlength();
                if(u>i){return 1;
                }
                if(u<i){return 0;
                }
        }
        
        strings getsubstring(int x , int y){
        strings temp;
        int mark = 0;
        for(int i = x ; i <=y;i++){
                temp.store[mark]=store[i];
                mark++;
        }
        return temp;
}

~strings(){
        erase();
}        
};

strings add(strings s1, strings s2){
        strings temp;
        int x = s1.returnlength();
        int y = s2.returnlength();
        int mark=0;
        for (int i = 0 ; i<x;i++){
                temp.store[i]=s1.store[i];
                mark++;
        }
        for (int i = 0 ; i<y;i++){
                temp.store[mark]=s2.store[i];
                mark++;
        }
        return temp;
}

int main()
{
        char x[100];
        char y[100];
        int enter;
        cout << "Enter String 1: " << endl;
        gets(x);
        cout << "Enter String 2: " << endl;
        gets(y);
        cout<<endl;
        strings str1(x), str2(y),str3;
        cout << "String 1 is: " << str1.store<<endl;
        cout << "String 2 is: " << str2.store<<endl;
        cout <<endl<< "1. to Add " << endl <<"2. to AddEql "<<endl << "3. to GetValue " << endl
		<< "4. to SetValue "<< endl <<"5. to test IsEqual "<<endl <<"6. to test IsNotEqual "<<endl 
		<<"7. to test IsGreater " <<endl <<"8. to test IsLess " <<endl << "9. to get substring "<<endl <<endl;
        cin>>enter;
        switch(enter){
                case 1:{
                        str3 = add(str1,str2);
                        cout <<"c = a + b "<< endl << str3.store;
                        break;
                }
                case 2:{
                        str1.addequal(str2);
                        cout <<"a += b "<< endl << str1.store;
                        break;
                }
                case 3:{
                        cout << "Enter Index : "<<endl;
                        int z;
                        cin>>z;
                        cout <<"a[" << z <<"] "<<str1.Getat(z); 
                        break;
                }
                case 4:{
                        cout << "Enter Index : "<<endl;
                        int z;
                        cin>>z;
                        cout << "Enter Character : " << endl;
                        char y ;
                        cin >> y ;
                        str1.Setat(z,y);
                        cout <<"String 1 after editing becomes : " << str1.store; 
                        break;
                }
                case 5:{
                        if (str1.isequal(str2)==true){
                                cout << " Both are equal "<< endl;
                        }
                        if (str1.isequal(str2)==false){
                                cout << " Both are not equal "<< endl;
                        }
                        break;
                }
                case 6:{
                        if (str1.isnotequal(str2)==true){
                                cout << " Both are not equal "<< endl;
                        }
                        if (str1.isnotequal(str2)==false){
                                cout << " Both are equal "<< endl;
                        }
                        break;
                }
                case 7:{
                        if (str1.isGreater(str2)==true){
                                cout << " String 1  is larger than second "<< endl;
                        }
                        if (str1.isGreater(str2)==false){
                                cout << " String 1 is smaller than second "<< endl;
                        }
                        break;
                }
                case 8:{
                        if (str1.isLess(str2)==true){
                                cout << " String 1 is smaller than second "<< endl;
                        }
                        if (str1.isLess(str2)==false){
                                cout << " String 1 is larger than second "<< endl;
                        }
                        break;
                }
                case 9:{
                        int z , y;
                        cout << "Enter start index of substring "<<endl;
                        cin >> z;
                        cout << "Enter end index of substring "<<endl;
                        cin >> y; 
                        str3=str1.getsubstring(z,y);
                        cout << "The substring from String 1 is : " << str3.store;
                        break;
                }
        }
        return 0;
}
