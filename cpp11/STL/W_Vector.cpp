#include "W_Vector.h"
W_Vector::~W_Vector()
{
}

void W_Vector::TraverseTheVector()
{
    cout<<"hello  "<<mstr<<endl;
    for(auto i : mvector)
    {
        cout<<" u have "<<i<<" in  the vector "<<endl;
    }
}
