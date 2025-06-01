#include<bits/stdc++.h>
using namespace std;

    //!-------------------------------Class-1-----------------------------
//! 1)Empty class size 
    class EmptySize{
        //There is no any state and methods so by default size of empty class is 1.
    };

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

//! 3)Declare Properteis and Methods
class Animal{    
    //Mene basicaly ek animal ka structrue bana liya hai ke jo bhi animal hum object banayenge uske yai yai properties hogi
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

//! 4)Getter & Setter
    class getSet{
        private:
        int value;
        public:
        int getvalue(){
            return value;
        }
        void setvalue(int v){
            value = v;
        }
    };

//! 5)Dynamic Memory Allocation
    class dynamicMemory{
        public:
        string name;
        int age;
        void eat(){
            cout<<"eating"<<endl;
        }
    };
 
//! 6)This keyword
    class Body{
        private://by default
        int weight;
        public:
        int getweight(){
            return weight;
        }
        void setweight(int weight){//mene yaha jo value aai hai uska name bhi same hi rakh dea jo uper declare kiya hia tabhi this use hoga
            this->weight = weight;
            //or
            // (*this).weight = weight;
        }
    };

//! 7)default ,parameterised and copy constructor
    class Animal1{
        public:
        string name;
        int age;
        int weight;

        //default constructor
        Animal1(){
            this->name = "Tommy";
            this->age = 12;
            this->weight = 21;
            cout<<"Default constructor called!!"<<endl;
        }

        //Parameterised constructor with single argument
        Animal1(string name){
            this->name = name;
            cout<<"Parameteriesed Constructor with I arrgument!"<<endl;
        }
        //Parameterised constructor with double arrgument
        Animal1(string name , int age){
            this->name = name;
            this->age = age;
            cout<<"Parameteriesed constructor with II arrgument!"<<endl;
        }
        //Parameterised constructor with triple arrgument
        Animal1(string name , int age , int weight){
            this->name = name;
            this->age = age;
            this->weight = weight;
            cout<<"Parameteised constructor with III arrgument!"<<endl;
        }
    
        //Copy Constructor
        Animal1(Animal1 &obj){
            this->name = obj.name;
            this->age = obj.age;
            this->weight = obj.weight;
        }
        void print(){
            cout<<name<<endl;
            cout<<age<<endl;
            cout<<weight<<endl;
        }
    };

//! 8)Destructor
    class DestructorDemo{
        public:
        int age;
        ~DestructorDemo(){
            cout<<"This is destructor call for memory free!"<<endl;
        }
    };

    //!----------------------class-2----------------------------------------

//! 9) Inheritence (Public , Protected , Private)
    class Parent{
        public://replace with private and protected as well to see the behaviour
        int age = 21;
    };
    class child : public Parent{//replace with private and protected as well to see the behaviour
        public:
        void print(){
            cout<<age;
        }
    };

//! 10) Types of Inhertance 
    //Single Level Inheritance+_+_+_+_
    class SingleParent{
        public:
        string name;
    };
    class SingleChild : public SingleParent{
    };

    //Multi Level Inheritance_+_+_+_+_+_
        class Fruit{
            public:
            string name;
        };
        class Mango : public Fruit{
            public:
            int weight;
        };
        class Alphanso : public Mango{
            public:
            int sugarLevel;
        };
    
    // Multiple Level Inheritance_+_+_+_+_+_+_
        class A{
            public:
            int chemistry;
            int physics = 65;//if physics also in A class this is dymand problem to resolve it use scope resolution operator(::)
            A(){
                chemistry = 76;
            }
        };
        class B{
            public:
            int physics;
            B(){
                physics = 73;
            }
        };
        class C : public A , public B{
            public:
            int math = 86;
        };

    // Hierarchical Level Inheritance+_+_+_+_+_+_+_
        class Amarnath{
            public:
            string name = "Amarnath";
            int age = 60;
        };
        class Surinder : public Amarnath{

        };
        class Himanshu : public Amarnath{

        };
        
