#include<iostream>

using namespace std;

class A
{
    public:
        A(){
            callA = 0;
        }
    private:
        int callA;
        void inc(){
            callA++;
        }

    protected:
        void func(int & a)
        {
            a = a * 2;
            inc();
        }
    public:
        int getA(){
            return callA;
        }
};

class B
{
    public:
        B(){
            callB = 0;
        }
    private:
        int callB;
        void inc(){
            callB++;
        }
    protected:
        void func(int & a)
        {
            a = a * 3;
            inc();
        }
    public:
        int getB(){
            return callB;
        }
};

class C
{
    public:
        C(){
            callC = 0;
        }
    private:
        int callC;
        void inc(){
            callC++;
        }
    protected:
        void func(int & a)
        {
            a = a * 5;
            inc();
        }
    public:
        int getC(){
            return callC;
        }
};

class D: public C, B, A
{

	int val;
	public:
		//Initially val is 1
		 D()
		 {
		 	val = 1;
		 }


		 //Implement this function
		 void update_val(int new_val)
		 {
            //find prime factors of the number
            int count2s = 0, count3s = 0, count5s = 0;
            int res = 2;
            while(new_val > 1){
                if(new_val % 2 == 0){
                    new_val = new_val/2;
                    count2s++;
                } else if(new_val % 3 == 0){
                    new_val = new_val/3;
                    count3s++;
                } else if(new_val % 5 == 0){
                    new_val = new_val/5;
                    count5s++;
                }
            }

            for(int i=0; i<count2s; i++){
                A::func(val);
                cout<<"2 x ";
            }
            for(int i=0; i<count3s; i++){
                B::func(val);
                cout<<"3 x ";
            }
            for(int i=0; i<count5s; i++){
                C::func(val);
                cout<<"5 x";
            }
            cout<<" = "<<val<<endl;
		 }
};



int main()
{
    D d;
    d.update_val(180);
    return 0;
}
