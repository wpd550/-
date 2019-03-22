//简单工厂类的实现
// Created by dong wu on 2019-03-22.
//

#ifndef UNTITLED_FACTORPATTERN_H
#define UNTITLED_FACTORPATTERN_H

#import <boost/shared_ptr.hpp>
#import <boost/make_shared.hpp>
//
class AbstractBase
{
public:
    virtual void spiliterFile() = 0; //调用接口
};

class AbstractBaseFoctor
{
protected:
    typedef boost::shared_ptr<AbstractBase> abstract_ref;
public:
    virtual abstract_ref getSpiliterImp() = 0; //工厂接口
};


class BinaryFileSpiliterImp:public AbstractBase
{
public:
    BinaryFileSpiliterImp()
    {
        std::cout<<"构造"<<__FUNCTION__<<std::endl;
    };
    ~BinaryFileSpiliterImp()
    {
        std::cout<<"析构"<<__FUNCTION__<<std::endl;
    }
public:
    void spiliterFile()
    {
        std::cout<<"调用BinaryFileSpiliterImp"<<std::endl;
    };
};

class HtmlFileSpiliterImp:public AbstractBase
{
public:
    HtmlFileSpiliterImp()
    {
        std::cout<<"构造"<<__FUNCTION__<<std::endl;
    };
    ~HtmlFileSpiliterImp()
    {
        std::cout<<"析构"<<__FUNCTION__<<std::endl;
    }
public:
    void spiliterFile()
    {
        std::cout<<"调用HtmlFileSpiliterImp"<<std::endl;
    };
};

class BinaryFileFactor:public AbstractBaseFoctor
{

public:
     abstract_ref getSpiliterImp()
     {
         return  boost::make_shared<BinaryFileSpiliterImp>();
     }
};

class HtmlFileFactor:public AbstractBaseFoctor
{
public:
    abstract_ref getSpiliterImp()
    {
        return  boost::make_shared<HtmlFileSpiliterImp>();
    }
};


#endif //UNTITLED_FACTORPATTERN_H
