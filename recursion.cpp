int f(int x)
{
    if( x==0 )
        return 0;
    else
        return 2 * f( x- 1) + x*x;
}

void printOut ( int n ) //  Print nonnegative n
{
    if( n >= 10 )
        printOut( n / 10);
}