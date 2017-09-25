//
// Created by Alexander Winter on 2017-09-24.
//

#include "expr/functions/absolute_value.h"
#include <cmath>

poly::absolute_value::absolute_value(const poly::expression& argument)
        : argument(argument)
{

}

double poly::absolute_value::value() const
{
    return std::abs(argument.value());
}

bool poly::absolute_value::is_constant() const
{
    return argument.is_constant();
}

poly::expr_content* poly::absolute_value::clone() const
{
    return new poly::absolute_value(argument);
}

std::string poly::absolute_value::to_string() const
{
    return "|" + argument.to_string() + "|";
}

std::string poly::absolute_value::to_mathjax() const
{
    return "\\lvert\\," + argument.to_string() + "\\,\\lvert ";
}