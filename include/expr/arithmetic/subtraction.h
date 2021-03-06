//
// Created by Alexander Winter on 2017-09-23.
//

#ifndef POLY_SUM_H
#define POLY_SUM_H

#include <bits/unique_ptr.h>
#include "expr/expression.h"
#include "expr/variable.h"
#include "expr/expr_content.h"

namespace poly {
    class subtraction;
}

class poly::subtraction final : public poly::expr_content
{
    poly::expression minuend;
    poly::expression subtrahend;

public:
    subtraction(const poly::expression& minuend, const poly::expression& subtrahend);

    double resolve() const override;

    bool is_constant() const override {
        return minuend.is_constant() && subtrahend.is_constant();
    }

    poly::expression derivative(const variable &var) const override;

    expr_content* clone() const override {
        return new poly::subtraction(minuend, subtrahend);
    }

    std::string to_string() const override;
    std::string to_mathjax() const override;


};





#endif //POLY_SUM_H
