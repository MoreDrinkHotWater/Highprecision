//
// Created by zhihui on 7/16/19.
//
#include <iostream>
#include "../include/Add.h"
#include "../include/DataStructs.h"
 #include "../include/GetElem.h"
using namespace std;

LinkList Add::add(LinkList &First,LinkList &Second,int firstLength,int secondLength)
{
      LNode *temp;
      std::string result = "";

      int Diff = abs(firstLength-secondLength);
      cout<<"Diff: "<<Diff<<endl;

      cout<<""<<GetElem(First,0)<<endl;

      // 相同长度的计算
      if(Diff==0)
      {
          temp = First->next;

          for (int i = 0; i < firstLength; ++i) {
              result+=partAdd(First, Second, GetElem(First,i), GetElem(Second,i), *temp);

              // result = string(result.rbegin(),result.rend());

              temp = temp->next;
          }
      }
      // 当第一个参数的长度 大于 第二个参数的长度
      else if (Diff!=0)
      {
          temp = First->next;
          // 第一个链表 长度大于 第二个链表
          if(firstLength>secondLength)
          {
              // 先循环计算最短的链表
              for (int i = 0; i < secondLength; ++i) {

                  result+=DiffAdd(First, Second, GetElem(First,i), GetElem(Second,i), *temp);

                  temp = temp->next;
              }

              // 再把多余的长度自动加到字符串后面
              for (int j = secondLength; j <firstLength; ++j) {
                      cout<<"Number1_Str: "<< GetElem(First,j)<<endl;
                      result += to_string(GetElem(First,j));
              }
          }
      }
      cout<<result<<endl;
}

string Add::partAdd(LinkList &First, LinkList &Second, int first, int second, LNode &temp)
{
    string Number1_Str = to_string(first);
    string Number2_Str = to_string(second);

    int Number1_Str_Length = Number1_Str.length();
    int Number2_Str_Length = Number2_Str.length();
    int max_length,min_length;

    if(Number1_Str_Length >= Number2_Str_Length)
    {
        max_length = Number1_Str_Length;
        min_length = Number2_Str_Length;

        cout<<"Number1_Str: "<<Number1_Str<<endl;
        cout<<"Number2_Str: "<<Number2_Str<<endl;
        cout<<"max: "<<max_length<<endl;
        cout<<"min: "<<min_length<<endl;
    }
    else
    {
        max_length = Number2_Str_Length;
        min_length = Number1_Str_Length;

        cout<<"Number1_Str: "<<Number1_Str<<endl;
        cout<<"Number2_Str: "<<Number2_Str<<endl;
        cout<<"max: "<<max_length<<endl;
        cout<<"min: "<<min_length<<endl;
    }

    string temp_str = "";

    for (int i = 0; i < min_length; ++i) {

        int number1 = std::atoi(Number1_Str.substr(i,1).c_str());
        int number2 = std::atoi(Number2_Str.substr(i,1).c_str());
        int sum = number1 + number2;

        if(sum<10){
            if(max_length == min_length)
            {
                temp_str+=to_string(sum);
            }
            else
            {
                temp_str+=to_string(sum);
                while(i!=max_length-1 && temp.next == nullptr)
                {
                    temp_str+=Number1_Str[i+1];
                    i++;
                }
            }
        }
        else if(sum>10){
            // 先安排这一位的数字
            temp_str+=to_string(sum-10);
            // 不是最后一个数字 链表的下一个元素不为空
            if (i!=min_length-1 && temp.next != nullptr)
            {
                Number1_Str[i+1]+=1;

                cout<<"Number1_Str[i+1] "<<Number1_Str[i+1]<<endl;
                cout<<"Number1_Str[i+2] "<<Number1_Str[i+2]<<endl;
            }
            // 不是最后一个数字 链表的下一个元素为空
            else if(i!= max_length-1 && temp.next == nullptr)
            {
                Number1_Str[i+1]+=1;
                temp_str+=Number1_Str[i+1];
                cout<<"不是最后一个数字 链表的下一个元素为空: "<<endl;
                cout<<"Number1_Str[i+1] is :"<<Number1_Str[i+1]<<endl;
            }
            // 是最后一个数字 链表的下一个元素为空
            else if(i== max_length-1 && temp.next == nullptr)
            {
                cout<<"是最后一个数字 链表的下一个元素为空: "<<endl;
                if(max_length == min_length)
                {
                    temp_str += "1";
                }
                else
                {
                    temp_str+=Number1_Str[i+1];
                }
            }
            // 是最后一个数字 链表的下一个元素不为空
            else if ( i == min_length-1  && temp.next != nullptr)
            {
                cout<<"Number1_Str[i] "<<Number1_Str[i]<<endl;

                int data = atoi(temp.next->data.c_str());

                cout<<"data: "<<data<<endl;

                if( data >=1 && data<=9)
                {
                    temp.next->data +=1;
                }
                else if(data>=10 && data <=99)
                {
                    temp.next->data +=10;
                }
                else if(data>=100 && data <=999)
                {
                    temp.next->data +=100;
                }
                else if(data>=1000 && data <=9999)
                {
                    temp.next->data +=1000;
                }
            }
        }
        // 相加等于10
        else{

            if(temp.next == nullptr)
            {
                cout<<"temp.next is empty"<<endl;
            }

            // 是最后一个数字 而且 下一个链表元素为空
            if (i== min_length-1 && temp.next == nullptr)
            {
                temp_str+="01";
                // Number1_Str[i+1]+=1;
            }
            // 不是最后一个数字
            else if(i!=min_length-1)
            {
                temp_str+='0';
                Number1_Str[i+1]+=1;
            }
            // 是最后一个元素 而且 下一个链表元素不为空
            else if (i==min_length-1 && temp.next != nullptr)
            {
                temp_str+='0';

                int data = atoi(temp.next->data.c_str());

                cout<<"data: "<<data<<endl;

                if( data >=1 && data<=9)
                {
                    temp.next->data +=1;
                }
                else if(data>=10 && data <=99)
                {
                    temp.next->data +=10;
                }
                else if(data>=100 && data <=999)
                {
                    temp.next->data +=100;
                }
                else if(data>=1000 && data <=9999)
                {
                    temp.next->data +=1000;
                }
            }
        }
    }
    cout<<"Number1_Str[0]: "<<Number1_Str[0]<<endl;
    cout<<"Number1_Str[1]: "<<Number1_Str[1]<<endl;
    cout<<"Number1_Str[2]: "<<Number1_Str[2]<<endl;
    cout<<"Number1_Str[3]: "<<Number1_Str[3]<<endl;

    cout<<"temp_str: "<<temp_str<<endl;

    return temp_str;
}

