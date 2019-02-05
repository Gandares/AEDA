#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

template <class T>
class heap{
        
    private:
    
        int demostrar;
    
    public:
    
        void set_demos(int n){
            
            demostrar=n;    
        }
        
        void heapify(vector<T>& v, int n, int i){
            
            int largest = i;
            int l = 2*i + 1;
            int r = 2*i + 2;
         
            if (l < n && v[l] > v[largest])
                largest = l;
                
            if (r < n && v[r] > v[largest])
                largest = r;
                
            if (largest != i)
            {
                swap(v[i],v[largest]);
                heapify(v,n,largest);
            }
        }
        
        void heap_sort(vector<T>& v){
            
            for (int i = v.size() / 2 - 1; i >= 0; i--)
                heapify(v, v.size(), i);
                
            for (int i=v.size()-1; i>=0; i--){
                swap(v[0], v[i]);
                heapify(v, i, 0);
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