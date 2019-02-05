#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

template <class T>
class bubble{
    
    private:
    
        int demostrar;
    
    public:
    
    
        void set_demos(int n){
            
            demostrar=n;    
        }
        
        void bubble_sort(vector<T>& v){
            
            int aux;
            
            for(int i=0;i<v.size();i++){
                for(int j=0;j<v.size();j++){
                    if(v[j]>v[j+1]){
                        aux=v[j];
                        v[j]=v[j+1];
                        v[j+1]=aux;
                    }
                    if(demostrar==1){
                        write(cout,v);
                        cin.get();
                    }
                }
            }
        }
        
        ostream& write(ostream& os, vector<T>& v){
            for(int j=0;j<v.size();j++)
                os << v[j] << ", ";
            os << endl << endl;
        }
        
        ostream& write(ostream& os, vector<double>& v){
            for(int j=0;j<v.size();j++)
                os << v[j] << fixed << setprecision(6) << ", ";
            os << endl << endl;
        }
};