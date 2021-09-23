///
/// file: incrementor.h
/// Joseph Casale

/**
 * Changes the value to val1 to f(val1, val2)
 * @param val1 the value to be changed.
 * @param val2 a parameter to use (may make var)
 * @param f function(val1, val2) to use to reset.
 */
void increment( double* val1,  double* val2,  double (*f)( double,  double) );

