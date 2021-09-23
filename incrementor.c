///
/// file: incremetor.c
/// author: Joseph Casale

/**
 * increment executes a stepping function on two values and increments the first one
 */

void increment( double* val1,  double* val2,  double (*f)( double,  double) ){
    *(val1+1) = f(*val1, *val2);
}
