//
// Created by Alexander Winter on 2017-09-24.
//

#ifndef POLY_ABSOLUTE_VALUE_H
#define POLY_ABSOLUTE_VALUE_H

#include "../expression.h"

namespace poly {
    class absolute_value;
}

class poly::absolute_value final : public expr_content
{
    expression argument;

public:
    absolute_value(const expression& argument);

    double value() const override;
    bool is_constant() const override;

    expr_content* clone() const override;

    std::string to_string() const override;
    std::string to_mathjax() const override;
};


#endif //POLY_ABSOLUTE_VALUE_H