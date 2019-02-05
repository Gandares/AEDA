#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

template <class T>
class quick{
        
    private:
    
        int demostrar;
    
    public:
    
        void set_demos(int n){
            
            demostrar=n;    
        }
        
        int partition (vector<T>& v, int low, int high){
            
            int pivot = v[high];
            int i = (low - 1);
         
            for (int j = low; j <= high- 1; j++){
                if (v[j] <= pivot){
                    i++;
                    swap(v[i], v[j]);
                }
            }
            swap(v[i + 1], v[high]);
            return (i + 1);
        }

        void quick_sort(vector<T>& v, int low, int high){
            
            if (low < high){
                int pi = partition(v, low, high);
                quick_sort(v, low, pi - 1);
                quick_sort(v, pi + 1, high);
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