#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

template <class T>
class shell{
        
    private:
    
        int demostrar;
    
    public:
    
        void set_demos(int n){
            
            demostrar=n;    
        }
        
        void shell_sort(vector<T>& v){
            
            for (int gap = v.size()/2; gap > 0; gap /= 2){
                for (int i = gap; i < v.size(); i++){
                    
                    int temp = v[i];
                    int j;            
                    for (j = i; j >= gap && v[j - gap] > temp; j -= gap)
                        v[j] = v[j - gap];
                    v[j] = temp;
                }
            }
        }

        ostream& write(ostream& os, vector<T>& v){
            for(int j=0;j<v.size();j++)
                cout << v[j] << ", ";
            cout << endl << endl;
        }
        
        ostream& write(ostream& os, vector<double>& v){
            for(int j=0;j<v.size();j++)
                cout << v[j] << fixed << setprecision(6) << ", ";
            cout << endl << endl;
        }
        
};