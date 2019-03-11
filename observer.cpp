//
//  observer.cpp
//  ppChainOfRespons
//
//  Created by wudong on 2019/3/11.
//  Copyright © 2019 wudong. All rights reserved.
//

#include <algorithm>
#include <vector>
#include <stdio.h>
#include <iostream>

class Observable;

class Observer
{
public:
    virtual void updata() =0;
    ~Observer();
    
    void addObsever(Observable *ob);
private:
    Observable *s_;
};


class Observable
{
public:
    void registerObserver(Observer* observer);
    void unregisterObserver(Observer* observer);
    void notifyObservsers();
private:
    std::vector<Observer*> m_;
};
void Observable::registerObserver(Observer* observer)
{
    m_.push_back(observer);
}
void Observable::unregisterObserver(Observer* observer)
{
    std::vector<Observer*>::iterator it = std::find(m_.begin(), m_.end(), observer);
    if(it != m_.end())
    {
        std::swap(*it, m_.back());
        m_.pop_back();
    }
}

void Observable::notifyObservsers()
{
    for(auto it : m_)
    {
        it->updata();
    }
}


void Observer::addObsever(Observable *ob)
{
    ob->registerObserver(this);
    this->s_ = ob;
}

Observer::~Observer()
{
    s_->unregisterObserver(this);
}

class Ando :public Observer
{
    void updata()
    {
        std::cout<<"我被调用了"<<std::endl;
    }
};

void onTask()
{
    Ando *ando = new Ando();
    Observable observable;
    ando->addObsever(&observable);
    observable.notifyObservsers();
    delete ando;
    observable.notifyObservsers();
}

int main()
{
    onTask();
    
}
