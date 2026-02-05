int main()
{
    enum {
        a,
        b,
        c,
        d
    } x;

    int i;
    x = 10;

    switch (x)
    {
        case a:
            i = 1;
            break;
        case b:
            i = 2;
            break;
        case c:
            i = 3;
            break;
        case d:
            i = 4;
            break;
        default:
            i = 0;
            break;
    }

    return i;
}