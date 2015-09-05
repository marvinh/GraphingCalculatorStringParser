//
//  Syard.cpp
//  GraphingCalculator
//
//  Created by Marvin on 5/3/15.
//  Copyright (c) 2015 Marvin. All rights reserved.
//

#include "Syard.h"
double Evaluation(queue<Token*> inputQ, double& x)
{
    double result;
    stack<Token*> output;
    bool inQL1=false;
    int size=inputQ.size();
    if(size==1&&(inputQ.front()->typeOf()==VARIABLE||inputQ.front()->typeOf()==NUM||inputQ.front()->typeOf()==CONSTANT))inQL1=true;
    
    if(inQL1==true)
    {
        //skip to result...
        if(inputQ.front()->typeOf()==NUM){
            result=static_cast<num*>(inputQ.front())->getNum();
            inputQ.front()=NULL;
            delete inputQ.front();
            inputQ.pop();
        }
        else if(inputQ.front()->typeOf()==VARIABLE){
            result=x;
            inputQ.front()=NULL;
            delete inputQ.front();
            inputQ.pop();
        }else{
            //my only constant...
            result=M_PI;
            inputQ.front()=NULL;
            delete inputQ.front();
            inputQ.pop();
        }
        
    }else{

        while(!inputQ.empty())
        {
            double i=0,j=0;
            while (inputQ.front()->typeOf()!=OP&&
                   inputQ.front()->typeOf()!=FUNCTION)
            {
                output.push(inputQ.front());
                inputQ.front()=NULL;
                delete inputQ.front();
                inputQ.pop();
            }
            
            if(output.empty())throw 42;
            if(inputQ.front()->typeOf()==FUNCTION)
            {
                switch (output.top()->typeOf()) {
                    case NUM:
                        i=static_cast<num*>(output.top())->getNum();
                        break;
                    case VARIABLE:
                        i=x;
                        break;
                    case CONSTANT:
                        i=M_PI;
                        break;
                    default:
                        break;
                }
                output.top()=NULL;
                delete output.top();
                output.pop();
                
                if(static_cast<mathfunctions*>(inputQ.front())->functionType()==MAX||
                   static_cast<mathfunctions*>(inputQ.front())->functionType()==MIN)
                {
                    if(output.empty())throw 42;
                    switch (output.top()->typeOf())
                    {
                        case NUM:
                            j=static_cast<num*>(output.top())->getNum();
                            break;
                        case VARIABLE:
                            j=x;
                            break;
                        case CONSTANT:
                            j=M_PI;
                            break;
                        default:
                            break;
                    }
                    output.top()=NULL;
                    delete output.top();
                    output.pop();
                }
                
            }else{
                switch (output.top()->typeOf())
                {
                    case NUM:
                        i=static_cast<num*>(output.top())->getNum();
                        break;
                    case VARIABLE:
                        i=x;
                        break;
                    case CONSTANT:
                        i=M_PI;
                        break;
                    default:
                        break;
                }
                output.top()=NULL;
                delete output.top();
                output.pop();
                if(output.empty())throw 42;
                switch (output.top()->typeOf())
                {
                    case NUM:
                        j=static_cast<num*>(output.top())->getNum();
                        break;
                    case VARIABLE:
                        j=x;
                        break;
                    case CONSTANT:
                        j=M_PI;
                        break;
                    default:
                        break;
                }
                output.top()=NULL;
                delete output.top();
                output.pop();
            }
            switch (inputQ.front()->typeOf())
            {
                case OP:
                    switch(static_cast<oper*>(inputQ.front())->getChar())
                {
                    case '*':
                        output.push(new num(j*i));
                        break;
                    case '/':
                        output.push(new num(j/i));
                        break;
                    case '+':
                        output.push(new num(j+i));
                        break;
                    case '-':
                        output.push(new num(j-i));
                        break;
                    case '^':
                        output.push(new num(pow(j,i)));
                        break;
                }
                    break;
                case FUNCTION:
                    switch (static_cast<mathfunctions*>(inputQ.front())->functionType()){
                        case SIN:
                            output.push(new num (sin(i)));
                            break;
                        case COS:
                            output.push(new num(cos(i)));
                            break;
                        case TAN:
                            output.push(new num(tan(i)));
                            break;
                        case CSC:
                            output.push(new num (1/sin(i)));
                            break;
                        case SEC:
                            output.push(new num(1/cos(i)));
                            break;
                        case COT:
                            output.push(new num(1/tan(i)));
                            break;
                        case LOG:
                            output.push(new num(log10(i)));
                            break;
                        case LN:
                            output.push(new num(log(i)));
                            break;
                        case EXP:
                            output.push(new num(exp(i)));
                        case MAX:
                            output.push(new num(max(j,i)));
                            break;
                        case MIN:
                            output.push(new num(min(j,i)));
                            break;
                        case NEGATIVE:
                            output.push(new num(i*-1));
                            break;
                            
                    }
                    break;
            }
            inputQ.pop();
        }
        
        result=static_cast<num*>(output.top())->getNum();
        output.top()=NULL;
        delete output.top();
        output.pop();
        if(!output.empty())throw 42;
    }
    return result;
}
queue<Token*>InFix(string s)
{
    QuickTokenize hold(s);
    
    queue<Token*> output;
    string temp;
    char t;
    double d;
    while(!hold.empty()){
        temp=hold.nextToken();
        switch (hold.ofType()) {
            case NUM:
                d=hold.getConversion();
                output.push(new num(d));
                break;
            case OP:
                t=temp[0];
                output.push(new oper(t));
                break;
            case LP:
                t=temp[0];
                output.push(new lparan(t));
                break;
            case RP:
                t=temp[0];
                output.push(new rparan(t));
                break;
            case FUNCTION:
                output.push(new mathfunctions(temp));
                break;
            case VARIABLE:
                t=temp[0];
                output.push(new variable(t));
                break;
            case CONSTANT:
                output.push(new mathconst(temp));
                break;
            case COMMA:
                t=temp[0];
                output.push(new comma(t));
                break;
            case SPACE:
                break;
            default:
                throw 40;
                break;
        }
        
    }
    if(output.empty())throw -1;
    return output;
}
queue<Token*>InFixToPostFix(queue<Token*> inputQ)
{
    //delete paranthesis in this delete everything else in evaluate
    queue<Token*> output;
    stack<Token*> st;
    while(!inputQ.empty())
    {
        switch (inputQ.front()->typeOf())
        {
            case CONSTANT:
            case NUM:
            case VARIABLE:
                output.push(inputQ.front());
                inputQ.front()=NULL;
                delete inputQ.front();
                inputQ.pop();
                break;
            case COMMA:
                if(output.empty())throw -1;
                while(!st.empty()&&st.top()->typeOf()!=LP)
                {
                    output.push(st.top());
                    st.pop();
                }
                if(st.empty())throw 41;
                inputQ.front()=NULL;
                delete inputQ.front();
                inputQ.pop();
                break;
            case LP:
                st.push(inputQ.front());
                inputQ.front()=NULL;
                delete inputQ.front();
                inputQ.pop();
                break;
            case RP:
                if(output.empty())throw -1;
                while(!st.empty()&&st.top()->typeOf()!=LP)
                {
                    output.push(st.top());
                    st.pop();
                }
                if(st.empty())throw 41;
                st.top()=NULL;
                delete st.top();
                st.pop();
                inputQ.front()=NULL;
                delete inputQ.front();
                inputQ.pop();
                break;
            case FUNCTION:
                st.push(inputQ.front());
                inputQ.front()=NULL;
                delete inputQ.front();
                inputQ.pop();
                break;
            case OP:
                if(st.empty())
                {
                    st.push(inputQ.front());
                    inputQ.front()=NULL;
                    delete inputQ.front();
                    inputQ.pop();
                }
                else if(st.top()->typeOf()==OP)
                {
                    if((static_cast<oper*>(inputQ.front())->getPrecendence()<=
                        static_cast<oper*>(st.top())->getPrecendence())&&static_cast<oper*>(st.top())->rassociative()==false)
                    {
                        while(!st.empty()&&st.top()->typeOf()!=LP&&st.top()->typeOf()!=FUNCTION)
                        {
                            output.push(st.top());
                            st.top()=NULL;
                            delete st.top();
                            st.pop();
                        }
                        st.push(inputQ.front());
                        inputQ.front()=NULL;
                        delete inputQ.front();
                        inputQ.pop();
                    }
                    else
                    {
                        st.push(inputQ.front());
                        inputQ.front()=NULL;
                        delete inputQ.front();
                        inputQ.pop();
                    }
                }
                else if (st.top()->typeOf()==FUNCTION)
                {
                    output.push(st.top());
                    st.top()=NULL;
                    delete st.top();
                    st.pop();
                    st.push(inputQ.front());
                    inputQ.front()=NULL;
                    delete inputQ.front();
                    inputQ.pop();
                }
                else
                {
                    st.push(inputQ.front());
                    inputQ.front()=NULL;
                    delete inputQ.front();
                    inputQ.pop();
                }
                break;
        }
        
    }
    while(!st.empty())
    {
        output.push(st.top());
        st.top()=NULL;
        delete st.top();
        st.pop();
    }
    if(output.empty())throw -1;
    
    return output;
}
void PostPrint(queue<Token*> p)
{
    cout<<"PostFix: ";
    while(!p.empty())
    {
        p.front()->Print();
        p.front()=NULL;
        delete p.front();
        p.pop();
    }
    cout<<endl;
}
