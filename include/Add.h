//
// Created by zhihui on 7/16/19.
//

#ifndef HIGHPRECISION_INCLUDE_ADD_H_
#define HIGHPRECISION_INCLUDE_ADD_H_

#include "DataStructs.h"

class Add
{
    public:

    ~Add() = default;

    public:

    LinkList add(LinkList &First,LinkList &Second,int firstLength,int secondLength);

    std::string partAdd(LinkList &First,LinkList &Second, int first, int second, LNode &temp);

    std::string DiffAdd(LinkList &First,LinkList &Second, int first, int second, LNode &temp);
};
#endif //HIGHPRECISION_INCLUDE_ADD_H_
