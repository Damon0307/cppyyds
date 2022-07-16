 #include "Third.h"
 
 using namespace std;
 
Third::~Third()
{
}

void Third::Third_DeliverOBJ()
{
 if(mGuoShi!= nullptr)
 {
        mGuoShi(mres_id,mres_str);
 }
}
