//
//  ppBride.cpp
//
//
//  Created by wudong on 2019/3/8.
//  Copyright © 2019 wudong. All rights reserved.
//
#include <iostream>


using namespace std;

//桥接模式
//适用于多维度变化的需求
/**
 examp：模拟跨平台实现播放器
 
 思考：
    继承转组合model的运用 减少类之间的耦合
    动态装载过程，增强了灵活行
 **/

//class MediaImp;


class MediaImp
{
public:
    virtual void play() =0;
    virtual void downMedia() =0;
    virtual void next() =0;
    virtual void forward() =0;
  
};

class SystemBase
{
public:
    virtual void  installMedIa() = 0;
    virtual void  downloadApp()  = 0;
protected:
    MediaImp *imp;
};


class MacosSystemBase:public SystemBase
{
public:
    MacosSystemBase(MediaImp* imp){
        this->imp = imp;
    }
    
    void installMedIa()
    {
        std::cout<<"MacosSystemBase"<<": 安装系统\n";
        imp->next();
        imp->forward();
    }
    void downloadApp()
    {
        std::cout<<"MacosSystemBase"<<": 下载系统\n";
        imp->downMedia();
        imp->play();
    }
};

class MobileSystemBase:public SystemBase
{
public:
    MobileSystemBase(MediaImp* imp){
        this->imp = imp;
    }
    void installMedIa()
    {
        std::cout<<"MobileSystemBase"<<": 安装系统\n";
        imp->next();
        imp->forward();
    }
    void downloadApp()
    {
        std::cout<<"MobileSystemBase"<<": 下载系统\n";
        imp->downMedia();
        imp->play();
    }
};
class LinuxSystemBase: public SystemBase
{
public:
    LinuxSystemBase(MediaImp* imp){
        this->imp = imp;
    }
    void installMedIa()
    {
        std::cout<<"LinuxSystemBase"<<": 安装系统\n";
        imp->next();
        imp->forward();
    }
    void downloadApp()
    {
        std::cout<<"LinuxSystemBase"<<": 下载系统\n";
        imp->downMedia();
        imp->play();
    }
};


class MusicMediaImp : public MediaImp
{
public:
    void play()
    {
        std::cout<<"MusicMediaImp->play()\n";
    }
    void downMedia()
    {
        std::cout<<"MusicMediaImp->downMedia()\n";
    }
    void next()
    {
        std::cout<<"MusicMediaImp->next()\n";
    }
    void forward()
    {
        std::cout<<"MusicMediaImp->forward()\n";
    }
};

class VideoMediaImp: public MediaImp
{
public:
    void play()
    {
        std::cout<<"VideoMediaImp->play()\n";
    }
    void downMedia()
    {
        std::cout<<"VideoMediaImp->downMedia()\n";
    }
    void next()
    {
        std::cout<<"VideoMediaImp->next()\n";
    }
    void forward()
    {
        std::cout<<"VideoMediaImp->forward()\n";
    }
};

class BokeMediaImp: public MediaImp
{
public:
    void play()
    {
        std::cout<<"BokeMediaImp->play()\n";
    }
    void downMedia()
    {
        std::cout<<"BokeMediaImp->downMedia()\n";
    }
    void next()
    {
        std::cout<<"BokeMediaImp->next()\n";
    }
    void forward()
    {
        std::cout<<"BokeMediaImp->forward()\n";
    }
};


void onTask()
{
    //动态装载过程
    BokeMediaImp *imp = new BokeMediaImp();
    LinuxSystemBase *sb = new LinuxSystemBase(imp);
    sb->downloadApp();
    sb->installMedIa();
    delete imp;
    delete sb;   
}

int main(int argc, const char * argv[]) {

    onTask();
    return 0;
}
