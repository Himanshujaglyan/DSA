#include<bits/stdc++.h>
using namespace std;

//! 1)Empty class size 
    class EmptySize{
        //There is no any state and methods so by default size of empty class is 1.
    };
//----------------------------------------------------------------
//! 2)Padding and Greedy Alignment
    // ->padding extra byte create ker deta hai system ke bit ko mantain rakhne ke liye like cpu 4byte hi consider karega jo koi 1 byte ka hoga phir uske liye exta byte add ker dega
    // ->geedy alignment padding ko minimize kerne ke technique hai jiske acc ager hum properties member ko desending order me laga denge tub yai problem ne hogi
    
    // #pragma pack(1) //-->ager without padding actual size dekhna hai ke kitna hu ahai to yai #use kerna!!
    class Padding{
        char a;
        char b;
        char c;
        short sum;
        int age;
    };
    class GreedyAlignment{
        int age;
        short sum;
        char a;
        char b;
        char c;
    };
    // Note :Why both classes show 8 bytes?
        //	Because modern compiler optimized the layout (verna padding wale me upper )

//-------------------------------------------------------------
//! Declare Properteis and Methods
    class Animal{//Mene basicaly ek animal ka structrue bana liya hai ke jo bhi animal hum object banayenge uske yai yai properties hogi
        public:
        //state or Properties
        int age;
        string name;
        string color;

        //Behaviour or Methods
        void eat(){
            cout<<"Eating"<<endl;
        }   
        void sleep(){
            cout<<"Sleeping"<<endl;
        }
    };





int main(){

    //1)Empty class size
    //  cout<<sizeof(EmptySize)<<endl;

    //2)Padding and Greedy Alignment
        // cout<<sizeof(Padding)<<endl;// Output:12 ->(Because char ne to 1 byte hi liye lekin system 32 bit ka hai to 3 byte extra add ho gayi that called Padding)
        // cout<<sizeof(GreedyAlignment)<<endl;

    //3) Declare Properteis and Methods
        Animal dog;//dog object bana liya hai jiske state or properties Animal blueprint ke according hogi
        dog.name = "Tommy";
        dog.age = 8;
        dog.color = "Brown";
    
        cout<<"Dog name: "<<dog.name<<endl;
        cout<<"Dog age: "<<dog.age<<endl;
        cout<<"Dog color: "<<dog.color<<endl;

        dog.eat();
        dog.sleep();
        return 0;
}