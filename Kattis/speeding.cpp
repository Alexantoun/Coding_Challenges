#include <iostream> 
using namespace std;

int main(){
    int numPhotos, t, d;
    int max = 0;
    int t2, d2;
    cin >> numPhotos;
    cin >> t >> d;
    for(int x = 1; x < numPhotos; x++){
        cin >> t2 >> d2;
        // t2 -= t;
        // d2 -= d;
        if( (d2-d)/(t2-t) > max)
            max = (d2-d)/(t2-t);
        t = t2;
        d = d2;
    }
    cout<<max<<endl;
}