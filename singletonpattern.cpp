#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define M 10000000007


// singleton Design pattern
// day 1 singleton pattern
// key thing was channging and non changing cheezo ko alg kr denge
//  in this we are favour the composition over the inheritance

// SDP was used where we want to call any different funtionality at the runtime

// example 
// let suppose we have a robot
// robot can be of different types like talkable ,flyable,runable
// talkable->normaltalkable,no premium talkable
// flyable->normalfyable,premium flyable
// runable->normalrunable,premium runable
// so we will call the robot at runtime like  create the robot of type runable,flyable etc

// abstact class

class Talkable{
  public:
    virtual void Talk()=0;
     virtual ~Talkable(){}
};

class NonTalkable:public Talkable{
  public:
    void Talk(){
        cout<<"NON talkable robot"<<endl;
    }
};

class PremiumTalkable:public Talkable{
  public:
    void Talk(){
        cout<<"Premium talkable robot"<<endl;
    }
};

// abstact class
class Flyable{
  public:
    virtual void Fly()=0;
    virtual ~Flyable(){}
};

class NonFlyable:public Flyable{
  public:
    void Fly(){
        cout<<"NON Flyable robot"<<endl;
    }
};

class PremiumFlyable:public Flyable{
  public:
    void Fly(){
        cout<<"Premium Flyable robot"<<endl;
    }
};



class Robot {
    public:
    Flyable*f;
    Talkable*t;

    Robot( Flyable*fly,Talkable*talk){
        this->f=fly;
        this->t=talk;
    }
    
    void perfomtalk(){
        if(t){
            t->Talk();
        }
    }
    void perfomfly(){
        if(f){
            f->Fly();
        }
    }

};



int main()
{

    Robot*nonrobot=new Robot(new NonFlyable(),new NonTalkable());
    Robot*premiumrobot=new Robot(new PremiumFlyable(),new PremiumTalkable());

    nonrobot->perfomtalk();
    premiumrobot->perfomtalk();




 return 0;
}