string Add::DiffAdd(LinkList &First, LinkList &Second, int first, int second, LNode &temp)
{
    string temp_str = "";

    string Number1_Str = to_string(first);
    string Number2_Str = to_string(second);

    int Number1_Str_Length = Number1_Str.length();
    int Number2_Str_Length = Number2_Str.length();
    int max_length,min_length;

    if(Number1_Str_Length >= Number2_Str_Length)
    {
        max_length = Number1_Str_Length;
        min_length = Number2_Str_Length;

        cout<<"Number1_Str: "<<Number1_Str<<endl;
        cout<<"Number2_Str: "<<Number2_Str<<endl;
        cout<<"max: "<<max_length<<endl;
        cout<<"min: "<<min_length<<endl;
    }
    else
    {
        max_length = Number2_Str_Length;
        min_length = Number1_Str_Length;

        cout<<"Number1_Str: "<<Number1_Str<<endl;
        cout<<"Number2_Str: "<<Number2_Str<<endl;
        cout<<"max: "<<max_length<<endl;
        cout<<"min: "<<min_length<<endl;
    }

    for (int i = 0; i < min_length; ++i) {

        int number1 = std::atoi(Number1_Str.substr(i,1).c_str());
        int number2 = std::atoi(Number2_Str.substr(i,1).c_str());
        int sum = number1 + number2;

        if(sum<10){
            if(max_length == min_length)
            {
                temp_str+=to_string(sum);
            }
            else
            {
                temp_str+=to_string(sum);

                while(i!=max_length-1 && temp.next == nullptr)
                {
                    temp_str+=Number1_Str[i+1];
                    i++;
                }

                while(i!=max_length-1 && temp.next != nullptr )
                {
                    int temp_number1 = std::atoi(Number1_Str.substr(i+1,1).c_str());
                    int temp_number2 = std::atoi(Number2_Str.substr(i+1,1).c_str());

                    int temp_sum = temp_number1 + temp_number2;

                    if(Number2_Str[i+1])
                    {
                        cout<<"Number1_Str[i+1]: "<<Number1_Str[i+1]<<endl;
                        cout<<"Number2_Str[i+1]: "<<Number2_Str[i+1]<<endl;

                        cout<<"temp_sum: "<<temp_sum<<endl;

                        if(temp_sum<10)
                        {
                            temp_str+=to_string(temp_sum);
                        }
                        else if(temp_sum==10)
                        {
                            temp_str+='0';
                        }
                        else
                        {
                            temp_str+=to_string(temp_sum-10);
                        }

                    }
                    else
                    {
                        int Temp_number1 = std::atoi(Number1_Str.substr(i,1).c_str());
                        int Temp_number2 = std::atoi(Number2_Str.substr(i,1).c_str());
                        int Temp = Temp_number1 + Temp_number2;

                        cout<<"Temp: "<<Temp<<endl;

                        if(Temp >=10)
                        {
                            Number1_Str[i+1]+=1;

                            temp_str+= Number1_Str[i+1];

                            cout<<Number1_Str[i+1]<<endl;

                            if(Number1_Str[i+1]==10)
                            {
                                Number1_Str[i+1]==0;

                                int data = atoi(temp.next->data.c_str());

                                if( data >=1 && data<=9)
                                {
                                    temp.next->data +=1;
                                }
                                else if(data>=10 && data <=99)
                                {
                                    temp.next->data +=10;
                                }
                                else if(data>=100 && data <=999)
                                {
                                    temp.next->data +=100;
                                }
                                else if(data>=1000 && data <=9999)
                                {
                                    temp.next->data +=1000;
                                }
                            }
                            else if(Number1_Str[i+1]>10)
                            {
                                Number1_Str[i+1]-=10;

                                int data = atoi(temp.next->data.c_str());

                                if( data >=1 && data<=9)
                                {
                                    temp.next->data +=1;
                                }
                                else if(data>=10 && data <=99)
                                {
                                    temp.next->data +=10;
                                }
                                else if(data>=100 && data <=999)
                                {
                                    temp.next->data +=100;
                                }
                                else if(data>=1000 && data <=9999)
                                {
                                    temp.next->data +=1000;
                                }
                            }
                        }
                        else
                        {
                            temp_str+= Number1_Str[i+1];
                        }

                        if(i!=max_length-2)
                        {
                            temp_str += to_string(Temp);
                            i++;
                        }
                    }
                    i++;
                }
            }
        }
        else if(sum>10){
            // 先安排这一位的数字
            temp_str+=to_string(sum-10);

            // 不是最后一个数字 链表的下一个元素不为空
            if (i!=min_length-1 && temp.next != nullptr)
            {
                Number1_Str[i+1]+=1;

                cout<<"Number1_Str[i+1] "<<Number1_Str[i+1]<<endl;

                cout<<"Number1_Str[i+2] "<<Number1_Str[i+2]<<endl;
            }
                // 不是最后一个数字 链表的下一个元素为空
            else if(i!= max_length-1 && temp.next == nullptr)
            {
                Number1_Str[i+1]+=1;

                temp_str+=Number1_Str[i+1];

                cout<<"不是最后一个数字 链表的下一个元素为空: "<<endl;
                cout<<"Number1_Str[i+1] is :"<<Number1_Str[i+1]<<endl;
            }
                // 是最后一个数字 链表的下一个元素为空
            else if(i== max_length-1 && temp.next == nullptr)
            {
                cout<<"是最后一个数字 链表的下一个元素为空: "<<endl;
                if(max_length == min_length)
                {
                    temp_str += "1";
                }
                else
                {
                    temp_str+=Number1_Str[i+1];
                }
            }
                // 是最后一个数字 链表的下一个元素不为空
            else if ( i == min_length-1  && temp.next != nullptr)
            {
                cout<<"Number1_Str[i] "<<Number1_Str[i]<<endl;

                int data = atoi(temp.next->data.c_str());

                cout<<"data: "<<data<<endl;

                if( data >=1 && data<=9)
                {
                    temp.next->data +=1;
                }
                else if(data>=10 && data <=99)
                {
                    temp.next->data +=10;
                }
                else if(data>=100 && data <=999)
                {
                    temp.next->data +=100;
                }
                else if(data>=1000 && data <=9999)
                {
                    temp.next->data +=1000;
                }
            }
        }
            // 相加等于10
        else{

            if(temp.next == nullptr)
            {
                cout<<"temp.next is empty"<<endl;
            }
            // 是最后一个数字 而且 下一个链表元素为空
            if (i== min_length-1 && temp.next == nullptr)
            {
                temp_str+="01";
                // Number1_Str[i+1]+=1;
            }
                // 不是最后一个数字
            else if(i!=min_length-1)
            {
                temp_str+='0';
                Number1_Str[i+1]+=1;
            }
                // 是最后一个元素 而且 下一个链表元素不为空
            else if (i==min_length-1 && temp.next != nullptr)
            {
                temp_str+='0';

                int data = atoi(temp.next->data.c_str());

                cout<<"data: "<<data<<endl;

                if( data >=1 && data<=9)
                {
                    temp.next->data +=1;
                }
                else if(data>=10 && data <=99)
                {
                    temp.next->data +=10;
                }
                else if(data>=100 && data <=999)
                {
                    temp.next->data +=100;
                }
                else if(data>=1000 && data <=9999)
                {
                    temp.next->data +=1000;
                }
            }
        }
    }
    cout<<"Number1_Str[0]: "<<Number1_Str[0]<<endl;
    cout<<"Number1_Str[1]: "<<Number1_Str[1]<<endl;
    cout<<"Number1_Str[2]: "<<Number1_Str[2]<<endl;
    cout<<"Number1_Str[3]: "<<Number1_Str[3]<<endl;

    cout<<"temp_str: "<<temp_str<<endl;

    return temp_str;
}