    // Hybrid Level Inheritance
        class AA{
            public:
            void showA(){
                cout<<"Class A"<<endl;
            }
        };

        class CC{
            public:
            void showC(){
                cout<<"Class C"<<endl;
            }
        };

        class BB: public AA{
            public:
            void ShowB(){
                cout<<"Class B Derived form class A"<<endl;
            }
        };

        class DD : public AA , public CC{
            public:
            void showD(){
                cout<<"Class D Derived form class A and class C"<<endl;
            }
        };




int main(){
    //! Class-1 (Oops)
    //1)Empty class size
    //  cout<<sizeof(EmptySize)<<endl;

    //2)Padding and Greedy Alignment
        // cout<<sizeof(Padding)<<endl;// Output:12 ->(Because char ne to 1 byte hi liye lekin system 32 bit ka hai to 3 byte extra add ho gayi that called Padding)
        // cout<<sizeof(GreedyAlignment)<<endl;

    //3) Declare Properteis and Methods
        // Animal dog;//dog object bana liya hai jiske state or properties Animal blueprint ke according hogi
        // dog.name = "Tommy";
        // dog.age = 8;
        // dog.color = "Brown";
        // cout<<"Dog name: "<<dog.name<<endl;
        // cout<<"Dog age: "<<dog.age<<endl;
        // cout<<"Dog color: "<<dog.color<<endl;
        // dog.eat();
        // dog.sleep();

    //4) Getter & Setter
        // getSet num;
        // num.setvalue(20);
        // cout<<"value : "<<num.getvalue()<<endl;

    //5)Dynamic Memory Allocation
        // dynamicMemory* himanshu = new dynamicMemory;
        //two ways to access object's members
        // (*himanshu).name = "Himanshu";
        // (*himanshu).age = 21;
        // (*himanshu).eat();
        //----------
        // himanshu->name = "Himanshu";
        // himanshu->age = 21;
        // himanshu->eat();
            
    //6)This keyword
        // Body a;
        // a.setweight(45);
        // cout<<a.getweight();

    //7)default ,parameterised and copy constructor
        // Animal1 a;
        // Animal1 b("Dog");
        // Animal1 c("Dog",21);
        // Animal1 d("Dog",21,34);
        //Animal1 e = a;// copy constructor a object ko e object me copy ker liya !!
        //or copy ese bhi ker sakte hai e(a) okkk!
        // e.print();

    //8) Destructor
    //DestructorDemo a;//this is static destructor by default call
    //-------
    //DestructorDemo *b = new DestructorDemo();
    //b->age = 10;
    //delete b; //this is manually deallocate the memory of object
        
    //! Class-2 (Oops)
    //!Inheritence:
    //9)Inheritence (Public , Protected , Private)
        //child c1;
        // cout<<c1.age;
        //c1.print();   
    
    //10) Types of Inheritance 
      //-->Single Level Inheritance
        // SingleChild c1;
        // c1.name = "Father";
        // cout<<c1.name<<endl;
    
      //--> Multi Level Inheritance
        //Alphanso f1;
        // f1.name = "Alphasno";
        // f1.weight = 1.5;
        // f1.sugarLevel = 1;
        // cout<<f1.name<<" "<<f1.weight<<"kg"<<" "<<f1.sugarLevel<<"g"<<endl;
        
      //--> Multiple Inheritance
        // C marks;
        // cout<<marks.chemistry<<" "<<marks.B::physics<<" "<<marks.A::physics<<" "<<marks.math<<endl;

      //--> Hierarchical Level Inheritance
            // Himanshu himanshu;
            // cout<<"Himanshu Father Name : "<<himanshu.name<<endl;
            // cout<<"Himanshu Father Age : "<<himanshu.age<<endl;
       
      //--> Hybrid Level Inheritance
        // DD obj;
        // obj.showA();
        // obj.showC();
        // obj.showD();

    //! Polymorphism:
    
    
    return 0;



}