/* 
 * File:   Subtraction.h
 * Author: yudong
 *
 * Created on June 11, 2015, 12:27 PM
 */

#ifndef SUBTRACTION_H
#define	SUBTRACTION_H
#include "AbstractOperator.h"

class Subtraction :public AbstractOperator{
public:
    Subtraction();
    ~Subtraction();
    static boost::shared_ptr<AbstractOperator> get_instance();
    std::string get_operator_token() const;
    double eval(double l) const; 
    double eval(double l, double r) const; 
    
    ADNumber eval(ADNumber &&l) const{return -l;};  // for unary operator
    ADNumber eval(ADNumber &&l, ADNumber &&r) const {return l-r;};  // for binary operator
    
    AbsExpNodeSptr get_jacobian_element(AbsExpNodeSptr l, AbsExpNodeSptr r, int i);
    AbsExpNodeSptr get_hessian_element(AbsExpNodeSptr l, AbsExpNodeSptr r, int i, int j);
private:
    static bool instance_created;
    static boost::shared_ptr<AbstractOperator> instance;

};

#endif	/* SUBTRACTION_H */

