//
//  main.cpp
//  ppChainOfRespons
//
//  Created by wudong on 2019/3/7.
//  Copyright © 2019 wudong. All rights reserved.
//

#include <iostream>


/** 责任链设计模式 example**/

//客户请求
class HolidyRequest
{
public:
    HolidyRequest(long long time):RequestTime(time)
    {
        
    }
    
    long long getRequestTime()
    {
        return RequestTime;
    }
private:
    long long RequestTime;
};

//响应者

class Manager
{
public:
    Manager* getImg()
    {
        return this->img;
    }
    void setImg(Manager*  manager)
    {
        this->img = manager;
    }
    virtual bool HandleRequest(HolidyRequest *request) = 0;
private:
    Manager* img;
};

//第一响应者
class FirstResponser:public Manager
{
public:
    FirstResponser(Manager* manager){
        this->setImg(manager);
    }
    
    bool HandleRequest(HolidyRequest *request){
        if(request->getRequestTime() < 20)
        {
            std::cout<<"FirstResponser agree \n";
            return true;
        }else{
            std::cout<<"FirstResponser 权限不足，转交下一级 \n";
            return this->getImg()->HandleRequest(request);
        }
    }
};

//第二响应者
class SecondResponser:public Manager
{
public:
    SecondResponser(Manager* manager)
    {
        this->setImg(manager);
    }
    bool HandleRequest(HolidyRequest *request)
    {
        if(request->getRequestTime() < 200)
        {
            std::cout<<"SecondResponser agree \n";
            return true;
        }else
        {
            if(this->getImg())
            {
                 std::cout<<"SecondResponser 权限不足，转交下一级 \n";
                return this->getImg()->HandleRequest(request);
            }
             std::cout<<"ThreeAResponser 不在，越级处理 \n";
            return true;
        }
    }
};

//第三响应者
class ThreeAResponser:public Manager
{
public:
    ThreeAResponser(Manager* manger)
    {
        this->setImg(manger);
    };
     bool HandleRequest(HolidyRequest *request)
    {
        std::cout<<"ThreeAResponser agree \n";
        return true;
    };
};

//测试

void onTast01()
{
    ThreeAResponser *Tp = new ThreeAResponser(NULL);
    SecondResponser *Sp = new SecondResponser(NULL);
    FirstResponser *Fp = new FirstResponser(Sp);
    HolidyRequest *request = new HolidyRequest(300);
    
    Fp->HandleRequest(request);
    
    delete Fp;
    delete Sp;
    delete Tp;
    delete request;
    
    
    
}



int main(int argc, const char * argv[]) {
    // insert code here...
    onTast01();
    return 0;
}
