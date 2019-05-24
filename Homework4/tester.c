#include <iostream>
using namespace std;
void transpose(int *dst, int *src, int dim)
{
    const int blocksize = 8;
    int i, j, x, y;

    for (i = 0; i < dim; i += blocksize)
    {
        for (j = 0; j < dim; j += blocksize)
        {
            for (x = i; (x < dim && x < i+blocksize); x++)
            {
                for (y = j; (y < dim && y < j+blocksize); y++)
                    dst[y*dim + x] = src[x*dim + y];
            }
        }
    }
}

int main()
{
    /*
    int a[2][2] = {{4, 5},
                   {7, 8}};
    int b[2][2];
    transpose(*b, *a, 2);

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
            cout << b[i][j] << " ";
        cout << endl;
    }
    */
    int a[4][4] =  {{1,2,3,4},
                    {5,6,7,8},
                    {9,10,11,12},
                    {13,14,15,16}};
    int b[4][4];
    transpose(*b, *a, 4);

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            cout << b[i][j] << " ";
        cout << endl;
    }
}


