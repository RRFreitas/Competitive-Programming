int x, y, d;
void gcdExtended(int a, int b) {
    if(b == 0) {
        x = 1;
        y = 0;
        d = a;
        return;
    }
    gcdExtended(b, a % b);
    int x1 = y;
    int y1 = x - (a/b) * y;
    x = x1;
    y = y1;
}
