//
// Created by zhihui on 7/16/19.
//

#ifndef HIGHPRECISION_INCLUDE_MUL_H_
#define HIGHPRECISION_INCLUDE_MUL_H_

#include "DataStructs.h"
#include <string>

class Mul
{
    public:

    ~Mul() = default;

    public:

    LinkList mul(LinkList &First,LinkList &Second,int firstLength,int secondLength);

    std::string partmul(LinkList &First,LinkList &Second, int first, int second, LNode &temp);
};

#endif //HIGHPRECISION_INCLUDE_MUL_H_
